/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstdelone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jliew <jliew@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 19:46:33 by jliew             #+#    #+#             */
/*   Updated: 2020/07/09 21:16:54 by jliew            ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	t_list	*list;

	if (argc == 1)
	{
		printf("-----------------------------------------------------\n");
		printf(" void ft_lstdelone(t_list *lst, void (*del)(void *))\n");
		printf("-----------------------------------------------------\n");
		printf("usage [manual]:\n");
		printf("1. a --free\n");
		return (42);
	}
	else if (!strcmp(argv[1], "--free"))
	{
		list = ft_lstnew(strdup("hello i m data."));
		/*printf("before: list->content: %s\n", list->content);*/
		ft_lstdelone(list, free);
		/*printf("after: list->content: %s\n", list->content);*/
	}
}
