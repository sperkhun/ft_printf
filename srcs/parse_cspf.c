/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cspf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperkhun <sperkhun@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 12:27:26 by sperkhun          #+#    #+#             */
/*   Updated: 2018/11/24 12:27:26 by sperkhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse_inv(t_param *prm)
{
	char *str;

	prm->var.i = prm->type;
	str = ft_strnew(1);
	str[0] = (char)prm->var.i;
	print_char(prm, str);
}

void		parse_csp(va_list argptr, t_param *prm)
{
	char *str;

	if (prm->type == c || prm->type == pct)
	{
		prm->var.i = prm->type == c ? va_arg(argptr, int) : prm->type;
		str = ft_strnew(1);
		str[0] = (char)prm->var.i;
		print_char(prm, str);
	}
	else if (prm->type == s)
	{
		prm->var.ip = va_arg(argptr, int*);
		if (!prm->var.ip)
			print_string(prm, ft_strdup("(null)"));
		else
			print_string(prm, ft_strdup((char*)prm->var.ip));
	}
	else if (prm->type == p)
	{
		prm->var.ul = va_arg(argptr, unsigned long);
		prm->flags.sharp = 2;
		print_number(prm, itoa_base(prm->var.ul, 16, ' ', "0123456789abcdef"));
	}
}

static char	*check_special(long double num)
{
	if (num != num)
		return (ft_strdup("nan"));
	else if (num == 1.0 / 0.0)
		return (ft_strdup("inf"));
	else if (num == -1.0 / 0.0)
		return (ft_strdup("-inf"));
	else
		return (NULL);
}

void		parse_f(va_list argptr, t_param *p)
{
	char	*str;
	int		precision;

	precision = p->precision >= 0 ? p->precision : 6;
	if (p->modifire == L)
	{
		p->var.ld = va_arg(argptr, long double);
		str = check_special(p->var.ld);
		!str ? str = ftoa(p->var.ld, precision) : 0;
	}
	else
	{
		p->var.d = va_arg(argptr, double);
		str = check_special(p->var.d);
		!str ? str = ftoa(p->var.d, precision) : 0;
	}
	print_float_nb(p, str);
}
