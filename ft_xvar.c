/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xvar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:03:37 by sunakim           #+#    #+#             */
/*   Updated: 2019/01/25 11:32:34 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_xvar(const char *format, t_var *v)
{
	if (v->length == l_zero)
	{
		if (format[v->i] == 'x' || format[v->i] == 'X')
			v->uret = va_arg(v->ap, unsigned int);
	}
	else
	{
		if ((format[v->i] == 'x' || format[v->i] == 'X') && v->length == l_h)
			v->uret = (short)va_arg(v->ap, unsigned int);
		if ((format[v->i] == 'x' || format[v->i] == 'X') && v->length == l_hh)
			v->uret = (char)va_arg(v->ap, unsigned int);
		if ((format[v->i] == 'x' || format[v->i] == 'X') && v->length == l_l)
			v->uret = va_arg(v->ap, unsigned long);
		if ((format[v->i] == 'x' || format[v->i] == 'X') && v->length == l_ll)
			v->uret = va_arg(v->ap, unsigned long long);
		if ((format[v->i] == 'x' || format[v->i] == 'X') && v->length == l_j)
			v->uret = va_arg(v->ap, uintmax_t);
		if ((format[v->i] == 'x' || format[v->i] == 'X') && v->length == l_z)
			v->uret = va_arg(v->ap, ssize_t);
	}
	if (v->f.sharp == 1 && v->uret == 0)
		v->f.sharp = 0;
}
