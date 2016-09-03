/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_conversion_c.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:19:46 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/03 17:01:02 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	nb;
	// DioOuUxXcC
	nb = printf("%c\n", 42);
	printf("%d\n", nb);

	nb = printf("%c\n", -42);
	printf("%d\n", nb);

	nb = printf("%c\n", 0);
	printf("%d\n", nb);

	nb = printf("%c\n", 100);
	printf("%d\n", nb);

	nb = printf("%c\n", 255);
	printf("%d\n", nb);

	nb = printf("%c\n", 'Y');
	printf("%d\n", nb);

	return (0);
}
