/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:23:03 by ymarcais          #+#    #+#             */
/*   Updated: 2022/11/24 10:22:46 by ymarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned	int	get_nb_digit(long n_l, int sign)
{
	unsigned int	nb_digit;

	if (n_l == 0)
		return (1);
	nb_digit = 0;
	while (n_l > 0)
	{
		n_l /= 10;
		nb_digit++;
	}
	if (sign == -1)
		nb_digit++;
	return (nb_digit);
}

static void	convert_nb(char *outstr, long n_l, unsigned int nb_digit, int sign)
{
	outstr[nb_digit] = '\0';
	outstr[--nb_digit] = n_l % 10 + '0';
	n_l /= 10;
	while (n_l > 0)
	{
		outstr[--nb_digit] = n_l % 10 + '0';
		n_l /= 10;
	}
	if (sign == -1)
		outstr[0] = '-';
}

char	*ft_itoa(int n)
{
	char			*outstr;
	long			n_l;
	unsigned int	nb_digit;
	int				sign;

	sign = 1;
	if (n < 0)
	{
		n_l = (long)n * -1;
		sign = -1;
	}
	else
		n_l = n;
	nb_digit = get_nb_digit(n_l, sign);
	outstr = malloc(sizeof(char) * (nb_digit + 1));
	if (outstr == NULL)
		return (NULL);
	convert_nb(outstr, n_l, nb_digit, sign);
	return (outstr);
}
