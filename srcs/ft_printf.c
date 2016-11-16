/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 00:33:18 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/14 16:45:43 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int error_output(int err)
{
	if (err == -1)
		write(0, ERR_SHARP, 87);
	else if (err == -2)
		write(0, ERR_ZERO, 88);
	else if (err == -3)
		write(0, ERR_SPACE, 87);
	else if (err == -4)
		write(0, ERR_PLUS, 87);
	else if (err == -5)
		write(0, ERR_PLUS_SPACE, 53);
	else if (err == -6)
		write(0, ERR_MEM, 85);
	else if (err == -7)
		write(0, ERR_BIN, 85);
	return (-1);
}

static int	ft_vsprintf(const char *format, va_list ap)
{
	t_result	*result;
	int			err;
	int			len;
	FILE* fichier = NULL; //Pour test

	fichier = fopen("ft_printf.txt", "a+");
	
	result = NULL;
	if (!(result = init_result(ap, format)) || (treatment(result)) == -1)
		return (-1);
	if ((err = find_error_in_format(result)) != 0)
		return (error_output(err));
	if ((len = print_result(result)) == -1)
		return (-1);
	if (fichier != NULL) //idem
    {
        fputs(result->result_str->str, fichier);
        fclose(fichier);
    }
	destroy_result(&result);
	return (len);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	int			len;

	len = format ? 0 : -1;
	if (format)
	{	
		va_start(ap, format);
		len = ft_vsprintf(format, ap);
		va_end(ap);
	}
	return (len);
}
