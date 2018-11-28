/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperkhun <sperkhun@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:31:39 by sperkhun          #+#    #+#             */
/*   Updated: 2018/11/26 12:31:40 by sperkhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse_oux(va_list argptr, t_param *p)
{
	p->var.u = va_arg(argptr, unsigned);
	print_number(p, itoa_base(p->var.u, p->base, ' ', p->base_str));
}

void		parse_ouxh(va_list argptr, t_param *p)
{
	char	*nb;

	p->var.u = va_arg(argptr, unsigned);
	nb = itoa_base((unsigned short)p->var.u, p->base, ' ', p->base_str);
	print_number(p, nb);
}

void		parse_ouxhh(va_list argptr, t_param *p)
{
	char	*nb;

	p->var.u = va_arg(argptr, unsigned);
	nb = itoa_base((unsigned char)p->var.u, p->base, ' ', p->base_str);
	print_number(p, nb);
}

void		parse_ouxl(va_list argptr, t_param *p)
{
	char	*nb;

	p->var.ul = va_arg(argptr, unsigned long);
	nb = itoa_base(p->var.ul, p->base, ' ', p->base_str);
	print_number(p, nb);
}

void		parse_ouxll(va_list argptr, t_param *p)
{
	char	*nb;

	p->var.ll = va_arg(argptr, unsigned long long);
	nb = itoa_base(p->var.ll, p->base, ' ', p->base_str);
	print_number(p, nb);
}
