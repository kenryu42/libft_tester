/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jliew <jliew@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 13:43:15 by jliew             #+#    #+#             */
/*   Updated: 2020/07/08 01:54:35 by jliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "time.h"
#include "ctype.h"
#include "string.h"
#include "limits.h"
#include "../libft.h"

int		ft_isalpha(int c);

int		main(int argc, char **argv)
{
	if (argc == 1)
    {
		printf("-----------------------\n");
		printf(" int ft_isalpha(int c)\n");
		printf("-----------------------\n");
        printf("usage [auto]:\n1. a --run\n2. a --run --print\n");
        printf("usage [manual]:\n");
		printf("1. a <int c>\n");
        printf("2. a --C <char c>\n");
        return (42);
    }
	else if (!strcmp(argv[1], "--run"))
	{
		long cnt = 0;
		long failed = 0;

		printf("Running small test(s): ft_isalpha\n");
		for (int i = 0; i <= 127; i++)
		{
			cnt++;
			if (isalpha(i) != ft_isalpha(i))
			{
				failed++;
				printf("FAILED case: %c , st: %d, ft: %d\n", i, isalpha(i), ft_isalpha(i));
			}
			if (argc == 3 && !strcmp(argv[2], "--print"))
				printf("%i: test case: %c , st: %i, ft: %i\n", i, i, isalpha(i), ft_isalpha(i));
		}
		double rate = ((cnt - failed) / (double)cnt) * 100;
		printf("%.2f%%: Checks: %ld, Failures: %ld\n", rate, cnt, failed);
		printf("Running full test(s): ft_isalpha\n");

		cnt = 0;
		failed = 0;
		for (long i = INT_MIN; i <= INT_MAX; i++)
		{
			cnt++;
			if (isalpha(i) != ft_isalpha(i))
			{
				failed++;
				printf("FAILED case: %ld , st: %d, ft: %d\n", i, isalpha(i), ft_isalpha(i));
			}
		}
		rate = ((cnt - failed) / (double)cnt) * 100;
		printf("%.2f%%: Checks: %ld, Failures: %ld\n", rate, cnt, failed);
	}
	else if (!strcmp(argv[1], "--C"))
    {
        printf("st: %i\n", isalpha(argv[2][0]));
        printf("ft: %i\n", ft_isalpha(argv[2][0]));
    }
	else
	{
		printf("st: %i\n", isalpha(atoi(argv[1])));
		printf("ft: %i\n", ft_isalpha(atoi(argv[1])));
	}
}
