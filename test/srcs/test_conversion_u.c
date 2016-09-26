/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_conversion_u.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:19:46 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/26 00:28:13 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <string.h>

int	main(void)
{
	unsigned int	nb;
	int				ret;

	nb = 42;
	ret = printf("%u\n", nb);
	printf("%d\n", ret);
	nb = -42;
	ret = printf("%u\n", nb);
	printf("%d\n", ret);
	nb = INT_MIN;
	ret = printf("%u\n", nb);
	printf("%d\n", ret);
	nb = INT_MAX;
	ret = printf("%u\n", nb);
	printf("%d\n", ret);

	//test with flags

	ret = printf("%-8u\n", nb);
	printf("%d\n", ret);
	ret = printf("%08u\n", nb);
	printf("%d\n", ret);

	ret = printf("%hhu\n", (char)2147483649051561567);
	printf("%d\n", ret);
	ret = printf("%hu\n", (short)2147483649051561567);
	printf("%d\n", ret);
	ret = printf("%u\n", (int)2147483649051561567);
	printf("%d\n", ret);
	ret = printf("%lu\n", (long)2147483649051561567);
	printf("%d\n", ret);
	ret = printf("%llu\n", (long long)2147483649051561567);
	printf("%d\n", ret);

	ret = printf("%hhu\n", (char)-2147483649051561567);
	printf("%d\n", ret);
	ret = printf("%hu\n", (short)-2147483649051561567);
	printf("%d\n", ret);
	ret = printf("%u\n", (int)-2147483649051561567);
	printf("%d\n", ret);
	ret = printf("%lu\n", (long)-2147483649051561567);
	printf("%d\n", ret);
	ret = printf("%llu\n", (long long)-2147483649051561567);
	printf("%d\n", ret);

	nb = printf("%-8.8hhu\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.8hu\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.8u\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.8lu\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.8llu\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

	nb = printf("%-16.8hhu\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-16.8hu\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-16.8u\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-16.8lu\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-16.8llu\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

	nb = printf("%-8.16hhu\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.16hu\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.16u\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.16lu\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.16llu\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

	return (0);
}
