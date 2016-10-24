/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_conversion_o.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:19:46 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/25 03:01:50 by jmarsal          ###   ########.fr       */
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
	ret = printf("%o\n", nb);
	printf("%d\n", ret);
	nb = -42;
	ret = printf("%o\n", nb);
	printf("%d\n", ret);
	nb = INT_MAX;
	ret = printf("%o\n", nb);
	printf("%d\n", ret);
	nb = INT_MIN;
	ret = printf("%o\n", nb);
	printf("%d\n", ret);

	//with flags

	ret = printf("%08o\n", nb);
	printf("%d\n", ret);
	ret = printf("%-8o\n", nb);
	printf("%d\n", ret);
	ret = printf("%#o\n", nb);
	printf("%d\n", ret);

	//with modifier

	ret = printf("%hho\n", (char)2147483649051561567);
	printf("%d\n", ret);
	ret = printf("%ho\n", (short)2147483649051561567);
	printf("%d\n", ret);
	ret = printf("%o\n", (int)2147483649051561567);
	printf("%d\n", ret);
	ret = printf("%lo\n", (long)2147483649051561567);
	printf("%d\n", ret);
	ret = printf("%llo\n", (long long)2147483649051561567);
	printf("%d\n", ret);

	ret = printf("%hho\n", (char)-2147483649051561567);
	printf("%d\n", ret);
	ret = printf("%ho\n", (short)-2147483649051561567);
	printf("%d\n", ret);
	ret = printf("%o\n", (int)-2147483649051561567);
	printf("%d\n", ret);
	ret = printf("%lo\n", (long)-2147483649051561567);
	printf("%d\n", ret);
	ret = printf("%llo\n", (long long)-2147483649051561567);
	printf("%d\n", ret);

	nb = printf("%#-8.8hho\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-8.8ho\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-8.8o\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-8.8lo\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-8.8llo\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

	nb = printf("%#-16.8hho\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-16.8ho\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-16.8o\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-16.8lo\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-16.8llo\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

	nb = printf("%#-8.16hho\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-8.16ho\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-8.16o\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-8.16lo\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-8.16llo\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

	nb = printf("%-8.8hho\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.8ho\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.8o\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.8lo\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.8llo\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

	nb = printf("%-16.8hho\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-16.8ho\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-16.8o\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-16.8lo\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-16.8llo\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

	nb = printf("%-8.16hho\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.16ho\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.16o\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.16lo\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.16llo\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

	nb = printf("%#8.8hho\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#8.8ho\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#8.8o\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#8.8lo\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#8.8llo\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

	nb = printf("%#16.8hho\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#16.8ho\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#16.8o\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#16.8lo\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#16.8llo\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

	nb = printf("%#8.16hho\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#8.16ho\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#8.16o\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#8.16lo\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#8.16llo\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

	return (0);
}
