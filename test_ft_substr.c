/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_substr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jliew <jliew@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 01:33:45 by jliew             #+#    #+#             */
/*   Updated: 2020/07/10 18:35:47 by jliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		printf("----------------------------------------------------------------\n");
		printf(" char *ft_substr(const char *s, unsigned int start, size_t len)\n");
		printf("----------------------------------------------------------------\n");
		printf("usage [auto]:\n");
		printf("1. a --run\n");
		printf("usage [manual]:\n");
		printf("1. a <string s> <int start> <int len>\n");
	}
	else if (!strcmp(argv[1], "--run"))
	{
		printf("----------------------------------------------------------------\n");
		printf(" char *ft_substr(const char *s, unsigned int start, size_t len)\n");
		printf("----------------------------------------------------------------\n");
		printf("1. ft_substr(\"42_tokyo\", 0, -1)\n");
		char *s = ft_substr("42_tokyo", 0, -1);
		printf("ft: %s\n", s);
		free(s);
		printf("2. ft_substr(\"42_tokyo\", -1, 5)\n");
		s = ft_substr("42_tokyo", -1, 5);
		printf("ft: %s\n", s);
		free(s);
		printf("3. ft_substr(\"42_tokyo\", 8, 5)\n");
		s = ft_substr("42_tokyo", 8, 5);
		printf("ft: %s\n", s);
		free(s);
		printf("4. ft_substr(\"42_tokyo\", 5, 0)\n");
		s = ft_substr("42_tokyo", 5, 0);
		printf("ft: %s\n", s);
		free(s);
		printf("5. ft_substr(\"42_tokyo\", 0, 0)\n");
		s = ft_substr("42_tokyo", 0, 0);
		printf("ft: %s\n", s);
		free(s);
		printf("6. ft_substr(NULL, 0, 5)\n");
		s = ft_substr(NULL, 0, 5);
		printf("ft: %s\n", s);
		free(s);
	}
	else
	{
		char *s = argv[1];
		int start = atoll(argv[2]);
		int len = atoll(argv[3]);
		char *substr = ft_substr(s, start, len);
		printf("ft: %s\n", substr);
		free(substr);
	}
}
