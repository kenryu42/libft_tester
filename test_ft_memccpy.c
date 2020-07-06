/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memccpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jliew <jliew@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 01:01:43 by jliew             #+#    #+#             */
/*   Updated: 2020/07/07 03:03:31 by jliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "../includes/libft.h"

void	gen_rand_string(char *dst, unsigned int n)
{
	for (unsigned int i = 0; i < n; i++)
		*dst++ = rand() % 95 + 32;
	*dst = '\0';
}

int		check(const char *st, const char *ft)
{
	if (!st && !ft)
		return (0); // ok
	if (st && ft)
		return (2); // need strcmp check
	return (1); // fail
}

int		main(int argc, char **argv)
{
	srand(time(0));

	if (argc == 1)
	{
		printf("----------------------------------------------------------------------\n");
		printf(" void *ft_memccpy(void *dst, const void *src, int c, unsigned long n)\n");
		printf("----------------------------------------------------------------------\n");
		printf("usage [auto]:\n");
		printf("1. a --run\n");
		printf("2. a --run <test_cases>\n");
		printf("3. a --run <test_cases> --print\n");
		printf("usage [manual]:\n1. a <string src> <int c> <int n>\n");
		return (42);
	}
	else if (!strcmp(argv[1], "--run"))
	{
		char src[51];
		int print = 0;
		char dst1[101];
		char dst2[101];
		unsigned long failed = 0;
		unsigned long test_cases = 1000000;

		if (argc >= 3)
			test_cases = atoi(argv[2]);
		if (argc >= 4 && !strcmp(argv[3], "--print"))
			print = 1;
		printf("Running test(s): ft_memccpy\n");
		for (unsigned long i = 0; i < test_cases; i++)
		{
			gen_rand_string(src, rand() % 51);
			memset(dst1, 48, sizeof(dst1));
			memset(dst2, 48, sizeof(dst2));
			dst1[100] = '\0';
			dst2[100] = '\0';
			int c = rand() % 95 + 32;
			int n = rand() % 51;
			char *st = memccpy(dst1, src, c, n);
			char *ft = memccpy(dst2, src, c, n);

			if ((check(st, ft) == 1) || (strcmp(dst1, dst2)) || ((check(st, ft) == 2) && strcmp(st, ft)))
			{
				failed++;
				printf("FAILED case:\nsrc: %s\nc: %c, n: %d\nst_ptr: %s\nst_dst: %s\nft_ptr: %s\nft_dst: %s\n", src, c, n, st, dst1, ft, dst2);
			}
			if (print)
				printf("[%lu] test case:\nsrc: %s\nc: %c, n: %d\nst_ptr: %s\nst_dst: %s\nft_ptr: %s\nft_dst: %s\n", i + 1, src, c, n, st, dst1, ft, dst2);
		}
		double rate = ((test_cases - failed) / (double)test_cases) * 100;
		printf("%.2f%%: Checks: %lu, Failures: %lu\n", rate, test_cases, failed);
	}
	else
	{
		/*char dst1[101];*/
		/*char dst2[101];*/
		/*memset(dst1, 48, sizeof(dst1));*/
		/*memset(dst2, 48, sizeof(dst2));*/
		/*dst1[100] = '\0';*/
		/*dst2[100] = '\0';*/
		/*char *src = argv[1];	*/
		/*char c = argv[2][0];*/
		/*int	n = atoi(argv[3]);*/
		char buff1[] = "abcdefghijklmnopqrstuvwxyz";
		char buff2[] = "abcdefghijklmnopqrstuvwxyz";
		char *src = "string with\200inside !";

		char *st_res = memccpy(buff1, src, 0600, 21);
		char *ft_res = ft_memccpy(buff2, src, 0600, 21);
		
		printf("st_ret: %s\n", st_res);
		printf("st_dst: ");
		for (int i = 0; i < 26; i++)
		{
			printf("%c", buff1[i]);
		}
		printf("\n");
		printf("ft_ret: %s\n", ft_res);
		printf("ft_dst: ");
		for (int i = 0; i < 26; i++)
		{
			printf("%c", buff2[i]);
		}
		printf("\n");
	}
}
