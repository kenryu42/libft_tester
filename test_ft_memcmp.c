/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jliew <jliew@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 13:35:18 by jliew             #+#    #+#             */
/*   Updated: 2020/07/07 03:06:55 by jliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "../includes/libft.h"

void	gen_rand_2strings(char *s1, char *s2, unsigned long n)
{
	while (n--)
	{
		int c = rand() % 95 + 32;

		*s1++ = c;
		*s2++ = c;
	}
	*s1 = '\0';
	*s2 = '\0';
}

int		main(int argc, char **argv)
{
	srand(time(0));

	if (argc == 1)
	{
		printf("----------------------------------------------------------------\n");
		printf(" int ft_memcmp(const void* s1, const void *s2, unsigned long n)\n");
		printf("----------------------------------------------------------------\n");
		printf("usage [auto]:\n");
		printf("1. a --run\n");
		printf("2. a --run <test_cases>\n");
		printf("3. a --run <test_cases> --print\n");
		printf("usage [manual]:\n");
		printf("1. a <string s1> <string s2> <int n>\n");
		return (42);
	}
	if (!strcmp(argv[1], "--run"))
	{
		char s1[101];
		char s2[101];
		int print = 0;
		unsigned long failed = 0;
		unsigned long test_cases = 1000000;
		
		if (argc >= 3)
			test_cases = atoi(argv[2]);
		if (argc >= 4 && !strcmp(argv[3], "--print"))
			print = 1;
		printf("Running test(s): ft_memcmp\n");
		for (unsigned long i = 0; i < test_cases; i++)
		{
			int n = rand() % 101;
			int rand_idx;
			int rand_c;

			gen_rand_2strings(s1, s2, n);
			if (n > 1)
			{
				rand_idx = rand() % n;
				rand_c = rand() % 95 + 32;
				s1[rand_idx] = rand_c;
			}
			int st = memcmp(s1, s2, n);
			int ft = ft_memcmp(s1, s2, n);
			
			if (st != ft)
			{
				failed++;
				printf("FAILED case:\ns1: %s\ns2: %s\nn: %d\nst: %d, ft: %d\n", s1, s2, n, st, ft);
			}
			if (print)
				printf("[%lu] test case:\ns1: %s\ns2: %s\nn: %d\nst: %d, ft: %d\n", i + 1, s1, s2, n, st, ft);
		}
		double rate = ((test_cases - failed) / (double)test_cases) * 100;
		printf("%.2f%%: Checks: %lu, Failures: %lu\n", rate, test_cases, failed);
	}
	else
	{
		char *s1 = argv[1];
		char *s2 = argv[2];
		int n = atoi(argv[3]);
		printf("st: %d\n", memcmp(s1, s2, n));
		printf("ft: %d\n", ft_memcmp(s1, s2, n));
	}
}
