/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 16:05:15 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/25 22:01:51 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		print_hex_x(t_result *result, size_t i)
{
	if (I_L_CONV == 'x' || I_L_CONV == 'X')
	{
		if (I_L_CONV == 'x')
			ft_buffer_add(RET_STR, RET_STR->len, I_STR, ft_strlen(I_STR));
		else
			ft_buffer_add(RET_STR, RET_STR->len, ft_strtoupper(I_STR),
				ft_strlen(I_STR));
	}
}
