/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 17:49:12 by jmarsal           #+#    #+#             */
/*   Updated: 2016/08/11 22:51:59 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int	len;

	len = 0;
	printf("\033[32m%s\n\033[0m", "Test 1");
	printf("%s\n", "printf(\%d\%%\%s\%d\%%, 42, le resultat est donc , 42)");
	printf("\033[31m--> output =\033[0m %d%%%s%d%%\n\n", 42, " le resultat est donc ", 42);

	printf("\033[32m%s\033[0m\n", "Test 2");
	ft_putstr("test putstr avec libftprintf !\n\n");

	printf("\033[32m%s\n\033[0m", "Test 3");
	printf("%s\n", "len = printf(ceci est un test du retour de printf)");
	len = printf("ceci est un test du retour de printf\n");
	printf("\033[31m--> len =\033[0m %d\n\n", len);

	printf("\033[32m%s\n\033[0m", "Test 4");
	len = printf("justine %s %s\n","est jolie","comme un coeur");
	printf("\033[31m--> len =\033[0m %d\n\n", len);

	printf("\033[32m%s\n\033[0m", "Test 5 avec ft_printf");
	len = ft_printf("justine %s%%\n","est jolie","comme un coeur");
	printf("\033[31m--> len =\033[0m %d\n\n", len);

	return (0);
}
