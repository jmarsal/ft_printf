/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_conversion_d_i.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:19:46 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/05 01:38:41 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	nb;

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
	return (0);
}
