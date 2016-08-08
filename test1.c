/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 17:49:12 by jmarsal           #+#    #+#             */
/*   Updated: 2016/08/09 00:52:38 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	printf("%d%%%s%d%%\n", 42, " le resultat est donc ", 42);
	ft_putstr("test putstr avec libftprintf ! \n");
	return (0);
}
