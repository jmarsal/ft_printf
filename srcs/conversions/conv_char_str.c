/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 15:38:50 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/11 16:26:52 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	conv_char_c(t_result *result, size_t * i)
{
	char	*format;

	format = result->format;
	if (format[*i] == 'c' && !I_MOD_L)
	{
		STR = ft_memalloc(sizeof(char) * 2);
		*STR = (unsigned char)va_arg(result->ap, int);
	}
	else if ((format[*i] == 'c' && I_MOD_L) || format[*i] == 'C')
	{
		if (result->format[*i] == 'C')
				reset_flags_struct(result);
			I_MOD_L = (result->format[*i] == 'C') ? 1 : I_MOD_L;
		if (!(STR = ft_wcconv((wchar_t)va_arg(result->ap, wint_t))))
			STR = ft_strdup("(null)");
	}
	get_specifier_and_ajust_width(result, 'c');
}

void		conv_str_s(t_result *result, size_t *i)
{
	if ((result->format[*i] == 's' || result->format[*i] == 'S'))
	{
		if (result->format[*i] == 's' && !I_MOD_L)
		{
			if (!(STR = va_arg(result->ap, char *)))
				STR = ft_strdup("(null)");
		}
		else if ((result->format[*i] == 's' && I_MOD_L) ||
			result->format[*i] == 'S')
		{
			if (result->format[*i] == 'S')
				reset_flags_struct(result);
			I_MOD_L = (result->format[*i] == 'S') ? 1 : I_MOD_L;
			if (!(STR = ft_wcsconv(va_arg(result->ap, wchar_t *))))
				STR = ft_strdup("(null)");
		}
		get_specifier_and_ajust_width(result, 's');
	}
	else if (STRLEN < 1 && (result->format[*i] == 'c' || result->format[*i] == 'C'))
			conv_char_c(result, i);
	else if (result->format[*i] == 's' || result->format[*i] == 'S' ||
		result->format[*i] == 'c' || result->format[*i] == 'C')
		write(0, ERR_C_S, 104);
}
