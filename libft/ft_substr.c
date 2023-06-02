/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:59:40 by ymarcais          #+#    #+#             */
/*   Updated: 2022/12/30 15:01:50 by ymarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*f1(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 1);
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*f2(char const *s, size_t *len, int start)
{
	char	*str;

	if (ft_strlen((char *)s) < start + *len)
		*len = ft_strlen((char *) s) - start;
	str = (char *)malloc((sizeof(char) * (*len + 1)));
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	cur;

	if (!len)
		return (ft_strdup("\0"));
	if (!s)
		return (NULL);
	if (start > ft_strlen((char *)s))
	{
		str = f1();
		if (str == NULL)
			return (NULL);
		return (str);
	}
	str = f2(s, &len, start);
	if (str == NULL)
		return (NULL);
	cur = 0;
	while (cur < len)
	{
		str[cur] = ((char *)s)[start + cur];
		cur++;
	}
	str[cur] = '\0';
	return (str);
}
