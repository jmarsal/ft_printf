/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_conversion_u.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:19:46 by jmarsal           #+#    #+#             */
/*   Updated: 2016/08/31 17:26:31 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <string.h>

int	main(void)
{
	unsigned int	nb;
	int				ret;

	// DioOuUxXcC
	nb = 42;
	ret = printf("%u\n", nb);
	printf("%d\n", ret);
	nb = -42;
	ret = printf("%u\n", nb);
	printf("%d\n", ret);
	nb = INT_MIN;
	ret = printf("%u\n", nb);
	printf("%d\n", ret);
	nb = INT_MAX;
	ret = printf("%u\n", nb);
	printf("%d\n", ret);
	nb = UINT_MAX;
	ret = printf("%u\n", nb);
	printf("%d\n", ret);
	return (0);
}
