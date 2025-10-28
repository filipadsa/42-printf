/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filda-si <filda-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:13:16 by filda-si          #+#    #+#             */
/*   Updated: 2025/10/20 16:47:31 by filda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_char(char c, t_flags f)
{
	int	total;

	total = 0;
	if (f.width > 1 && !f.minus)
		total += print_pad(' ', f.width - 1);
	total += write(1, &c, 1);
	if (f.width > 1 && f.minus)
		total += print_pad(' ', f.width - 1);
	return (total);
}

static int	handle_null_str(t_flags f)
{
	int	plen;
	int	total;

	if (f.dot && f.prec < 6)
		plen = 0;
	else
		plen = 6;
	total = 0;
	if (f.width > plen && !f.minus)
		total += print_pad(' ', f.width - plen);
	if (plen > 0)
		total += write(1, "(null)", plen);
	if (f.width > plen && f.minus)
		total += print_pad(' ', f.width - plen);
	return (total);
}

int	print_str(char *s, t_flags f)
{
	int	total;
	int	len;
	int	plen;

	total = 0;
	if (!s)
		return (handle_null_str(f));
	len = ft_strlen(s);
	plen = len;
	if (f.dot && f.prec < len)
		plen = f.prec;
	if (f.width > plen && !f.minus)
		total += print_pad(' ', f.width - plen);
	total += write(1, s, plen);
	if (f.width > plen && f.minus)
		total += print_pad(' ', f.width - plen);
	return (total);
}

int	print_uint(unsigned int n, t_flags f)
{
	int	total;
	int	dlen;
	int	w;

	if (n == 0 && f.dot && f.prec == 0)
	{
		if (f.width > 0)
			return (print_pad(' ', f.width));
		return (0);
	}
	dlen = num_len(n);
	w = dlen;
	if (f.dot && f.prec > dlen)
		w = f.prec;
	total = 0;
	if (f.width > w && !f.minus && f.zero && !f.dot)
		total += print_pad('0', f.width - w);
	else if (f.width > w && !f.minus)
		total += print_pad(' ', f.width - w);
	if (f.dot && f.prec > dlen)
		total += print_pad('0', f.prec - dlen);
	total += print_num(n);
	if (f.width > w && f.minus)
		total += print_pad(' ', f.width - w);
	return (total);
}
