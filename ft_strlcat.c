/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:54:34 by marmoral          #+#    #+#             */
/*   Updated: 2022/04/27 16:16:34 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_l;
	size_t	src_l;
	size_t	ans;

	i = 0;
	src_l = 0;
	dst_l = 0;
	ans = 0;
	while (dst[dst_l])
		dst_l++;
	while (src[src_l])
		src_l++;
	if (dst_l > size)
		ans = src_l + size;
	else
		ans = dst_l + src_l;
	while (src[i] && dst_l < (size - 1))
	{
		dst[dst_l] = src[i];
		dst_l++;
		i++;
	}
	dst[dst_l++] = 0;
	return (ans);
}
