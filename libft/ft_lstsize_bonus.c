/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 13:31:31 by gisidro-          #+#    #+#             */
/*   Updated: 2025/04/26 13:46:10 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/*
int	main()
{
	t_list	*list = NULL;

	t_list	*nodo1 = ft_lstnew("Nodo 1");
	t_list	*nodo2 = ft_lstnew("Nodo 2");
	t_list	*nodo3 = ft_lstnew("Nodo 3");

	ft_lstadd_front(&list, nodo3);
	ft_lstadd_front(&list, nodo2);
	ft_lstadd_front(&list, nodo1);

	int	size = ft_lstsize(nodo1);
	printf("%d\n", size);

	t_list *tmp;
	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}

	return 0;
}
*/