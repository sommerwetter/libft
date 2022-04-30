/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:26:25 by marmoral          #+#    #+#             */
/*   Updated: 2022/04/29 12:44:32 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((char)c == str[i])
			return ((char *)&str[i]);
		i++;
	}
	if((char)c == str[i])
		return((char *)&str[i]);
	return (NULL);
}
