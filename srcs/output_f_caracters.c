/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_f_caracters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 01:07:28 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/13 15:13:12 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	is_caracters_is_neg_and_precision(t_args *v_args, size_t i)
{
	// int	tmp;

	// tmp = v_args->f_conv[i]->width_precision->width_cpy +
			// ft_strlen(ft_itoa(v_args->f_conv[i]->type->nb)) +
			// v_args->f_conv[i]->width_precision->precision_cpy;
	// printf("%d\n", tmp);
	if (v_args->f_conv[i]->caracters->minus == 1 &&
		v_args->f_conv[i]->is_width == 1)
	{
		// printf("ici\n");
		// while (v_args->f_conv[i]->f_width > 0)
		// {
		// 	ft_putchar(' ');
		// 	v_args->f_conv[i]->f_width--;
		// 	v_args->ret_ft_printf += 1;
		// }
		while (v_args->f_conv[i]->width_precision->width_cpy > 0)
		{
			RET_STR = ft_strcat(RET_STR, " ");
			v_args->f_conv[i]->width_precision->width_cpy--;
			// v_args->f_conv[i]->precision--;
		}
	}
}

void	is_width_in_format(t_args *v_args, size_t i) // Voir a gerer la
{													// precision ici !!!
	int	tmp;

	tmp = 0;
	if (v_args->f_conv[i]->is_width == 1 &&
		!v_args->f_conv[i]->caracters->minus)
	{
		if (v_args->f_conv[i]->caracters->zero)
		{
			if (v_args->f_conv[i]->caracters->plus)
				RET_STR = ft_strcat(RET_STR, "+");
			if ((v_args->f_conv[i]->type->nb < 0 ||
				v_args->f_conv[i]->type->l_nb < 0) &&
				(v_args->f_conv[i]->l_conv != 'x' &&
				v_args->f_conv[i]->l_conv != 'X'))
				{
					v_args->f_conv[i]->type->nb = -v_args->f_conv[i]->type->nb;
					v_args->f_conv[i]->type->l_nb = v_args->f_conv[i]->type->l_nb;
					RET_STR = ft_strcat(RET_STR, "-");
				}
			while (v_args->f_conv[i]->width_precision->width_cpy > 0)
			{
				RET_STR = ft_strcat(RET_STR, "0");
				v_args->f_conv[i]->width_precision->width_cpy--;
			}
		}
		else
		{
			while (v_args->f_conv[i]->width_precision->width_cpy > 0)
			{
				RET_STR = ft_strcat(RET_STR, " ");
				v_args->f_conv[i]->width_precision->width_cpy--;
			}
			if (v_args->f_conv[i]->caracters->plus == 1 &&
				v_args->f_conv[i]->caracters->minus == 0)
				RET_STR = ft_strcat(RET_STR, "+");
		}
		// if ((v_args->f_conv[i]->caracters->minus != 1) ||
		// 	(v_args->f_conv[i]->caracters->plus == 1 &&
		// 	v_args->f_conv[i]->caracters->minus == 1 &&
		// 	v_args->f_conv[i]->is_precision == 1))
		// {
		// 	while (v_args->f_conv[i]->width_precision->width_cpy > 0)
		// 	{
		// 		if (v_args->f_conv[i]->caracters->zero == 1 &&
		// 					v_args->f_conv[i]->is_precision == 0)
		// 			ft_putchar('0');
		// 		else
		// 		{
		// 			printf("ici\n");
		// 			// if (v_args->f_conv[i]->caracters->plus == 0)
		// 			// 	v_args->f_conv[i]->width_precision->width++;
		// 			if (!(v_args->f_conv[i]->caracters->plus == 1 &&
		// 			v_args->f_conv[i]->caracters->minus == 1 &&
		// 			v_args->f_conv[i]->is_precision == 1))
		// 			{
		// 				while (v_args->f_conv[i]->width_precision->width_cpy >
		// 					v_args->f_conv[i]->width_precision->precision_cpy)
		// 				{
		// 					RET_STR = ft_strcat(RET_STR, " ");
		// 					v_args->f_conv[i]->width_precision->width_cpy--;
		// 					test = 1;
		// 				}
		// 			}
		// 			// if (v_args->f_conv[i]->caracters->plus == 1 &&
		// 			// 	v_args->f_conv[i]->caracters->minus == 0)
		// 			// 		ft_putchar('+');
		// 		}
		// 		v_args->f_conv[i]->width_precision->width_cpy--;
		// 	}
		// 	if (v_args->f_conv[i]->caracters->plus == 1)
		// 	{
		// 		ft_putchar('+');
		// 		if ((test == 1) || (v_args->f_conv[i]->caracters->plus == 1 &&
		// 		v_args->f_conv[i]->caracters->minus == 1 &&
		// 		v_args->f_conv[i]->is_precision == 1))
		// 		{
		// 			tmp = v_args->f_conv[i]->width_precision->precision -
		// 			ft_strlen(ft_itoa(v_args->f_conv[i]->type->nb));
		// 			while (tmp > 0)
		// 			{
		// 				ft_putchar('0');
		// 				v_args->f_conv[i]->width_precision->precision--;
		// 				v_args->f_conv[i]->width_precision->width++;
		// 				tmp--;
		// 			}
		// 			v_args->f_conv[i]->width_precision->width +=
		// 			ft_strlen(ft_itoa(v_args->f_conv[i]->type->nb)) + 1;
		// 		}
		// 	}
		// }

	}
}
//
void	is_caracters_is_sharp(t_args *v_args, size_t i)
{
	if (v_args->f_conv[i]->caracters->sharp == 1)
	{
		if (v_args->f_conv[i]->l_conv == 'o' ||
			v_args->f_conv[i]->l_conv == 'O')
			RET_STR = ft_strcat(RET_STR, "0");
		else if (v_args->f_conv[i]->l_conv == 'x')
			RET_STR = ft_strcat(RET_STR, "0x");
		else if (v_args->f_conv[i]->l_conv == 'X')
			RET_STR = ft_strcat(RET_STR, "0X");
	}
}
//
// void	is_precision_in_format(t_args *v_args, size_t i)
// {
// 	if (v_args->f_conv[i]->f_width != 0 &&
// 		v_args->f_conv[i]->f_width > v_args->f_conv[i]->precision)
// 	{
// 		while (v_args->f_conv[i]->precision-- > 0)
// 		{
// 			while (v_args->f_conv[i]->f_width-- > 0)
// 			{
// 				v_args->f_conv[i]->precision -= 1;
// 			}
// 		}
// 	}
// }
