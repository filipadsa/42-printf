/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_ptr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filda-si <filda-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:47:28 by filda-si          #+#    #+#             */
/*   Updated: 2025/10/20 17:05:58 by filda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	get_ptr_len(unsigned long addr)
{
	int				plen;
	unsigned long	w;

	plen = 0;
	w = addr;
	while (w && ++plen)
		w /= 16;
	if (plen == 0)
		plen = 1;
	return (plen);
}

int	print_ptr(void *ptr, t_flags f)
{
	unsigned long	addr;
	int				total;
	int				plen;
	int				w;

	if (!ptr)
		return (print_str("(nil)", f));
	addr = (unsigned long)ptr;
	plen = get_ptr_len(addr);
	w = plen + 2;
	total = 0;
	if (f.width > w && !f.minus)
		total += print_pad(' ', f.width - w);
	total += write(1, "0x", 2);
	total += print_hex_rec(addr, "0123456789abcdef");
	if (f.width > w && f.minus)
		total += print_pad(' ', f.width - w);
	return (total);
}
