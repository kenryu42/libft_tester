/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strnstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jliew <jliew@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 20:08:41 by jliew             #+#    #+#             */
/*   Updated: 2020/07/09 23:15:25 by jliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "libft.h"

void	gen_rand_string(char *dst, int n)
{
	for (int i = 0; i < n; i++)
		*dst++ = rand() % 26 + 97;
	*dst = '\0';
}

int		main(int argc, char **argv)
{
	srand(time(0));
	
	if (argc == 1)
    {
		printf("-----------------------------------------------------------------\n");
		printf(" char *ft_strnstr(const char *str, const char *target, size_t n)\n");
		printf("------------------------------------------------------------------\n");
        printf("usage [auto]:\n1. a --run\n2. a --run <test_cases>\n3. a --run <test_cases> --print\n");
        printf("usage [manual]:\n1. a <string str> <string target> <int n>\n");
        return (42);
    }
	else if (!strcmp(argv[1], "--run"))
	{
		char	str[101];
		int		print = 0;
		int		failed = 0;
		char	target[4];
		int		test_cases = 1000000;

		if (argc >= 3)
			test_cases = atoi(argv[2]);
		if (argc >= 4 && !strcmp(argv[3], "--print"))
			print = 1;
		printf("Running test(s): ft_strnstr\n");
		for (int i = 0; i < test_cases; i++)
		{
			int		n = rand() % 105;
			gen_rand_string(str, rand() % 101);
			gen_rand_string(target, 1);
			char *st = strnstr(str, target, n);
			char *ft = strnstr(str, target, n);
			
			if (st != ft)
			{
				failed++;
				printf("FAILED case:\nstr: %s\ntarget: %s n: %d\nst: %s\nft: %s\n", str, target, n, st, ft);
			}
			if (print)
				printf("[%d] test case:\nstr: %s\ntarget: %s\nn: %d\nst: %s\nft: %s\n", i + 1, str, target, n, st, ft);
		}
		double rate = ((test_cases - failed) / (double)test_cases) * 100;
		printf("%.2f%%: Checks: %d, Failures: %d\n", rate, test_cases, failed);
	}
	else
	{
		char	*str = argv[1];
		char	*target = argv[2];
		int		n = atoi(argv[3]);

		printf("st: %s\n", strnstr(str, target, n));
		printf("ft: %s\n", ft_strnstr(str, target, n));
	}
}
