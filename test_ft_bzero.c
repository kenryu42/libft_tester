/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jliew <jliew@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 21:44:17 by jliew             #+#    #+#             */
/*   Updated: 2020/07/07 23:04:41 by jliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "string.h"
#include "../libft.h"

int		main(int argc, char **argv)
{
	if (argc == 1)
    {
		printf("-------------------------------------------\n");
		printf(" void ft_bzero(void *dst, unsigned long n)\n");
		printf("-------------------------------------------\n");
        printf("usage [manual]:\n1. a <int n>\n");
        return (42);
    }
	char	dst1[100];
	char	dst2[100];
	unsigned int n = atoi(argv[1]);

	memset(dst1, 1, sizeof(dst1));
	memset(dst2, 1, sizeof(dst2));
	argc = 0;
	bzero(dst1, n);
	printf("st: ");
	for (int i = 0; i < 100; i++)
		printf("%i", dst1[i]);
	printf("\n");
	ft_bzero(dst2, n);
	printf("ft: ");
	for (int i = 0; i < 100; i++)
		printf("%i", dst2[i]);
	printf("\n");
}
