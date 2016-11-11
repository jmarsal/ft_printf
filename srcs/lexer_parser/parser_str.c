/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 14:59:44 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/11 13:57:56 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	get_str(t_result *result, size_t *i, int j)
{
	int	k;

	k = -1;
	tab_conv_add(result, result->i_args);	
	L_CONV = 's';
	STR = ft_strnew(j + 1);
	if (result->format[*i - j] == '%' && result->format[*i + 1] == '\0')
		STR = "";
	else
	{
		while (++k <= j)
			STR[k] = result->format[*i - j + k];
		STR[++k] = '\0';
	}
	result->i_args++;
	*i = (result->format[*i]) ? *i + 1 : *i;
}

void		parser_str(t_result *result, size_t *i)
{
	char	*format;
	int		j;

	format = result->format;
	j = 0;
	while ((format[*i] != '%' && format[*i] != '{') ||
			(format[*i] == '%' && format[*i + 1] == '\0'))
	{
		if (format[*i] == '\0' || format[*i + 1] == '%' ||
			format[*i + 1] == '{' || format[*i] == '\n')
		{
			get_str(result, i, j);
			break ;
		}
		*i += 1;
		j++;
	}
}
