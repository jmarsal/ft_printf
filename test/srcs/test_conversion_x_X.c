/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_conversion_x_X.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:19:46 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/20 15:39:53 by jmarsal          ###   ########.fr       */
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
	return (0);
}
