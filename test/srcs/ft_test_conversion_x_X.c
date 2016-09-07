/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_conversion_x_X.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:19:24 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/07 01:43:14 by jmarsal          ###   ########.fr       */
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
	ret = ft_printf("%x\n", nb);
	ft_printf("%d\n", ret);

	nb = -42;
	ret = ft_printf("%x\n", nb);
	ft_printf("%d\n", ret);

	nb = INT_MIN;
	ret = ft_printf("%x\n", nb);
	ft_printf("%d\n", ret);

	nb = INT_MAX;
	ret = ft_printf("%x\n", nb);
	ft_printf("%d\n", ret);

	nb = 42;
	ret = ft_printf("%X\n", nb);
	ft_printf("%d\n", ret);

	nb = -42;
	ret = ft_printf("%X\n", nb);
	ft_printf("%d\n", ret);

	nb = INT_MIN;
	ret = ft_printf("%X\n", nb);
	ft_printf("%d\n", ret);

	nb = INT_MAX;
	ret = ft_printf("%X\n", nb);
	ft_printf("%d\n", ret);

	// test with flags

	ret = ft_printf("%-8x\n", nb);
	ft_printf("%d\n", ret);
	ret = ft_printf("%08x\n", nb);
	ft_printf("%d\n", ret);
	ret = ft_printf("%-8X\n", nb);
	ft_printf("%d\n", ret);
	ret = ft_printf("%08X\n", nb);
	ft_printf("%d\n", ret);

	ret = ft_printf("%#x\n", nb);
	ft_printf("%d\n", ret);
	ret = ft_printf("%#X\n", nb);
	ft_printf("%d\n", ret);
	ret = ft_printf("%#8x\n", nb);
	ft_printf("%d\n", ret);
	ret = ft_printf("%-#8x\n", nb);
	ft_printf("%d\n", ret);
	ret = ft_printf("%#8X\n", nb);
	ft_printf("%d\n", ret);
	ret = ft_printf("%-#8X\n", nb);
	ft_printf("%d\n", ret);

	return (0);
}
