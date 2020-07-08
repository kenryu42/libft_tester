/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstiter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jliew <jliew@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 19:46:33 by jliew             #+#    #+#             */
/*   Updated: 2020/07/09 05:57:15 by jliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "../libft.h"

void	print_list(t_list *list)
{
	while (list)
	{
		printf("[%s]", list->content);
		printf("%s", ((list->next) ? " -> " : "\n"));
		list = list->next;
	}
}

void	func(void *content)
{
	free(content);
	content = strdup("42");
}

int		main(int argc, char **argv)
{
	int 	i;
	t_list	*list;

	if (argc == 1)
	{
		printf("-------------------------------------------------\n");
		printf(" void ft_lstiter(t_list *lst, void (*f)(void *))\n");
		printf("-------------------------------------------------\n");
		printf("usage [manual]:\n");
		printf("1. a --run\n");
		return (42);
	}
	else if (!strcmp(argv[1], "--run"))
	{
		list = NULL;
		i = 1;
		while (i <= 10)
			ft_lstadd_back(&list, ft_lstnew(ft_itoa(i++)));
		printf("before: ");
		print_list(list);
		ft_lstiter(list, func);
		printf("after: ");
		print_list(list);
		ft_lstclear(&list, free);
	}
}
