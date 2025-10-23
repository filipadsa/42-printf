/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filda-si <filda-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:58:27 by filda-si          #+#    #+#             */
/*   Updated: 2025/10/20 16:31:36 by filda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_flags
{
	int	sharp;
	int	space;
	int	plus;
	int	minus;
	int	zero;
	int	dot;
	int	width;
	int	prec;
}	t_flags;

int				ft_printf(const char *s, ...);
int				print_char(char c, t_flags f);
int				print_str(char *s, t_flags f);
int				print_int(int n, t_flags f);
int				print_uint(unsigned int n, t_flags f);
int				print_hex(unsigned int n, int up, t_flags f);
int				print_ptr(void *ptr, t_flags f);
int				print_pad(char c, int count);
int				print_num(unsigned long n);
int				ft_strlen(char *s);
int				num_len(unsigned long n);
int				hex_len(unsigned int n);
void			init_flags(t_flags *f);
int				calc_int_width(long n, t_flags f, int dlen);
int				print_sign(long n, t_flags f);
int				handle_zero_case(t_flags f);
unsigned long	get_absolute(long ln);
void			print_int_padding(t_flags f, int w, int *total, long ln);
int				print_hex_rec(unsigned long n, char *base);
int				calc_hex_width(unsigned int n, t_flags f, int hlen);
char			*get_hex_base(int up);

#endif
