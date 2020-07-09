/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jliew <jliew@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 21:24:57 by jliew             #+#    #+#             */
/*   Updated: 2020/07/09 23:14:19 by jliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "libft.h"

void			gen_rand_string(char *dst)
{
	int n = rand() % 100000;

	for (int i = 0; i < n; i++)
	{
		*dst++ = rand() % 95 + 32;
	}
	*dst = '\0';
}

int				main(int argc, char **argv)
{
	srand(time(0));
	if (argc == 1)
    {
		printf("-----------------------------------\n");
		printf(" size_t ft_strlen(const char *str)\n");
		printf("-----------------------------------\n");
        printf("usage [auto]:\n1. a --run\n2. a --run <test_cases>\n3. a --run <test_cases> --print\n");
        printf("usage [manual]:\n1. a <string str>\n");
        return (42);
    }
	else if (!strcmp(argv[1], "--run"))
	{
		int		print = 0;
		int		failed = 0;
		char	str[100001];
		int		test_cases = 10000;
		
		if (argc >= 3)
			test_cases = atoi(argv[2]);
		if (argc >= 4 && !strcmp(argv[3], "--print"))
			print = 1;
		printf("Running test(s): ft_strlen\n");
		for (int i = 0; i < test_cases; i++)
		{
			gen_rand_string(str);
			unsigned long st = strlen(str), ft = ft_strlen(str);
			
			if (st != ft)
			{
				failed++;
				printf("FAILED case: str: %lu st: %lu ft: %lu\n", st, st, ft);
			}
			if (print)
				printf("[%d] test case: str: %lu st: %lu ft: %lu\n", i + 1, st, st, ft);
		}
		double rate = ((test_cases - failed) / (double)test_cases) * 100;
		printf("%.2f%%: Checks: %d, Failures: %d\n", rate, test_cases, failed);
	}
	else
	{
		char	*str = argv[1];

		printf("st: %lu\n", strlen(str));
		printf("ft: %lu\n", ft_strlen(str));
	}
}
