/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_conversion_U.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:19:46 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/06 15:15:52 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <string.h>

int	main(void)
{
	unsigned long	nb;
	int				ret;

	// DioOuUxXcC
	nb = 42;
	ret = printf("%lu\n", nb);
	printf("%d\n", ret);
	nb = -42;
	ret = printf("%lu\n", nb);
	printf("%d\n", ret);
	nb = INT_MIN;
	ret = printf("%lu\n", nb);
	printf("%d\n", ret);
	nb = INT_MAX;
	ret = printf("%lu\n", nb);
	printf("%d\n", ret);
	nb = ULONG_MAX;
	ret = printf("%lu\n", nb);
	printf("%d\n", ret);

	//test with flags

	ret = printf("%-8lu\n", nb);
	printf("%d\n", ret);
	ret = printf("%08lu\n", nb);
	printf("%d\n", ret);
}
