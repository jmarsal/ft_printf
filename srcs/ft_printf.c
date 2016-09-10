/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 00:33:18 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/10 02:10:18 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int         ft_printf(const char *format, ...)
{
	t_args		*v_args;
	va_list		args;
	int			len;

	if (!(v_args = init_t_args()))
		return (-1);
	len = 0;
	if (format)
	{
		va_start(args, format);
		if ((len = treatment(&args, format, v_args)) == -1)
			return (-1);
		va_end(args);
		if (find_error_in_format(v_args) != 0)
		{
			printf("error\n");
			return (-1);
		}
		// //Gestion d'erreurs ici !!!!!!!!!!!
		// if ((print_format(v_args)) == -1)
		// 	return (-1);
	}
	return (len);
}
