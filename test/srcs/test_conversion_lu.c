/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_conversion_lu.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 12:10:54 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/24 12:10:56 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <string.h>

int	main(void)
{
	unsigned long	nb;
	int				ret;

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