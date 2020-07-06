/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jliew <jliew@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 16:23:43 by jliew             #+#    #+#             */
/*   Updated: 2020/07/03 21:41:04 by jliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char	*ft_strdup(const char *str);

void	gen_rand_string(char *str, unsigned long n)
{
	while (n--)
		*str++ = rand() % 95 + 32;
	*str = '\0';
}

int		main(int argc, char **argv)
{
	srand(time(0));
	
	if (argc == 1)
	{
		printf("-----------------------------------\n");
		printf(" char * ft_strdup(const char *str)\n");
		printf("-----------------------------------\n");
		printf("usage [auto]:\n");
		printf("1. a --run\n");
		printf("2. a --run <test_cases>\n");
		printf("3. a --run <test_cases> --print\n");
		printf("usage [manual]:\n");
		printf("1. a <string src>\n");
		return (42);
	}
	if (!strcmp(argv[1], "--run"))
	{
		char			src[101];
		int				print = 0;
		unsigned long	failed = 0;
		unsigned long	test_cases = 1000000;

		if (argc >= 3)
			test_cases = atoi(argv[2]);
		if (argc >= 4 && !strcmp(argv[3], "--print"))
			print = 1;
		printf("Running test(s): ft_strdup\n");
		for (unsigned long i = 0; i < test_cases; i++)
		{
			int n = rand() % 101;
			gen_rand_string(src, n);
			char *st = strdup(src);
			char *ft = ft_strdup(src);
			if (st == NULL || ft == NULL)
			{
				printf("malloc failed at n: %d\n", n);
				continue;
			}
			if (strcmp(st, ft))
			{
				failed++;
				printf("FAILED case:\nsrc: %s\nst: %s\nft: %s\n", src, st, ft);
			}
			if (print)
				printf("[%lu] test case:\nsrc: %s\nst: %s\nft: %s\n", i + 1, src, st, ft);
			free(st);
			free(ft);
		}
		double rate = ((test_cases - failed) / (double)test_cases) * 100;
		printf("%.2f%%: Checks: %lu, Failures: %lu\n", rate, test_cases, failed);
	}
	else
	{
		char *src = argv[1];
		char *st = strdup(src);
		char *ft = ft_strdup(src);

		printf("st: %s\n", st);
		printf("ft: %s\n", ft);
		free(st);
		free(ft);
	}
}
