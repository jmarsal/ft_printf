/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_conversion_c.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:19:24 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/11 12:57:51 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	int	nb;
	nb = ft_printf("%c\n", 42);
	ft_printf("%d\n", nb);

	nb = ft_printf("%c\n", -42);
	ft_printf("%d\n", nb);

	nb = ft_printf("%c\n", 0);
	ft_printf("%d\n", nb);

	nb = ft_printf("%c\n", 100);
	ft_printf("%d\n", nb);

	nb = ft_printf("%c\n", 127);
	ft_printf("%d\n", nb);

	nb = ft_printf("%c\n", 'Y');
	ft_printf("%d\n", nb);

	return (0);
}
