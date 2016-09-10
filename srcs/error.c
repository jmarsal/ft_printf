/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 02:06:27 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/10 02:26:45 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		find_error_in_format(t_args *v_args)
{
	int	index_cpy;
	int	i;

	index_cpy = v_args->index;
	i = 0;
	while (index_cpy--)
	{
		if (v_args->f_conv[i]->caracters->sharp == 1 &&
			(!ft_strchr(ERR_SHARP, v_args->f_conv[i]->l_conv)))
			return (-1);
		i++;
	}
	return (0);
}
