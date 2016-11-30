/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 15:38:50 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/30 16:16:35 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	conv_char_c(t_result *result, size_t *i)
{
	char	*format;
	char	tmp[2];

	format = result->format;
	if (format[*i] == 'c' && !I_MOD_L)
	{
		tmp[0] = (unsigned char)va_arg(R_AP, int);
		tmp[1] = '\0';
		STR = ft_strdup(tmp);
	}
	else if ((format[*i] == 'c' && I_MOD_L) || format[*i] == 'C')
	{
		if (result->format[*i] == 'C')
			reset_flags_struct(result);
		I_MOD_L = (result->format[*i] == 'C') ? 1 : I_MOD_L;
		if (!(STR = ft_wcconv((wchar_t)va_arg(R_AP, wint_t))))
			STR = ft_strdup("(null)");
	}
	get_specifier_and_ajust_width(result, 'c');
}

static void	get_str_conv(t_result *result, size_t *i, char *tmp)
{
	if (result->format[*i] == 's' && !I_MOD_L)
	{
		if (!(tmp = va_arg(R_AP, char *)))
			STR = ft_strdup("(null)");
		else
			STR = ft_strdup(tmp);
	}
	else if ((result->format[*i] == 's' && I_MOD_L) ||
		result->format[*i] == 'S')
	{
		if (result->format[*i] == 'S')
			reset_flags_struct(result);
		I_MOD_L = (result->format[*i] == 'S') ? 1 : I_MOD_L;
		if (!(tmp = ft_wcsconv(va_arg(R_AP, wchar_t *))))
			STR = ft_strdup("(null)");
		else
			STR = tmp;
	}
}

void		conv_str_s(t_result *result, size_t *i)
{
	char	*tmp;

	tmp = NULL;
	if (result->format[*i] == 's' || result->format[*i] == 'S')
	{
		get_str_conv(result, i, tmp);
		get_specifier_and_ajust_width(result, 's');
	}
	else if (STRLEN < 1 && (result->format[*i] == 'c' ||
		result->format[*i] == 'C'))
		conv_char_c(result, i);
}
