/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_conversion_s.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:19:46 by jmarsal           #+#    #+#             */
/*   Updated: 2016/08/21 23:34:05 by jmarsal          ###   ########.fr       */
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
	return (0);
}
