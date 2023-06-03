/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 23:10:45 by hakobaya          #+#    #+#             */
/*   Updated: 2023/06/01 00:54:42 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*target;
	int		i;

	target = (char *)malloc(sizeof(char) * ft_strlen(s));
	i = 0;
	while (target[i] != '\0')
	{
		target[i] = f(i, s[i]);
		i++;
	}
	return (target);
}
