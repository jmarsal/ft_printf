/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_char_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 15:44:22 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/29 02:37:38 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	print_char(t_args *v_args, size_t i, size_t *test_c)
{
	if (I_L_CONV == 'c')
	{
		if (I_C == 0)
		{
			ft_putchar('\0');
			*test_c += 1;
		}
		else
			RET_STR = ft_strjoin(RET_STR, &I_C);
	}
}

static void print_str(t_args *v_args, size_t i)
{
	if (I_L_CONV == 's')
		RET_STR = ft_strjoin(RET_STR, I_STR);
}

void 		print_char_str(t_args *v_args, size_t i, size_t *test_c)
{
	print_str(v_args, i);
	print_char(v_args, i, test_c);
}
