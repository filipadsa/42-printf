/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_hex2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filda-si <filda-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:57:09 by filda-si          #+#    #+#             */
/*   Updated: 2025/10/20 16:28:08 by filda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	handle_hex_padding(t_flags f, int w, int up, unsigned int n)
{
	int	total;

	total = 0;
	if (f.width > w && !f.minus && f.zero && !f.dot)
	{
		if (f.sharp && n != 0)
		{
			if (up)
				total += write(1, "0X", 2);
			else
				total += write(1, "0x", 2);
		}
		total += print_pad('0', f.width - w);
	}
	else if (f.width > w && !f.minus)
		total += print_pad(' ', f.width - w);
	return (total);
}

static int	write_sharp_prefix(int up, unsigned int n, t_flags f, int w)
{
	if (f.sharp && n != 0 && !(f.zero && !f.dot && f.width > w))
	{
		if (up)
			return (write(1, "0X", 2));
		return (write(1, "0x", 2));
	}
	return (0);
}

int	print_hex(unsigned int n, int up, t_flags f)
{
	int		total;
	int		hlen;
	int		w;

	if (n == 0 && f.dot && f.prec == 0)
	{
		if (f.width > 0)
			return (print_pad(' ', f.width));
		return (0);
	}
	hlen = hex_len(n);
	w = calc_hex_width(n, f, hlen);
	total = handle_hex_padding(f, w, up, n);
	total += write_sharp_prefix(up, n, f, w);
	if (f.dot && f.prec > hlen)
		total += print_pad('0', f.prec - hlen);
	total += print_hex_rec(n, get_hex_base(up));
	if (f.width > w && f.minus)
		total += print_pad(' ', f.width - w);
	return (total);
}
