/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 00:37:13 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/07 02:07:25 by jmarsal          ###   ########.fr       */
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

int		print_format(t_v_args *v_args)
{
	size_t				i;
	size_t				j;

	i = 0;
	j = 0;
	while (v_args->index--)
	{
		if (v_args->f_conv[i]->l_conv == 's')
		{
			if (v_args->f_conv[i]->f_caracters->sharp == 1)
			{
				ft_putstr(ERR_SHARP_S);
				return (-1);
			}
			ft_putstr(v_args->f_conv[i]->str);
		}
		else if (v_args->f_conv[i]->l_conv == 'd')
		{
			if (v_args->f_conv[i]->f_caracters->sharp == 1)
			{
				ft_putstr(ERR_SHARP_D);
				return (-1);
			}
			v_args->f_conv[i]->f_width -=
								ft_strlen(ft_itoa(v_args->f_conv[i]->nb));
			if (v_args->f_conv[i]->f_caracters->space == 1 &&
				v_args->f_conv[i]->f_is_width != 0)
				v_args->f_conv[i]->f_width -= 1;
			if (v_args->f_conv[i]->f_caracters->plus == 1 &&
				v_args->f_conv[i]->f_is_width != 0)
				v_args->f_conv[i]->f_width -= 1;
			is_f_caracters_is_space(v_args, i);
			is_f_caracters_is_positive(v_args, i);
			is_precision(v_args, i);
			ft_putnbr(v_args->f_conv[i]->nb);
			is_f_caracters_is_neg_and_precision(v_args, i);
		}
		else if (v_args->f_conv[i]->l_conv == 'D')
		{
			if (v_args->f_conv[i]->f_caracters->sharp == 1)
			{
				ft_putstr(ERR_SHARP_LD);
				return (-1);
			}
			v_args->f_conv[i]->f_width -=
								ft_strlen(ft_itoa(v_args->f_conv[i]->l_nb));
			if (v_args->f_conv[i]->f_caracters->space == 1 &&
				v_args->f_conv[i]->f_is_width != 0)
				v_args->f_conv[i]->f_width -= 1;
			if (v_args->f_conv[i]->f_caracters->plus == 1 &&
				v_args->f_conv[i]->f_is_width != 0)
				v_args->f_conv[i]->f_width -= 1;
			is_f_caracters_is_space(v_args, i);
			is_f_caracters_is_positive(v_args, i);
			is_precision(v_args, i);
			ft_putlnbr(v_args->f_conv[i]->l_nb);
			is_f_caracters_is_neg_and_precision(v_args, i);
		}
		else if (v_args->f_conv[i]->l_conv == 'u')
		{
			if (v_args->f_conv[i]->f_caracters->sharp == 1)
			{
				ft_putstr(ERR_SHARP_U);
				return (-1);
			}
			v_args->f_conv[i]->f_width -=
								ft_strlen(ft_itoa(v_args->f_conv[i]->u_nb));
			is_precision(v_args, i);
			ft_putlnbr(v_args->f_conv[i]->u_nb);
			is_f_caracters_is_neg_and_precision(v_args, i);
		}
		else if (v_args->f_conv[i]->l_conv == 'U')
		{
			if (v_args->f_conv[i]->f_caracters->sharp == 1)
			{
				ft_putstr(ERR_SHARP_LU);
				return (-1);
			}
			v_args->f_conv[i]->f_width -=
								ft_strlen(ft_ulitoa(v_args->f_conv[i]->u_l_nb));
			is_precision(v_args, i);
			ft_putstr(ft_ulitoa(v_args->f_conv[i]->u_l_nb));
			is_f_caracters_is_neg_and_precision(v_args, i);
		}
		else if (v_args->f_conv[i]->l_conv == 'c')
		{
			if (v_args->f_conv[i]->f_caracters->sharp == 1)
			{
				ft_putstr(ERR_SHARP_C);
				return (-1);
			}
			ft_putchar(v_args->f_conv[i]->c);
		}
		else if (v_args->f_conv[i]->l_conv == 'x')
		{
			v_args->f_conv[i]->f_width -=
								ft_strlen(ft_itoa(v_args->f_conv[i]->nb));
			if (v_args->f_conv[i]->f_caracters->sharp == 1)
				v_args->f_conv[i]->f_width -= 1;
			if (v_args->f_conv[i]->f_is_width == 1)
				v_args->f_conv[i]->f_width -= 1;
			is_precision(v_args, i);
			is_f_caracters_is_sharp(v_args, i);
			ft_putstr(ft_strtolower(ft_itoa_base(v_args->f_conv[i]->nb, 16)));
			is_f_caracters_is_neg_and_precision(v_args, i);
		}
		else if (v_args->f_conv[i]->l_conv == 'p')
		{
			if (v_args->f_conv[i]->f_caracters->sharp == 1)
			{
				ft_putstr(ERR_SHARP_P);
				return (-1);
			}
			print_ptr(v_args->f_conv[i]->ptr, v_args);
		}
		else if (v_args->f_conv[i]->l_conv == 'X')
		{
			v_args->f_conv[i]->f_width -=
								ft_strlen(ft_itoa(v_args->f_conv[i]->nb));
			is_precision(v_args, i);
			is_f_caracters_is_sharp(v_args, i);
			ft_putstr(ft_itoa_base(v_args->f_conv[i]->nb, 16));
			is_f_caracters_is_neg_and_precision(v_args, i);
		}
		else if (v_args->f_conv[i]->l_conv == 'b')
		{
			if (v_args->f_conv[i]->f_caracters->sharp == 1)
			{
				ft_putstr(ERR_SHARP_B);
				return (-1);
			}
			ft_putstr(ft_itoa_base(v_args->f_conv[i]->nb, 2));
		}
		else if (v_args->f_conv[i]->l_conv == 'o')
		{
			v_args->f_conv[i]->f_width -=
								ft_strlen(ft_itoa(v_args->f_conv[i]->u_nb));
			is_precision(v_args, i);
			is_f_caracters_is_sharp(v_args, i);
			ft_putstr(ft_itoa_base(v_args->f_conv[i]->u_nb, 8));
			is_f_caracters_is_neg_and_precision(v_args, i);
		}
		else if (v_args->f_conv[i]->l_conv == 'O')
		{
			v_args->f_conv[i]->f_width -=
								ft_strlen(ft_itoa(v_args->f_conv[i]->u_l_nb));
			is_precision(v_args, i);
			is_f_caracters_is_sharp(v_args, i);
			ft_putstr(ft_litoa_base(v_args->f_conv[i]->u_l_nb, 8));
			is_f_caracters_is_neg_and_precision(v_args, i);
		}
		else if (v_args->f_conv[i]->l_conv == '%')
			ft_putstr(v_args->f_conv[i]->str);
		i++;
	}
	return (0);
}
