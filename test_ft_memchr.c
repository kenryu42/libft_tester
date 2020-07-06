/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jliew <jliew@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 16:24:55 by jliew             #+#    #+#             */
/*   Updated: 2020/07/02 22:18:44 by jliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>

void	*ft_memchr(const void *s, int c, unsigned long n);

void	gen_rand_string(char *dst)
{
	for (int i = 0; i < 100; i++)
	{
		*dst++ = rand() % 95 + 32;
	}
	*dst = '\0';
}

int		check(const char *st, const char *ft)
{
	if (!st && !ft)
		return (0);
	if (st && ft)
		return (2);
	return (1);
}

int		main(int argc, char **argv)
{
	srand(time(0));

	if (argc == 1)
	{
		printf("--------------------------------------------------------\n");
		printf(" void *ft_memchr(const void *s, int c, unsigned long n)\n");
		printf("--------------------------------------------------------\n");
		printf("usage [auto]:\n");
		printf("1. a --run\n");
		printf("2. a --run <test_cases>\n");
		printf("3. a --run <test_cases> --print\n");
		printf("usage [manual]:\n");
		printf("1. a <string src> <int c> <int n>\n");
		return (42);
	}
	else if (!strcmp(argv[1], "--run"))
	{
		char 			str[101];
		int				print = 0;
		unsigned long	failed = 0;
		unsigned long	test_cases = 1000000;

		if (argc >= 3)
			test_cases = atoi(argv[2]);
		if (argc >= 4 && !strcmp(argv[3], "--print"))
			print = 1;
		printf("Running test(s): ft_memchr\n");
		for (unsigned long i = 0; i < test_cases; i++)
		{
			gen_rand_string(str);
			int c = rand() % 95 + 32;
			int n = rand() % 101;

			char *st = memchr(str, c, n);
			char *ft = ft_memchr(str, c, n);

			if ((check(st, ft) == 2 && strcmp(st, ft)) || check(st, ft) == 1)
			{
				failed++;
				printf("FAILED case:\nstr: %s\nc: %c, n: %d\nst: %s\nft: %s\n", str, c, n, st, ft);
			}
			if (print)
				printf("[%lu] test case:\nstr: %s\nc: %c, n: %d\nst: %s\nft: %s\n", i + 1, str, c, n, st, ft);
		}
		double rate = ((test_cases - failed) / (double)test_cases) * 100;
		printf("%.2f%%: Checks: %lu, Failures: %lu\n", rate, test_cases, failed);
	}
	else
	{
		char *s = argv[1];
		int c = argv[2][0];
		int n = atoi(argv[3]);
		/*int s[] = {48, 2, 3, 4, 5, 6, 7, 8, 9};*/
		/*int c = argv[1][0];*/
		/*int n = atoi(argv[2]);*/
		
		char *st_res = memchr(s, c, n);
		char *ft_res = ft_memchr(s, c, n);

		printf("st: %s\n", st_res);
		printf("ft: %s\n", ft_res);
	}
}
