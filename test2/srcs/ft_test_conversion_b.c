/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_conversion_b.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 16:32:12 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/11 12:57:40 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	int	nb;
	int nb1;

	nb = 42;
	nb1 = ft_printf("%b\n", nb);
	ft_printf("%d\n", nb1);

	nb = INT_MAX;
	nb1 = ft_printf("%b\n", nb);
	ft_printf("%d\n", nb1);

	nb = INT_MIN;
	nb1 = ft_printf("%b\n", nb);
	ft_printf("%d\n", nb1);

	return (0);
}
