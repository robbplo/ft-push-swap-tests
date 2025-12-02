/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_greedy_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rploeger <rploeger@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 14:59:21 by rploeger          #+#    #+#             */
/*   Updated: 2025/11/27 13:06:49 by rploeger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <limits.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include "../sort.h"
#include "../list.h"
#include "../push_swap.h"
#include "test.h"

#define OPS_SIZE 100

static void	reset_state(t_state *s)
{
	s->min_ops_len = INT_MAX;
	bzero(s->curr_ops, OPS_SIZE * sizeof(t_op));
	bzero(s->min_ops, OPS_SIZE * sizeof(t_op));
}

void	test_correct_index_desc(void)
{
	t_state s;
	bzero(&s, sizeof(t_state));
	list_push_back(&s.b, list_node(5));
	list_push_back(&s.b, list_node(3));
	list_push_back(&s.b, list_node(1));
	s.b_len = 3;
	// l: 5 3 1
	assert(correct_index_desc(&s, 42) == 0);
	assert(correct_index_desc(&s, 6) == 0);
	assert(correct_index_desc(&s, 5) == 0);
	assert(correct_index_desc(&s, 4) == 1);
	assert(correct_index_desc(&s, 3) == 1);
	assert(correct_index_desc(&s, 2) == 2);
	assert(correct_index_desc(&s, 1) == 0);
	assert(correct_index_desc(&s, 0) == 0);
	assert(correct_index_desc(&s, -1) == 0);
	list_rotate(&s.b);
	// l: 3 1 5
	assert(correct_index_desc(&s, 42) == 2);
	assert(correct_index_desc(&s, 6) == 2);
	assert(correct_index_desc(&s, 5) == 0);
	assert(correct_index_desc(&s, 4) == 0);
	assert(correct_index_desc(&s, 3) == 0);
	assert(correct_index_desc(&s, 2) == 1);
	assert(correct_index_desc(&s, 1) == 1);
	assert(correct_index_desc(&s, 0) == 2);
	assert(correct_index_desc(&s, -1) == 2);
	list_rotate(&s.b);
	// l: 1 5 3
	assert(correct_index_desc(&s, 42) == 1);
	assert(correct_index_desc(&s, 6) == 1);
	assert(correct_index_desc(&s, 5) == 1);
	assert(correct_index_desc(&s, 4) == 2);
	assert(correct_index_desc(&s, 3) == 0);
	assert(correct_index_desc(&s, 2) == 0);
	assert(correct_index_desc(&s, 1) == 0);
	assert(correct_index_desc(&s, 0) == 1);
	assert(correct_index_desc(&s, -1) == 1);
	list_rotate(&s.b);
	// l: 5 3 1
	free(list_pop(&s.b));
	s.b_len--;
	list_swap(&s.b);
	// l: 1 3
	assert(correct_index_desc(&s, 2) == 0);
}

void	test_ops_to_move()
{
	t_state s;
	bzero(&s, sizeof(t_state));
	s.min_ops_len = INT_MAX;
	s.curr_ops = calloc(OPS_SIZE, sizeof(t_op));
	s.min_ops = calloc(OPS_SIZE, sizeof(t_op));
	s.a_len = 10;
	s.b_len = 5;

	// Forward-only moves
	assert_ops_eq(
		ops_to_move(&s, 0, 0),
		(t_op[]){},
		0
	);
	assert(s.min_ops_len == 0);
	reset_state(&s);
	assert_ops_eq(
		ops_to_move(&s, 1, 0),
		(t_op[]){RA},
		1
	);
	assert(s.min_ops_len == 1);
	reset_state(&s);
	assert_ops_eq(
		ops_to_move(&s, 4, 4),
		(t_op[]){RR,RR,RR,RR},
		4
	);
	assert(s.min_ops_len == 4);
	reset_state(&s);
	assert_ops_eq(
		ops_to_move(&s, 1, 2),
		(t_op[]){RR,RB},
		2
	);
	assert(s.min_ops_len == 2);
	reset_state(&s);
	assert_ops_eq(
		ops_to_move(&s, 2, 1),
		(t_op[]){RR,RA},
		2
	);
	assert(s.min_ops_len == 2);
	reset_state(&s);
	// Reverse moves
	assert_ops_eq(
		ops_to_move(&s, -1, 0),
		(t_op[]){RRA},
		1
	);
	assert(s.min_ops_len == 1);
	reset_state(&s);
	assert_ops_eq(
		ops_to_move(&s, -3, -4),
		(t_op[]){RRR,RRR,RRR,RRB},
		4
	);
	assert(s.min_ops_len == 4);
	reset_state(&s);
	assert_ops_eq(
		ops_to_move(&s, -3, 3),
		(t_op[]){RB,RB,RB,RRA,RRA,RRA},
		6
	);
	assert(s.min_ops_len == 6);
	reset_state(&s);
	free(s.curr_ops);
	free(s.min_ops);
}

void	test_min_ops(void)
{
	t_state s;
	bzero(&s, sizeof(t_state));
	s.min_ops_len = INT_MAX;
	s.curr_ops = calloc(OPS_SIZE, sizeof(t_op));
	s.min_ops = calloc(OPS_SIZE, sizeof(t_op));
	s.a_len = 10;
	s.b_len = 5;

	assert_ops_eq(
		min_ops(&s, 9, 4),
		(t_op[]){RRR},
		1
	);
	assert(s.min_ops_len == 1);
	reset_state(&s);
	assert_ops_eq(
		min_ops(&s, 1, 4),
		(t_op[]){RA, RRB},
		2
	);
	reset_state(&s);
	assert_ops_eq(
		min_ops(&s, 0, 0),
		(t_op[]){},
		0
	);
	reset_state(&s);
	// place at the end
	s.a_len = 1;
	s.b_len = 3;
	assert_ops_eq(
		min_ops(&s, 0, 3),
		(t_op[]){RRB},
		1
	);
	reset_state(&s);
	s.a_len = 2;
	s.b_len = 2;
	assert_ops_eq(
		min_ops(&s, 0, 1),
		(t_op[]){RB},
		1
	);
	free(s.curr_ops);
	free(s.min_ops);
}

void	four_low_numbers_greedy()
{
	t_state state;

	bzero(&state, sizeof(t_state));
	list_push(&state.a, list_node(1));
	list_push(&state.a, list_node(3));
	list_push(&state.a, list_node(5));
	list_push(&state.a, list_node(2));
	state.a_len = 4;
	greedy_sort(&state);
	assert_list_eq(state.a, ((int[]){1,2,3,5}), 4);
}

void	four_high_numbers_greedy()
{
	t_state state;

	bzero(&state, sizeof(t_state));
	list_push_back(&state.a, list_node(321));
	list_push_back(&state.a, list_node(617));
	list_push_back(&state.a, list_node(484));
	list_push_back(&state.a, list_node(708));
	state.a_len = 4;
	greedy_sort(&state);
	assert_list_eq(state.a, ((int[]){321,484,617,708}), 4);
}

void	four_sorted_rotated_greedy()
{
	t_state state;

	bzero(&state, sizeof(t_state));
	list_push_back(&state.a, list_node(4));
	list_push_back(&state.a, list_node(1));
	list_push_back(&state.a, list_node(2));
	list_push_back(&state.a, list_node(3));
	state.a_len = 4;
	greedy_sort(&state);
	assert_list_eq(state.a, ((int[]){1,2,3,4}), 4);
}

void	six_three_digits_greedy()
{
	t_state state;

	bzero(&state, sizeof(t_state));
	list_push_back(&state.a, list_node(320));
	list_push_back(&state.a, list_node(693));
	list_push_back(&state.a, list_node(595));
	list_push_back(&state.a, list_node(530));
	list_push_back(&state.a, list_node(177));
	list_push_back(&state.a, list_node(652));
	state.a_len = 6;
	greedy_sort(&state);
	assert_list_eq(state.a, ((int[]){177,320,530,595,652,693}), 6);
}

void	test_greedy_sort(void)
{
	test_correct_index_desc();
	test_ops_to_move();
	test_min_ops();
	four_low_numbers_greedy();
	four_high_numbers_greedy();
	four_sorted_rotated_greedy();
	six_three_digits_greedy();
}
