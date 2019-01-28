/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ditoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 10:55:42 by sunakim           #+#    #+#             */
/*   Updated: 2019/01/28 14:51:29 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_cnt(long long int n)
{
	int				cnt;
	long long int	new_int;

	cnt = 0;
	if (n < 0)
		new_int = (long long int)(n * -1);
	else
		new_int = n;
	while (new_int > 9)
	{
		new_int = new_int / 10;
		cnt++;
	}
	cnt++;
	return (cnt);
}

static int		ft_malloc(t_var *v)
{
	int		cnt;

	cnt = ft_cnt(v->ret);
	(v->ret < 0) ? (v->f.space = 0) : (0);
	((v->f.plus == 1 && v->ret >= 0) || v->ret < 0) ? (cnt++) : (0);
	((v->f.space == 1)) ? (cnt++) : (0);
	if (v->f.width <= v->f.prec)
	{
		v->f.width = v->f.prec;
		if (v->f.prec != -1 && ((v->f.plus == 1 && v->ret >= 0) || v->ret < 0))
			v->f.width++;
	}
	((v->f.width >= cnt)) ? (0) : (v->f.width = cnt);
	if (!(v->str = (char*)malloc(sizeof(char) * (v->f.width + 1))))
		error();
	(v->str)[v->f.width] = '\0';
	((v->f.minus == 0)) ? (cnt = v->f.width) : (0);
	if (v->f.minus == 1 && v->f.prec != -1 && v->f.prec != 0)
	{
		cnt = v->f.prec;
		((v->f.plus == 1 && v->ret >= 0) || v->ret < 0) ? (cnt++) : (0);
		((v->f.space == 1)) ? (cnt++) : (0);
	}
	return (cnt);
}

static int		ft_precision(int cnt, t_var *v)
{
	int	nbr;
	int	i;

	nbr = ft_cnt(v->ret);
	i = v->f.prec - nbr;
	while (i-- > 0)
		(v->str)[cnt-- - 1] = 0 + '0';
	return (cnt);
}

static void		ft_new_itoa(int cnt, t_var *v)
{
	long long int	tmp;

	tmp = v->ret;
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
	((tmp >= 0 && tmp < 10)) ? ((v->str)[cnt-- - 1] = tmp + '0') : (0);
	(v->f.prec != -1) ? (cnt = ft_precision(cnt, v)) : (0);
	if (v->f.zero == 0)
		((v->ret < 0)) ? ((v->str)[cnt - 1] = '-') : (0);
	if (v->ret >= 0 && v->f.plus == 1 && v->f.minus == 0 && v->f.zero == 0)
		(v->str)[cnt - 1] = '+';
	((v->f.space == 1)) ? ((v->str)[--cnt - 1] = ' ') : (0);
}

void			ft_ditoa(const char *format, t_var *v)
{
	int		cnt;

	ft_divar(format, v);
	if (v->ret == 0 && v->f.prec == 0 && v->f.width == 0)
		return ;
	cnt = ft_malloc(v);
	(v->f.zero == 0) ? (ft_memset(v->str, ' ', v->f.width)) : (0);
	(v->f.zero == 1) ? (ft_memset(v->str, '0', v->f.width)) : (0);
	if (v->f.width != 0 && v->f.prec == 0 && v->ret == 0)
	{
		ft_memset(v->str, ' ', v->f.width);
		return ;
	}
	ft_new_itoa(cnt, v);
	if ((v->f.plus == 1 && v->f.minus == 1) || (v->f.zero == 1)
		|| (v->f.prec != -1 && v->f.plus == 1 && v->f.minus == 1))
	{
		if (v->ret < 0)
			v->str[0] = '-';
		if (v->f.plus == 1 && v->ret >= 0)
			v->str[0] = '+';
	}
}
