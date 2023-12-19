/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 02:38:21 by lbouguet          #+#    #+#             */
/*   Updated: 2022/12/22 19:23:13 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*p;

	p = (*lst);
	while (p)
	{	
		p = (*lst)->next;
		del((*lst)->content);
		free((*lst));
		(*lst) = p;
	}
	lst = NULL;
}
