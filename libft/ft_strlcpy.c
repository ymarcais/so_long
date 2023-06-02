/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:11:55 by ymarcais          #+#    #+#             */
/*   Updated: 2022/12/30 15:07:51 by ymarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lsrc;

	i = 0;
	lsrc = ft_strlen((char *)src);
	if (!size)
		return (lsrc);
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = ((char *)src)[i];
		i++;
	}
	if (size < lsrc)
		dst[size - 1] = '\0';
	else if (size != 0)
		dst[i] = '\0';
	return (lsrc);
}
