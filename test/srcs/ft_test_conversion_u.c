/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_conversion_u.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:19:24 by jmarsal           #+#    #+#             */
/*   Updated: 2016/08/16 00:49:24 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>
#include <string.h>

int	main(void)
{
	unsigned int	nb;

	// DioOuUxXcC
	nb = 42;
	ft_printf("%u\n", nb);
	nb = -42;
	ft_printf("%u\n", nb);
	nb = INT_MIN;
	ft_printf("%u\n", nb);
	nb = INT_MAX;
	ft_printf("%u\n", nb);
	return (0);
}
