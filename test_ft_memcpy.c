/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jliew <jliew@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 21:44:17 by jliew             #+#    #+#             */
/*   Updated: 2020/07/10 22:22:20 by jliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "libft.h"

void	gen_rand_2string(char *s1, char *s2, unsigned long n)
{
	while (n--)
	{
		int c = rand() % 95 + 32;
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

void	print_i(char *dst)
{
	int i = 0;

	while (i < 100)
		printf("%c", dst[i++]);
	printf("\n");
}

int		main(int argc, char **argv)
{
	srand(time(0));

	if (argc == 1)
	{
		printf("-------------------------------------------------------\n");
		printf(" void *ft_memcpy(void *dst. const void *src, size_t n)\n");
		printf("-------------------------------------------------------\n");
		printf("usage [auto]:\n");
        printf("1. a --run\n");
        printf("2. a --run <test_cases>\n");
        printf("3. a --run <test_cases> --print\n");
		printf("4. a --run\n");
		printf("usage [manual]:\n");
		printf("1. a <string src> <int n>\n");
		printf("2. a --overlap\n");
		return (42);
	}
	if (!strcmp(argv[1], "--run"))
	{
		int print = 0;
		char src[101];
		/*char src2[101];*/
		/*char cpy_src[101];*/
		char dst1[101];
		char dst2[101];
		unsigned long failed = 0;
		unsigned long test_cases = 1000000;

		if (argc >= 3)
			test_cases = atoi(argv[2]);
		if (argc >= 4 && !strcmp(argv[3], "--print"))
			print = 1;
		printf("Running test(s): ft_memcpy\n");
		for (unsigned long i = 0; i < test_cases; i++)
		{
			gen_rand_string(src, rand() % 101);	
			memset(dst1, 48, sizeof(dst1));
			memset(dst2, 48, sizeof(dst2));
			/*gen_rand_2string(src1, src2, rand() % 101);*/
			/*strcpy(cpy_src, src1);*/
			int n = rand() % 51;
			char *st = memcpy(dst1, src, n);
			char *ft = ft_memcpy(dst2, src, n);

			if (memcmp(st, ft, 100))
			{
				failed++;
				printf("FAILED case:\nsrc: %s\nn: %d\n", src, n);
				printf("st: ");
				print_i(st);
				printf("ft: ");
				print_i(ft);
			}
			if (print)
			{
				printf("[%lu] test case:\nsrc: %s\nn: %d\n", i + 1, src, n);
				printf("st: ");
				print_i(st);
				printf("ft: ");
				print_i(ft);
			}
		}
		double rate = ((test_cases - failed) / (double)test_cases) * 100;
		printf("%.2f%%: Checks: %lu, Failures: %lu\n", rate, test_cases, failed);
	}
	else if (!strcmp(argv[1], "--runs"))
	{
		char dst1[100];
		char dst2[100];
		memset(dst1, 0, sizeof(dst1));
		memset(dst2, 0, sizeof(dst2));
		printf("-------------------------------------------------------\n");
		printf(" void *ft_memcpy(void *dst. const void *src, size_t n)\n");
		printf("-------------------------------------------------------\n");
		printf("1. ft_memcpy(NULL, NULL, 5)\n");
		char *st = memcpy(NULL, NULL, 5);
		char *ft = ft_memcpy(NULL, NULL, 5);
		printf("st: %s\n", st);
		printf("ft: %s\n", ft);
	}
	else
	{

		if (!strcmp(argv[1], "--overlap"))
		{
			char dst1[] = "ABCDEF";
			char dst2[] = "ABCDEF";
			char dst3[] = "ABCDEF";
			int n = 6;

			printf("-------------------------------------------------------\n");
			printf(" void *ft_memcpy(void *dst. const void *src, size_t n)\n");
			printf("-------------------------------------------------------\n");
			printf("str: %s\n", dst1);
			memcpy(dst1 + 1, dst1, n);
			memmove(dst3 + 1, dst3, n);
			ft_memcpy(dst2 + 1, dst2, n);
			printf("ft_memcpy(str + 1, str, 6)\n");
			printf("st: ");
			for (int i = 0; i < n; i ++)
				printf("%c", dst1[i]);
			printf("\n");
			printf("ft: ");
			for (int i = 0; i < n; i++)
				printf("%c", dst2[i]);
			printf("\n");
			printf("memmove: ");
			for (int i = 0; i < n; i ++)
				printf("%c", dst3[i]);
			printf("\n");
		}
		else
		{
			char dst1[100];
			char dst2[100];
			char *src = argv[1];
			/*char *src = strdup(argv[1]);*/
			int n = atoi(argv[2]);

			memset(dst1, 48, sizeof(dst1));
			memset(dst2, 48, sizeof(dst2));
			memcpy(dst1, src, n);
			ft_memcpy(dst2, src, n);
			printf("st: ");
			for (int i = 0; i < 100; i ++)
				printf("%c", dst1[i]);
			printf("\n");
			printf("ft: ");
			for (int i = 0; i < 100; i++)
				printf("%c", dst2[i]);
			printf("\n");
			/*free(src);*/
		}
	}
}
