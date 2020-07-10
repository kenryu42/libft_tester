/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jliew <jliew@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 05:16:40 by jliew             #+#    #+#             */
/*   Updated: 2020/07/10 18:25:38 by jliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	print_split(char **split)
{
	if (!split)
	{
		printf("(null)\n");
		return ;
	}
	if (!*split)
	{
		printf("[%s]\n", *split);
		return ;
	}
	for (int i = 0; split[i]; i++)
	{
		printf(" [%s]\n", split[i]);
		free(split[i]);
	}
	free(split);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		printf("----------------------------------------\n");
		printf(" char **ft_split(const char *s, char c)\n");
		printf("----------------------------------------\n");
		printf("usage [auto]:\n");
		printf("1. a --run\n");
		printf("usage [manual]:\n");
		printf("1. a <string s> <char c>\n");
		return (42);
	}
	else if (!strcmp(argv[1], "--run"))
	{
		printf("----------------------------------------\n");
		printf(" char **ft_split(const char *s, char c)\n");
		printf("----------------------------------------\n");
		printf("1. ft_split(\"abababa\", '\\0')\n");
		char **s = ft_split("abababa", '\0');
		print_split(s);
		printf("2. ft_split(\"\", '\\0')\n");
		s = ft_split("", '\0');
		print_split(s);
		printf("3. ft_split(\"\", 'x')\n");
		s = ft_split("", 'x');
		print_split(s);
		printf("4. ft_split(\"aaaaaaaa\", 'a')\n");
		s = ft_split("aaaaaaaa", 'a');
		print_split(s);
		printf("5. ft_split(NULL, '\\0')\n");
		s = ft_split(NULL, '\0');
		print_split(s);
		printf("6. ft_split(\"axbxc\", 'x')\n");
		s = ft_split("axbxc", 'x');
		print_split(s);
	}
	else
	{
		char *str = argv[1];
		char c = argv[2][0];
		char **split = ft_split(str, c);
		
		print_split(split);
	}
}
