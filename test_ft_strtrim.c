/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strtrim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jliew <jliew@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 01:33:45 by jliew             #+#    #+#             */
/*   Updated: 2020/07/07 23:08:16 by jliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "../libft.h"

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		printf("---------------------------------------------------\n");
		printf(" char *ft_strtrim(const char *s1, const char *set)\n");
		printf("---------------------------------------------------\n");
		printf("usage [manual]:\n");
		printf("1. a <string s1> <string set>\n");
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
