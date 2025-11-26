/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_selection_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rploeger <rploeger@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:28:57 by rploeger          #+#    #+#             */
/*   Updated: 2025/11/24 12:10:55 by rploeger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include "../sort.h"
#include "../list.h"
#include "../push_swap.h"
#include "test.h"

void	four_low_numbers()
{
	t_state state;

	bzero(&state, sizeof(t_state));
	list_push(&state.a, list_node(3));
	list_push(&state.a, list_node(1));
	list_push(&state.a, list_node(5));
	list_push(&state.a, list_node(2));
	selection_sort(&state);
	assert_list_eq(state.a, ((int[]){1,2,3,5}), 4);
}

void	test_selection_sort(void)
{
	four_low_numbers();
}
