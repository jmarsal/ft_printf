/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_conversion_x_X.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:19:24 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/29 02:08:54 by jmarsal          ###   ########.fr       */
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

	nb = ft_printf("%#-8.8hhx\n", (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-8.8hx\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-8.8x\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-8.8lx\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-8.8llx\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-8.8hhX\n", (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-8.8hX\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-8.8X\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-8.8lX\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-8.8llX\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);

	nb = ft_printf("%#-8.8hhx\n", (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-8.8hx\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-8.8x\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-8.8lx\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-8.8llx\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);

	nb = ft_printf("%#-16.8hhx\n", (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-16.8hx\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-16.8x\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-16.8lx\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-16.8llx\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);

	nb = ft_printf("%#-8.16hhx\n", (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-8.16hx\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-8.16x\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-8.16lx\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-8.16llx\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);

	nb = ft_printf("%-8.8hhx\n", (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.8hx\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.8x\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.8lx\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.8llx\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);

	nb = ft_printf("%-16.8hhx\n", (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-16.8hx\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-16.8x\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-16.8lx\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-16.8llx\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);

	nb = ft_printf("%-8.16hhx\n", (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.16hx\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.16x\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.16lx\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.16llx\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);

	nb = ft_printf("%#8.8hhx\n", (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#8.8hx\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#8.8x\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#8.8lx\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#8.8llx\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);

	nb = ft_printf("%#16.8hhx\n", (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#16.8hx\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#16.8x\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#16.8lx\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#16.8llx\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);

	nb = ft_printf("%#8.16hhx\n", (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#8.16hx\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#8.16x\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#8.16lx\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#8.16llx\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);

	nb = ft_printf("%#-8.8hhX\n", (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-8.8hX\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-8.8X\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-8.8lX\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-8.8llX\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);

	nb = ft_printf("%#-16.8hhX\n", (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-16.8hX\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-16.8X\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-16.8lX\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-16.8llX\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);

	nb = ft_printf("%#-8.16hhX\n", (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-8.16hX\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-8.16X\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-8.16lX\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-8.16llX\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);

	nb = ft_printf("%-8.8hhX\n", (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.8hX\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.8X\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.8lX\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.8llX\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);

	nb = ft_printf("%-16.8hhX\n", (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-16.8hX\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-16.8X\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-16.8lX\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-16.8llX\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);

	nb = ft_printf("%-8.16hhX\n", (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.16hX\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.16X\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.16lX\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.16llX\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);

	nb = ft_printf("%#8.8hhX\n", (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#8.8hX\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#8.8X\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#8.8lX\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#8.8llX\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);

	nb = ft_printf("%#16.8hhX\n", (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#16.8hX\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#16.8X\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#16.8lX\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#16.8llX\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);

	nb = ft_printf("%#8.16hhX\n", (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#8.16hX\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#8.16X\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#8.16lX\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#8.16llX\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);

	nb = ft_printf("%#16.8hhx%#16.8hhx\n", (char)-2147483649051561567, (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#16.8hx\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#16.8x\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#16.8lx\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#16.8llx\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);

	nb = ft_printf("%10x", 42);
	ft_printf("%d\n", nb);
	nb = ft_printf("%2x", 542);
	ft_printf("%d\n", nb);

	return (0);
}