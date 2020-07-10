/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jliew <jliew@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 01:33:45 by jliew             #+#    #+#             */
/*   Updated: 2020/07/10 18:32:29 by jliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		printf("--------------------------------------------------\n");
		printf(" char *ft_strjoin(const char *s1, const char *s2)\n");
		printf("--------------------------------------------------\n");
		printf("usage [auto]\n");
		printf("1. a --run\n");
		printf("usage [manual]:\n");
		printf("1. a <string s1> <string s2>\n");
	}
	else if(!strcmp(argv[1], "--run"))
	{
		printf("--------------------------------------------------\n");
		printf(" char *ft_strjoin(const char *s1, const char *s2)\n");
		printf("--------------------------------------------------\n");
		printf("1. ft_strjoin(NULL, NULL)\n");
		char *s = ft_strjoin(NULL, NULL);
		printf("ft: %s\n", s);
		free(s);
		printf("2. ft_strjoin(\"\", \"\")\n");
		s = ft_strjoin("", "");
		printf("ft: %s\n", s);
		free(s);
		printf("3. ft_strjoin(\"\", \"42\")\n");
		s = ft_strjoin("", "42");
		printf("ft: %s\n", s);
		free(s);
		printf("4. ft_strjoin(\"42\", \"Tokyo\")\n");
		s = ft_strjoin("42", "Tokyo");
		printf("ft: %s\n", s);
		free(s);
	}
	else
	{
		char *s1 = argv[1];
		char *s2 = argv[2];
		char *strjoin = ft_strjoin(s1, s2);
		printf("ft: %s\n", strjoin);
		free(strjoin);
	}
}
