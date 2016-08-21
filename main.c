/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 01:24:50 by jmarsal           #+#    #+#             */
/*   Updated: 2016/08/22 01:56:39 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int main()
{
	int nb;
	int nb1;
	int nb2;

	// nb1 = ft_printf("Hello%s%s world\n", " World !\n", "I am so happy");
	// nb2 = printf("Hello%s%s world\n", " World !\n", "I am so happy");
	// ft_printf("%d\n", nb1);
	// printf("%d\n", nb1);
	// ft_printf("%d\n", nb2);
	// printf("%d\n", nb2);
	//
	// nb1 = ft_printf("%s", "Hello World !\n");
	// nb2 = printf("%s", "Hello World !\n");
	// ft_printf("%d\n", nb1);
	// printf("%d\n", nb1);
	// ft_printf("%d\n", nb2);
	// printf("%d\n", nb2);
	//
	// nb1 = ft_printf("\n\n%s%s", "Hello World !\n", "C'est la fete !\n");
	// nb2 = printf("\n\n%s%s", "Hello World !\n", "C'est la fete !\n");
	// ft_printf("%d\n", nb1);
	// printf("%d\n", nb1);
	// ft_printf("%d\n", nb2);
	// printf("%d\n", nb2);
	//
	// nb1 = ft_printf("\n\n%s%s%%%%%s", "Justine et jolie\n", "Antoine aussi!\n", "mon ange evidemment !\n");
	// nb2 = printf("\n\n%s%s%%%%%s", "Justine et jolie\n", "Antoine aussi!\n", "mon ange evidemment !\n");
	// ft_printf("%d\n", nb1);
	// printf("%d\n", nb1);
	// ft_printf("%d\n", nb2);
	// printf("%d\n", nb2);
	//
	// nb1 = ft_printf("%%\n");
	// nb2 = printf("%%\n");
	// ft_printf("%d\n", nb1);
	// printf("%d\n", nb1);
	// ft_printf("%d\n", nb2);
	// printf("%d\n", nb2);
	//
	// nb1 = ft_printf("Hello World\n");
	// nb2 = printf("Hello World\n");
	// ft_printf("%d\n", nb1);
	// printf("%d\n", nb1);
	// ft_printf("%d\n", nb2);
	// printf("%d\n", nb2);

	// nb1 = ft_printf("%i\n", 42);
	// nb2 = printf("%i\n", 42);
	// ft_printf("%i\n", nb1);
	// printf("%i\n", nb1);
	// ft_printf("%i\n", nb2);
	// printf("%i\n", nb2);

	// nb1 = ft_printf("%c\n", 'Y');
	// nb2 = printf("%c\n", 'Y');
	// ft_printf("%d\n", nb1);
	// printf("%d\n", nb1);
	// ft_printf("%d\n", nb2);
	// printf("%d\n", nb2);

	// nb1 = ft_printf("%x\n", 42);
	// nb2 = printf("%x\n", 42);
	// ft_printf("%d\n", nb1);
	// printf("%d\n", nb1);
	// ft_printf("%d\n", nb2);
	// printf("%d\n", nb2);

	// nb = 42;
	// nb1 = ft_printf("%x\n", nb);
	// ft_printf("%d\n", nb1);

	nb = 42;
	nb1 = ft_printf("%x\n", nb);
	ft_printf("%d\n", nb1);

	// nb = INT_MIN;
	// nb1 = ft_printf("%x\n", nb);
	// ft_printf("%d\n", nb1);
	//
	// nb = INT_MAX;
	// nb1 = ft_printf("%x\n", nb);
	// ft_printf("%d\n", nb1);
	//
	// nb = 42;
	// nb1 = ft_printf("%X\n", nb);
	// ft_printf("%d\n", nb1);
	//
	// nb = -42;
	// nb1 = ft_printf("%X\n", nb);
	// ft_printf("%d\n", nb1);
	//
	// nb = INT_MIN;
	// nb1 = ft_printf("%X\n", nb);
	// ft_printf("%d\n", nb1);
	//
	// nb = INT_MAX;
	// nb1 = ft_printf("%X\n", nb);
	// ft_printf("%d\n", nb1);


	// nb1 = ft_printf("%%%s", "Hello World !\n");
	// nb2 = printf("%%%s", "Hello World !\n");
	// ft_printf("%d\n", nb1);
	// printf("%d\n", nb1);
	// ft_printf("%d\n", nb2);
	// printf("%d\n", nb2);

return (0);
}
