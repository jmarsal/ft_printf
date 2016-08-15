/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_conversion_x_X.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:19:46 by jmarsal           #+#    #+#             */
/*   Updated: 2016/08/16 00:59:04 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <string.h>

int	main(void)
{
	unsigned int	nb;

	// DioOuUxXcC
	nb = 42;
	printf("%x\n", nb);
	nb = -42;
	printf("%x\n", nb);
	nb = INT_MIN;
	printf("%x\n", nb);
	nb = INT_MAX;
	printf("%x\n", nb);
	nb = 42;
	printf("%X\n", nb);
	nb = -42;
	printf("%X\n", nb);
	nb = INT_MIN;
	printf("%X\n", nb);
	nb = INT_MAX;
	printf("%X\n", nb);
	return (0);
}
