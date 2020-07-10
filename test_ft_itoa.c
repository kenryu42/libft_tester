/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jliew <jliew@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 15:26:10 by jliew             #+#    #+#             */
/*   Updated: 2020/07/10 19:04:22 by jliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "libft.h"

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		printf("----------------------\n");
		printf(" char *ft_itoa(int n)\n");
		printf("----------------------\n");
		printf("usage [auto]:\n");
		printf("1. a --run\n");
		printf("usage [manual]:\n");
		printf("1. a <int n>\n");
	}
	else if (!strcmp(argv[1], "--run"))
	{
		int cases[] = {INT_MIN, INT_MAX, 0};
		printf("----------------------\n");
		printf(" char *ft_itoa(int n)\n");
		printf("----------------------\n");
		for (int i = 0; i < 3; i++)
		{
			char *ft = ft_itoa(cases[i]);
			printf("[%i] n : %i, ft: %s\n", i + 1, cases[i], ft);
			free(ft);
		}
	}
	else
	{
		int n = atoi(argv[1]);
		char *s = ft_itoa(n);

		printf("ft: %s\n", s);
		free(s);
		printf("freed\n");
	}
}
