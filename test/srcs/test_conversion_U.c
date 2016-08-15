/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_conversion_U.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:19:46 by jmarsal           #+#    #+#             */
/*   Updated: 2016/08/16 00:55:17 by jmarsal          ###   ########.fr       */
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
	printf("%lu\n", nb);
	nb = -42;
	printf("%lu\n", nb);
	nb = INT_MIN;
	printf("%lu\n", nb);
	nb = INT_MAX;
	printf("%lu\n", nb);
	return (0);
}
