/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 10:43:26 by sunakim           #+#    #+#             */
/*   Updated: 2019/01/28 12:02:44 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define FLAGS "+-0123456789*# ."
# define CONVERT "diouUxXcspf"

typedef enum				e_length
{
	l_zero = 0,
	l_h,
	l_hh,
	l_l,
	l_ll,
	l_L,
	l_j,
	l_z,
}							t_length;

typedef struct				s_flags
{
	int	minus;
	int	plus;
	int	space;
	int	sharp;
	int	zero;
	int	width;
	int	star;
	int prec;
	int	sign;
}							t_flags;

typedef struct				s_var
{
	int						i;
	int						num;
	int						len;
	int						opt;
	char					sign;
	char					chr;
	char					*str;
	char					*line;
	char					*cret;
	int						iret;
	long double				fret;
	long int				f_fret;
	long double				s_fret;
	size_t					pret;
	long long int			ret;
	unsigned long long int	uret;
	va_list					ap;
	t_flags					f;
	t_length				length;
}							t_var;

void						error(void);
int							ft_printf(const char *format, ...);
void						ft_output(const char *format, t_var *v);
void						parsing(const char *format, t_var *v);
void						ft_ditoa(const char *format, t_var *v);
void						ft_utoa(const char *format, t_var *v);
void						ft_otoa(const char *format, t_var *v);
void						ft_xtoa(const char *format, t_var *v);
void						ft_char(const char *format, t_var *v);
void						ft_string(const char *format, t_var *v);
void						ft_pointer(const char *format, t_var *v);
void						ft_float(const char *format, t_var *v);
void						ft_excep(const char *format, t_var *v);
void						flags_init(t_var *v);
long double					ft_power(long long int itmp, int prec, t_var *v);
void						ft_divar(const char *format, t_var *v);
void						ft_ovar(const char *format, t_var *v);
void						ft_uvar(const char *format, t_var *v);
void						ft_xvar(const char *format, t_var *v);
void						ft_rounding(t_var *v);
void						ft_double_sharp(t_var *v);

#endif
