/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstclear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jliew <jliew@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 19:46:33 by jliew             #+#    #+#             */
/*   Updated: 2020/07/08 18:15:48 by jliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "../libft.h"

void	print_list(t_list *list)
{
	if (!list)
		printf("%s\n", (char *)list);
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
		printf("-----------------------------------------------------\n");
		printf(" void ft_lstclear(t_list **lst, void (*del)(void *))\n");
		printf("-----------------------------------------------------\n");
		printf("usage [manual]:\n");
		printf("1. a --free <. . .>\n");
		return (42);
	}
	else if (!strcmp(argv[1], "--free"))
	{
		i = 2;
		list = NULL;
		while (i < argc)
			ft_lstadd_back(&list, ft_lstnew(strdup(argv[i++])));
		printf("before: ");
		print_list(list);
		ft_lstclear(&list, free);
		printf("ft_lstclear(&list, free);\n");
		printf("after: ");
		print_list(list);
	}
}
