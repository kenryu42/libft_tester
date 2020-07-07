/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putnbr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jliew <jliew@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 13:47:23 by jliew             #+#    #+#             */
/*   Updated: 2020/07/07 23:06:10 by jliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "../libft.h"

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		printf("-----------------------------------\n");
		printf(" void ft_putnbr_fd(int nb, int fd)\n");
		printf("-----------------------------------\n");
		printf("usage [manual]:\n");
		printf("1. a <int nb>\n");
	}
	else
	{
		int		nb;
		int		fd;

		nb = atoi(argv[1]);
		fd = open("42", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
		if (fd == -1)
			printf("open failed\n");
		ft_putnbr_fd(nb, fd);
		if (close(fd) == -1)
			printf("close failed\n");
	}
}
