/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filda-si <filda-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:14:13 by filda-si          #+#    #+#             */
/*   Updated: 2025/10/20 16:30:27 by filda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	hex_len(unsigned int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	print_hex_rec(unsigned long n, char *base)
{
	int	total;

	total = 0;
	if (n >= 16)
		total += print_hex_rec(n / 16, base);
	total += write(1, &base[n % 16], 1);
	return (total);
}

int	calc_hex_width(unsigned int n, t_flags f, int hlen)
{
	int	w;

	w = hlen;
	if (f.dot && f.prec > hlen)
		w = f.prec;
	if (f.sharp && n != 0)
		w += 2;
	return (w);
}

char	*get_hex_base(int up)
{
	if (up)
		return ("0123456789ABCDEF");
	return ("0123456789abcdef");
}
