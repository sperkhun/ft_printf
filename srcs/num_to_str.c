/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperkhun <sperkhun@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 12:24:44 by sperkhun          #+#    #+#             */
/*   Updated: 2018/11/24 12:24:45 by sperkhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long double	ft_pow(long double x, int y)
{
	long double res;

	res = x;
	if (y == 0)
		return (1);
	while (--y > 0)
		res *= x;
	return (res);
}

static long double	roundd(long double num, int precision)
{
	long double tmp;
	int			sign;

	sign = 1;
	if (num < 0)
	{
		sign = -1;
		num = -num;
	}
	tmp = num - (long long)num;
	tmp *= ft_pow(10, precision);
	tmp -= (long long)tmp;
	if (tmp >= 0.5)
	{
		tmp = 0.5;
		num += tmp * ft_pow(0.1, precision);
	}
	return (num * sign);
}

char				*ftoa(long double num, int precision)
{
	char		*str;
	char		*fraction;
	int			i;
	long double	tmp1;
	int			digit;

	num = roundd(num, precision);
	str = ft_itoa((long long int)num);
	i = ft_strlen(str);
	fraction = ft_strnew(i + precision + 1);
	fraction = ft_memcpy(fraction, str, i);
	ft_strdel(&str);
	if (precision)
		fraction[i] = '.';
	num < 0 ? num = -num : 0;
	tmp1 = num - (long long int)num;
	while (precision-- > 0)
	{
		digit = tmp1 * 10.0 + (precision < 10 ? 1e-9 : 0);
		fraction[++i] = digit + 48;
		tmp1 = tmp1 * 10 - digit;
	}
	return (fraction);
}

char				*itoa_base(unsigned long long num, int base, char sign,\
														char *s)
{
	int		i;
	int		j;
	char	*buf;

	j = 0;
	i = 29;
	buf = ft_strnew(30);
	if (num == 0)
		buf[0] = '0';
	while (num > 0 && i >= 0)
	{
		buf[i] = s[num % base];
		i--;
		num = num / base;
	}
	if (sign != ' ')
		buf[j++] = sign;
	while (++i < 30)
	{
		buf[j++] = buf[i];
		buf[i] = '\0';
	}
	return (buf);
}
