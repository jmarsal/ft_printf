/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 02:06:27 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/17 01:16:00 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void 	error_output(int err)
{
	if (err == -1)
		ft_putstr(ERR_SHARP);
	else if (err == -2)
		ft_putstr(ERR_ZERO);
	else if (err == -3)
		ft_putstr(ERR_SPACE);
	else if (err == -4)
		ft_putstr(ERR_PLUS);
	else if (err == -5)
		ft_putstr(ERR_PLUS_SPACE);
	else if (err == -6)
		ft_putstr(ERR_MEM);
	else if (err == -7)
		ft_putstr(ERR_BIN);
}

int		find_error_in_format(t_args *v_args)
{
	int	index_cpy;
	int	i;

	index_cpy = v_args->index;
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
