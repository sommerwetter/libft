/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:48:39 by marmoral          #+#    #+#             */
/*   Updated: 2022/05/21 13:12:26 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_mod(const char *s1, size_t size, size_t i)
{
	char	*s1_cpy;
	size_t	x;

	x = 0;
	if (!s1)
		return (NULL);
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

static	void	save(char **split, const char *s, char c)
{
	size_t	i;
	size_t	x;
	size_t	count;

	i = 0;
	x = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
			count++;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
		{
			split[x] = ft_strdup_mod(s, count, (i - (count - 1)));
			x++;
			count = 0;
		}
		i++;
	}
	split[x] = NULL;
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	x;
	char	**split;

	i = 0;
	x = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			x++;
		i++;
	}
	split = malloc(sizeof(char *) * (x + 1));
	if (!split)
		return (NULL);
	save(split, s, c);
	return (split);
}
