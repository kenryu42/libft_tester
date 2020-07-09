/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstadd_front.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jliew <jliew@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 19:46:33 by jliew             #+#    #+#             */
/*   Updated: 2020/07/09 23:19:33 by jliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

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
	t_list	*list;

	if (argc == 1)
	{
		printf("-------------------------------------------------\n");
		printf(" void ft_lstadd_front(t_list **lst, t_list *new)\n");
		printf("-------------------------------------------------\n");
		printf("usage [manual]:\n");
		printf("1. a --list <. . .>\n");
		return (42);
	}
	else if (!strcmp(argv[1], "--list"))
	{
		list = NULL;
		i = 2;
		while (i < argc)
			ft_lstadd_front(&list, ft_lstnew(strdup(argv[i++])));
		print_list(list);
		ft_lstclear(&list, free);
	}
}
