/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 05:28:51 by hakobaya          #+#    #+#             */
/*   Updated: 2023/06/10 06:48:15 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ndPtr;

	if (lst == NULL)
		return ;
	if (*lst != NULL)
	{
		ndPtr = ft_lstlast(*lst);
		ndPtr->next = new;
	}
	else
		*lst = new;
}

