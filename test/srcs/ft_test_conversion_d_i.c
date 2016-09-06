/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_conversion_d_i.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:19:24 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/06 00:58:33 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	int	nb;
	int nb2;

	nb = ft_printf("%d\n", 42);
	ft_printf("%d\n", nb);
	nb = ft_printf("%d\n", -42);
	ft_printf("%d\n", nb);
	nb = ft_printf("%d\n", INT_MIN);
	ft_printf("%d\n", nb);
	nb = ft_printf("%d\n", INT_MAX);
	ft_printf("%d\n", nb);
	nb = ft_printf("%i\n", 42);
	ft_printf("%d\n", nb);
	nb = ft_printf("%i\n", -42);
	ft_printf("%d\n", nb);
	nb = ft_printf("%i\n", INT_MIN);
	ft_printf("%d\n", nb);
	nb = ft_printf("%i\n", INT_MAX);
	ft_printf("%d\n", nb);

	// test Flags caracters

	nb = ft_printf("%+d\n", 0);
	ft_printf("%d\n", nb);
	nb = ft_printf("%+d\n", 42);
	ft_printf("%d\n", nb);
	nb = ft_printf("%+d\n", -42);
	ft_printf("%d\n", nb);

	nb2 = 42;
	nb = ft_printf("%8d\n", nb2);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8d\n", nb2);
	ft_printf("%d\n", nb);
	nb = ft_printf("%08d\n", nb2);
	ft_printf("%d\n", nb);

	return (0);
}
