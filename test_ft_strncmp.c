/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strncmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jliew <jliew@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 21:24:57 by jliew             #+#    #+#             */
/*   Updated: 2020/07/09 23:15:53 by jliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>
#include <string.h>
#include "libft.h"

void	gen_rand_2strings(char *s1, char* s2, unsigned long n)
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
        printf("-------------------------------------------------------\n");
		printf(" int strncmp(const char *s1, const char *s2, size_t n)\n");
        printf("-------------------------------------------------------\n");
        printf("usage [auto]:\n1. a --run\n2. a --run <test_cases>\n3. a --run <test_cases> --print\n");
        printf("usage [manual]:\n1. a <string s1> <string s2> <int n>\n");
        return (42);
    }
	else if (!strcmp(argv[1], "--run"))
	{
		int					print = 0;
		char				s1[101];
		char				s2[101];
		unsigned long		failed = 0;
		unsigned long		test_cases = 1000000;
		
		if (argc >= 3)
			test_cases = atoi(argv[2]);
		if (argc >= 4 && !strcmp(argv[3], "--print"))
			print = 1;
		printf("Running test(s): ft_strncmp\n");
		for (unsigned long i = 0; i < test_cases; i++)
		{
			int s_n = rand() % 101;
			gen_rand_2strings(s1, s2, s_n);
			if (s_n > 1)
			{
				int rand_idx = rand() % s_n;
				s1[rand_idx] = rand() % 95 + 32;
			}
			int n = rand() % 101;
			int st = strncmp(s1, s2, n), ft = ft_strncmp(s1, s2, n);
			
			if (st != ft)
			{
				failed++;
				printf("FAILED case:\n s1: %s\ns2: %s\nst: %d ft: %d n: %d\n", s1, s2, st, ft, n);
			}
			if (print)
				printf("[%lu] test case:\ns1: %s\ns2: %s\nst: %d ft: %d n: %d\n", i + 1, s1, s2, st, ft, n);
		}
		double rate = ((test_cases - failed) / (double)test_cases) * 100;
		printf("%.2f%%: Checks: %lu, Failures: %lu\n", rate, test_cases, failed);
	}
	else
	{
		char			*s1 = argv[1];
		char			*s2 = argv[2];
		unsigned long	n = atoi(argv[3]);

		printf("st: %d\n", strncmp(s1, s2, n));
		printf("ft: %d\n", ft_strncmp(s1, s2, n));
	}

}
