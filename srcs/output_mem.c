/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_mem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 16:10:44 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/10 16:26:07 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_ptr(t_args *v_args, size_t i)
{
	unsigned char 	t[sizeof(v_args->f_conv[i]->type->ptr)];
	char			*ret;
	size_t			j;

	if (v_args->f_conv[i]->l_conv == 'p')
	{
		// if (v_args->f_conv[i]->caracters->sharp == 1)
		// 			{
		// 				ft_putstr(ERR_SHARP_B);
		// 				return (-1);
		// 			}
		ret = ft_strnew(0);
		j = sizeof(v_args->f_conv[i]->type->ptr);
		j -= 2;
		ft_memcpy(t, &v_args->f_conv[i]->type->ptr,
									sizeof(v_args->f_conv[i]->type->ptr));
		ret = ft_strcat(ret, "0x");
		while ((j--) > 0)
			ret = ft_strcat(ret, ft_strtolower(ft_itoa_base(t[j], 16)));
		ft_putstr(ret);
		// v_args->ret_ft_printf += ft_strlen(ret);
	}
}
