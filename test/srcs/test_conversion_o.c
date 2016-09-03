/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_conversion_O.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:19:46 by jmarsal           #+#    #+#             */
/*   Updated: 2016/08/31 00:50:45 by jmarsal          ###   ########.fr       */
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
	return (0);
}
