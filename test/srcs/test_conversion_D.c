/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_conversion_D.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:19:46 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/05 15:14:39 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <string.h>

int	main(void)
{
	long int	nb;
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

	return (0);
}
