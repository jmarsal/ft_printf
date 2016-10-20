/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_conversion_x_X.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:19:46 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/20 23:16:21 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <string.h>

int	main(void)
{
	unsigned int	nb;
	int				ret;

	nb = 42;
	ret = printf("%x\n", nb);
	printf("%d\n", ret);

	nb = -42;
	ret = printf("%x\n", nb);
	printf("%d\n", ret);

	nb = INT_MIN;
	ret = printf("%x\n", nb);
	printf("%d\n", ret);

	nb = INT_MAX;
	ret = printf("%x\n", nb);
	printf("%d\n", ret);

	nb = 42;
	ret = printf("%X\n", nb);
	printf("%d\n", ret);

	nb = -42;
	ret = printf("%X\n", nb);
	printf("%d\n", ret);

	nb = INT_MIN;
	ret = printf("%X\n", nb);
	printf("%d\n", ret);

	nb = INT_MAX;
	ret = printf("%X\n", nb);
	printf("%d\n", ret);

	// test with flags

	ret = printf("%-8x\n", nb);
	printf("%d\n", ret);
	ret = printf("%08x\n", nb);
	printf("%d\n", ret);
	ret = printf("%-8X\n", nb);
	printf("%d\n", ret);
	ret = printf("%08X\n", nb);
	printf("%d\n", ret);

	ret = printf("%#x\n", nb);
	printf("%d\n", ret);
	ret = printf("%#X\n", nb);
	printf("%d\n", ret);
	ret = printf("%#8x\n", nb);
	printf("%d\n", ret);
	ret = printf("%-#8x\n", nb);
	printf("%d\n", ret);
	ret = printf("%#8X\n", nb);
	printf("%d\n", ret);
	ret = printf("%-#8X\n", nb);
	printf("%d\n", ret);

	// test precision

	ret = printf("%#-8.0X\n", nb);
	printf("%d\n", ret);
	ret = printf("%#-8.1X\n", nb);
	printf("%d\n", ret);
	ret = printf("%#-8.2X\n", nb);
	printf("%d\n", ret);
	ret = printf("%#-8.3X\n", nb);
	printf("%d\n", ret);
	ret = printf("%#-8.4X\n", nb);
	printf("%d\n", ret);
	ret = printf("%#-8.5X\n", nb);
	printf("%d\n", ret);
	ret = printf("%#-8.6X\n", nb);
	printf("%d\n", ret);
	ret = printf("%#-8.7X\n", nb);
	printf("%d\n", ret);
	ret = printf("%#-8.8X\n", nb);
	printf("%d\n", ret);

	// test with modifier

	ret = printf("%hhx\n", (char)2147483649051561567);
	printf("%d\n", ret);
	ret = printf("%hx\n", (short)2147483649051561567);
	printf("%d\n", ret);
	ret = printf("%x\n", (int)2147483649051561567);
	printf("%d\n", ret);
	ret = printf("%lx\n", (long)2147483649051561567);
	printf("%d\n", ret);
	ret = printf("%llx\n", (long long)2147483649051561567);
	printf("%d\n", ret);
	ret = printf("%hhX\n", (char)2147483649051561567);
	printf("%d\n", ret);
	ret = printf("%hX\n", (short)2147483649051561567);
	printf("%d\n", ret);
	ret = printf("%X\n", (int)2147483649051561567);
	printf("%d\n", ret);
	ret = printf("%lX\n", (long)2147483649051561567);
	printf("%d\n", ret);
	ret = printf("%llX\n", (long long)2147483649051561567);
	printf("%d\n", ret);

	nb = printf("%#-8.8hhx\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-8.8hx\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-8.8x\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-8.8lx\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-8.8llx\n", (long long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-8.8hhX\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-8.8hX\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-8.8X\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-8.8lX\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-8.8llX\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

	nb = printf("%#-8.8hhx\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-8.8hx\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-8.8x\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-8.8lx\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-8.8llx\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

	nb = printf("%#-16.8hhx\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-16.8hx\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-16.8x\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-16.8lx\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-16.8llx\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

	nb = printf("%#-8.16hhx\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-8.16hx\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-8.16x\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-8.16lx\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-8.16llx\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

	nb = printf("%-8.8hhx\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.8hx\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.8x\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.8lx\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.8llx\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

	nb = printf("%-16.8hhx\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-16.8hx\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-16.8x\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-16.8lx\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-16.8llx\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

	nb = printf("%-8.16hhx\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.16hx\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.16x\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.16lx\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.16llx\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

	nb = printf("%#8.8hhx\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#8.8hx\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#8.8x\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#8.8lx\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#8.8llx\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

	nb = printf("%#16.8hhx\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#16.8hx\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#16.8x\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#16.8lx\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#16.8llx\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

	nb = printf("%#8.16hhx\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#8.16hx\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#8.16x\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#8.16lx\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#8.16llx\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

	nb = printf("%#-8.8hhX\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-8.8hX\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-8.8X\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-8.8lX\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-8.8llX\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

	nb = printf("%#-16.8hhX\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-16.8hX\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-16.8X\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-16.8lX\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-16.8llX\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

	nb = printf("%#-8.16hhX\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-8.16hX\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-8.16X\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-8.16lX\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-8.16llX\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

	nb = printf("%-8.8hhX\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.8hX\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.8X\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.8lX\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.8llX\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

	nb = printf("%-16.8hhX\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-16.8hX\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-16.8X\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-16.8lX\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-16.8llX\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

	nb = printf("%-8.16hhX\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.16hX\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.16X\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.16lX\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.16llX\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

	nb = printf("%#8.8hhX\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#8.8hX\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#8.8X\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#8.8lX\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#8.8llX\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

	nb = printf("%#16.8hhX\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#16.8hX\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#16.8X\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#16.8lX\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#16.8llX\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

	nb = printf("%#8.16hhX\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#8.16hX\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#8.16X\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#8.16lX\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#8.16llX\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

	nb = printf("%#16.8hhx%#16.8hhx\n", (char)-2147483649051561567, (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#16.8hx\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#16.8x\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#16.8lx\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#16.8llx\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

	return (0);
}