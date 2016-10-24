/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_conversion_c.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 11:54:42 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/24 11:54:46 by jmarsal          ###   ########.fr       */
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
