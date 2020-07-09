/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strmapi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jliew <jliew@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 17:13:48 by jliew             #+#    #+#             */
/*   Updated: 2020/07/09 18:46:15 by jliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libft.h"

char	cmap(unsigned int i, char c)
{
	return (c + i);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		printf("----------------------------------------------------------------\n");
		printf(" char *ft_strmapi(const char *s, char (*f)(unsigned int, char))\n");
		printf("----------------------------------------------------------------\n");
		printf("usage [manual]:\n");
		printf("1. a <string>\n");
	}
	else
	{
		char *s;
		s = argv[1];

		size_t size = ft_strlen(s);
		char s2[0XF0];
		for (size_t i = 0; i < size; i++)
			s2[i] = cmap(i, s[i]);
		s2[size] = 0;
		char *ret = ft_strmapi(s, cmap);
		printf("st: %s\n", s2);
		printf("ft: %s\n", ret);
		free(ret);
	}
}
