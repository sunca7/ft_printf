/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 10:45:23 by sunakim           #+#    #+#             */
/*   Updated: 2019/01/28 17:29:54 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_precision(const char *format, t_var *v)
{
	if (format[v->i] == '*')
	{
		v->f.prec = va_arg(v->ap, unsigned int);
		v->i++;
	}
	else if (format[v->i] >= '0' && format[v->i] <= '9')
	{
		v->f.prec = ft_atoi(&(format[v->i]));
		while (format[v->i] >= '0' && format[v->i] <= '9')
			v->i++;
	}
	else
		v->f.prec = 0;
}

static void		ft_width(const char *format, t_var *v)
{
	if (format[v->i] >= '1' && format[v->i] <= '9')
	{
		(v->f).width = ft_atoi(&(format[v->i]));
		while (format[v->i] >= '0' && format[v->i] <= '9')
			v->i++;
		v->i--;
	}
}

static void		ft_length(const char *format, t_var *v)
{
	if (format[v->i] == 'h' && v->length == l_zero && format[v->i + 1] != 'h')
	{
		v->length = l_h;
		v->i++;
	}
	if (format[v->i] == 'h' && format[v->i + 1] == 'h')
	{
		v->length = l_hh;
		v->i = v->i + 2;
	}
	if (format[v->i] == 'l' && v->length == l_zero && format[v->i + 1] != 'l')
	{
		v->length = l_l;
		v->i++;
	}
	if (format[v->i] == 'l' && format[v->i + 1] == 'l')
	{
		v->length = l_ll;
		v->i = v->i + 2;
	}
	if (format[v->i] == 'L' && v->length == l_zero)
	{
		v->length = l_L;
		v->i++;
	}
	if (format[v->i] == 'j' && v->length == l_zero)
	{
		v->length = l_j;
		v->i++;
	}
	if (format[v->i] == 'z' && v->length == l_zero)
	{
		v->length = l_z;
		v->i++;
	}
}

static void		ft_flags(const char *format, t_var *v)
{
	flags_init(v);
	while (ft_strchr(FLAGS, format[v->i]))
	{
		((format[v->i] == '-')) ? (v->f.minus = 1) : (0);
		((format[v->i] == '+')) ? (v->f.plus = 1) : (0);
		((format[v->i] == ' ')) ? (v->f.space = 1) : (0);
		((format[v->i] == '#')) ? (v->f.sharp = 1) : (0);
		((format[v->i] == '0')) ? (v->f.zero = 1) : (0);
		((format[v->i] == '*')) ? (v->f.width = va_arg(v->ap, int)) : (0);
		if (format[v->i] >= '1' && format[v->i] <= '9')
			ft_width(format, v);
		if (format[v->i] == '.')
			break ;
		else
			v->i++;
	}
	if (format[v->i] == '.')
	{
		v->i++;
		ft_precision(format, v);
	}
	ft_length(format, v);
	ft_excep(format, v);
}

void			parsing(const char *format, t_var *v)
{
	ft_flags(format, v);
	ft_output(format, v);
}
