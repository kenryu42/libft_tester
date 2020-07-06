/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jliew <jliew@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 15:18:35 by jliew             #+#    #+#             */
/*   Updated: 2020/07/07 03:05:22 by jliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "time.h"
#include "string.h"
#include "../includes/libft.h"

void	gen_rand_string(char *dst)
{
	for (int i = 0; i < 95; i ++)
		*dst++ = rand() % 95 + 32;
	*dst = '\0';
}

int		main(int argc, char **argv)
{
	srand(time(0));

	if (argc == 1)
    {
		printf("-----------------------------------------\n");
		printf(" char *ft_strchr(const char *str, int c)\n");
		printf("-----------------------------------------\n");
        printf("usage [auto]:\n1. a --run\n2. a --run <test_cases>\n3. a --run <test_cases> --print\n");
        printf("usage [manual]:\n1. a <string str> <char c>\n");
        return (42);
    }
	else if (argc >= 2 && !strcmp(argv[1], "--run"))
	{
		char	str[96];
		int		print = 0;
		int		failed = 0;
		int		test_cases = 1000000;

		printf("Running test(s): ft_strchr\n");
		if (argc >= 3)
			test_cases = atoi(argv[2]);
		if (argc >= 4 && !strcmp(argv[3], "--print"))
			print = 1;
		for (int i = 0; i < test_cases; i++)
		{
			gen_rand_string(str);
			int		c = rand() % 95 + 32;
			char	*st = strchr(str, c);
			char	*ft = ft_strchr(str, c);

			if (st != ft)
			{
				failed++;
				printf("FAILED CASE:\nstr: %s | c: %c\nst: %s\nft: %s\n", str, c, st, ft);
			}
			if (print)
				printf("[%d] test case:\nstr: %s | c: %c\nst: %s\nft: %s\n", i + 1, str, c, st, ft);
		}
		double rate = ((test_cases - failed) / (double)test_cases) * 100;
		printf("%.2f%%: Checks: %d, Failures: %d\n", rate, test_cases, failed);
	}
	else
	{
		char *str = argv[1];
		int n = argv[2][0];
		
		printf("st: %s\n", strchr(str, n));
		printf("ft: %s\n", ft_strchr(str, n));
	}
}
