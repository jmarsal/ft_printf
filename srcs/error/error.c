/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 02:06:27 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/17 14:56:28 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		find_error_in_format(t_result *result)
{
	int	index_cpy;
	int	i;

	index_cpy = result->index;
	i = 0;
	while (index_cpy--)
	{
		if (SHARP == 1 && (!ft_strchr(GOOD_SHARP, I_L_CONV)))
			return (-1);
		else if (ZERO == 1 && (!ft_strchr(GOOD_ZERO, I_L_CONV)))
			return (-2);
		else if (SPACE == 1 && (!ft_strchr(GOOD_SPACE, I_L_CONV)))
			return (-3);
		else if (PLUS == 1 && (!ft_strchr(GOOD_PLUS, I_L_CONV)))
			return (-4);
		else if (PLUS == 1 && SPACE)
			return (-5);
		else if (I_L_CONV == 'p' && IS_PRECISION == 1)
			return (-6);
		else if (I_L_CONV == 'b' && IS_PRECISION == 1)
			return (-7);
		i++;
	}
	return (0);
}

int		print_error_specifier(char caracters)
{
	ft_putstr("error : invalid conversion specifier '");
	ft_putchar(caracters);
	ft_putstr("'\n");
	return (-1);
}