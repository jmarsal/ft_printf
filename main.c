/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 01:24:50 by jmarsal           #+#    #+#             */
/*   Updated: 2016/08/27 01:47:47 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int main()
{
	int nb;
	int nb1;
	int nb2;
	int ret;
	int *p;
	char test;
	char *so;

	// p = &nb;
	// ret = ft_printf("%p\n", p);
	// // ft_printf("%d\n", ret);
	//
	// ret = printf("%p\n", p);
	// // printf("%d\n", ret);

	nb = 42;

	printf("%o\n", nb);
	ft_putstr(ft_itoa_base(nb, 8));
	ft_putchar('\n');
	// p = &nb;
	// nb1 = ft_printf("%p\n", p);
	// ft_printf("%d\n", nb1);
	//
	// nb2 = printf("%p\n", p);
	// printf("%d\n", nb2);
	//
	// so = &test;
	// nb1 = ft_printf("%p\n", so);
	// ft_printf("%d\n", nb1);
	//
	// nb2 = printf("%p\n", so);
	// printf("%d\n", nb2);

	// nb1 = ft_printf("%b\n", "Hello World");
	// ft_printf("%d\n", nb1);

return (0);
}
