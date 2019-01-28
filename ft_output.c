/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:50:20 by sunakim           #+#    #+#             */
/*   Updated: 2019/01/28 16:17:02 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_output(const char *format, t_var *v)
{
	int fd;

	fd = 1;
	if (ft_strchr(CONVERT, format[v->i]))
	{
		(format[v->i] == 'd' || format[v->i] == 'i') ? ft_ditoa(format, v) : 0;
		(format[v->i] == 'u' || format[v->i] == 'U') ? ft_utoa(format, v) : 0;
		(format[v->i] == 'o') ? ft_otoa(format, v) : 0;
		(format[v->i] == 'x' || format[v->i] == 'X') ? ft_xtoa(format, v) : 0;
		(format[v->i] == 'c') ? ft_char(format, v) : 0;
		(format[v->i] == 's') ? ft_string(format, v) : 0;
		(format[v->i] == 'p') ? ft_pointer(format, v) : 0;
		(format[v->i] == 'f') ? ft_float(format, v) : 0;
		if (format[v->i] == 'c')
			v->opt = write(fd, v->str, v->f.width) + v->opt;
		else if (v->str != NULL)
			v->opt = write(fd, v->str, ft_strlen(v->str)) + v->opt;
	}
	else if (format[v->i] == '%')
	{
		ft_double_sharp(v);
		v->opt = write(fd, v->str, ft_strlen(v->str)) + v->opt;
	}
	else
		v->i--;
}
