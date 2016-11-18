/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 16:21:47 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/18 17:07:48 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	search_for_print_zero(t_result *result)
{
	t_buffer	*buff_tmp;
	char	*str_c;
	size_t	i;
	int		len;

	buff_tmp = ft_buffer_new(0);
	i = 0;
	while (result->result_str->str[i])
	{
		str_c = NULL;
		if ((len = ft_strchrpos(result->result_str->str + i, 140)) != -1)
		{
			str_c = ft_strsub(result->result_str->str, i, len);
			i += 1;
		}
		else
			str_c = ft_strsub(result->result_str->str, i,
								result->result_str->len + i);
		ft_buffer_add(buff_tmp, buff_tmp->len, str_c, ft_strlen(str_c));
		i += ft_strlen(str_c);
	}
	result->result_str->str = ft_strdup(buff_tmp->str);
	result->result_str->len = buff_tmp->len;
	ft_buffer_destroy(&buff_tmp);
	ft_free_null(str_c);
}

static int	ft_vsprintf(char *ret, const char *format, va_list ap)
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
	// ret = ft_strnew((int)ft_strlen(result->result_str->str));
	ret = ft_strcpy(ret, result->result_str->str);
	destroy_result(&result);
	return (len);
}

int			ft_sprintf(char *restrict str, const char * restrict format, ...)
{
	va_list		ap;
	int			len;

	len = format ? 0 : -1;
	if (format)
	{	
		va_start(ap, format);
		len = ft_vsprintf(str, format, ap);
		va_end(ap);
	}
	return (len);
}
