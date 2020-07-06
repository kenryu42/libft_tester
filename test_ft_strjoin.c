/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jliew <jliew@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 01:33:45 by jliew             #+#    #+#             */
/*   Updated: 2020/07/04 02:27:52 by jliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strjoin(const char *s1, const char *s2);

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		printf("--------------------------------------------------\n");
		printf(" char *ft_strjoin(const char *s1, const char *s2)\n");
		printf("--------------------------------------------------\n");
		printf("usage [manual]:\n");
		printf("1. a <string s1> <string s2>\n");
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
