/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_conversion_D.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:19:24 by jmarsal           #+#    #+#             */
/*   Updated: 2016/08/31 01:18:42 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>
#include <string.h>

int	main(void)
{
	long int	nb;
	int			ret;

	// DioOuUxXcC
	nb = 42;
	ret = ft_printf("%D\n", nb);
	ft_printf("%d\n", ret);
	nb = -42;
	ret = ft_printf("%D\n", nb);
	ft_printf("%d\n", ret);
	nb = INT_MIN;
	ret = ft_printf("%D\n", nb);
	ft_printf("%d\n", ret);
	nb = INT_MAX;
	ret = ft_printf("%D\n", nb);
	ft_printf("%d\n", ret);
	nb = LONG_MAX;
	ret = ft_printf("%D\n", nb);
	ft_printf("%d\n", ret);
	return (0);
}
