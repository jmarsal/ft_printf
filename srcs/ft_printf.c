/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 00:33:18 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/17 15:55:18 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
	if ((err = find_error_in_format(result)))
		return (-1);
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
