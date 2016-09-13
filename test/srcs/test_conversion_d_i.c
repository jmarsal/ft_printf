/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_conversion_d_i.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:19:46 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/13 01:06:12 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	nb;
	int nb2;

	nb = printf("%d\n", 42);
	printf("%d\n", nb);
	nb = printf("%d\n", -42);
	printf("%d\n", nb);
	nb = printf("%d\n", INT_MIN);
	printf("%d\n", nb);
	nb = printf("%d\n", INT_MAX);
	printf("%d\n", nb);
	nb = printf("%i\n", 42);
	printf("%d\n", nb);
	nb = printf("%i\n", -42);
	printf("%d\n", nb);
	nb = printf("%i\n", INT_MIN);
	printf("%d\n", nb);
	nb = printf("%i\n", INT_MAX);
	printf("%d\n", nb);

	// test Flags caracters

	nb = printf("%+d\n", 0);
	printf("%d\n", nb);
	nb = printf("%+d\n", 42);
	printf("%d\n", nb);
	nb = printf("%+d\n", -42);
	printf("%d\n", nb);

	nb2 = 42;
	nb = printf("%8d\n", nb2);
	printf("%d\n", nb);
	nb = printf("%-8d\n", nb2);
	printf("%d\n", nb);
	nb = printf("%08d\n", nb2);
	printf("%d\n", nb);
	nb = printf("%+08d\n", nb2);
	printf("%d\n", nb);

	return (0);
}
