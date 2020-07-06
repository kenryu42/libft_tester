/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstsize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jliew <jliew@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 19:46:33 by jliew             #+#    #+#             */
/*   Updated: 2020/07/06 21:46:59 by jliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "../includes/libft.h"

void	print_list(t_list *list)
{
	while (list)
	{
		printf("[%s]", list->content);
		printf("%s", ((list->next) ? " -> " : "\n"));
		list = list->next;
	}
}

int		main(int argc, char **argv)
{
	int		i;
	int		size;
	t_list	*list;

	if (argc == 1)
	{
		printf("-----------------------------\n");
		printf(" int ft_lstsize(t_list *lst)\n");
		printf("-----------------------------\n");
		printf("usage [manual]:\n");
		printf("1. a --list <. . .>\n");
		return (42);
	}
	else if (!strcmp(argv[1], "--list"))
	{
		i = 2;
		list = NULL;
		while (i < argc)
			ft_lstadd_back(&list, ft_lstnew(strdup(argv[i++])));
		print_list(list);
		size = ft_lstsize(list);
		printf("size: %d\n", size);
		ft_lstclear(&list, free);
	}
}
