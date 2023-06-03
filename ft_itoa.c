/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 04:46:53 by hakobaya          #+#    #+#             */
/*   Updated: 2023/06/01 00:46:41 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*num_array;
	int		i;
	int		digit;
	int		num;

	i = 0;
	digit = 0;
	num = n;

	while (num / 10 != 0)
	{
		num /= 10;
		digit++;
	}
	num_array = (char *)malloc(sizeof(char) * digit);
	while (digit >= 0)
	{
		i = n % 10;
		n /= 10;
		num_array[digit - 1] = i + '0';
		digit--;
	}
	return (num_array);
}
