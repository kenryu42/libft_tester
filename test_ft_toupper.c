/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_toupper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jliew <jliew@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 13:43:15 by jliew             #+#    #+#             */
/*   Updated: 2020/07/08 01:59:45 by jliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "time.h"
#include "ctype.h"
#include "string.h"
#include "limits.h"
#include "../libft.h"

int		main(int argc, char **argv)
{
	if (argc == 1)
    {
		printf("---------------------\n");
		printf(" int ft_toupper(int)\n");
		printf("---------------------\n");
        printf("usage [auto]:\n1. a --run\n2. a --run --print\n");
        printf("usage [manual]:\n1. a <int>\n");
		printf("2. a --C <char c>\n");
        return (42);
    }
	else if (!strcmp(argv[1], "--run"))
	{
		long cnt = 0;
		long failed = 0;

		printf("Running small test(s): ft_toupper\n");
		for (int i = 0; i <= 127; i++)
		{
			cnt++;
			if (toupper(i) != ft_toupper(i))
			{
				failed++;
				printf("FAILED case: %c, st: %c, ft: %c\n", (char)i, toupper(i), ft_toupper(i));
			}
			if (argc == 3 && !strcmp(argv[2], "--print"))
				printf("%i: test case: %c , st: %c, ft: %c\n", i, i, toupper(i), ft_toupper(i));
		}
		double rate = ((cnt - failed) / (double)cnt) * 100;
		printf("%.2f%%: Checks: %ld, Failures: %ld\n", rate, cnt, failed);

		printf("Running full test(s): ft_toupper\n");
		cnt = 0;
		failed = 0;
		for (long i = INT_MIN; i <= INT_MAX; i++)
		{
			cnt++;
			if (toupper(i) != ft_toupper(i))
			{
				failed++;
				printf("FAILED case: %c, st: %d, ft: %d\n", (char)i, toupper(i), ft_toupper(i));
			}
		}
		rate = ((cnt - failed) / (double)cnt) * 100;
		printf("%.2f%%: Checks: %ld, Failures: %ld\n", rate, cnt, failed);
	}
	else if (!strcmp(argv[1], "--C"))
    {
        printf("st: %c\n", toupper(argv[2][0]));
        printf("ft: %c\n", ft_toupper(argv[2][0]));
    }
	else
	{
		printf("st: %i\n", toupper(atoi(argv[1])));
		printf("ft: %i\n", ft_toupper(atoi(argv[1])));
	}
}
