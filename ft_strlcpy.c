/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivoire <jrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:59:36 by jrivoire          #+#    #+#             */
/*   Updated: 2020/11/30 22:00:07 by jrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.a"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t lensrc;
	size_t index;

	lensrc = (size_t)ft_strlen((char*)src);
	index = 0;
	if (dstsize < 1)
		return (lensrc);
	while ((index < (dstsize - 1)) && src[index])
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = 0;
	return (lensrc);
}
