/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivoire <jrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 23:10:01 by jrivoire          #+#    #+#             */
/*   Updated: 2020/12/07 23:10:03 by jrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t index;

	if (n == 0)
		return (dest);
	index = 0;
	while (index < n)
	{
		((char*)dest)[index] = ((const char*)src)[index];
		index++;
	}
	return (dest);
}
