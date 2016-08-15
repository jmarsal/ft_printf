/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_conversion_d_i.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:19:24 by jmarsal           #+#    #+#             */
/*   Updated: 2016/08/16 00:32:17 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	// DioOuUxXcC
	ft_printf("%d\n", 42);
	ft_printf("%d\n", -42);
	ft_printf("%d\n", INT_MIN);
	ft_printf("%d\n", INT_MAX);
	ft_printf("%i\n", 42);
	ft_printf("%i\n", -42);
	ft_printf("%i\n", INT_MIN);
	ft_printf("%i\n", INT_MAX);
	return (0);
}
