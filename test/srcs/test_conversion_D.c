/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_conversion_D.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:19:46 by jmarsal           #+#    #+#             */
/*   Updated: 2016/08/16 00:25:36 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <string.h>

int	main(void)
{
	size_t	nb;

	// DioOuUxXcC
	nb = 42;
	printf("%ld\n", nb);
	nb = -42;
	printf("%ld\n", nb);
	nb = INT_MIN;
	printf("%ld\n", nb);
	nb = INT_MAX;
	printf("%ld\n", nb);
	return (0);
}
