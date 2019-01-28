/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:02:22 by sunakim           #+#    #+#             */
/*   Updated: 2018/11/19 19:58:56 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		cnt;
	int		i;
	char	*str;

	cnt = ft_strlen(src);
	if (!(str = (char *)malloc(sizeof(char) * (cnt + 1))))
		return (0);
	if (src == '\0')
	{
		*str = '\0';
		return (str);
	}
	i = 0;
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
