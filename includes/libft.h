/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperkhun <sperkhun@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 14:45:10 by sperkhun          #+#    #+#             */
/*   Updated: 2018/11/24 14:45:10 by sperkhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <string.h>

# define MININT -9223372036854775807

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *s1);
char				*ft_strchr(const char *s, int c);
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
char				*ft_itoa(long long int n);
int					ft_putchar(char c);
int					ft_putstr(char const *s, int len);
int					ft_isspace(int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strjoin(char const *s1, char const *s2);

#endif
