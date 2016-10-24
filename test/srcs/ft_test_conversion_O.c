/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_conversion_o.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:19:24 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/25 23:26:11 by jmarsal          ###   ########.fr       */
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
	ret = ft_printf("%o\n", nb);
	ft_printf("%d\n", ret);
	nb = -42;
	ret = ft_printf("%o\n", nb);
	ft_printf("%d\n", ret);
	nb = INT_MAX;
	ret = ft_printf("%o\n", nb);
	ft_printf("%d\n", ret);
	nb = INT_MIN;
	ret = ft_printf("%o\n", nb);
	ft_printf("%d\n", ret);

	//with flags

	ret = ft_printf("%08o\n", nb);
	ft_printf("%d\n", ret);
	ret = ft_printf("%-8o\n", nb);
	ft_printf("%d\n", ret);
	ret = ft_printf("%#o\n", nb);
	ft_printf("%d\n", ret);

	//with modifier


	ret = ft_printf("%hho\n", (char)2147483649051561567);
	ft_printf("%d\n", ret);
	ret = ft_printf("%ho\n", (short)2147483649051561567);
	ft_printf("%d\n", ret);
	ret = ft_printf("%o\n", (int)2147483649051561567);
	ft_printf("%d\n", ret);
	ret = ft_printf("%lo\n", (long)2147483649051561567);
	ft_printf("%d\n", ret);
	ret = ft_printf("%llo\n", (long long)2147483649051561567);
	ft_printf("%d\n", ret);

	ret = ft_printf("%hho\n", (char)-2147483649051561567);
	ft_printf("%d\n", ret);
	ret = ft_printf("%ho\n", (short)-2147483649051561567);
	ft_printf("%d\n", ret);
	ret = ft_printf("%o\n", (int)-2147483649051561567);
	ft_printf("%d\n", ret);
	ret = ft_printf("%lo\n", (long)-2147483649051561567);
	ft_printf("%d\n", ret);
	ret = ft_printf("%llo\n", (long long)-2147483649051561567);
	ft_printf("%d\n", ret);

	nb = ft_printf("%#-8.8hho\n", (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-8.8ho\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-8.8o\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-8.8lo\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-8.8llo\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);

	nb = ft_printf("%#-16.8hho\n", (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-16.8ho\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-16.8o\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-16.8lo\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-16.8llo\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);

	nb = ft_printf("%#-8.16hho\n", (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-8.16ho\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-8.16o\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-8.16lo\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-8.16llo\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);

	nb = ft_printf("%-8.8hho\n", (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.8ho\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.8o\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.8lo\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.8llo\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);

	nb = ft_printf("%-16.8hho\n", (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-16.8ho\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-16.8o\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-16.8lo\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-16.8llo\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);

	nb = ft_printf("%-8.16hho\n", (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.16ho\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.16o\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.16lo\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.16llo\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);

	nb = ft_printf("%#8.8hho\n", (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#8.8ho\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#8.8o\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#8.8lo\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#8.8llo\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);

	nb = ft_printf("%#16.8hho\n", (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#16.8ho\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#16.8o\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#16.8lo\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#16.8llo\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);

	nb = ft_printf("%#8.16hho\n", (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#8.16ho\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#8.16o\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#8.16lo\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#8.16llo\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);

	return (0);
}
