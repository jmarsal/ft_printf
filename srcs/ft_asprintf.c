/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 09:26:26 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/30 18:23:55 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	search_for_print_zero(t_result *result)
{
	t_buffer	*buff_tmp;
	char		*str_c;
	size_t		i;
	int			len;

	buff_tmp = ft_buffer_new(0);
	i = 0;
	while (RESULT_STR[i])
	{
		str_c = NULL;
		if ((len = ft_strchrpos(RESULT_STR + i, 140)) != -1)
		{
			str_c = ft_strsub(RESULT_STR, i, len);
			i += 1;
		}
		else
			str_c = ft_strsub(RESULT_STR, i, RESULT_LEN + i);
		ft_buffer_add(buff_tmp, buff_tmp->len, str_c, ft_strlen(str_c));
		i += ft_strlen(str_c);
	}
	RESULT_STR = ft_strdup(buff_tmp->str);
	RESULT_LEN = buff_tmp->len;
	ft_buffer_destroy(&buff_tmp);
	ft_free(str_c);
}

static int	ft_vsprintf(char **ret, const char *format, va_list ap)
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
	search_for_print_zero(result);
	*ret = ft_strdup(RESULT_STR);
	destroy_result(&result);
	return (len);
}

/*
** Alloue dynamiquement ret et y copie le retour de buffer de la conversion
*/

int			ft_asprintf(char **ret, const char *format, ...)
{
	va_list		ap;
	int			len;

	len = format ? 0 : -1;
	if (format)
	{
		va_start(ap, format);
		len = ft_vsprintf(ret, format, ap);
		va_end(ap);
	}
	return (len);
}
