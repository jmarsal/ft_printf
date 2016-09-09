/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_f_caracters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 01:07:28 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/09 02:22:36 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	is_f_caracters_is_positive(t_v_args *v_args, size_t i)
{
	if (((v_args->f_conv[i]->nb >= 0 && v_args->f_conv[i]->l_nb >= 0
		&& (long int)v_args->f_conv[i]->u_l_nb >= 0)) &&
		(v_args->f_conv[i]->f_caracters->plus == 1 &&
		v_args->f_conv[i]->is_precision == 0 &&
		v_args->f_conv[i]->f_is_width == 0))
	{
		ft_putchar('+');
			v_args->ret_ft_printf += 1;
	}
	if (((v_args->f_conv[i]->nb >= 0 && v_args->f_conv[i]->l_nb >= 0
		&& (long int)v_args->f_conv[i]->u_l_nb >= 0)) &&
		((v_args->f_conv[i]->f_caracters->plus == 1 &&
		v_args->f_conv[i]->is_precision == 0 &&
		v_args->f_conv[i]->f_is_width == 1 &&
		v_args->f_conv[i]->f_caracters->minus == 1)))
	{
		ft_putchar('+');
			v_args->ret_ft_printf += 1;
	}
}

void	is_f_caracters_is_neg_and_precision(t_v_args *v_args, size_t i)
{
	int	tmp;

	tmp = v_args->f_conv[i]->f_width +
			ft_strlen(ft_itoa(v_args->f_conv[i]->nb)) +
			v_args->f_conv[i]->f_caracters->plus -
			v_args->f_conv[i]->precision;
	// printf("%d\n", tmp);
	if (v_args->f_conv[i]->f_caracters->minus == 1)
	{
		// printf("ici\n");
		// while (v_args->f_conv[i]->f_width > 0)
		// {
		// 	ft_putchar(' ');
		// 	v_args->f_conv[i]->f_width--;
		// 	v_args->ret_ft_printf += 1;
		// }
		while (tmp > 0)
		{
			ft_putchar(' ');
			if (!(v_args->f_conv[i]->f_caracters->plus == 1 &&
			v_args->f_conv[i]->f_caracters->minus == 1 &&
			v_args->f_conv[i]->f_is_width == 1 &&
			v_args->f_conv[i]->is_precision == 1))
				v_args->ret_ft_printf += 1;
			tmp--;
			// v_args->f_conv[i]->precision--;
		}
	}
}

void	is_width_in_format(t_v_args *v_args, size_t i) // Voir a gerer la
{													// precision ici !!!
	int	test;
	int	tmp;

	test = 0;
	tmp = 0;
	if ((v_args->f_conv[i]->f_caracters->minus != 1) ||
		(v_args->f_conv[i]->f_caracters->plus == 1 &&
		v_args->f_conv[i]->f_caracters->minus == 1 &&
		v_args->f_conv[i]->f_is_width == 1 &&
		v_args->f_conv[i]->is_precision == 1))
	{
		while (v_args->f_conv[i]->f_width > 0)
		{
			if (v_args->f_conv[i]->f_caracters->zero == 0 ||
				(v_args->f_conv[i]->f_caracters->zero == 1 &&
				v_args->f_conv[i]->is_precision == 1))
			{
				if (v_args->f_conv[i]->f_caracters->plus == 0 && v_args->f_conv[i]->f_is_width == 1)
				{
					v_args->f_conv[i]->f_width -= 1;
					v_args->ret_ft_printf -= 1;
				}
				if (!(v_args->f_conv[i]->f_caracters->plus == 1 &&
				v_args->f_conv[i]->f_caracters->minus == 1 &&
				v_args->f_conv[i]->f_is_width == 1 &&
				v_args->f_conv[i]->is_precision == 1))
				{
					while (v_args->f_conv[i]->f_width >= v_args->f_conv[i]->precision + v_args->f_conv[i]->f_caracters->plus)
					{
						ft_putchar(' ');
						v_args->ret_ft_printf += 1;
						v_args->f_conv[i]->f_width--;
						test = 1;
					}
				}
				if (v_args->f_conv[i]->f_caracters->plus == 1 &&
					v_args->f_conv[i]->f_caracters->minus == 0 &&
					v_args->f_conv[i]->f_is_width == 1)
						ft_putchar('+');
			}
			else if (v_args->f_conv[i]->f_caracters->zero == 1 &&
						v_args->f_conv[i]->is_precision == 0)
				ft_putchar('0');
			v_args->ret_ft_printf += 1;
			v_args->f_conv[i]->f_width--;
		}
		if (v_args->f_conv[i]->f_caracters->plus == 1 &&
			v_args->f_conv[i]->f_is_width == 1 &&
			v_args->f_conv[i]->is_precision == 1)
		{
			v_args->ret_ft_printf += 1;
			ft_putchar('+');
			if ((test == 1) || (v_args->f_conv[i]->f_caracters->plus == 1 &&
			v_args->f_conv[i]->f_caracters->minus == 1 &&
			v_args->f_conv[i]->f_is_width == 1 &&
			v_args->f_conv[i]->is_precision == 1))
			{
				tmp = v_args->f_conv[i]->precision - ft_strlen(ft_itoa(v_args->f_conv[i]->nb));
				while (tmp > 0)
				{
					ft_putchar('0');
					v_args->f_conv[i]->precision--;
					v_args->f_conv[i]->f_width++;
					tmp--;
				}
				// }
				// if ((test == 1) || (v_args->f_conv[i]->f_caracters->plus == 1 &&
				// v_args->f_conv[i]->f_caracters->minus == 1 &&
				// v_args->f_conv[i]->f_is_width == 1 &&
				// v_args->f_conv[i]->is_precision == 1))
				// {
				// 	v_args->ret_ft_printf -= ft_strlen(ft_itoa(v_args->f_conv[i]->nb));
				v_args->f_conv[i]->f_width += ft_strlen(ft_itoa(v_args->f_conv[i]->nb)) + 1;
				// }
				// else
					v_args->ret_ft_printf -= ft_strlen(ft_itoa(v_args->f_conv[i]->nb));
			}
		}
	}
}

void	is_f_caracters_is_sharp(t_v_args *v_args, size_t i)
{
	if (v_args->f_conv[i]->f_caracters->sharp == 1)
	{
		if (v_args->f_conv[i]->l_conv == 'o' ||
			v_args->f_conv[i]->l_conv == 'O')
				ft_putchar('0');
		else if (v_args->f_conv[i]->l_conv == 'x')
		{
			ft_putstr("0x");
				v_args->ret_ft_printf += 1;
		}
		else if (v_args->f_conv[i]->l_conv == 'X')
		{
			ft_putstr("0X");
				v_args->ret_ft_printf += 1;
		}
			v_args->ret_ft_printf += 1;
	}
}

void	is_f_caracters_is_space(t_v_args *v_args, size_t i)
{
	if (v_args->f_conv[i]->f_caracters->space == 1 &&
					v_args->f_conv[i]->nb >= 0 &&
					v_args->f_conv[i]->l_nb >= 0)
	{
		if (v_args->f_conv[i]->l_conv == 'd' ||
			v_args->f_conv[i]->l_conv == 'D')
				ft_putchar(' ');
		v_args->ret_ft_printf += 1;
	}
}

// void	is_precision_in_format(t_v_args *v_args, size_t i)
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
