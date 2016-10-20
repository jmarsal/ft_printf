/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_conversion_O.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:19:24 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/20 23:11:41 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>
#include <string.h>

int	main(void)
{
	unsigned long int	nb;
	int					ret;

	nb = 42;
	ret = ft_printf("%O\n", nb);
	ft_printf("%d\n", ret);
	nb = -42;
	ret = ft_printf("%O\n", nb);
	ft_printf("%d\n", ret);
	nb = LONG_MIN;
	ret = ft_printf("%O\n", nb);
	ft_printf("%d\n", ret);
	nb = LONG_MAX;
	ret = ft_printf("%O\n", nb);
	ft_printf("%d\n", ret);
	nb = INT_MAX;
	ret = ft_printf("%O\n", nb);
	ft_printf("%d\n", ret);
	nb = INT_MIN;
	ret = ft_printf("%O\n", nb);
	ft_printf("%d\n", ret);

	//with flags

	ret = ft_printf("%08O\n", nb);
	ft_printf("%d\n", ret);
	ret = ft_printf("%-8O\n", nb);
	ft_printf("%d\n", ret);
	ret = ft_printf("%#O\n", nb);
	ft_printf("%d\n", ret);
	return (0);
}