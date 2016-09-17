/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 15:44:22 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/13 17:07:50 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_char_c(t_args *v_args, size_t i, size_t *test_c)
{
	if (I_L_CONV == 'c')
	{
		if (I_C == 0)
		{
			ft_putchar('\0');
			*test_c += 1;
		}
		else
			RET_STR = ft_strcat(RET_STR, &I_C);
	}
}
