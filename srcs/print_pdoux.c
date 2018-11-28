/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pdoux.c                                      :+:      :+:    :+:   */
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

static void	check_zero(t_param *prm, char *str)
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

	sign = str[0] == '-' ? 1 : 0;
	check_zero(prm, str);
	nb = (prm->precision + sign) - ft_strlen(str);
	width = prm->width - ft_strlen(str) - prm->flags.sharp - (nb > 0 ? nb : 0);
	!sign && (prm->flags.plus || prm->flags.space) ? width-- : 0;
	if (!prm->flags.minus && !prm->flags.zero)
		prm->res += print_width(width, ' ');
	prm->flags.sharp ? prm->res += ft_putchar('0') : 0;
	prm->flags.sharp && prm->type == o ? nb-- : 0;
	if (prm->flags.sharp == 2)
		prm->res += prm->type == p ? ft_putchar('x') : ft_putchar(prm->type);
	sign ? prm->res += ft_putchar(str[0]) : 0;
	!sign && prm->flags.plus ? prm->res += ft_putchar('+') : 0;
	!sign && prm->flags.space ? prm->res += ft_putchar(' ') : 0;
	prm->flags.zero && nb <= 0 ? prm->res += print_width(width, '0') : 0;
	prm->res += print_width(nb, '0');
	prm->res += ft_putstr(str + sign, 0);
	prm->flags.minus ? prm->res += print_width(width, ' ') : 0;
	ft_strdel(&str);
}
