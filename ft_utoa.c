/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 10:55:42 by sunakim           #+#    #+#             */
/*   Updated: 2019/01/28 12:10:21 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_cnt(unsigned long long int n)
{
	int						cnt;
	unsigned long long int	new_int;

	cnt = 0;
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

	cnt = ft_cnt(v->uret);
	((v->f.width >= v->f.prec)) ? (0) : (v->f.width = v->f.prec);
	((v->f.width >= cnt)) ? (0) : (v->f.width = cnt);
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
	((v->f.minus == 0)) ? (v->f.prec--) : (0);
	i = v->f.prec - nbr;
	while (i >= 0)
	{
		(v->str)[cnt - 1] = 0 + '0';
		cnt--;
		i--;
	}
	return (cnt);
}

static void		ft_new_utoa(int cnt, t_var *v)
{
	unsigned long long int	tmp;

	tmp = v->uret;
	while (tmp > 9)
	{
		(v->str)[cnt-- - 1] = tmp % 10 + '0';
		tmp = tmp / 10;
	}
	((tmp < 10)) ? ((v->str)[cnt - 1] = tmp + '0') : (0);
	cnt--;
	if (v->f.prec != -1)
		cnt = ft_precision(cnt, v);
}

void			ft_utoa(const char *format, t_var *v)
{
	int		cnt;

	ft_uvar(format, v);
	cnt = ft_malloc(v);
	if (v->f.zero == 0)
		ft_memset(v->str, ' ', v->f.width);
	if (v->f.zero == 1)
		ft_memset(v->str, '0', v->f.width);
	ft_new_utoa(cnt, v);
}
