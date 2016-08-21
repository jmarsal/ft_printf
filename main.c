/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 01:24:50 by jmarsal           #+#    #+#             */
/*   Updated: 2016/08/21 17:51:13 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
	ft_printf("Hello%s%s world\n", " World !\n", "I am so happy");
	ft_printf("%s", "Hello World !\n");
	ft_printf("\n\n%s%s", "Hello World !\n", "C'est la fete !\n");
	ft_printf("\n\n%s%s%%%%%s", "Justine et jolie\n", "Antoine aussi!\n", "mon ange evidemment !\n");
	ft_printf("%%\n");
	ft_printf("Hello World\n");
	ft_printf("%d\n", 42);
	ft_printf("%%%s", "Hello World !\n");
	return (0);
}
