/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_conversion_x_X.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:19:46 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/07 01:42:32 by jmarsal          ###   ########.fr       */
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
	return (0);
}
