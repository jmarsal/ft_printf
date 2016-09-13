/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 15:51:52 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/13 16:01:18 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void 	print_str_s(t_args *v_args, size_t i)
{
	if (v_args->f_conv[i]->l_conv == 's')
	{
		RET_STR = ft_strcat(RET_STR, v_args->f_conv[i]->type->str);
	}
}
