/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnumbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperkhun <sperkhun@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 12:41:21 by sperkhun          #+#    #+#             */
/*   Updated: 2018/11/24 12:41:22 by sperkhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_width(int w, char c)
{
	int res;

	res = 0;
	while (w > 0)
	{
		res += ft_putchar(c);
		w--;
	}
	return (res);
}

void		check_zero(t_param *prm, char *str)
{
	if (ft_strequ(str, "0"))
	{
		if (prm->type == o && prm->flags.sharp && prm->precision == 0)
		{
			str[0] = '\0';
			return ;
		}
		prm->type != p ? prm->flags.sharp = 0 : 0;
		if (prm->precision == 0)
		{
			str[0] = '\0';
		}
	}
}

void		print_number(t_param *prm, char *str)
{
	int nb;
	int sign;
	int width;

	sign = 0;
	if (str[0] == '-')
		sign++;
	if (ft_strequ(str, "0"))
		check_zero(prm, str);
	nb = (prm->precision + sign) - ft_strlen(str);
	width = nb > 0 ? prm->width - (ft_strlen(str) + nb) : prm->width - ft_strlen(str);
	width -= prm->flags.sharp;
	!sign && (prm->flags.plus || prm->flags.space) ? width-- : 0;
	if (!prm->flags.minus && !prm->flags.zero)
		prm->res += print_width(width, ' ');
	if (prm->flags.sharp)
	{
		prm->type == o ? nb-- : 0;
		prm->res += ft_putchar('0');
	}
	if (prm->flags.sharp == 2)
		prm->res += prm->type == p ? ft_putchar('x') : ft_putchar(prm->type);
	sign ? prm->res += ft_putchar(str[0]) : 0;
	!sign && prm->flags.plus ? prm->res += ft_putchar('+') : 0;
	!sign && prm->flags.space ? prm->res += ft_putchar(' ') : 0;
	if (prm->flags.zero && nb <= 0)
		prm->res += print_width(width, '0');
	prm->res += print_width(nb, '0');
	prm->res += ft_putstr(str + sign, 0);
	if (prm->flags.minus)
		prm->res += print_width(width, ' ');
	ft_strdel(&str);
}

void		print_float_nb(t_param *p, char *str)
{
	int sign;
	int width;

	sign = 0;
	if (str[0] == '-')
		sign++;
	width = p->width - ft_strlen(str);
	if (!p->flags.minus && !p->flags.zero)
		p->res += print_width(width, ' ');
	sign ? p->res += ft_putchar(str[0]) : 0;
	!sign && p->flags.plus ? p->res += ft_putchar('+') : 0;
	if (p->flags.zero)
		p->res += print_width(width, '0');
	p->res += ft_putstr(str + sign, 0);
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
	nb = p->precision < (int)ft_strlen(str) && p->precision != 0 ? p->precision : 0;
	width = nb > 0 ? p->width - nb : p->width - ft_strlen(str);
	if (!*str && p->type == c)
	{
		nb = 1;
		width--;
	}
	if (!p->flags.minus && !p->flags.zero)
		p->res += print_width(width, ' ');
	if (p->flags.sharp)
		p->res += ft_putchar('0');
	if (p->flags.sharp == 2)
		p->res += ft_putchar(p->type);
	if (p->flags.zero)
		p->res += print_width(width, '0');
	if (nb > 0)
		while (nb-- > 0)
			p->res += ft_putchar(str[i++]);
	else
		p->res += ft_putstr(str, 0);
	if (p->flags.minus)
		p->res += print_width(width, ' ');
	ft_strdel(&str);
}

void		print_string(t_param *p, char *str)
{
	int nb;
	int width;
	int	i;

	i = 0;
	nb = p->precision < (int)ft_strlen(str) && p->precision >= 0 ? p->precision : -1;
	width = nb >= 0 ? p->width - nb : p->width - ft_strlen(str);
	if (!p->flags.minus && !p->flags.zero)
		p->res += print_width(width, ' ');
	if (p->flags.sharp)
		p->res += ft_putchar('0');
	if (p->flags.sharp == 2)
		p->res += ft_putchar(p->type);
	if (p->flags.zero && nb <= 0)
		p->res += print_width(width, '0');
	if (nb >= 0)
		while (nb-- > 0)
			p->res += ft_putchar(str[i++]);
	else
		p->res += ft_putstr(str, 0);
	if (p->flags.minus)
		p->res += print_width(width, ' ');
	ft_strdel(&str);
}
