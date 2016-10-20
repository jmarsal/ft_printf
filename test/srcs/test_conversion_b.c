/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_conversion_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 16:33:43 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/20 23:13:38 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int ret;

//nb = 42
	ret = printf("%s\n", "101010");
	printf("%d\n", ret);

//INT_MAX
	ret = printf("%s\n", "1111111111111111111111111111111");
	printf("%d\n", ret);

//INT_MIN
	ret = printf("%s\n", "10000000000000000000000000000000");
	printf("%d\n", ret);

	return (0);
}