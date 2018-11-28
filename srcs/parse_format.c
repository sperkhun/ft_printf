/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperkhun <sperkhun@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:41:17 by sperkhun          #+#    #+#             */
/*   Updated: 2018/11/21 11:41:18 by sperkhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			parse_param(t_param p, va_list argptr)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (i < 33)
	{
		if (p.type == g_print_type[i].type && p.modifire == g_print_type[i].mod)
		{
			g_print_type[i].parse(argptr, &p);
			status = 1;
		}
		i++;
	}
	if (!status)
		parse_inv(&p);
	return (p.res);
}

static void			default_param(t_param *p)
{
	*p = (t_param) {
		.modifire = none,
		.type = 0,
		.precision = -1,
		.width = 0,
		.res = 0,
		.base = 10,
		.base_str = "0123456789",
		.flags = {
			.zero = 0,
			.space = 0,
			.minus = 0,
			.plus = 0,
			.sharp = 0
		}
	};
}

static t_param		create_param(const char *str, int len, int valid)
{
	t_param		p;
	int			i;
	int			j;

	i = 0;
	j = 0;
	default_param(&p);
	if (str[i] == '%' && valid)
	{
		i++;
		while (j < 5)
		{
			g_define_spec[j](str, &i, &p);
			j++;
		}
	}
	else
		p.res += ft_putstr(str, len);
	return (p);
}

int					parse_format(const char *format, va_list argptr)
{
	int		i;
	int		start;
	int		valid;
	int		res;

	i = 0;
	res = format ? 0 : -1;
	while (format && format[i])
	{
		start = i;
		valid = 0;
		if (format[i] == '%')
		{
			i++;
			if (is_valid(format, &i, &valid))
				continue ;
		}
		else
			while (format[i] && format[i] != '%')
				i++;
		res += parse_param(create_param(format + start, i - start, valid),\
																	argptr);
	}
	return (res);
}
