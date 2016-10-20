/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_conversion_D.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:19:24 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/20 23:10:58 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>
#include <string.h>

int	main(void)
{
	long int	nb;
	long int	nb2;
	int			ret;

	nb = 42;
	ret = ft_printf("%D\n", nb);
	ft_printf("%d\n", ret);
	nb = -42;
	ret = ft_printf("%D\n", nb);
	ft_printf("%d\n", ret);
	nb = INT_MIN;
	ret = ft_printf("%D\n", nb);
	ft_printf("%d\n", ret);
	nb = INT_MAX;
	ret = ft_printf("%D\n", nb);
	ft_printf("%d\n", ret);
	nb = LONG_MAX;
	ret = ft_printf("%D\n", nb);
	ft_printf("%d\n", ret);

	// test flags

	ret = ft_printf("%+D\n", LONG_MIN);
	ft_printf("%d\n", ret);
	ret = ft_printf("%+D\n", LONG_MAX);
	ft_printf("%d\n", ret);
	nb = -0;
	ret = ft_printf("%+D\n", nb);
	ft_printf("%d\n", ret);

	nb2 = 42;
	nb = ft_printf("%8D\n", nb2);
	ft_printf("%D\n", nb);
	nb = ft_printf("%-8D\n", nb2);
	ft_printf("%D\n", nb);
	nb = ft_printf("%08D\n", nb2);
	ft_printf("%D\n", nb);

	return (0);
}