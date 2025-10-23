/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_int2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filda-si <filda-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:55:49 by filda-si          #+#    #+#             */
/*   Updated: 2025/10/20 10:55:56 by filda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_int(int n, t_flags f)
{
	long	ln;
	int		total;
	int		dlen;
	int		w;

	ln = n;
	if (ln == 0 && f.dot && f.prec == 0)
		return (handle_zero_case(f));
	dlen = num_len(get_absolute(ln));
	w = calc_int_width(ln, f, dlen);
	total = 0;
	print_int_padding(f, w, &total, ln);
	if (!(f.zero && !f.dot && f.width > w))
		total += print_sign(ln, f);
	if (f.dot && f.prec > dlen)
		total += print_pad('0', f.prec - dlen);
	total += print_num(get_absolute(ln));
	if (f.width > w && f.minus)
		total += print_pad(' ', f.width - w);
	return (total);
}
