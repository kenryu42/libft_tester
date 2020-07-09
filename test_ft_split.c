/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jliew <jliew@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 05:16:40 by jliew             #+#    #+#             */
/*   Updated: 2020/07/09 23:23:04 by jliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		printf("----------------------------------------\n");
		printf(" char **ft_split(const char *s, char c)\n");
		printf("----------------------------------------\n");
		printf("usage [manual]:\n");
		printf("1. a <string s> <char c>\n");
		return (42);
	}
	else
	{
		char *str = argv[1];
		char c = argv[2][0];
		char **split = ft_split(str, c);
		
		for (int i = 0; split[i]; i++)
		{
			printf("%i. [%s]\n", i + 1, split[i]);
			free(split[i]);
		}
		free(split);
	}
}
