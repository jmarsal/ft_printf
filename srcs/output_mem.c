/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_mem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 16:10:44 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/13 16:01:44 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_ptr(t_args *v_args, size_t i)
{
	if (v_args->f_conv[i]->l_conv == 'p')
	{
		RET_STR = ft_get_ptr(v_args->f_conv[i]->type->ptr);
	}
}
