/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rploeger <rploeger@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:55:50 by rploeger          #+#    #+#             */
/*   Updated: 2025/12/02 17:24:13 by rploeger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <stdio.h>

int	main(void)
{
	test_list();
	test_short_sort();
	test_greedy_sort();
	printf("All tests passed!\n");
}
