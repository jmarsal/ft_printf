/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_conversion_o.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:19:46 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/06 16:05:43 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <string.h>

int	main(void)
{
	unsigned int	nb;
	int				ret;

	nb = 42;
	ret = printf("%o\n", nb);
	printf("%d\n", ret);
	nb = -42;
	ret = printf("%o\n", nb);
	printf("%d\n", ret);
	nb = INT_MAX;
	ret = printf("%o\n", nb);
	printf("%d\n", ret);
	nb = INT_MIN;
	ret = printf("%o\n", nb);
	printf("%d\n", ret);

	//with flags

	ret = printf("%08o\n", nb);
	printf("%d\n", ret);
	ret = printf("%-8o\n", nb);
	printf("%d\n", ret);
	ret = printf("%#o\n", nb);
	printf("%d\n", ret);
	return (0);
}
