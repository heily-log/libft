/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 04:27:43 by hakobaya          #+#    #+#             */
/*   Updated: 2023/06/04 06:21:11 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

size_t	ft_strlen(const char *s)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (s[i] != '\0')
		i++;
	return ((size_t) i);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*get;
	size_t	i;
	size_t	sum;

	i = 0;
	sum = count * size;
	if (size != 0 && count >= SIZE_T_MAX / size)
		return (NULL);
	get = (char *)malloc(sizeof(char) * sum);
	if (!get)
		return (NULL);
	while (sum > 0)
	{
		get[i] = 0;
		i++;
		sum--;
	}
	return (get);
}

//static char	*make_trim(char *buf, char const *s1, char const *set)
//{
//	int	i;
//	int	j;

//	i = 0;
//	j = 0;
//	while (s1[i] != '\0')
//	{
//		if (s1[i] == set[0])
//		{
//			if (ft_strncmp(s1, set, ft_strlen(set)) == 0)
//				i += ft_strlen(set);
//		}
//		else
//		{
//			buf[j] = s1[i];
//			j++;
//		}
//		i++;
//	}
//	buf[j] = '\0';
//	return (buf);
//}

//static int	count(char const *s1, char const *set)
//{
//	int	i;
//	int	count;
//	int	ans;

//	i = 0;
//	ans = 0;
//	count = 0;
//	while (s1[i] != '\0')
//	{
//		if (s1[i] == set[0])
//		{
//			if (ft_strncmp(s1, set, ft_strlen(set)) == 0)
//			{
//				count += ft_strlen(set);
//				i += ft_strlen(set);
//			}
//		}
//		i++;
//	}
//	return (ft_strlen(s1) - count);
//}

static int	search(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (set[j] != '\0')
	{
		while (s1[i] == set[j])
		{
			printf("%d[%c] %d[%c]\n", i, s1[i], j, set[j]);
			i++;
			j++;
		}
		j++;
	}
	return (i);
}

static int	rev_search(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	s1len;
	int	setlen;

	i = 0;
	j = 0;
	s1len = ft_strlen(s1) - 1;
	setlen = ft_strlen(set) - 1;
	while (j <= setlen)
	{
		if (s1[s1len - i] == set[setlen - j])
		{
			while (s1[s1len - i] == set[setlen - j] && j <= setlen && i <= s1len)
			{
				printf("%d[%c] %d[%c]\n", i, s1[s1len - i], j, set[setlen - j]);
				i++;
				j++;
			}
			return (i);
		}
		j++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	int		start;
	int		last;
	int		len;
	int		i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	//if (searh(s1, set) != 0)
	start = search(s1, set);
	printf("start : %d\n", start);
	//if (rev_search(s1, set) != 0)
	last = rev_search(s1, set);
	printf("last : %d\n", last);
	len = ft_strlen(s1) - start - last;
	trimmed = ft_calloc(len + 1, sizeof(char));
	if (!trimmed)
		return (NULL);
	i = 0;
	while (s1[start] != '\0' && i < len)
	{
		trimmed[i] = s1[start];
		i++;
		start++;
	}
	trimmed[i] = '\0';
	return(trimmed);
}
//char	*ft_strtrim(char const *s1, char const *set)
//{
//	char	*trimmed;
//	int		i;
//	int		j;

//	i = 0;
//	j = 0;
//	if (s1 == NULL)
//		return (NULL);
//	if (ft_strnstr(s1, set, ft_strlen(s1)) == NULL)
//		trimmed = ft_calloc(ft_strlen(s1) + 1, sizeof(char));
//	else
//		trimmed = ft_calloc(count(s1, set) + 1, sizeof(char));
//	return (make_trim(trimmed, s1, set));
//}


int	main(void)
{
	printf("%s\n", ft_strtrim("hello world", "world"));
	printf("%s\n", ft_strtrim("hello world", "hello"));
	//ft_strtrim("hello world", "");
	//ft_strtrim("", "");
	//ft_strtrim("    hello world     ", " ");
	//ft_strtrim(" \n\t\r    hello \n\t\r world     \r\t\n\t \r\n", " \n\t\r");
	//ft_strtrim("hello world", "abcdefghijklmnopqrstuvwxyz");
	//test("hello world", "world");
	//test("hello world", "hello");
	//test("hello world", "");
	//test("", "");
	//test("    hello world     ", " ");
	//test(" \n\t\r    hello \n\t\r world     \r\t\n\t \r\n", " \n\t\r");
	//test("hello world", "abcdefghijklmnopqrstuvwxyz");
}