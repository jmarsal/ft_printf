/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_conversion_D.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:19:46 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/06 01:39:05 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <string.h>

int	main(void)
{
	long int	nb;
	long int	nb2;
	int			ret;

	// DioOuUxXcC
	nb = 42;
	ret = printf("%ld\n", nb);
	printf("%d\n", ret);
	nb = -42;
	ret = printf("%ld\n", nb);
	printf("%d\n", ret);
	nb = INT_MIN;
	ret = printf("%ld\n", nb);
	printf("%d\n", ret);
	nb = INT_MAX;
	ret = printf("%ld\n", nb);
	printf("%d\n", ret);
	nb = LONG_MAX;
	ret = printf("%ld\n", nb);
	printf("%d\n", ret);

	// test flags

	ret = printf("%+ld\n", LONG_MIN);
	printf("%d\n", ret);
	ret = printf("%+ld\n", LONG_MAX);
	printf("%d\n", ret);
	nb = -0;
	ret = printf("%+ld\n", nb);
	printf("%d\n", ret);

	nb2 = 42;
	nb = printf("%8ld\n", nb2);
	printf("%ld\n", nb);
	nb = printf("%-8ld\n", nb2);
	printf("%ld\n", nb);
	nb = printf("%08ld\n", nb2);
	printf("%ld\n", nb);

	return (0);
}
