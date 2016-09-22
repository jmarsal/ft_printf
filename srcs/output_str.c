/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 15:51:52 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/22 11:26:52 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void 	print_str_s(t_args *v_args, size_t i)
{
	if (I_L_CONV == 's')
	{
		RET_STR = ft_strjoin(RET_STR, I_STR);
	}
}
