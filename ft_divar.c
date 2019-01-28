/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_divar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:00:15 by sunakim           #+#    #+#             */
/*   Updated: 2019/01/25 11:29:39 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_divar(const char *format, t_var *v)
{
	if (v->length == l_zero)
	{
		if (format[v->i] == 'd' || format[v->i] == 'i')
			v->ret = va_arg(v->ap, int);
	}
	else
	{
		if ((format[v->i] == 'd' || format[v->i] == 'i') && v->length == l_h)
			v->ret = (short)va_arg(v->ap, int);
		if ((format[v->i] == 'd' || format[v->i] == 'i') && v->length == l_hh)
			v->ret = (char)va_arg(v->ap, int);
		if ((format[v->i] == 'd' || format[v->i] == 'i') && v->length == l_l)
			v->ret = va_arg(v->ap, long int);
		if ((format[v->i] == 'd' || format[v->i] == 'i') && v->length == l_ll)
			v->ret = va_arg(v->ap, long long int);
		if ((format[v->i] == 'd' || format[v->i] == 'i') && v->length == l_j)
			v->ret = va_arg(v->ap, intmax_t);
		if ((format[v->i] == 'd' || format[v->i] == 'i') && v->length == l_z)
			v->ret = va_arg(v->ap, ssize_t);
	}
}
