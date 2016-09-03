/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_conversion_c.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:19:24 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/03 17:00:34 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../includes/ft_printf.h"
#include <limits.h>
#include "libft.h"

int	main(void)
{
	int	nb;
	// DioOuUxXcC
	nb = ft_printf("%c\n", 42);
	ft_printf("%d\n", nb);

	nb = ft_printf("%c\n", -42);
	ft_printf("%d\n", nb);

	nb = ft_printf("%c\n", 0);
	ft_printf("%d\n", nb);

	nb = ft_printf("%c\n", 100);
	ft_printf("%d\n", nb);

	nb = ft_printf("%c\n", 255);
	ft_printf("%d\n", nb);

	nb = ft_printf("%c\n", 'Y');
	ft_printf("%d\n", nb);

	return (0);
}
