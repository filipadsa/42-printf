/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filda-si <filda-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:10:39 by filda-si          #+#    #+#             */
/*   Updated: 2025/10/20 16:38:34 by filda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	parse_flags(const char *s, int *i, t_flags *f)
{
	while (s[*i] == '#' || s[*i] == ' ' || s[*i] == '+' || s[*i] == '-'
		|| s[*i] == '0')
	{
		if (s[*i] == '#')
			f->sharp = 1;
		else if (s[*i] == ' ')
			f->space = 1;
		else if (s[*i] == '+')
			f->plus = 1;
		else if (s[*i] == '-')
			f->minus = 1;
		else if (s[*i] == '0')
			f->zero = 1;
		(*i)++;
	}
}

static void	parse_width_prec(const char *s, int *i, t_flags *f)
{
	while (s[*i] >= '0' && s[*i] <= '9')
		f->width = f->width * 10 + s[(*i)++] - '0';
	if (s[*i] == '.')
	{
		f->dot = 1;
		(*i)++;
		while (s[*i] >= '0' && s[*i] <= '9')
			f->prec = f->prec * 10 + s[(*i)++] - '0';
	}
}

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

static int	parse_and_print(const char *s, va_list *args, int *i)
{
	t_flags	f;
	int		j;
	char	conv;

	init_flags(&f);
	j = *i + 1;
	parse_flags(s, &j, &f);
	parse_width_prec(s, &j, &f);
	conv = s[j];
	if (conv != 'c' && conv != 's' && conv != 'p' && conv != 'd'
		&& conv != 'i' && conv != 'u' && conv != 'x'
		&& conv != 'X' && conv != '%')
	{
		*i = j;
		return (0);
	}
	*i = j;
	return (handle_conv(conv, args, f));
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		total;
	int		i;

	if (!s)
		return (-1);
	va_start(args, s);
	total = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			total += parse_and_print(s, &args, &i);
			i++;
		}
		else
		{
			total += write(1, &s[i], 1);
			i++;
		}
	}
	va_end(args);
	return (total);
}
