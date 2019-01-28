/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:15:52 by sunakim           #+#    #+#             */
/*   Updated: 2019/01/28 17:01:20 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_cnt(unsigned long long int n)
{
	int						cnt;
	unsigned long long int	new_int;

	cnt = 0;
	new_int = n;
	while (new_int > 7)
	{
		new_int = new_int / 8;
		cnt++;
	}
	cnt++;
	return (cnt);
}

static int		ft_malloc(t_var *v)
{
	int		cnt;

	cnt = ft_cnt(v->uret);
	(v->f.sharp == 1 && v->uret != 0) ? (cnt++) : (0);
	((v->f.width >= v->f.prec)) ? (0) : (v->f.width = v->f.prec);
	((v->f.width >= cnt)) ? (0) : (v->f.width = cnt);
	if (v->uret == 0 && v->f.prec == 0 && v->f.width == 0 && v->f.sharp == 1)
	{
		v->f.width = 1;
		v->f.sharp = 0;
	}
	if (!(v->str = (char*)malloc(sizeof(char) * (v->f.width + 1))))
		error();
	(v->str)[v->f.width] = '\0';
	((v->f.minus == 0)) ? (cnt = v->f.width) : (0);
	((v->f.minus == 1 && v->f.prec != -1)) ? (cnt = v->f.prec) : (0);
	return (cnt);
}

static int		ft_precision(int cnt, t_var *v)
{
	int	nbr;
	int	i;

	nbr = ft_cnt(v->uret);
	i = v->f.prec - nbr;
	if (i > 0)
		v->f.sharp = 0;
	while (i > 0)
	{
		(v->str)[cnt - 1] = 0 + '0';
		cnt--;
		i--;
	}
	return (cnt);
}

static void		ft_new_otoa(int cnt, t_var *v)
{
	unsigned long long int	tmp;

	tmp = v->uret;
	while (tmp > 7)
	{
		(v->str)[cnt-- - 1] = tmp % 8 + '0';
		tmp = tmp / 8;
	}
	((tmp < 8)) ? ((v->str)[cnt - 1] = tmp + '0') : (0);
	cnt--;
	if (v->f.prec != -1)
		cnt = ft_precision(cnt, v);
	if (v->f.sharp == 1 && v->f.minus == 0 && v->f.zero == 0)
		(v->str)[cnt - 1] = '0';
}

void			ft_otoa(const char *format, t_var *v)
{
	int		cnt;

	ft_ovar(format, v);
	if (v->uret == 0 && v->f.prec == 0 && v->f.width == 0 && v->f.sharp == 0)
		return ;
	cnt = ft_malloc(v);
	(v->f.zero == 0) ? ft_memset(v->str, ' ', v->f.width) : (0);
	(v->f.zero == 1) ? ft_memset(v->str, '0', v->f.width) : (0);
	if (v->f.width != 0 && v->f.prec == 0 && v->uret == 0 && v->f.sharp == 0)
	{
		ft_memset(v->str, ' ', v->f.width);
		return ;
	}
	ft_new_otoa(cnt, v);
	if ((v->f.sharp == 1 && v->f.minus == 1) || (v->f.sharp == 1 && v->f.zero
		== 1) || (v->f.prec != -1 && v->f.sharp == 1 && v->f.minus == 1))
		(v->str)[0] = '0';
}
