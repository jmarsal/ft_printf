/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_conversion_U.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:19:24 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/13 15:21:51 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>
#include <string.h>

int	main(void)
{
	unsigned long	nb;
	int				ret;

	nb = 42;
	ret = ft_printf("%U\n", nb);
	ft_printf("%d\n", ret);
	nb = -42;
	ret = ft_printf("%U\n", nb);
	ft_printf("%d\n", ret);
	nb = INT_MIN;
	ret = ft_printf("%U\n", nb);
	ft_printf("%d\n", ret);
	nb = INT_MAX;
	ret = ft_printf("%U\n", nb);
	ft_printf("%d\n", ret);
	nb = ULONG_MAX;
	ret = ft_printf("%U\n", nb);
	ft_printf("%d\n", ret);

	//test with flags

	ret = ft_printf("%-8U\n", nb);
	ft_printf("%d\n", ret);
	ret = ft_printf("%08U\n", nb);
	ft_printf("%d\n", ret);
	return (0);
}
