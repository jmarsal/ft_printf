/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_conversion_x_X.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:19:24 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/20 15:40:07 by jmarsal          ###   ########.fr       */
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

	// test precision

	ret = ft_printf("%#-8.0X\n", nb);
	ft_printf("%d\n", ret);
	ret = ft_printf("%#-8.1X\n", nb);
	ft_printf("%d\n", ret);
	ret = ft_printf("%#-8.2X\n", nb);
	ft_printf("%d\n", ret);
	ret = ft_printf("%#-8.3X\n", nb);
	ft_printf("%d\n", ret);
	ret = ft_printf("%#-8.4X\n", nb);
	ft_printf("%d\n", ret);
	ret = ft_printf("%#-8.5X\n", nb);
	ft_printf("%d\n", ret);
	ret = ft_printf("%#-8.6X\n", nb);
	ft_printf("%d\n", ret);
	ret = ft_printf("%#-8.7X\n", nb);
	ft_printf("%d\n", ret);
	ret = ft_printf("%#-8.8X\n", nb);
	ft_printf("%d\n", ret);

	// test with modifier

	ret = ft_printf("%hhx\n", (char)2147483649051561567);
	ft_printf("%d\n", ret);
	ret = ft_printf("%hx\n", (short)2147483649051561567);
	ft_printf("%d\n", ret);
	ret = ft_printf("%x\n", (int)2147483649051561567);
	ft_printf("%d\n", ret);
	ret = ft_printf("%lx\n", (long)2147483649051561567);
	ft_printf("%d\n", ret);
	ret = ft_printf("%llx\n", (long long)2147483649051561567);
	ft_printf("%d\n", ret);
	ret = ft_printf("%hhX\n", (char)2147483649051561567);
	ft_printf("%d\n", ret);
	ret = ft_printf("%hX\n", (short)2147483649051561567);
	ft_printf("%d\n", ret);
	ret = ft_printf("%X\n", (int)2147483649051561567);
	ft_printf("%d\n", ret);
	ret = ft_printf("%lX\n", (long)2147483649051561567);
	ft_printf("%d\n", ret);
	ret = ft_printf("%llX\n", (long long)2147483649051561567);
	ft_printf("%d\n", ret);

	return (0);
}
