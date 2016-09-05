/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 00:37:13 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/05 22:48:12 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void print_ptr(void *p, t_v_args *v_args)
{
	unsigned char 	t[sizeof(p)];
	char			*ret;
	size_t			i;

	ret = ft_strnew(0);
	i = sizeof(p);
	i -= 2;
	ft_memcpy(t, &p, sizeof(p));
	ret = ft_strcat(ret, "0x");
	while ((i--) > 0)
		ret = ft_strcat(ret, ft_strtolower(ft_itoa_base(t[i], 16)));
	ft_putstr(ret);
	v_args->ret_ft_printf += ft_strlen(ret);
}

void	print_format(t_v_args *v_args)
{
	size_t				i;
	size_t				j;

	i = 0;
	j = 0;
	while (v_args->index--)
	{
		if (v_args->f_conv[i]->l_conv == 's')
			ft_putstr(v_args->f_conv[i]->str);
		else if (v_args->f_conv[i]->l_conv == 'd')
		{
			if (v_args->f_conv[i]->nb >= 0 &&
				v_args->f_conv[i]->f_caracters == '+')
			{
				ft_putchar('+');
				v_args->ret_ft_printf += 1;
			}
			ft_putnbr(v_args->f_conv[i]->nb);
		}
		else if (v_args->f_conv[i]->l_conv == 'D')
		{
			if (v_args->f_conv[i]->l_nb >= 0 &&
				v_args->f_conv[i]->f_caracters == '+')
			{
				ft_putchar('+');
				v_args->ret_ft_printf += 1;
			}
			ft_putlnbr(v_args->f_conv[i]->l_nb);
		}
		else if (v_args->f_conv[i]->l_conv == 'u')
			ft_putlnbr(v_args->f_conv[i]->u_nb);
		else if (v_args->f_conv[i]->l_conv == 'U')
			ft_putstr(ft_ulitoa(v_args->f_conv[i]->u_l_nb));
		else if (v_args->f_conv[i]->l_conv == 'c')
			ft_putchar(v_args->f_conv[i]->c);
		else if (v_args->f_conv[i]->l_conv == 'x')
			ft_putstr(ft_strtolower(ft_itoa_base(v_args->f_conv[i]->nb, 16)));
		else if (v_args->f_conv[i]->l_conv == 'p')
			print_ptr(v_args->f_conv[i]->ptr, v_args);
		else if (v_args->f_conv[i]->l_conv == 'X')
			ft_putstr(ft_itoa_base(v_args->f_conv[i]->nb, 16));
		else if (v_args->f_conv[i]->l_conv == 'b')
			ft_putstr(ft_itoa_base(v_args->f_conv[i]->nb, 2));
		else if (v_args->f_conv[i]->l_conv == 'o')
			ft_putstr(ft_itoa_base(v_args->f_conv[i]->nb, 8));
		else if (v_args->f_conv[i]->l_conv == 'O')
			ft_putstr(ft_litoa_base(v_args->f_conv[i]->l_nb, 8));
		else if (v_args->f_conv[i]->l_conv == '%')
			ft_putstr(v_args->f_conv[i]->str);
		i++;
	}
}
