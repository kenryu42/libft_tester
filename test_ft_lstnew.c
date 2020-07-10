/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstnew.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jliew <jliew@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 19:46:33 by jliew             #+#    #+#             */
/*   Updated: 2020/07/10 19:05:35 by jliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int		main(int argc, char **argv)
{
	t_list *list;

	if (argc == 1)
	{
		printf("-------------------------------\n");
		printf(" void ft_lstnew(void *content)\n");
		printf("-------------------------------\n");
		printf("usage [manual]:\n");
		printf("1. a <string>/--null\n");
		return (42);
	}
	if (!strcmp(argv[1], "--null"))
		list = ft_lstnew(NULL);
	else if  (!(list = ft_lstnew(strdup(argv[1]))))
	{
		printf("Malloc failed.\n");
		return (0);
	}
	printf("list->content: %s\n", list->content);
	printf("list->next: %s\n", (char *)list->next);
	ft_lstdelone(list, free);
	printf("freed\n");
}
