/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strtrim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jliew <jliew@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 01:33:45 by jliew             #+#    #+#             */
/*   Updated: 2020/07/10 18:21:02 by jliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		printf("---------------------------------------------------\n");
		printf(" char *ft_strtrim(const char *s1, const char *set)\n");
		printf("---------------------------------------------------\n");
		printf("usage [auto]\n");
		printf("1. a --run\n");
		printf("usage [manual]:\n");
		printf("1. a <string s1> <string set>\n");
	}
	else if (!strcmp(argv[1], "--run"))
	{
		printf("---------------------------------------------------\n");
		printf(" char *ft_strtrim(const char *s1, const char *set)\n");
		printf("---------------------------------------------------\n");
		printf("1. ft_strtrim(\"aaabbb\", \"ab\")\n");
		char *s = ft_strtrim("aaabbb", "ab");
		printf("ft: %s\n", s);
		free(s);
		printf("2. ft_strtrim(\"aaabbb\", \"\")\n");
		s = ft_strtrim("aaabbb", "");
		printf("ft: %s\n", s);
		free(s);
		printf("3. ft_strtrim(\"\", \"ab\")\n");
		s = ft_strtrim("", "ab");
		printf("ft: %s\n", s);
		free(s);
		printf("4. ft_strtrim(\"\", \"\")\n");
		s = ft_strtrim("", "");
		printf("ft: %s\n", s);
		free(s);
		printf("5. ft_strtrim(NULL, NULL)\n");
		s = ft_strtrim(NULL, NULL);
		printf("ft: %s\n", s);
		free(s);
	}
	else
	{
		char *s1 = argv[1];
		char *s2 = argv[2];
		char *strtrim = ft_strtrim(s1, s2);
		printf("ft: %s\n", strtrim);
		free(strtrim);
	}
}
