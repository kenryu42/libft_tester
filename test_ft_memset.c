/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jliew <jliew@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 21:44:17 by jliew             #+#    #+#             */
/*   Updated: 2020/07/07 03:04:10 by jliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "../includes/libft.h"

int		check(const char *st, const char *ft)
{
	for (int i = 0; i < 100; i++)
		if(st[i] != ft[i])
			return (1);
	return (0);
}

void	print_dst(const char *dst)
{
	for (int i = 0; i < 100; i++)
		printf("%i", dst[i]);
	printf("\n");
}

int		main(int argc, char **argv)
{
	srand(time(0));

	if (argc == 1)
	{
		printf("--------------------------------------------------\n");
		printf(" void *ft_memset(void *b, int c, unsigned long n)\n");
		printf("--------------------------------------------------\n");
		printf("usage [auto]:\n");
        printf("1. a --run\n");
        printf("2. a --run <test_cases>\n");
        printf("3. a --run <test_cases> --print\n");
		printf("usage [manual]:\n1. a <char/int> <int c> <int n>\n");
		return (42);
	}
	else if (!strcmp(argv[1], "--run"))
	{
		char dst1[100];
		char dst2[100];
		int print = 0;
		unsigned long failed = 0;
		unsigned long test_cases = 1000000;

		if (argc >= 3)
			test_cases = atoi(argv[2]);
		if (argc >= 4 && !strcmp(argv[3], "--print"))
			print = 1;
		printf("Running test(s): ft_memset\n");
		for (unsigned long i = 0; i < test_cases; i++)
		{
			int c = rand() % 10;
			int n = rand() % 101;
			memset(dst1, 0, sizeof(dst1));
			memset(dst2, 0, sizeof(dst2));

			char *st = memset(dst1, c, n);
			char *ft = ft_memset(dst2, c, n);
			if (check(st, ft))
			{
				failed++;
				printf("FAILED case:\nc: %i, n: %i\nst: ", c, n);
				print_dst(st);
				printf("ft: ");
				print_dst(ft);
			}
			if (print)
			{
				printf("[%lu] test case:\nc: %i, n: %i\nst: ", i + 1, c, n);
				print_dst(st);
				printf("ft: ");
				print_dst(ft);
			}
		}
		double rate = ((test_cases - failed) / (double)test_cases) * 100;
		printf("%.2f%%: Checks: %lu, Failures: %lu\n", rate, test_cases, failed);
	}
	else
	{
		char	c_dst1[100];
		char	c_dst2[100];
		int		i_dst1[100];
		int		i_dst2[100];
		memset(c_dst1, 0, sizeof(c_dst1));
		memset(c_dst2, 0, sizeof(c_dst2));
		memset(i_dst1, 0, sizeof(i_dst1));
		memset(i_dst2, 0, sizeof(i_dst2));

		int		c = atoi(argv[2]);
		int		n = atoi(argv[3]);

		if (argc != 4)
			return (42);

		if (!strcmp(argv[1], "char"))
		{
			memset(c_dst1, c, n);
			printf("st: ");
			for (int i = 0; i < 100; i++)
				printf("%i", c_dst1[i]);
			printf("\n");
			ft_memset(c_dst2, c, n);
			printf("ft: ");
			for (int i = 0; i < 100; i++)
				printf("%i", c_dst2[i]);
			printf("\n");
		}
		else
		{
			memset(i_dst1, c, n);
			printf("st: ");
			for (int i = 0; i < 100; i++)
				printf("%i", i_dst1[i]);
			printf("\n");
			ft_memset(i_dst2, c, n);
			printf("ft: ");
			for (int i = 0; i < 100; i++)
				printf("%i", i_dst2[i]);
			printf("\n");
		}
	}
}
