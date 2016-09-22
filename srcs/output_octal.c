/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 16:12:52 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/22 11:36:46 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_octal_o(t_args *v_args, size_t i)
{
	if (I_L_CONV == 'o')
	{
		RET_STR = ft_strjoin(RET_STR,
			ft_itoa_base(I_U_INT, 8));
	}
}

void	print_octal_lo(t_args *v_args, size_t i)
{
	if (I_L_CONV == 'O')
	{
		RET_STR = ft_strjoin(RET_STR,
			ft_litoa_base(I_U_L_INT, 8));
	}
}
