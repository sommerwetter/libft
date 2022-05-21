/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:53:49 by marmoral          #+#    #+#             */
/*   Updated: 2022/05/21 14:17:48 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_strdup_mod(const char *s1, int size, int i)
{
	char	*s1_cpy;
	size_t	x;

	x = 0;
	if (size == 0)
		return (ft_strdup(&s1[i]));
	if (size < 0)
		return (ft_strdup(""));
	if (!s1)
		return (NULL);
	size++;
	s1_cpy = malloc(size + 1);
	if (!s1_cpy)
		return (NULL);
	while (size)
	{
		s1_cpy[x] = s1[i];
		i++;
		x++;
		size--;
	}
	s1_cpy[x] = 0;
	return (s1_cpy);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	size_t	x;
	int		end;
	char	*s1_trim;

	i = 0;
	x = 0;
	end = ft_strlen(s1) - 1;
	while (set[x])
	{
		if (s1[i] == set[x])
		{
			i++;
			x = -1;
		}
		else if (s1[end] == set[x] && end > i)
		{
			end--;
			x = -1;
		}
		x++;
	}
	s1_trim = ft_strdup_mod(s1, (end - i), i);
	return (s1_trim);
}
