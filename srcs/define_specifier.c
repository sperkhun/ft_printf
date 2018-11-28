/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperkhun <sperkhun@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 12:35:22 by sperkhun          #+#    #+#             */
/*   Updated: 2018/11/24 12:35:23 by sperkhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		define_mod(const char *str, int *i, t_param *p)
{
	if (!valid_mod(str[*i]))
		return ;
	if (str[*i] == 'l')
	{
		p->modifire = str[*i + 1] == str[*i] ? ll : l;
		*i += p->modifire == ll ? 2 : 1;
	}
	else if (str[*i] == 'h')
	{
		p->modifire = str[*i + 1] == str[*i] ? hh : h;
		*i += p->modifire == hh ? 2 : 1;
	}
	else if (str[*i] == 'L')
	{
		p->modifire = L;
		(*i)++;
	}
}

void		define_type(const char *str, int *i, t_param *p)
{
	char c;

	c = str[*i];
	c == 'i' ? c = 'd' : 0;
	p->type = c;
	if (!valid_type(c))
		return ;
	if (c == 'o')
	{
		p->base = 8;
		p->base_str = "01234567";
	}
	else if ((c == 'x' || c == 'X'))
	{
		p->flags.sharp ? p->flags.sharp++ : 0;
		p->base = 16;
		p->base_str = c == 'X' ? "0123456789ABCDEF" : "0123456789abcdef";
	}
	if (ft_strchr("ouxXpcs", c) != NULL)
	{
		p->flags.space = 0;
		p->flags.plus = 0;
	}
	c == 'i' || c == 'd' ? p->flags.sharp = 0 : 0;
}

void		define_precis(const char *str, int *i, t_param *p)
{
	if (str[*i] != '.')
		return ;
	else
		(*i)++;
	p->precision = ft_atoi(str + *i);
	p->precision ? p->flags.zero = 0 : 0;
	while (ft_isdigit(str[*i]))
		(*i)++;
}

void		define_width(const char *str, int *i, t_param *p)
{
	if (!ft_isdigit(str[*i]))
		return ;
	p->width = ft_atoi(str + *i);
	while (ft_isdigit(str[*i]))
		(*i)++;
}

void		define_flags(const char *str, int *i, t_param *p)
{
	while (valid_flags(str[*i]))
	{
		if (str[*i] == '-')
		{
			if (p->flags.zero)
				p->flags.zero = 0;
			p->flags.minus = 1;
		}
		if (str[*i] == '+')
		{
			if (p->flags.space)
				p->flags.space = 0;
			p->flags.plus = 1;
		}
		if (str[*i] == ' ' && !p->flags.plus)
			p->flags.space = 1;
		if (str[*i] == '#')
			p->flags.sharp = 1;
		if (str[*i] == '0' && !p->flags.minus)
			p->flags.zero = 1;
		(*i)++;
	}
}
