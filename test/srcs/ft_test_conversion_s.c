/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_conversion_s.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:19:24 by jmarsal           #+#    #+#             */
/*   Updated: 2016/08/21 23:34:12 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int nb1;

	nb1 = ft_printf("Hello%s%s world\n", " World !\n", "I am so happy");
	ft_printf("%d\n", nb1);

	nb1 = ft_printf("%s", "Hello World !\n");
	ft_printf("%d\n", nb1);

	nb1 = ft_printf("\n\n%s%s", "Hello World !\n", "C'est la fete !\n");
	ft_printf("%d\n", nb1);

	nb1 = ft_printf("\n\n%s%s%%%%%s", "Justine et jolie\n", "Antoine aussi!\n", "mon ange evidemment !\n");
	ft_printf("%d\n", nb1);

	nb1 = ft_printf("%%\n");
	ft_printf("%d\n", nb1);

	nb1 = ft_printf("Hello World\n");
	ft_printf("%d\n", nb1);

	nb1 = ft_printf("%%%s", "Hello World !\n");
	ft_printf("%d\n", nb1);
	return (0);
}
