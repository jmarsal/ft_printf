/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_conversion_d_i.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:19:46 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/20 23:14:38 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	nb;
	int nb2;

	nb = printf("%d\n", 42);
	printf("%d\n", nb);
	nb = printf("%d\n", -42);
	printf("%d\n", nb);
	nb = printf("%d\n", INT_MIN);
	printf("%d\n", nb);
	nb = printf("%d\n", INT_MAX);
	printf("%d\n", nb);
	nb = printf("%i\n", 42);
	printf("%d\n", nb);
	nb = printf("%i\n", -42);
	printf("%d\n", nb);
	nb = printf("%i\n", INT_MIN);
	printf("%d\n", nb);
	nb = printf("%i\n", INT_MAX);
	printf("%d\n", nb);

	// test Flags caracters

	nb = printf("%+d\n", 0);
	printf("%d\n", nb);
	nb = printf("%+d\n", 42);
	printf("%d\n", nb);
	nb = printf("%+d\n", -42);
	printf("%d\n", nb);

	nb2 = 42;
	nb = printf("%8d\n", nb2);
	printf("%d\n", nb);
	nb = printf("%-8d\n", nb2);
	printf("%d\n", nb);
	nb = printf("%08d\n", nb2);
	printf("%d\n", nb);
	nb = printf("%+08d\n", nb2);
	printf("%d\n", nb);

	//test modifier

	nb = printf("%hhd\n", (char)2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%hd\n", (short)2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%d\n", (int)2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%ld\n", (long)2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%lld\n", (long long)2147483649051561567);
	printf("%d\n", nb);

	nb = printf("%hhd\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%hd\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%d\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%ld\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%lld\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

	nb = printf("%-8.8hhd\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.8hd\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.8d\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.8ld\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.8lld\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

	nb = printf("%-16.8hhd\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-16.8hd\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-16.8d\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-16.8ld\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-16.8lld\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

	nb = printf("%-8.16hhd\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.16hd\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.16d\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.16ld\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.16lld\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

	return (0);
}