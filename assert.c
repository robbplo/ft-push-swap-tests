/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rploeger <rploeger@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:29:22 by rploeger          #+#    #+#             */
/*   Updated: 2025/11/26 10:07:13 by rploeger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include "../list.h"
#include "../push_swap.h"
#include "../libft/libft.h"

void	list_print(t_list *head)
{
	t_list	*start;

	if (!head)
		return;
	start = head;
	while (1)
	{
		ft_putnbr_fd(head->value, STDOUT_FILENO);
		head = head->next;
		if (head == start)
			break;
		ft_putchar_fd(' ', STDOUT_FILENO);
	}
	ft_putchar_fd('\n', STDOUT_FILENO);
}

void debug_print_impl(const char *file, int line, const char *msg)
{
	printf("[%s:%d] %s\n", file, line, msg);
}

static int	assert_list_eq_test(t_list *head, int arr[], int size, int index)
{
	if (list_get(head, index)->value == arr[index])
		return 1;
	write(STDOUT_FILENO, "actual:   ", 11);
	list_print(head);
	write(STDOUT_FILENO, "expected: ", 11);
	for (int i = 0; i < size; i++)
	{
		ft_putnbr_fd(arr[i], STDOUT_FILENO);
		ft_putchar_fd(' ', STDOUT_FILENO);
	}
	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, "          ", 11);
	for (int i = 0; i < size; i++)
	{
		if (head->value != arr[i])
			write(STDOUT_FILENO, "^ ", 2);
		else 
			write(STDOUT_FILENO, "  ", 2);
		head = head->next;
	}
	write(STDOUT_FILENO, "\n", 1);
	return 0;
}

int	assert_list_eq_impl(t_list *head, int arr[], int size)
{
	int i = 0;
	t_list	*node = head;

	while (i < size) {
		if (!assert_list_eq_test(head, arr, size, i))
			return (0);
		node = node->next;
		i++;
	}
	i = size - 1;
	node = node->prev;
	while (i >= 0) {
		if (!assert_list_eq_test(head, arr, size, i))
			return (0);	
		node = node->prev;
		i--;
	}
	return (1);
}

void	assert_ops_eq(t_op *ops, t_op arr[], int size)
{
	int i = 0;
	while (i < size)
	{
		assert(arr[i] == ops[i]);
		i++;
	}
	assert(ops[i] == OP_NULL);
}
