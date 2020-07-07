/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putstr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jliew <jliew@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 13:47:23 by jliew             #+#    #+#             */
/*   Updated: 2020/07/07 23:05:46 by jliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "../libft.h"

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		printf("------------------------------------\n");
		printf(" void ft_putstr_fd(char *s, int fd)\n");
		printf("------------------------------------\n");
		printf("usage [manual]:\n");
		printf("1. a <string s>\n");
	}
	else
	{
		char	*s;
		int		fd;

		s = argv[1];
		fd = open("42", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
		if (fd == -1)
			printf("open failed\n");
		ft_putstr_fd(s, fd);
		if (close(fd) == -1)
			printf("close failed\n");
	}
}
