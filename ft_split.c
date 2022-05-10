/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 01:27:24 by marmoral          #+#    #+#             */
/*   Updated: 2022/05/09 16:01:29 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*sp_str(char const *s, char c, size_t count_c, size_t i)
{
	char	*sv;
	size_t	x;

	x = 0;
	sv = malloc(count_c + 1);
	if (!sv)
		return (NULL);
	i -= count_c;
	while (s[i] != c)
	{
		sv[x] = s[i];
		x++;
		i++;
	}
	sv[x] = 0;
	return (sv);
}

static	void	save(char const *s, char c, int count, char **split)
{
	size_t	i;
	size_t	x;
	int		count_c;

	i = 0;
	x = 0;
	count_c = 0;
	while (count > 0)
	{
		if (s[i] == c)
		{
			split[x] = sp_str(s, c, count_c, i);
			count_c = -1;
			x++;
			count--;
		}
		i++;
		count_c++;
	}
	if (s[i])
		split[x] = ft_strdup(&s[i]);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		count;

	count = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	split = malloc((count + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	save(s, c, count, split);
	return (split);
}
