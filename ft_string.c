/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:45:21 by sunakim           #+#    #+#             */
/*   Updated: 2019/01/28 16:27:39 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_malloc(t_var *v)
{
	int	cnt;

	cnt = ft_strlen(v->cret);
	if (v->f.prec >= v->f.width)
		v->f.width = v->f.prec;
	if (v->f.prec <= 0 && cnt >= v->f.width)
		v->f.width = cnt;
	if (!(v->str = (char*)malloc(sizeof(char) * (v->f.width + 1))))
		error();
	(v->str)[v->f.width] = '\0';
}

static void		ft_new_string(t_var *v)
{
	int	cnt;

	ft_memset(v->str, ' ', v->f.width);
	cnt = ft_strlen(v->cret);
	if (v->f.prec >= 0)
		cnt = v->f.prec;
	cnt = v->f.width - cnt;
	if (v->f.minus == 1 || v->f.width == 0)
	{
		if (v->f.prec == 0)
			return ;
		if (v->f.prec != -1 && v->f.prec != 0)
			ft_strcpy_no_end(v->str, v->cret, v->f.prec);
		if (v->f.prec == -1)
			ft_strcpy_no_end(v->str, v->cret, 0);
	}
	else
	{
		if (v->f.prec == 0)
			return ;
		if (v->f.prec != -1 && v->f.prec != 0)
			ft_strcpy_no_end(&(v->str[cnt]), v->cret, v->f.prec);
		if (v->f.prec == -1)
			ft_strcpy_no_end(&(v->str[cnt]), v->cret, 0);
	}
}

static void		ft_var(const char *format, t_var *v)
{
	if (format[v->i] == 's')
		v->cret = va_arg(v->ap, char*);
}

void			ft_string(const char *format, t_var *v)
{
	int tmp;

	tmp = v->f.width;
	ft_var(format, v);
	if (v->cret == NULL)
	{
		v->cret = "(null)";
	}
	if (!(ft_strcmp(v->cret, "")) && tmp == 0)
		return ;
	ft_malloc(v);
	ft_memset(v->str, ' ', v->f.width);
	ft_new_string(v);
}
