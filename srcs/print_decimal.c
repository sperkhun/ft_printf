/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperkhun <sperkhun@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:32:34 by sperkhun          #+#    #+#             */
/*   Updated: 2018/11/26 12:32:35 by sperkhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_d(va_list argptr, t_param *p)
{
	p->var.i = va_arg(argptr, int);
	print_number(p, ft_itoa(p->var.i));
}

void		print_dh(va_list argptr, t_param *p)
{
	p->var.i = va_arg(argptr, int);
	print_number(p, ft_itoa((short)p->var.i));
}

void		print_dhh(va_list argptr, t_param *p)
{
	p->var.i = va_arg(argptr, int);
	print_number(p, ft_itoa((char)p->var.i));
}

void		print_dl(va_list argptr, t_param *p)
{
	char sign;

	sign = ' ';
	p->var.li = va_arg(argptr, long int);
	if (p->var.li < (long int)0)
	{
		sign = '-';
		p->var.li *= -1;
	}
	print_number(p, itoa_base(p->var.li, 10, sign, "0123456789"));
}

void		print_dll(va_list argptr, t_param *p)
{
	char sign;

	sign = ' ';
	p->var.lli = va_arg(argptr, long long int);
	if (p->var.lli < (long long int)0)
	{
		sign = '-';
		p->var.lli *= -1;
	}
	print_number(p, itoa_base(p->var.lli, 10, sign, "0123456789"));
}
