/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 10:56:03 by sunakim           #+#    #+#             */
/*   Updated: 2019/01/23 15:07:26 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_cnt(size_t n)
{
	int						cnt;
	size_t					new_int;

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

	cnt = ft_cnt(v->pret);
	cnt = cnt + 2;
	((v->f.width >= cnt)) ? (0) : (v->f.width = cnt);
	if (!(v->str = (char*)malloc(sizeof(char) * (v->f.width + 1))))
		error();
	(v->str)[v->f.width] = '\0';
	((v->f.minus == 0)) ? (cnt = v->f.width) : (0);
	if (v->f.width >= cnt)
		ft_memset(v->str, ' ', v->f.width);
	return (cnt);
}

static void		ft_new_pointer(int cnt, t_var *v)
{
	size_t					tmp;
	unsigned int			md;

	tmp = v->pret;
	while (tmp > 15)
	{
		md = tmp % 16;
		if (md >= 10 && md < 16)
			v->str[cnt - 1] = md - 10 + 'a';
		else
			v->str[cnt - 1] = md + '0';
		tmp = tmp / 16;
		cnt--;
	}
	if (tmp >= 10 && tmp < 16)
		(v->str)[cnt - 1] = tmp - 10 + 'a';
	((tmp < 10)) ? ((v->str)[cnt - 1] = tmp + '0') : (0);
	cnt--;
	if (v->f.minus == 0)
	{
		(v->str)[cnt - 1] = 'x';
		(v->str)[cnt - 2] = '0';
	}
}

static void		ft_var(const char *format, t_var *v)
{
	if (format[v->i] == 'p')
		v->pret = (size_t)va_arg(v->ap, void*);
}

void			ft_pointer(const char *format, t_var *v)
{
	int cnt;

	ft_var(format, v);
	cnt = ft_malloc(v);
	ft_new_pointer(cnt, v);
	if (v->f.minus == 1)
	{
		(v->str)[0] = '0';
		(v->str)[1] = 'x';
	}
}
