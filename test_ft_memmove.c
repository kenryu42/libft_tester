/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memmove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jliew <jliew@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 21:44:17 by jliew             #+#    #+#             */
/*   Updated: 2020/07/07 03:04:01 by jliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "../includes/libft.h"

void	gen_rand_2string(char *s1, char *s2, unsigned long n)
{
	while (n--)
	{
		int c = rand() % 26 + 97;
		*s1++ = c;
		*s2++ = c;
	}
	*s1 = '\0';
	*s2 = '\0';
}

void	gen_rand_string(char* str, unsigned long n)
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
		printf("--------------------------------------------------------------\n");
		printf(" void *ft_memmove(void *dst. const void *src, unsigned long n)\n");
		printf("--------------------------------------------------------------\n");
		printf("usage [auto]:\n");
        printf("1. a --run\n");
        printf("2. a --run <test_cases>\n");
        printf("3. a --run <test_cases> --print\n");
		printf("usage [manual]:\n");
		printf("1. a <string src> <int n>\n");
		printf("2. a --overlap\n");
		return (42);
	}
	if (!strcmp(argv[1], "--run"))
	{
		int print = 0;
		char src1[101];
		char src2[101];
		char cpy_src[101];
		unsigned long failed = 0;
		unsigned long test_cases = 1000000;

		if (argc >= 3)
			test_cases = atoi(argv[2]);
		if (argc >= 4 && !strcmp(argv[3], "--print"))
			print = 1;
		printf("Running test(s): ft_memmove\n");
		for (unsigned long i = 0; i < test_cases; i++)
		{
			gen_rand_2string(src1, src2, 100);
			strcpy(cpy_src, src1);
			int n = rand() % 51;
			int rl = rand() % 10, rr = rand() % 10;
			memmove(src1 + rl, src1 + rr, n);
			ft_memmove(src2 + rl, src2 + rr, n);
			if (memcmp(src1, src2, 100))
			{
				failed++;
				printf("FAILED case:\ndst/src: %s\nn: %d, dst + %d, src + %d\nst: %s\nft: %s\n", cpy_src, n, rl, rr, src1, src2);
			}
			if (print)
				printf("[%lu] test case:\ndst/src: %s\nn: %d, dst + %d, src + %d\nst: %s\nft: %s\n", i + 1, cpy_src, n, rl, rr, src1, src2);
		}
		double rate = ((test_cases - failed) / (double)test_cases) * 100;
		printf("%.2f%%: Checks: %lu, Failures: %lu\n", rate, test_cases, failed);
	}
	else
	{
		if (!strcmp(argv[1], "--overlap"))
        {
            char dst1[] = "ABCDEF";
            char dst2[] = "ABCDEF";
            char dst3[] = "ABCDEF";
            int n = 6;

            memmove(dst1 + 1, dst1, n);
            ft_memmove(dst2 + 1, dst2, n);
            ft_memcpy(dst3 + 1, dst3, n);
            printf("ft_memcpy: ");
            for (int i = 0; i < n; i ++)
                printf("%c", dst3[i]);
            printf("\n");
            printf("st: ");
            for (int i = 0; i < n; i ++)
                printf("%c", dst1[i]);
            printf("\n");
            printf("ft: ");
            for (int i = 0; i < n; i++)
                printf("%c", dst2[i]);
            printf("\n");
        }
		else
		{
			char dst1[100];
			char dst2[100];
			char *src = argv[1];
			int n = atoi(argv[2]);

			memset(dst1, 48, sizeof(dst1));
			memset(dst2, 48, sizeof(dst2));
			memmove(dst1, src, n);
			ft_memmove(dst2, src, n);
            printf("st: ");
            for (int i = 0; i < 100; i ++)
                printf("%c", dst1[i]);
            printf("\n");
            printf("ft: ");
            for (int i = 0; i < 100; i++)
                printf("%c", dst2[i]);
            printf("\n");	
		}
	}
}
