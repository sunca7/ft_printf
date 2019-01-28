/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_excep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:47:30 by sunakim           #+#    #+#             */
/*   Updated: 2019/01/28 12:23:33 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_excep(const char *format, t_var *v)
{
	if (v->f.zero == 1 && v->f.minus == 1)
		v->f.zero = 0;
	if (v->f.space == 1 && v->f.plus == 1)
		v->f.space = 0;
	if (v->f.space == 1 && v->f.minus == 1)
		v->f.space = 0;
	if (v->f.space == 1 && v->f.minus == 1)
		v->f.space = 0;
	if ((v->f.prec != -1 && v->f.prec != -1) && v->f.zero == 1)
		v->f.zero = 0;
	if (format[v->i] == 'u')
	{
		v->f.space = 0;
		v->f.plus = 0;
	}
	if (format[v->i] == 'o' || format[v->i] == 'x' || format[v->i] == 'X')
	{
		v->f.space = 0;
		v->f.plus = 0;
	}
	if (format[v->i] == 'f')
		v->f.space = 0;
}
