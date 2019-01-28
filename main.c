/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 10:39:35 by sunakim           #+#    #+#             */
/*   Updated: 2019/01/28 18:27:39 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
int main ()
{
//	int i;
//	int	*nbr = NULL;
//	char *str = "wtf";
//	int cnt;
//	ft_printf("%lld", -9223372036854775808);
//	ft_printf(" %%\n  %%%\n  %%%%\n  %ld %hhd %lld %Lf %f %lf %lu\n", LONG_MAX, CHAR_MAX, LLONG_MAX, 0.127491L, 128045.8011, 0.000124, ULONG_MAX);
//	ft_printf("%.2s is a string\n", "");
//	ft_printf("%d\n", -1);
//	printf("printf : %8.0s, %.0ld %hhd %lld %Lf %f %lf %lu\n", str, LONG_MAX, CHAR_MAX, LLONG_MAX, 0.127491L, 128045.8011, 0.000124, ULONG_MAX);

ft_printf("\n");
  ft_printf("%%\n");
  ft_printf("%d\n", 42);
  ft_printf("%d%d\n", 42, 41);
  ft_printf("%d%d%d\n", 42, 43, 44);
  ft_printf("%ld\n", 2147483647);
  ft_printf("%lld\n", 9223372036854775807);
  ft_printf("%x\n", 505);
  ft_printf("%X\n", 505);
  ft_printf("%p\n", &ft_printf);
  ft_printf("%20.15d\n", 54321);
  ft_printf("%-10d\n", 3);
  ft_printf("% d\n", 3);
  ft_printf("%+d\n", 3);
  ft_printf("%010d\n", 1);
  ft_printf("%hhd\n", 0);
  ft_printf("%jd\n", 9223372036854775807);
  ft_printf("%zd\n", 4294967295);
  ft_printf("%\n");
  ft_printf("%U\n", 4294967295);
  ft_printf("%u\n", 4294967295);
  ft_printf("%o\n", 40);
  ft_printf("%%#08x\n", 42);
  ft_printf("%x\n", 1000);
  ft_printf("%#X\n", 1000);
  ft_printf("%s\n", NULL);
  ft_printf("%S\n", L"ݗݜशব");
  ft_printf("%s%s\n", "test", "test");
  ft_printf("%s%s%s\n", "test", "test", "test");
  ft_printf("%C\n", 15000);
//  while (1);
  return (0);
}
