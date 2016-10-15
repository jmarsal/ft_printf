/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 00:33:18 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/15 01:25:07 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int error_output(int err)
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
	return (-1);
}

static int	ft_vasprintf(va_list ap, const char *format)
{
	t_result	*result;
	int			err;
	int			len;

	result = NULL;
	if (!(result = init_result(ap, format)))
			return (-1);
	if ((treatment(result)) == -1)
			return (-1);
	if ((err = find_error_in_format(result)) != 0)
			return (error_output(err));
	if ((len = print_result(result)) == -1)
				return (-1);
	destroy_result(&result);
	return (len);
}

int         ft_printf(const char *format, ...)
{
	va_list		ap;
	int			len;

	len = format ? 0 : -1;
	if (format)
	{	
		va_start(ap, format);
		len = ft_vasprintf(ap, format);
		va_end(ap);
	}
	return (len);
}
