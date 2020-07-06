/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_calloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jliew <jliew@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 21:57:42 by jliew             #+#    #+#             */
/*   Updated: 2020/07/03 23:47:15 by jliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void	*ft_calloc(unsigned long count, unsigned long size);

int		main(int argc, char **argv)
{
	srand(time(0));

	if (argc == 1)
	{
		printf("----------------------------------------------------------\n");
		printf(" void *ft_calloc(unsigned long count, unsigned long size)\n");
		printf("----------------------------------------------------------\n");
		printf("usage [auto]:\n");
		printf("1. a --run\n");
		printf("1. a --run <test_cases>\n");
		printf("1. a --run <test_cases> --print\n");
		printf("usage [manual]:\n");
		printf("1. a <char/int> <count>\n");
		return (42);
	}
	if (!strcmp(argv[1], "--run"))
	{
		int				print = 0;
		unsigned long	failed = 0;
		unsigned long	test_cases = 1000000;

		if (argc >= 3)
			test_cases = atoi(argv[2]);
		if (argc >= 4 && !strcmp(argv[3], "--print"))
			print = 1;
		printf("Running test(s): ft_calloc\n");
		for (unsigned long i = 0; i < test_cases; i++)
		{
			int type = rand() % 2;
			int count = rand() % 1000;

			if (type)
			{
				char *st = calloc(count, sizeof(char));
				char *ft = ft_calloc(count, sizeof(char));
				int res = memcmp(st, ft, count * sizeof(char));

				if (res)
				{
					failed++;
					printf("FAILED case:\nType: char, Count: %d\nmemcmp: %d\n", count, res);
				}
				if (print)
					printf("[%lu] test case:\nType: char, Count: %d\nmemcmp: %d\n", i + 1, count, res);
				free(st);
				free(ft);
			}
			else
			{
				int *st = calloc(count, sizeof(int));
				int *ft = ft_calloc(count, sizeof(int));
				int res = memcmp(st, ft, count * sizeof(int));

				if (res)
				{
					failed++;
					printf("FAILED case:\nType: int, Count: %d\nmemcmp: %d\n", count, res);
				}
				if (print)
					printf("[%lu] test case:\nType: int, Count: %d\nmemcmp: %d\n", i + 1, count, res);
				free(st);
				free(ft);
			}
		}
		double rate = ((test_cases - failed) / (double)test_cases) * 100;
		printf("%.2f%%: Checks: %lu, Failures: %lu\n", rate, test_cases, failed);
	}
	else
	{
		int count = atoi(argv[2]);
		if (!strcmp(argv[1], "int"))
		{
			int *n1 = calloc(count, sizeof(int));
			int *n2 = ft_calloc(count, sizeof(int));

			char *num1 = (char *)n1;
			char *num2 = (char *)n2;
			printf("st: ");
			for (int i = 0; i < count * (int)sizeof(int); i++)
				printf("%i", num1[i]);
			printf("\n");
			printf("ft: ");
			for (int i = 0; i < count * (int)sizeof(int); i++)
				printf("%i", num2[i]);
			printf("\n");
			free(n1);
			free(n2);
		}
		else
		{
			char *str1 = calloc(count, sizeof(char));
			char *str2 = ft_calloc(count, sizeof(char));

			printf("st: ");
			for (int i = 0; i < count; i++)
				printf("%i", str1[i]);
			printf("\n");
			printf("ft: ");
			for (int i = 0; i < count; i++)
				printf("%i", str2[i]);
			printf("\n");
			free(str1);
			free(str2);
		}
	}
}
