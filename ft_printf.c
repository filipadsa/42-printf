/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filda-si <filda-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:50:38 by filda-si          #+#    #+#             */
/*   Updated: 2025/10/20 10:54:39 by filda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_conv(char c, va_list *args, t_flags f)
{
	if (c == 'c')
		return (print_char(va_arg(*args, int), f));
	if (c == 's')
		return (print_str(va_arg(*args, char *), f));
	if (c == 'p')
		return (print_ptr(va_arg(*args, void *), f));
	if (c == 'd' || c == 'i')
		return (print_int(va_arg(*args, int), f));
	if (c == 'u')
		return (print_uint(va_arg(*args, unsigned int), f));
	if (c == 'x')
		return (print_hex(va_arg(*args, unsigned int), 0, f));
	if (c == 'X')
		return (print_hex(va_arg(*args, unsigned int), 1, f));
	if (c == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	t_flags	f;
	int		total;
	int		i;

	if (!s)
		return (-1);
	init_flags(&f);
	va_start(args, s);
	total = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] == '%' && s[i + 1])
			total += handle_conv(s[++i], &args, f);
		else
			total += write(1, &s[i], 1);
	}
	va_end(args);
	return (total);
}
