/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 16:05:15 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/14 16:10:44 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		print_hex_x(t_result *result, size_t i)
{
	if (I_L_CONV == 'x' || I_L_CONV == 'X')
	{
		RET_STR = (I_L_CONV == 'x') ?
			ft_strjoin(RET_STR, I_STR) :
			ft_strjoin(RET_STR, ft_strtoupper(I_STR));
	}
}
