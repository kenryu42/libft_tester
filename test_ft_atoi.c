/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jliew <jliew@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 21:24:57 by jliew             #+#    #+#             */
/*   Updated: 2020/07/08 02:20:47 by jliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "time.h"
#include "string.h"
#include "../libft.h"

void	gen_rand_int(char *dst)
{
	int n = rand() % 10;

	for (int i = 0; i < n; i++)
		*dst++ = rand() % 10 + 48;
	*dst = '\0';
}

int		main(int argc, char **argv)
{
	srand(time(0));

	if (argc == 1)
    {
		printf("------------------------------\n");
		printf(" int ft_atoi(const char *str)\n");
		printf("------------------------------\n");
        printf("usage [auto]:\n1. a --run\n2. a --run <test_cases>\n3. a --run <test_cases> --print\n");
        printf("usage [manual]:\n1. a <string>\n");
        return (42);
    }
	else if (!strcmp(argv[1], "--run"))
	{
		int failed = 0;
		int test_cases = 1000000;

		if (argc >= 3 && strcmp(argv[2], "--print"))
			test_cases = atoi(argv[2]);
		printf("Running test(s): ft_atoi\n");
		for (int i = 0; i < test_cases; i++)
		{
			char n[10]; 
			gen_rand_int(n);
			int st = atoi(n), ft = ft_atoi(n);

			if (st != ft)
			{
				failed++;
				printf("FAILED case: %s, st: %d, ft: %d\n", n, st, ft);
			}
			if (argc == 4 && !strcmp(argv[3], "--print"))
				printf("%d: test case: %s, st: %d, ft: %d\n", i + 1, n, st, ft);
		}

		char *corner_cases[] = {"-2147483648", "2147483647", "+123", "123+32", "3+-1"};
		for (int i = 0; i < 5; i ++)
		{
			test_cases++;
			int st = atoi(corner_cases[i]);
			int ft = ft_atoi(corner_cases[i]);
			if (st != ft)
			{
				failed++;
				printf("FAILED case: %s, st: %i, ft: %i\n", corner_cases[i], st, ft);
			}
		}
		double rate = ((test_cases - failed) / (double) test_cases) * 100;
		printf("%.2f%%: Checks: %d, Failures: %d\n", rate, test_cases, failed);
	}	
	else
	{
		char	*str = argv[1];
		/*char *str = "\t\v\f\r\n \f-06050";*/

		printf("st: %d\n", atoi(str));
		printf("ft: %d\n", ft_atoi(str));
	}

}
