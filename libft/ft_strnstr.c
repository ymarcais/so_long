/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:09:38 by ymarcais          #+#    #+#             */
/*   Updated: 2022/12/02 13:13:38 by ymarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	c;
	size_t	n_len;
	char	*b;

	if (!*little)
		return ((char *)big);
	if (!len && !*little)
		return ((char *) big);
	if (!len)
		return (NULL);
	i = 0;
	b = (char *)big;
	n_len = ft_strlen(little);
	while (b[i] != '\0' && i < len)
	{
		c = 0;
		while (b[i + c] != '\0' && little[c] != '\0' \
			&& b[i + c] == little[c] && i + c < len)
			c++;
		if (c == n_len)
			return (b + i);
	i++;
	}
	return (0);
}
