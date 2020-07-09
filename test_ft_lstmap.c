/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jliew <jliew@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 19:46:33 by jliew             #+#    #+#             */
/*   Updated: 2020/07/09 23:19:52 by jliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*func(void *content)
{
	void *res;

	res = ft_strjoin(content, "_42");
	return (res);
}

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
	t_list	*new_list;

	if (argc == 1)
	{
		printf("------------------------------------------------------------------------\n");
		printf(" t_list ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))\n");
		printf("------------------------------------------------------------------------\n");
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
		new_list = ft_lstmap(list, func, free);
		printf("before: ");
		print_list(list);
		printf("new list: ");
		print_list(new_list);
		printf("after: ");
		print_list(list);
		ft_lstclear(&list, free);
		ft_lstclear(&new_list, free);
	}
}
