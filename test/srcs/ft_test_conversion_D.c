/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_conversion_D.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:19:24 by jmarsal           #+#    #+#             */
/*   Updated: 2016/08/16 00:25:47 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>
#include <string.h>

int	main(void)
{
	size_t	nb;

	// DioOuUxXcC
	nb = 42;
	ft_printf("%D\n", nb);
	nb = -42;
	ft_printf("%D\n", nb);
	nb = INT_MIN;
	ft_printf("%D\n", nb);
	nb = INT_MAX;
	ft_printf("%D\n", nb);
	return (0);
}
