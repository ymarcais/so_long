/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:31:15 by ymarcais          #+#    #+#             */
/*   Updated: 2022/12/30 15:06:46 by ymarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*cur;
	unsigned int	i;

	i = 0;
	cur = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			cur = (char *)&s[i];
		i++;
	}
	if (cur)
		return (cur);
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (0);
}
