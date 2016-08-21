/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 00:37:13 by jmarsal           #+#    #+#             */
/*   Updated: 2016/08/21 12:47:31 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_format(t_v_args *v_args)
{
	size_t	i;

	i = 0;
	while (v_args->index--)
	{
		if (v_args->f_conv[i]->l_conv == 's')
		{
			ft_putstr(v_args->f_conv[i]->str);
		}
		else if (v_args->f_conv[i]->l_conv == 'd')
		{
			ft_putnbr(v_args->f_conv[i]->nb);
		}
		else if (v_args->f_conv[i]->l_conv == '%')
		{
			ft_putstr(v_args->f_conv[i]->str);
		}
		i++;
	}
}
