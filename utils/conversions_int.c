/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filda-si <filda-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:46:23 by filda-si          #+#    #+#             */
/*   Updated: 2025/10/20 10:55:21 by filda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	calc_int_width(long n, t_flags f, int dlen)
{
	int	w;

	w = dlen;
	if (f.dot && f.prec > dlen)
		w = f.prec;
	if (n < 0 || f.plus || f.space)
		w++;
	return (w);
}

int	print_sign(long n, t_flags f)
{
	if (n < 0)
		return (write(1, "-", 1));
	if (f.plus)
		return (write(1, "+", 1));
	if (f.space)
		return (write(1, " ", 1));
	return (0);
}

int	handle_zero_case(t_flags f)
{
	if (f.width > 0)
		return (print_pad(' ', f.width));
	return (0);
}

unsigned long	get_absolute(long ln)
{
	if (ln < 0)
		return (-ln);
	return (ln);
}

void	print_int_padding(t_flags f, int w, int *total, long ln)
{
	if (f.width > w && !f.minus && f.zero && !f.dot)
	{
		*total += print_sign(ln, f);
		*total += print_pad('0', f.width - w);
	}
	else if (f.width > w && !f.minus)
		*total += print_pad(' ', f.width - w);
}
