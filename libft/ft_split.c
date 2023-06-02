/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:09:55 by ymarcais          #+#    #+#             */
/*   Updated: 2022/12/01 13:23:52 by ymarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	cnt_words(char const *s, char c)
{
	int	cnt;
	int	sub;

	sub = 0;
	cnt = 0;
	while (*s)
	{
		if (sub == 1 && *s == c)
			sub = 0;
		if (sub == 0 && *s != c)
		{
			sub = 1;
			cnt++;
		}
		s++;
	}
	return (cnt);
}

static int	cnt_len(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**t;
	int		nb_word;
	int		index;

	index = 0;
	nb_word = cnt_words((const char *)s, c);
	t = (char **)malloc(sizeof(*t) * (nb_word + 1));
	if (t == NULL)
		return (NULL);
	while (nb_word--)
	{
		while (*s == c && *s != '\0')
			s++;
		t[index] = ft_substr((const char *)s, 0, cnt_len((const char *)s, c));
		if (t[index] == NULL)
			return (NULL);
		s += cnt_len(s, c);
		index++;
	}
	t[index] = NULL;
	return (t);
}
