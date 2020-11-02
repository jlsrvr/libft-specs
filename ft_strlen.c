/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivoire <jrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:23:16 by jrivoire          #+#    #+#             */
/*   Updated: 2020/11/19 17:29:11 by jrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlen(char const *str)
{
	int index;

	index = 0;
	if (!str)
		return (0);
	while (str[index])
		index++;
	return (index);
}
