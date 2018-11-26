/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperkhun <sperkhun@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 12:20:36 by sperkhun          #+#    #+#             */
/*   Updated: 2018/11/24 12:20:37 by sperkhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			valid_type(char c)
{
	if (ft_strchr("cspdiouxXf%", c) != NULL)
	{
		return (1);
	}
	return (0);
}

int			valid_mod(char c)
{
	if (ft_strchr("hlL", c) != NULL)
	{
		return (1);
	}
	return (0);
}

int			valid_precis(char c)
{
	if (ft_isdigit(c) || c == '.')
	{
		return (1);
	}
	return (0);
}

int			valid_flags(char c)
{
	if (ft_strchr("-+ #0", c) != NULL)
	{
		return (1);
	}
	return (0);
}

int			valid(const char *str, int *i, int *val)
{
	while (str[*i] && (valid_mod(str[*i]) || valid_precis(str[*i])\
								|| valid_flags(str[*i])))
	{
		(*val)++;
		(*i)++;
	}
	if (str[*i])
	{
		(*val)++;
		(*i)++;
	}
	if (*val)
		return (0);
	return (1);
}
