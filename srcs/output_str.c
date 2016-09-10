/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 15:51:52 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/10 15:53:56 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void 	print_str_s(t_args *v_args, size_t i)
{
	if (v_args->f_conv[i]->l_conv == 's')
	{
		// if (v_args->f_conv[i]->caracters->sharp == 1)
		// 	ft_putstr(ERR_SHARP_S);
		ft_putstr(v_args->f_conv[i]->type->str);
	}
}
