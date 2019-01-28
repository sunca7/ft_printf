/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 10:35:50 by sunakim           #+#    #+#             */
/*   Updated: 2019/01/23 18:50:44 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_char(const char *format, t_var *v)
{
	int a;

	v->line = NULL;
	a = 0;
	while (format[v->i + a] != '\0' && format[v->i + a] != '%')
		a++;
	if (!(v->line = ft_memalloc(a + 1)))
		error();
	if (a != 0)
		ft_memcpy(v->line, &format[v->i], a);
	if (v->line != '\0')
		v->opt = write(1, &v->line[0], ft_strlen(v->line)) + v->opt;
	v->i = v->i + a;
}

int			ft_printf(const char *format, ...)
{
	t_var	v;
	int		cnt;

	cnt = ft_strlen(format);
	v.i = 0;
	v.opt = 0;
	ft_bzero(v.ap, sizeof(v.ap));
	va_start(v.ap, format);
	if (*format == '\0')
		return (0);
	while (v.i <= cnt)
	{
		ft_put_char(format, &v);
		if (format[v.i] == '%')
		{
			v.i++;
			parsing(format, &v);
		}
		v.i++;
	}
	va_end(v.ap);
	return (v.opt);
}
