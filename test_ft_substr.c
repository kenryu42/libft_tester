/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_substr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jliew <jliew@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 01:33:45 by jliew             #+#    #+#             */
/*   Updated: 2020/07/04 02:03:40 by jliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_substr(const char *s, unsigned int start, size_t len);

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		printf("----------------------------------------------------------------\n");
		printf(" char *ft_substr(const char *s, unsigned int start, size_t len)\n");
		printf("----------------------------------------------------------------\n");
		printf("usage [manual]:\n");
		printf("1. a <string s> <int start> <int len>\n");
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
