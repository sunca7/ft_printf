/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:45:10 by sunakim           #+#    #+#             */
/*   Updated: 2019/01/28 15:13:45 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_malloc(t_var *v)
{
	if (!(v->str = (char*)malloc(sizeof(char) * (v->f.width + 1))))
		error();
	(v->str)[v->f.width] = '\0';
}

static void		ft_new_char(t_var *v)
{
	if (v->f.minus == 1)
		(v->str)[0] = v->iret;
	else
		(v->str)[v->f.width - 1] = v->iret;
}

static void		ft_var(const char *format, t_var *v)
{
	if (format[v->i] == 'c')
		v->iret = va_arg(v->ap, int);
}

void			ft_char(const char *format, t_var *v)
{
	ft_var(format, v);
	if (v->f.width == 0)
		v->f.width = 1;
	ft_malloc(v);
	ft_memset(v->str, ' ', v->f.width);
	ft_new_char(v);
}
