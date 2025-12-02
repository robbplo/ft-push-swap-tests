/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_short_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rploeger <rploeger@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:23:22 by rploeger          #+#    #+#             */
/*   Updated: 2025/12/02 17:26:28 by rploeger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include "../sort.h"
#include "../list.h"
#include "../push_swap.h"
#include "test.h"


void	three_numbers_short()
{
	t_state state;

	bzero(&state, sizeof(t_state));
	list_push_back(&state.a, list_node(1));
	list_push_back(&state.a, list_node(2));
	list_push_back(&state.a, list_node(3));
	state.a_len = 3;
	greedy_sort(&state);
	assert_list_eq(state.a, ((int[]){1,2,3}), 3);
}

void	test_short_sort(void)
{
	three_numbers_short();
}
