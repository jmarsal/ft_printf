/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_conversion_s.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:19:46 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/07 12:35:06 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <wchar.h>


int	main(void)
{
	int nb1;

	nb1 = printf("Hello%s%s world\n", " World !\n", "I am so happy");
	printf("%d\n", nb1);

	nb1 = printf("%s", "Hello World !\n");
	printf("%d\n", nb1);

	nb1 = printf("\n\n%s%s", "Hello World !\n", "C'est la fete !\n");
	printf("%d\n", nb1);

	nb1 = printf("\n\n%s%s%%%%%s", "Justine et jolie\n", "Antoine aussi!\n", "mon ange evidemment !\n");
	printf("%d\n", nb1);

	nb1 = printf("%%\n");
	printf("%d\n", nb1);

	nb1 = printf("Hello World\n");
	printf("%d\n", nb1);

	nb1 = printf("%%%s", "Hello World !\n");
	printf("%d\n", nb1);

	nb1 = printf("\033[32;1m%s\033[0m comment \033[32;1mva tu \033[0m?\n", "Hello World !");
	printf("%d\n", nb1);
	nb1 = printf("\033[31m%s\033[0m comment \033[31mva tu \033[0m?\n", "Hello World !");
	printf("%d\n", nb1);
	nb1 = printf("\033[34m%s\033[0m comment \033[34mva tu \033[0m?\n", "Hello World !");
	printf("%d\n", nb1);
	nb1 = printf("\033[35;1m%s\033[0m comment \033[35;1mva tu \033[0m?\n", "Hello World !");
	printf("%d\n", nb1);
	nb1 = printf("\033[36;1m%s\033[0m comment \033[36;1mva tu \033[0m?\n", "Hello World !");
	printf("%d\n", nb1);
	nb1 = printf("{yan}%s\033[0m comment \033[36;1mva tu \033[0m?\n", "Hello World !");
	printf("%d\n", nb1);
	return (0);
}
