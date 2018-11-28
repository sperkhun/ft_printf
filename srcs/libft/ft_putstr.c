/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperkhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:05:00 by sperkhun          #+#    #+#             */
/*   Updated: 2017/11/15 15:40:34 by sperkhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_putstr(char const *s, int len)
{
	int res;

	if (!s)
		return (0);
	res = len ? len : ft_strlen(s);
	write(1, s, res);
	return (res);
}
