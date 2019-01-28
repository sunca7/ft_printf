/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:14:31 by sunakim           #+#    #+#             */
/*   Updated: 2019/01/28 17:37:42 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_cnt(unsigned long long int n)
{
	int						cnt;
	unsigned long long int	new_int;

	cnt = 0;
	new_int = n;
	while (new_int > 15)
	{
		new_int = new_int / 16;
		cnt++;
	}
	cnt++;
	return (cnt);
}

static int		ft_malloc(t_var *v)
{
	int		cnt;

	cnt = ft_cnt(v->uret);
	(v->f.sharp == 1) ? (cnt = cnt + 2) : (0);
	if (v->f.width <= v->f.prec)
	{
		v->f.width = v->f.prec;
		if (v->f.sharp == 1)
			v->f.width = v->f.width + 2;
	}
	((v->f.width >= cnt)) ? (0) : (v->f.width = cnt);
	if (!(v->str = (char*)malloc(sizeof(char) * (v->f.width + 1))))
		error();
	(v->str)[v->f.width] = '\0';
	((v->f.minus == 0)) ? (cnt = v->f.width) : (0);
	((v->f.minus == 1 && v->f.prec != -1)) ? cnt = v->f.prec + 2 : 0;
	return (cnt);
}

static int		ft_precision(int cnt, t_var *v)
{
	int	nbr;
	int	i;

	nbr = ft_cnt(v->uret);
	i = v->f.prec - nbr;
	while (i > 0)
	{
		(v->str)[cnt - 1] = 0 + '0';
		cnt--;
		i--;
	}
	return (cnt);
}

static int		ft_new_xtoa(const char *format, int cnt, t_var *v)
{
	unsigned long long int	tmp;
	unsigned int			md;

	tmp = v->uret;
	while (tmp > 15)
	{
		md = tmp % 16;
		if (md >= 10 && md < 16)
		{
			v->str[cnt - 1] = md - 10 + 'a';
			(format[v->i] == 'X') ? (v->str[cnt - 1] = md - 10 + 'A') : (0);
		}
		else
			v->str[cnt - 1] = md + '0';
		tmp = tmp / 16;
		cnt--;
	}
	if (tmp >= 10 && tmp < 16)
	{
		(v->str)[cnt - 1] = tmp - 10 + 'a';
		(format[v->i] == 'X') ? ((v->str)[cnt - 1] = tmp - 10 + 'A') : (0);
	}
	((tmp < 10)) ? ((v->str)[cnt - 1] = tmp + '0') : (0);
	cnt--;
	return (cnt);
}

void			ft_xtoa(const char *format, t_var *v)
{
	int		cnt;

	ft_xvar(format, v);
	if (v->uret == 0 && v->f.prec == 0 && v->f.width == 0)
		return ;
	cnt = ft_malloc(v);
	(v->f.zero == 0) ? (ft_memset(v->str, ' ', v->f.width)) : (0);
	(v->f.zero == 1) ? (ft_memset(v->str, '0', v->f.width)) : (0);
	if (v->f.width != 0 && v->f.prec == 0 && v->uret == 0)
	{
		ft_memset(v->str, ' ', v->f.width);
		return ;
	}
	cnt = ft_new_xtoa(format, cnt, v);
	(v->f.prec != -1) ? (cnt = ft_precision(cnt, v)) : (0);
	if (v->f.sharp == 1 && v->f.minus == 0 && v->f.zero == 0)
	{
		(format[v->i] == 'x') ? ((v->str)[cnt - 1] = 'x') : (0);
		(format[v->i] != 'x') ? ((v->str)[cnt - 1] = 'X') : (0);
		(v->str)[cnt - 2] = '0';
	}
	if ((v->f.sharp == 1 && v->f.minus == 1) || (v->f.sharp == 1 && v->f.zero
		== 1) || (v->f.prec != -1 && v->f.sharp == 1 && v->f.minus == 1))
	{
		(v->str)[0] = '0';
		if (format[v->i] == 'x')
			(v->str)[1] = 'x';
		else
			(v->str)[1] = 'X';
	}
}
