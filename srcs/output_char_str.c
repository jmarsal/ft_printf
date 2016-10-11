/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_char_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 01:06:21 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/11 16:02:41 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	print_char(t_result *result, size_t i, size_t *test_c)
{
	if (I_L_CONV == 'c' && !MOD_L)
	{
		if (I_C == 0)
		{
			ft_putchar('\0');
			*test_c += 1;
		}
		else
			RET_STR = ft_strjoin(RET_STR, &I_C);
	}
	else if (I_L_CONV == 'c' && MOD_L) // si 's' ok, delette
		RET_STR = ft_strjoin(RET_STR, I_STR);
}

static void	print_str(t_result *result, size_t i)
{
	if (I_L_CONV == 's')
		RET_STR = ft_strjoin(RET_STR, I_STR);
}

void		print_char_str(t_result *result, size_t i, size_t *test_c)
{
	print_str(result, i);
	print_char(result, i, test_c);
}
