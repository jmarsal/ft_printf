/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_conversion_O.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:19:46 by jmarsal           #+#    #+#             */
/*   Updated: 2016/08/16 00:42:29 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <string.h>

int	main(void)
{
	unsigned long int	nb;

	// DioOuUxXcC
	nb = 42;
	printf("%lo\n", nb);
	nb = -42;
	printf("%lo\n", nb);
	nb = INT_MIN;
	printf("%lo\n", nb);
	nb = INT_MAX;
	printf("%lo\n", nb);
	return (0);
}
