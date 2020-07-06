/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstlast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jliew <jliew@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 19:46:33 by jliew             #+#    #+#             */
/*   Updated: 2020/07/06 22:28:42 by jliew            ###   ########.fr       */
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
	t_list	*list;
	t_list	*last;

	if (argc == 1)
	{
		printf("--------------------------------\n");
		printf(" t_list ft_lstlast(t_list *lst)\n");
		printf("--------------------------------\n");
		printf("usage [manual]:\n");
		printf("1. a --list <. . .>\n");
		return (42);
	}
	else if (!strcmp(argv[1], "--list"))
	{
		list = NULL;
		i = 2;
		while (i < argc)
			ft_lstadd_back(&list, ft_lstnew(strdup(argv[i++])));
		print_list(list);
		last = ft_lstlast(list);
		if (last)
			printf("last content: [%s]\n", last->content);
		ft_lstclear(&list, free);
	}
}
