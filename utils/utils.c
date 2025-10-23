/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filda-si <filda-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:55:34 by filda-si          #+#    #+#             */
/*   Updated: 2025/10/20 10:12:47 by filda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	init_flags(t_flags *f)
{
	f->sharp = 0;
	f->space = 0;
	f->plus = 0;
	f->minus = 0;
	f->zero = 0;
	f->dot = 0;
	f->width = 0;
	f->prec = 0;
}

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

int	print_pad(char c, int count)
{
	int	total;

	total = 0;
	while (count-- > 0)
		total += write(1, &c, 1);
	return (total);
}

int	print_num(unsigned long n)
{
	int	total;

	total = 0;
	if (n >= 10)
		total += print_num(n / 10);
	total += write(1, &(char){n % 10 + '0'}, 1);
	return (total);
}

int	num_len(unsigned long n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}
