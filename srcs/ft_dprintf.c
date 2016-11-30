/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:04:07 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/30 18:24:57 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_vsprintf(int fd, const char *format, va_list ap)
{
	t_result	*result;
	int			err;
	int			len;

	result = NULL;
	if (!(result = init_result(ap, format)) || (treatment(result)) == -1)
		return (-1);
	if ((err = find_error_in_format(result)))
		return (-1);
	if ((len = print_result(result)) == -1)
		return (-1);
	if (result->test_c_zero > 0)
		print_str_in_fd_if_char_to_zero(fd, result);
	else
		write(fd, RESULT_STR, RESULT_LEN);
	destroy_result(&result);
	return (len);
}

/*
** Ecrit dans un fichier le retour de buffer de la conversion
*/

int			ft_dprintf(int fd, const char *format, ...)
{
	va_list		ap;
	int			len;

	len = format ? 0 : -1;
	if (format)
	{
		va_start(ap, format);
		len = ft_vsprintf(fd, format, ap);
		va_end(ap);
	}
	return (len);
}
