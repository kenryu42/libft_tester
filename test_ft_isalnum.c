/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jliew <jliew@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 13:43:15 by jliew             #+#    #+#             */
/*   Updated: 2020/07/07 23:00:20 by jliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time.h"
#include "stdio.h"
#include "ctype.h"
#include "string.h"
#include "limits.h"
#include "../libft.h"

int		main(int argc, char **argv)
{
	if (argc == 1)
    {
		printf("-----------------------\n");
		printf(" int ft_isalnum(int c)\n");
		printf("-----------------------\n");
        printf("usage [auto]:\n1. a --run\n2. a --run --print\n");
        printf("usage [manual]:\n1. a <int c>\n");
		printf("2. a --C <char c>\n");
        return (42);
    }
	else if (!strcmp(argv[1], "--run"))
	{
		long cnt = 0;
		long failed = 0;

		printf("Running small test(s): ft_isalnum\n");
		for (int i = 0; i <= 127; i++)
		{
			cnt++;
			if (isalnum(i) != ft_isalnum(i))
			{
				failed++;
				printf("FAILED case: %c , st: %d, ft: %d\n", i, isalnum(i), ft_isalnum(i));
			}
			if (argc == 3 && !strcmp(argv[2], "--print"))
				printf("%ld: test case: %c , st: %d, ft: %d\n", cnt, i, isalnum(i), ft_isalnum(i));
		}
		double rate = ((cnt - failed) / (double)cnt) * 100;
		printf("%.2f%%: Checks: %ld, Failures: %ld\n", rate, cnt, failed);

		printf("Running full test(s): ft_isalnum\n");
		cnt = 0;
		failed = 0;
		for (long i = INT_MIN; i <= INT_MAX; i++)
		{
			cnt++;
			if (isalnum(i) != ft_isalnum(i))
			{
				failed++;
				printf("FAILED case: %ld , st: %d, ft: %d\n", i, isalnum(i), ft_isalnum(i));
			}
		}
		rate = ((cnt - failed) / (double)cnt) * 100;
		printf("%.2f%%: Checks: %ld, Failures: %ld\n", rate, cnt, failed);
	}
	else if (!strcmp(argv[1], "--C"))
    {
        printf("st: %i\n", isalnum(argv[2][0]));
        printf("ft: %i\n", ft_isalnum(argv[2][0]));
    }
	else
	{
		printf("st: %i\n", isalnum(atoi(argv[1])));
		printf("ft: %i\n", ft_isalnum(atoi(argv[1])));
	}
}
