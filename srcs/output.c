/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 00:37:13 by jmarsal           #+#    #+#             */
/*   Updated: 2016/08/25 01:20:27 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_format(t_v_args *v_args)
{
	size_t				i;
	size_t				j;
	unsigned char	t[sizeof(v_args->f_conv[i]->p)];

	i = 0;
	j = 0;
	// t = 0;
	while (v_args->index--)
	{
		if (v_args->f_conv[i]->l_conv == 's')
			ft_putstr(v_args->f_conv[i]->str);
		else if (v_args->f_conv[i]->l_conv == 'd')
			ft_putnbr(v_args->f_conv[i]->nb);
		else if (v_args->f_conv[i]->l_conv == 'c')
			ft_putchar(v_args->f_conv[i]->c);
		else if (v_args->f_conv[i]->l_conv == 'x')
			ft_putstr(ft_strtolower(ft_itoa_base(v_args->f_conv[i]->hex, 16)));
		else if (v_args->f_conv[i]->l_conv == 'p')
		{
			ft_memcpy(t, &v_args->f_conv[i]->p, sizeof(v_args->f_conv[i]->p));
			while (i < sizeof(v_args->f_conv[i]->p))
			{
				ft_putstr(ft_strtolower(ft_itoa_base(t[j], 16)));
				++j;
			}
		}
		else if (v_args->f_conv[i]->l_conv == 'X')
			ft_putstr(ft_itoa_base(v_args->f_conv[i]->hex, 16));
		else if (v_args->f_conv[i]->l_conv == 'b')
			ft_putstr(ft_itoa_base(v_args->f_conv[i]->binary, 2));
		else if (v_args->f_conv[i]->l_conv == '%')
			ft_putstr(v_args->f_conv[i]->str);
		i++;
	}
}
