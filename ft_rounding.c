/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rounding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:20:28 by sunakim           #+#    #+#             */
/*   Updated: 2019/01/28 12:22:19 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_rounding(t_var *v)
{
	int				i;
	long double		tmp;
	long double		result;
	long long int	itmp;

	tmp = v->fret;
	(tmp < 0) ? (tmp = -1 * tmp) : (0);
	itmp = (long long int)v->fret;
	tmp = tmp - itmp;
	(v->f.prec == -1) ? (v->f.prec = 6) : (0);
	i = 0;
	while (i++ < v->f.prec)
	{
		tmp = 10 * tmp;
		itmp = (long long int)tmp;
		tmp = tmp - itmp;
	}
	tmp = 10 * tmp;
	itmp = (long long int)tmp;
	if (itmp >= 5 && itmp <= 9)
	{
		result = ft_power(1, v->f.prec, v);
		v->fret = v->fret + result;
	}
}
