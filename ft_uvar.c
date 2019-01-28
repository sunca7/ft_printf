/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uvar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:03:25 by sunakim           #+#    #+#             */
/*   Updated: 2019/01/28 14:39:52 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_uvar(const char *format, t_var *v)
{
	if (v->length == l_zero && format[v->i] != 'U')
	{
		if (format[v->i] == 'u')
			v->uret = va_arg(v->ap, unsigned int);
	}
	else
	{
		if ((format[v->i] == 'u') && v->length == l_h)
			v->uret = (short)va_arg(v->ap, unsigned int);
		if ((format[v->i] == 'u') && v->length == l_hh)
			v->uret = (char)va_arg(v->ap, unsigned int);
		if (((format[v->i] == 'u') && v->length == l_l) || format[v->i] == 'U')
			v->uret = va_arg(v->ap, unsigned long);
		if ((format[v->i] == 'u') && v->length == l_ll)
			v->uret = va_arg(v->ap, unsigned long long);
		if ((format[v->i] == 'u') && v->length == l_j)
			v->uret = va_arg(v->ap, uintmax_t);
		if ((format[v->i] == 'u') && v->length == l_z)
			v->uret = va_arg(v->ap, ssize_t);
	}
}
