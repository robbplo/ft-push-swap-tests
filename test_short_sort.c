/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_short_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rploeger <rploeger@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:23:22 by rploeger          #+#    #+#             */
/*   Updated: 2025/12/03 09:25:52 by rploeger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include "../sort.h"
#include "../list.h"
#include "../push_swap.h"
#include "test.h"


void	three_numbers_short_a()
{
	t_state state;

	bzero(&state, sizeof(t_state));
	list_push_back(&state.a, list_node(1));
	list_push_back(&state.a, list_node(2));
	list_push_back(&state.a, list_node(3));
	state.a_len = 3;
	short_sort(&state);
	assert_list_eq(state.a, ((int[]){1,2,3}), 3);
}

void	three_numbers_short_b()
{
	t_state state;

	bzero(&state, sizeof(t_state));
	list_push_back(&state.a, list_node(1));
	list_push_back(&state.a, list_node(3));
	list_push_back(&state.a, list_node(2));
	state.a_len = 3;
	short_sort(&state);
	assert_list_eq(state.a, ((int[]){1,2,3}), 3);
}

void	three_numbers_short_c()
{
	t_state state;

	bzero(&state, sizeof(t_state));
	list_push_back(&state.a, list_node(2));
	list_push_back(&state.a, list_node(1));
	list_push_back(&state.a, list_node(3));
	state.a_len = 3;
	short_sort(&state);
	assert_list_eq(state.a, ((int[]){1,2,3}), 3);
}

void	three_numbers_short_d()
{
	t_state state;

	bzero(&state, sizeof(t_state));
	list_push_back(&state.a, list_node(2));
	list_push_back(&state.a, list_node(3));
	list_push_back(&state.a, list_node(1));
	state.a_len = 3;
	short_sort(&state);
	assert_list_eq(state.a, ((int[]){1,2,3}), 3);
}

void	three_numbers_short_e()
{
	t_state state;

	bzero(&state, sizeof(t_state));
	list_push_back(&state.a, list_node(3));
	list_push_back(&state.a, list_node(1));
	list_push_back(&state.a, list_node(2));
	state.a_len = 3;
	short_sort(&state);
	assert_list_eq(state.a, ((int[]){1,2,3}), 3);
}

void	three_numbers_short_f()
{
	t_state state;

	bzero(&state, sizeof(t_state));
	list_push_back(&state.a, list_node(3));
	list_push_back(&state.a, list_node(2));
	list_push_back(&state.a, list_node(1));
	state.a_len = 3;
	short_sort(&state);
	assert_list_eq(state.a, ((int[]){1,2,3}), 3);
}

void	two_numbers_short_a()
{
	t_state state;

	bzero(&state, sizeof(t_state));
	list_push_back(&state.a, list_node(1));
	list_push_back(&state.a, list_node(2));
	state.a_len = 2;
	short_sort(&state);
	assert_list_eq(state.a, ((int[]){1,2}), 2);
}

void	two_numbers_short_b()
{
	t_state state;

	bzero(&state, sizeof(t_state));
	list_push_back(&state.a, list_node(2));
	list_push_back(&state.a, list_node(1));
	state.a_len = 2;
	short_sort(&state);
	assert_list_eq(state.a, ((int[]){1,2}), 2);
}

void	test_short_sort(void)
{
	three_numbers_short_a();
	three_numbers_short_b();
	three_numbers_short_c();
	three_numbers_short_d();
	three_numbers_short_e();
	three_numbers_short_f();
	two_numbers_short_a();
	two_numbers_short_b();
}
