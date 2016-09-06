/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_conversion_O.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:19:46 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/06 16:06:08 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <string.h>

int	main(void)
{
	unsigned long int	nb;
	int					ret;

	nb = 42;
	ret = printf("%lo\n", nb);
	printf("%d\n", ret);
	nb = -42;
	ret = printf("%lo\n", nb);
	printf("%d\n", ret);
	nb = LONG_MIN;
	ret = printf("%lo\n", nb);
	printf("%d\n", ret);
	nb = LONG_MAX;
	ret = printf("%lo\n", nb);
	printf("%d\n", ret);
	nb = INT_MAX;
	ret = printf("%lo\n", nb);
	printf("%d\n", ret);
	nb = INT_MIN;
	ret = printf("%lo\n", nb);
	printf("%d\n", ret);
	//with flags

	ret = printf("%08lo\n", nb);
	printf("%d\n", ret);
	ret = printf("%-8lo\n", nb);
	printf("%d\n", ret);
	ret = printf("%#lo\n", nb);
	printf("%d\n", ret);

	return (0);
}
