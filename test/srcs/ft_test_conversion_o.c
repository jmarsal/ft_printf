/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_conversion_o.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:19:24 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/06 16:05:13 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>
#include <string.h>

int	main(void)
{
	unsigned int	nb;
	int				ret;

	nb = 42;
	ret = ft_printf("%o\n", nb);
	ft_printf("%d\n", ret);
	nb = -42;
	ret = ft_printf("%o\n", nb);
	ft_printf("%d\n", ret);
	nb = INT_MAX;
	ret = ft_printf("%o\n", nb);
	ft_printf("%d\n", ret);
	nb = INT_MIN;
	ret = ft_printf("%o\n", nb);
	ft_printf("%d\n", ret);

	//with flags

	ret = ft_printf("%08o\n", nb);
	ft_printf("%d\n", ret);
	ret = ft_printf("%-8o\n", nb);
	ft_printf("%d\n", ret);
	ret = ft_printf("%#o\n", nb);
	ft_printf("%d\n", ret);
	return (0);
}
