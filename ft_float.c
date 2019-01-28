/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 14:26:52 by sunakim           #+#    #+#             */
/*   Updated: 2019/01/28 12:22:46 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_cnt(long double n)
{
	int			cnt;
	long double	new_int;

	cnt = 0;
	if (n < 0)
		new_int = (long double)(n * -1);
	else
		new_int = n;
	while (new_int > 9)
	{
		new_int = new_int / 10;
		cnt++;
	}
	cnt = cnt + 2;
	return (cnt);
}

static int		ft_malloc(t_var *v)
{
	int		cnt;

	ft_rounding(v);
	v->f_fret = (long long int)v->fret;
	v->s_fret = v->fret + -1 * (v->f_fret);
	cnt = ft_cnt(v->fret);
	((v->f.plus == 1 && v->fret >= 0) || v->fret < 0) ? (cnt++) : (0);
	((v->f.space == 1)) ? (cnt++) : (0);
	if (v->f.prec != -1)
		((v->f.width >= v->f.prec + cnt)) ?
			(0) : (v->f.width = v->f.prec + cnt);
	if (v->f.prec == -1)
		((v->f.width >= 6 + cnt)) ? (0) : (v->f.width = 6 + cnt);
	if (!(v->str = (char*)malloc(sizeof(char) * (v->f.width + 1))))
		error();
	(v->str)[v->f.width] = '\0';
	((v->f.minus == 0)) ? (cnt = v->f.width) : (0);
	((v->f.minus == 1 && v->f.prec != 0)) ? (cnt = cnt + v->f.prec) : (0);
	((v->f.minus == 1 && v->f.prec == 0)) ? (cnt = cnt + 6) : (0);
	return (cnt);
}

static int		ft_put_number(int cnt, t_var *v, long int tmp)
{
	if (tmp < 0)
	{
		v->str[cnt-- - 1] = (tmp % 10) * -1 + '0';
		((tmp < -9)) ? (tmp = -1 * (tmp / 10)) : (0);
	}
	while (tmp > 9)
	{
		(v->str)[cnt-- - 1] = tmp % 10 + '0';
		tmp = tmp / 10;
	}
	((tmp >= 0 && tmp < 10)) ? ((v->str)[cnt - 1] = tmp + '0') : (0);
	cnt--;
	return (cnt);
}

static void		ft_new_float(int cnt, t_var *v)
{
	int			stmp;
	long int	tmp;
	int			i;

	i = 0;
	(v->s_fret < 0) ? v->s_fret = -1 * v->s_fret : 0;
	while (i < v->f.prec)
	{
		v->s_fret = 10 * v->s_fret;
		stmp = (int)v->s_fret;
		v->str[cnt - v->f.prec + i] = stmp + '0';
		v->s_fret = v->s_fret - stmp;
		i++;
	}
	if (v->f.prec != 0)
		v->str[cnt - v->f.prec - 1] = '.';
	if (v->f.prec == 0)
		v->str[cnt - v->f.prec - 1] = '\0';
	tmp = v->f_fret;
	cnt = ft_put_number(cnt - v->f.prec - 1, v, tmp);
	if (v->f.minus == 0)
		((v->fret < 0)) ? ((v->str)[cnt - 1] = '-') : (0);
	if (v->fret >= 0 && v->f.plus == 1 && v->f.minus == 0 && v->f.zero == 0)
		(v->str)[cnt - 1] = '+';
}

void			ft_float(const char *format, t_var *v)
{
	int		cnt;

	if ((format[v->i] == 'f') && v->length == l_l)
		v->fret = va_arg(v->ap, long);
	if ((format[v->i] == 'f') && v->length == l_L)
		v->fret = va_arg(v->ap, long double);
	else
	{
		if (format[v->i] == 'f')
			v->fret = va_arg(v->ap, double);
	}
	cnt = ft_malloc(v);
	if (v->f.zero == 0)
		ft_memset(v->str, ' ', v->f.width);
	if (v->f.zero == 1)
		ft_memset(v->str, '0', v->f.width);
	ft_new_float(cnt, v);
	if ((v->f.plus == 1 && v->f.minus == 1) || (v->f.plus == 1 && v->f.zero ==
		1) || (v->f.prec != 0 && v->f.plus == 1 && v->f.minus == 1))
	{
		(v->fret < 0) ? (v->str[0] = '-') : (0);
		(v->fret >= 0) ? (v->str[0] = '+') : (0);
	}
}
