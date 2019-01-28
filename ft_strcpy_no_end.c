/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_no_end.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:00:01 by sunakim           #+#    #+#             */
/*   Updated: 2019/01/24 15:03:01 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy_no_end(char *dst, const char *src, int cnt)
{
	int i;

	i = 0;
	if (cnt == 0)
	{
		while (src[i])
		{
			dst[i] = src[i];
			i++;
		}
	}
	else
	{
		while (i < cnt && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
	}
	return (dst);
}
