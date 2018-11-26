/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperkhun <sperkhun@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:27:30 by sperkhun          #+#    #+#             */
/*   Updated: 2018/11/21 11:27:35 by sperkhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

typedef enum			e_modifire
{
	h, hh, l, ll, L, none
}						t_modifire;

typedef enum			e_type
{
	pct = '%', c = 'c', s = 's', p = 'p', d = 'd', o = 'o',
	u = 'u', x = 'x', X = 'X', f = 'f', inv = 0
}						t_type;

typedef union			u_variable
{
	int					i;
	int					*ip;
	unsigned			u;
	unsigned char		uc;
	unsigned short		us;
	unsigned long		ul;
	unsigned long long	ll;
	long int			li;
	long long int		lli;
	double				d;
	long double			ld;
}						t_variable;

typedef struct			s_format
{
	int					zero;
	int					minus;
	int					plus;
	int					sharp;
	int					space;
}						t_flags;

typedef struct			s_param
{
	t_flags				flags;
	int					width;
	int					precision;
	t_modifire			modifire;
	t_variable			var;
	t_type				type;
	int					res;
	int					base;
	char				*base_str;
}						t_param;

int						ft_printf(const char *format, ...);

int						parse_format(const char *format, va_list argptr);

int						valid_type(char c);
int						valid_mod(char c);
int						valid_precis(char c);
int						valid_flags(char c);
int						valid(const char *str, int *i, int *val);

void					define_flags(const char *str, int *i, t_param *p);
void					define_width(const char *str, int *i, t_param *p);
void					define_precis(const char *str, int *i, t_param *p);
void					define_mod(const char *str, int *i, t_param *p);
void					define_type(const char *str, int *i, t_param *p);

char					*ftoa(long double num, int precision);
char					*itoa_base(unsigned long long num, int base, char sign,\
									char *s);

void					print_inv(t_param *prm);
void					print_csp(va_list argptr, t_param *p);
void					print_d(va_list argptr, t_param *p);
void					print_dh(va_list argptr, t_param *p);
void					print_dhh(va_list argptr, t_param *p);
void					print_dl(va_list argptr, t_param *p);
void					print_dll(va_list argptr, t_param *p);
void					print_oux(va_list argptr, t_param *p);
void					print_ouxh(va_list argptr, t_param *p);
void					print_ouxhh(va_list argptr, t_param *p);
void					print_ouxl(va_list argptr, t_param *p);
void					print_ouxll(va_list argptr, t_param *p);
void					print_f(va_list argptr, t_param *p);

typedef struct			s_print
{
	t_type				type;
	t_modifire			mod;
	void				(*print)(va_list, t_param*);
}						t_print;

void					print_number(t_param *p, char *str);
void					print_float_nb(t_param *p, char *str);
void					print_char(t_param *p, char *str);
void					print_string(t_param *p, char *str);

static void				(*g_define_spec[5])(const char*, int*, t_param*) = {
	define_flags,
	define_width,
	define_precis,
	define_mod,
	define_type
};

static t_print			g_print_type[33] = {
	{.type = c, .mod = none, .print = print_csp},
	{.type = s, .mod = none, .print = print_csp},
	{.type = p, .mod = none, .print = print_csp},
	{.type = p, .mod = l, .print = print_csp},
	{.type = pct, .mod = none, .print = print_csp},

	{.type = d, .mod = h, .print = print_dh},
	{.type = d, .mod = hh, .print = print_dhh},
	{.type = d, .mod = l, .print = print_dl},
	{.type = d, .mod = ll, .print = print_dll},
	{.type = d, .mod = none, .print = print_d},

	{.type = o, .mod = h, .print = print_ouxh},
	{.type = o, .mod = hh, .print = print_ouxhh},
	{.type = o, .mod = l, .print = print_ouxl},
	{.type = o, .mod = ll, .print = print_ouxll},
	{.type = o, .mod = none, .print = print_oux},

	{.type = x, .mod = h, .print = print_ouxh},
	{.type = x, .mod = hh, .print = print_ouxhh},
	{.type = x, .mod = l, .print = print_ouxl},
	{.type = x, .mod = ll, .print = print_ouxll},
	{.type = x, .mod = none, .print = print_oux},

	{.type = X, .mod = h, .print = print_ouxh},
	{.type = X, .mod = hh, .print = print_ouxhh},
	{.type = X, .mod = l, .print = print_ouxl},
	{.type = X, .mod = ll, .print = print_ouxll},
	{.type = X, .mod = none, .print = print_oux},

	{.type = u, .mod = h, .print = print_ouxh},
	{.type = u, .mod = hh, .print = print_ouxhh},
	{.type = u, .mod = l, .print = print_ouxl},
	{.type = u, .mod = ll, .print = print_ouxll},
	{.type = u, .mod = none, .print = print_oux},

	{.type = f, .mod = none, .print = print_f},
	{.type = f, .mod = l, .print = print_f},
	{.type = f, .mod = L, .print = print_f}
};

#endif
