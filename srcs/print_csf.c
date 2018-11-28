/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_csf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperkhun <sperkhun@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:09:22 by sperkhun          #+#    #+#             */
/*   Updated: 2018/11/27 17:09:22 by sperkhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_float_nb(t_param *p, char *str)
{
	int sign;
	int width;

	sign = 0;
	if (str[0] == '-')
		sign++;
	width = p->width - ft_strlen(str);
	!sign && (p->flags.plus || p->flags.space) ? width-- : 0;
	if (!p->flags.minus && !p->flags.zero)
		p->res += print_width(width, ' ');
	sign ? p->res += ft_putchar(str[0]) : 0;
	!sign && p->flags.plus && !ft_strequ(str, "nan") ?\
						p->res += ft_putchar('+') : 0;
	!sign && p->flags.space && !ft_strequ(str, "nan") ?\
						p->res += ft_putchar(' ') : 0;
	if (p->flags.zero)
		p->res += print_width(width, '0');
	p->res += ft_putstr(str + sign, 0);
	if (p->flags.sharp && p->precision == 0)
		p->res += ft_putchar('.');
	if (p->flags.minus)
		p->res += print_width(width, ' ');
	ft_strdel(&str);
}

void		print_char(t_param *p, char *str)
{
	int nb;
	int width;
	int	i;

	i = 0;
	nb = p->precision < (int)ft_strlen(str) && p->precision != 0 ?\
											p->precision : 0;
	width = nb > 0 ? p->width - nb : p->width - ft_strlen(str);
	if (!*str && p->type == c)
	{
		nb = 1;
		width--;
	}
	!p->flags.minus && !p->flags.zero ? p->res += print_width(width, ' ') : 0;
	p->flags.sharp ? p->res += ft_putchar('0') : 0;
	p->flags.sharp == 2 ? p->res += ft_putchar(p->type) : 0;
	p->flags.zero ? p->res += print_width(width, '0') : 0;
	if (nb > 0)
		while (nb-- > 0)
			p->res += ft_putchar(str[i++]);
	else
		p->res += ft_putstr(str, 0);
	p->flags.minus ? p->res += print_width(width, ' ') : 0;
	ft_strdel(&str);
}

void		print_string(t_param *p, char *str)
{
	int nb;
	int width;
	int	i;

	i = 0;
	nb = p->precision < (int)ft_strlen(str) && p->precision >= 0 ?\
												p->precision : -1;
	width = nb >= 0 ? p->width - nb : p->width - ft_strlen(str);
	!p->flags.minus && !p->flags.zero ? p->res += print_width(width, ' ') : 0;
	p->flags.sharp ? p->res += ft_putchar('0') : 0;
	p->flags.sharp == 2 ? p->res += ft_putchar(p->type) : 0;
	p->flags.zero && nb <= 0 ? p->res += print_width(width, '0') : 0;
	if (nb >= 0)
		while (nb-- > 0)
			p->res += ft_putchar(str[i++]);
	else
		p->res += ft_putstr(str, 0);
	p->flags.minus ? p->res += print_width(width, ' ') : 0;
	ft_strdel(&str);
}
