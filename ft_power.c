/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 11:29:22 by sunakim           #+#    #+#             */
/*   Updated: 2019/01/23 15:09:40 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double	ft_power(long long int itmp, int prec, t_var *v)
{
	int			i;
	long double	result;

	result = (long double)itmp;
	i = 0;
	while (i < prec)
	{
		result = result / 10;
		i++;
	}
	if (v->fret < 0)
		result = result * -1;
	return (result);
}
