/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_conversion_u.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:19:24 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/26 00:29:02 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>
#include <string.h>

int	main(void)
{
	unsigned int	nb;
	int				ret;

	nb = 42;
	ret = ft_printf("%u\n", nb);
	ft_printf("%d\n", ret);
	nb = -42;
	ret = ft_printf("%u\n", nb);
	ft_printf("%d\n", ret);
	nb = INT_MIN;
	ret = ft_printf("%u\n", nb);
	ft_printf("%d\n", ret);
	nb = INT_MAX;
	ret = ft_printf("%u\n", nb);
	ft_printf("%d\n", ret);

	//test with flags

	ret = ft_printf("%-8u\n", nb);
	ft_printf("%d\n", ret);
	ret = ft_printf("%08u\n", nb);
	ft_printf("%d\n", ret);

	ret = ft_printf("%hhu\n", (char)2147483649051561567);
	ft_printf("%d\n", ret);
	ret = ft_printf("%hu\n", (short)2147483649051561567);
	ft_printf("%d\n", ret);
	ret = ft_printf("%u\n", (int)2147483649051561567);
	ft_printf("%d\n", ret);
	ret = ft_printf("%lu\n", (long)2147483649051561567);
	ft_printf("%d\n", ret);
	ret = ft_printf("%llu\n", (long long)2147483649051561567);
	ft_printf("%d\n", ret);

	ret = ft_printf("%hhu\n", (char)-2147483649051561567);
	ft_printf("%d\n", ret);
	ret = ft_printf("%hu\n", (short)-2147483649051561567);
	ft_printf("%d\n", ret);
	ret = ft_printf("%u\n", (int)-2147483649051561567);
	ft_printf("%d\n", ret);
	ret = ft_printf("%lu\n", (long)-2147483649051561567);
	ft_printf("%d\n", ret);
	ret = ft_printf("%llu\n", (long long)-2147483649051561567);
	ft_printf("%d\n", ret);

	nb = ft_printf("%-8.8hhu\n", (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.8hu\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.8u\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.8lu\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.8llu\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);

	nb = ft_printf("%-16.8hhu\n", (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-16.8hu\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-16.8u\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-16.8lu\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-16.8llu\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);

	nb = ft_printf("%-8.16hhu\n", (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.16hu\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.16u\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.16lu\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.16llu\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);

	return (0);
}
