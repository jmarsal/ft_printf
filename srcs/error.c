/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 02:06:27 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/14 01:24:21 by jmarsal          ###   ########.fr       */
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
		if (v_args->f_conv[i]->caracters->sharp == 1 &&
			(!ft_strchr(GOOD_SHARP, v_args->f_conv[i]->l_conv)))
			return (-1);
		else if (v_args->f_conv[i]->caracters->zero == 1 &&
			(!ft_strchr(GOOD_ZERO, v_args->f_conv[i]->l_conv)))
			return (-2);
		else if (v_args->f_conv[i]->caracters->space == 1 &&
			(!ft_strchr(GOOD_SPACE, v_args->f_conv[i]->l_conv)))
			return (-3);
		else if (v_args->f_conv[i]->caracters->plus == 1 &&
			(!ft_strchr(GOOD_PLUS, v_args->f_conv[i]->l_conv)))
			return (-4);
		else if (v_args->f_conv[i]->caracters->plus == 1 &&
			v_args->f_conv[i]->caracters->space)
			return (-5);
		else if (v_args->f_conv[i]->l_conv == 'p' &&
			v_args->f_conv[i]->is_precision == 1)
			return (-6);
		else if (v_args->f_conv[i]->l_conv == 'b' &&
			v_args->f_conv[i]->is_precision == 1)
			return (-7);
		// pointeur ne marche pas avec '+', ' ', '#', 'precision(.6)', '0'
		// marche avec 'width', '-'
		////////////////////////////////////////////////////////////////////////
		// binaire ne marche pas avec '+', '#', 'precision', '0'
		// marche ' ', '-', 'width'
		i++;
	}
	return (0);
}
