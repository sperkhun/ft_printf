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
# include "libft.h"

typedef enum			e_modifire
{
	h, hh, l, ll, L, none
}						t_modifire;

typedef enum			e_type
{
	pct = '%', c = 'c', s = 's', p = 'p', d = 'd', o = 'o',
	u = 'u', x = 'x', X = 'X', f = 'f'
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
int						is_valid(const char *str, int *i, int *val);

void					define_flags(const char *str, int *i, t_param *p);
void					define_width(const char *str, int *i, t_param *p);
void					define_precis(const char *str, int *i, t_param *p);
void					define_mod(const char *str, int *i, t_param *p);
void					define_type(const char *str, int *i, t_param *p);

char					*ftoa(long double num, int precision);
char					*itoa_base(unsigned long long num, int base, char sign,\
									char *s);

void					parse_inv(t_param *prm);
void					parse_csp(va_list argptr, t_param *p);
void					parse_d(va_list argptr, t_param *p);
void					parse_dh(va_list argptr, t_param *p);
void					parse_dhh(va_list argptr, t_param *p);
void					parse_dl(va_list argptr, t_param *p);
void					parse_dll(va_list argptr, t_param *p);
void					parse_oux(va_list argptr, t_param *p);
void					parse_ouxh(va_list argptr, t_param *p);
void					parse_ouxhh(va_list argptr, t_param *p);
void					parse_ouxl(va_list argptr, t_param *p);
void					parse_ouxll(va_list argptr, t_param *p);
void					parse_f(va_list argptr, t_param *p);

typedef struct			s_print
{
	t_type				type;
	t_modifire			mod;
	void				(*parse)(va_list, t_param*);
}						t_print;

void					print_number(t_param *p, char *str);
void					print_float_nb(t_param *p, char *str);
void					print_char(t_param *p, char *str);
void					print_string(t_param *p, char *str);
int						print_width(int w, char c);

static void				(*g_define_spec[5])(const char*, int*, t_param*) = {
	define_flags,
	define_width,
	define_precis,
	define_mod,
	define_type
};

static t_print			g_print_type[33] = {
	{.type = c, .mod = none, .parse = parse_csp},
	{.type = s, .mod = none, .parse = parse_csp},
	{.type = p, .mod = none, .parse = parse_csp},
	{.type = p, .mod = l, .parse = parse_csp},
	{.type = pct, .mod = none, .parse = parse_csp},

	{.type = d, .mod = h, .parse = parse_dh},
	{.type = d, .mod = hh, .parse = parse_dhh},
	{.type = d, .mod = l, .parse = parse_dl},
	{.type = d, .mod = ll, .parse = parse_dll},
	{.type = d, .mod = none, .parse = parse_d},

	{.type = o, .mod = h, .parse = parse_ouxh},
	{.type = o, .mod = hh, .parse = parse_ouxhh},
	{.type = o, .mod = l, .parse = parse_ouxl},
	{.type = o, .mod = ll, .parse = parse_ouxll},
	{.type = o, .mod = none, .parse = parse_oux},

	{.type = x, .mod = h, .parse = parse_ouxh},
	{.type = x, .mod = hh, .parse = parse_ouxhh},
	{.type = x, .mod = l, .parse = parse_ouxl},
	{.type = x, .mod = ll, .parse = parse_ouxll},
	{.type = x, .mod = none, .parse = parse_oux},

	{.type = X, .mod = h, .parse = parse_ouxh},
	{.type = X, .mod = hh, .parse = parse_ouxhh},
	{.type = X, .mod = l, .parse = parse_ouxl},
	{.type = X, .mod = ll, .parse = parse_ouxll},
	{.type = X, .mod = none, .parse = parse_oux},

	{.type = u, .mod = h, .parse = parse_ouxh},
	{.type = u, .mod = hh, .parse = parse_ouxhh},
	{.type = u, .mod = l, .parse = parse_ouxl},
	{.type = u, .mod = ll, .parse = parse_ouxll},
	{.type = u, .mod = none, .parse = parse_oux},

	{.type = f, .mod = none, .parse = parse_f},
	{.type = f, .mod = l, .parse = parse_f},
	{.type = f, .mod = L, .parse = parse_f}
};

#endif
