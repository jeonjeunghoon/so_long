/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 16:04:51 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/17 17:49:51 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*head;
	t_list	*tail;

	head = *lst;
	if (!(*lst))
	{
		*lst = new;
		new->next = 0;
		return ;
	}
	else
	{
		while (*lst)
		{
			tail = *lst;
			*lst = (*lst)->next;
		}
		tail->next = new;
		new->next = 0;
		*lst = head;
	}
}
