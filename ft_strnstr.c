/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 10:18:19 by marmoral          #+#    #+#             */
/*   Updated: 2022/05/04 11:19:30 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	check_nh(const char *haystack, const char *needle, size_t index)
{
	int	i;

	i = 0;
	while (haystack[index] && needle[i])
	{
		if (haystack[index] != needle[i])
		{
			return (1);
		}
		i++;
		index++;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (needle[0] == 0)
	{
		return ((char *)haystack);
	}
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0])
		{
			if (check_nh(haystack, needle, i) == 0)
			{
				return ((char *)&haystack[i]);
			}
		}
		i++;
	}
	return (NULL);
}
