/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_sharp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 10:50:00 by sunakim           #+#    #+#             */
/*   Updated: 2019/01/28 12:22:00 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_malloc(t_var *v)
{
	int		cnt;

	cnt = 1;
	v->f.prec = -1;
	((v->f.width >= cnt)) ? (0) : (v->f.width = cnt);
	if (!(v->str = (char*)malloc(sizeof(char) * (v->f.width + 1))))
		error();
	(v->str)[v->f.width] = '\0';
	((v->f.minus == 0)) ? (cnt = v->f.width) : (0);
	return (cnt);
}

static void		ft_new_sharp(int cnt, t_var *v)
{
	v->str[cnt - 1] = v->chr;
}

void			ft_double_sharp(t_var *v)
{
	int		cnt;

	v->chr = '%';
	cnt = ft_malloc(v);
	(v->f.zero == 0) ? (ft_memset(v->str, ' ', v->f.width)) : (0);
	(v->f.zero == 1) ? (ft_memset(v->str, '0', v->f.width)) : (0);
	ft_new_sharp(cnt, v);
}
