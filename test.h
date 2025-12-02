/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rploeger <rploeger@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:57:44 by rploeger          #+#    #+#             */
/*   Updated: 2025/12/02 17:24:20 by rploeger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../list.h"
#include "../push_swap.h"

#define assert_list_eq(head, arr, size) \
	if (!assert_list_eq_impl(head, arr, size)) {\
		debug_print_impl(__FILE__, __LINE__, "assertion failed, lists are not equal"); \
		exit(1); \
	} \

void	debug_print_impl(const char *file, int line, const char *msg);
int		assert_list_eq_impl(t_list *head, int arr[], int size);
void	assert_ops_eq(t_op *ops, t_op arr[], int size);
void	test_list(void);
void	test_selection_sort(void);
void	test_greedy_sort(void);
void	test_short_sort(void);
