/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 02:06:27 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/21 16:53:35 by jmarsal          ###   ########.fr       */
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
		if (I_L_CONV == 'b' && IS_PRECISION == 1)
		{
			write(0, ERR_BIN, 85);
			return (-1);
		}
		i++;
	}
	return (0);
}

int		print_error_specifier(char caracters)
{
	write(0, "error : invalid conversion specifier '", 38);
	write(0, &caracters, 1);
	write(0, "'\n", 2);
	return (-1);
}
