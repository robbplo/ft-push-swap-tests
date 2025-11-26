/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rploeger <rploeger@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:12:40 by rploeger          #+#    #+#             */
/*   Updated: 2025/11/15 15:43:58 by rploeger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdlib.h>
#include "../list.h"
#include "test.h"

void	test_list_push(void)
{
	t_list *l = NULL;
	list_push(&l, list_node(3));
	list_push(&l, list_node(2));
	list_push(&l, list_node(1));
	assert_list_eq(l, ((int []){1, 2, 3}), 3);
}

void	test_list_push_back(void)
{
	t_list *l = NULL;
	list_push_back(&l, list_node(1));
	list_push_back(&l, list_node(2));
	list_push_back(&l, list_node(3));
	assert_list_eq(l, ((int []){1, 2, 3}), 3);
}

void	test_list_pop(void)
{
	t_list *l = NULL;
	list_push(&l, list_node(3));
	list_push(&l, list_node(2));
	list_push(&l, list_node(1));
	assert(1 == list_pop(&l)->value);
	assert_list_eq(l, ((int []){2, 3}), 2);
	assert(2 == list_pop(&l)->value);
	assert_list_eq(l, ((int []){3}), 1);
	assert(3 == list_pop(&l)->value);
	assert(l == NULL);
}

void	test_list_swap(void)
{
	t_list *l = NULL;
	list_push(&l, list_node(3));
	list_push(&l, list_node(2));
	list_swap(&l);
	assert_list_eq(l, ((int []){3, 2}), 2);
	list_swap(&l);
	assert_list_eq(l, ((int []){2, 3}), 2);
	list_push(&l, list_node(1));
	list_swap(&l);
	assert_list_eq(l, ((int []){2, 1, 3}), 3);
	list_swap(&l);
	assert_list_eq(l, ((int []){1, 2, 3}), 3);
}

void test_list_rotate(void)
{
	t_list *l = NULL;
	list_push(&l, list_node(3));
	list_push(&l, list_node(2));
	list_push(&l, list_node(1));
	list_rotate(&l);
	assert_list_eq(l, ((int []){2, 3, 1}), 3);
	list_rotate(&l);
	assert_list_eq(l, ((int []){3, 1, 2}), 3);
	list_rotate(&l);
	assert_list_eq(l, ((int []){1, 2, 3}), 3);
}

void test_list_rev_rotate(void)
{
	t_list *l = NULL;
	list_push(&l, list_node(3));
	list_push(&l, list_node(2));
	list_push(&l, list_node(1));
	list_rotate(&l);
	assert_list_eq(l, ((int []){2,3,1}), 3);
	list_rotate(&l);
	assert_list_eq(l, ((int []){3,1,2}), 3);
	list_rotate(&l);
	assert_list_eq(l, ((int []){1,2,3}), 3);
}

void	test_list_length(void)
{
	t_list *l = NULL;
	assert(list_length(l) == 0);
	list_push(&l, list_node(5));
	assert(list_length(l) == 1);
	list_push(&l, list_node(4));
	assert(list_length(l) == 2);
	list_push(&l, list_node(3));
	assert(list_length(l) == 3);
	list_push(&l, list_node(2));
	assert(list_length(l) == 4);
	list_push(&l, list_node(1));
	assert(list_length(l) == 5);
}

void	test_list_index_of(void)
{
	t_list *l = NULL;
	list_push(&l, list_node(5));
	list_push(&l, list_node(4));
	list_push(&l, list_node(3));
	list_push(&l, list_node(2));
	list_push(&l, list_node(1));
	assert(list_index_of(l, 1) == 0);
	assert(list_index_of(l, 2) == 1);
	assert(list_index_of(l, 3) == 2);
	assert(list_index_of(l, 4) == 3);
	assert(list_index_of(l, 5) == 4);
	list_push(&l, list_node(6));
	list_push(&l, list_node(7));
	assert(list_index_of(l, 6) == 1);
	assert(list_index_of(l, 7) == 0);
	assert(list_index_of(l, 123) == -1);
}

void	test_list_min_index(void)
{
	t_list *l = NULL;
	list_push(&l, list_node(3));
	list_push(&l, list_node(2));
	list_push(&l, list_node(1));
	assert(list_min_index(l) == 0);
	list_rev_rotate(&l);
	assert(list_min_index(l) == 1);
	list_rev_rotate(&l);
	assert(list_min_index(l) == 2);
	list_rev_rotate(&l);
	list_push(&l, list_node(4));
	list_rev_rotate(&l);
	list_push(&l, list_node(5));
	list_rev_rotate(&l);
	list_push(&l, list_node(6));
	list_rev_rotate(&l);
	assert(list_min_index(l) == 0);
	list_rotate(&l);
	assert(list_min_index(l) == 5);
	list_rotate(&l);
	assert(list_min_index(l) == 4);
	list_rotate(&l);
	assert(list_min_index(l) == 3);
}

void test_list_get(void)
{
	t_list *l = NULL;
	list_push_back(&l, list_node(1));
	list_push_back(&l, list_node(2));
	list_push_back(&l, list_node(3));
	list_push_back(&l, list_node(4));
	list_push_back(&l, list_node(5));
	assert(list_get(l, 0)->value == 1);
	assert(list_get(l, 1)->value == 2);
	assert(list_get(l, 2)->value == 3);
	assert(list_get(l, 3)->value == 4);
	assert(list_get(l, 4)->value == 5);
	assert(list_get(l, 5)->value == 1);
	assert(list_get(l, -1)->value == 5);
	assert(list_get(l, -2)->value == 4);
	assert(list_get(l, -3)->value == 3);
	assert(list_get(l, -4)->value == 2);
	assert(list_get(l, -5)->value == 1);
	assert(list_get(l, -6)->value == 5);
}

void test_list_index_to_offset(void)
{
	assert(list_index_to_offset(5, 0) == 0);
	assert(list_index_to_offset(5, 1) == 1);
	assert(list_index_to_offset(5, 2) == 2);
	assert(list_index_to_offset(5, 3) == -2);
	assert(list_index_to_offset(5, 4) == -1);
}

void test_list(void)
{
	test_list_push();
	test_list_push_back();
	test_list_pop();
	test_list_swap();
	test_list_rotate();
	test_list_rev_rotate();
	test_list_min_index();
	test_list_length();
	test_list_index_of();
	test_list_get();
	test_list_index_to_offset();
}
