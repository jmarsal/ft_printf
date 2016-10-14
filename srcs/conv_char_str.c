/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 15:38:50 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/14 10:59:56 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	conv_char_c(t_result *result, size_t * i)
{
	char	*format;

	format = result->format;
	if (format[*i] == 'c' && !I_MOD_L)
	{
		get_specifier_and_ajust_width(result, 'c');
		STR[0] = (unsigned char)va_arg(result->ap, int);
		STR[1] = '\0';
		ajust_width_precision_itoa_base(result);
	}
	else if ((format[*i] == 'c' && I_MOD_L) || format[*i] == 'C')
	{
		I_MOD_L = 1;
		get_specifier_and_ajust_width(result, 'c');
		STR = ft_wcconv((wchar_t)va_arg(result->ap, wint_t));
	}
}

void		conv_str_s(t_result *result, size_t *i)
{
	if (!IS_MODIFIER || I_MOD_L)
	{
		if (result->format[*i] == 's' && !I_MOD_L)
		{
			get_specifier_and_ajust_width(result, 's');
			STR = ft_strdup(va_arg(result->ap, char *));
			I_WIDTH_CPY -= ft_strlen(STR);
			I_PRECISION_CPY -= ft_strlen(STR);
		}
		else if ((result->format[*i] == 's' && I_MOD_L) ||
			result->format[*i] == 'S')
		{
			I_MOD_L = 1;
			get_specifier_and_ajust_width(result, 's');
			STR = ft_wcsconv(va_arg(result->ap, wchar_t *));
		}
		conv_char_c(result, i);
	}
	else if (result->format[*i] == 's' || result->format[*i] == 'S' ||
		result->format[*i] == 'c' || result->format[*i] == 'C')
		ft_putstr(ERR_C_S);
}
