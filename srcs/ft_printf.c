/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 00:33:18 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/02 02:32:42 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void error_output(int err)
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

int         ft_printf(const char *format, ...)
{
	t_args		*v_args;
	va_list		args;
	int			len;
	int			err;

	if (!(v_args = init_t_args()))
		return (-1);
	len = format ? 0 : -1;
	if (format)
	{
		va_start(args, format);
		if ((treatment(&args, format, v_args)) == -1)
			return (-1);
		va_end(args);
		if ((err = find_error_in_format(v_args)) != 0)
		{
			error_output(err);
			return (-1);
		}
		else
			if ((len = print_format(v_args)) == -1)
				return (-1);
	}
	return (len);
}
