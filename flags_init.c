/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:49:35 by sunakim           #+#    #+#             */
/*   Updated: 2019/01/28 12:03:06 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		flags_init(t_var *v)
{
	v->f.minus = 0;
	v->f.plus = 0;
	v->f.space = 0;
	v->f.sharp = 0;
	v->f.zero = 0;
	v->f.prec = -1;
	v->f.width = 0;
	v->f.star = 0;
	v->length = l_zero;
	v->sign = 0;
	v->ret = 0;
	v->cret = 0;
	v->iret = 0;
	v->uret = 0;
	v->pret = 0;
	v->fret = 0;
	v->f_fret = 0;
	v->s_fret = 0;
	v->chr = '\0';
	v->str = NULL;
	v->line = NULL;
}
