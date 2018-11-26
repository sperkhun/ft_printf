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

char	*ftoa(long double num, int precision)
{
	char		*str;
	char		*fraction;
	int			i;
	long double	tmp1;
	int			digit;

	str = ft_itoa((long long int)num);
	i = ft_strlen(str);
	fraction = ft_strnew(i + precision + 1);
	fraction = ft_memcpy(fraction, str, i);
	ft_strdel(&str);
	fraction[i] = '.';
	if (num < 0)
		num *= -1;
	tmp1 = num - (long long int)num;
	while (precision-- > 0)
	{
		digit = (int)(tmp1 * 10 + 1e-9);
		fraction[++i] = digit + 48;
		tmp1 = tmp1 * 10 - digit;
	}
	return (fraction);
}

char	*itoa_base(unsigned long long num, int base, char sign, char *s)
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
