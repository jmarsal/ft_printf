/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 15:38:50 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/11 16:03:09 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_wcslen(const wchar_t *s)
{
	size_t	i;

	i = 0;
	while (s[i] != L'\0')
		i++;
	return (i);
}

/*
**	0xxxxxxx // 0x00
**	Aucune action
**
**	110xxxxx 10xxxxxx // 0xC0 0x80
**	Je deplace de 6 sur la droite et j'ajoute 11000000
**	Je filtre par 111111 et j'ajoute 10000000
**
**	1110xxxx 10xxxxxx 10xxxxxx // 0xE0 0x80 0x80
**	Je deplace de 12 sur la droite et j'ajoute 11100000
**	Je deplace de 6, je filtre par 111111 et j'ajoute 10000000
**	Je filtre par 111111 et j'ajoute 10000000
**
**	11110xxx 10xxxxxx 10xxxxxx 10xxxxxx // 0xF0 0x80 0x80 0x80
**	Je deplace de 18 sur la droite et j'ajoute 11110000
**	Je deplace de 12 sur la droite, je filtre par 111111 et j'ajoute 10000000
**	Je deplace de 6 sur la droite, je filtre par 111111 et j'ajoute 10000000
**	Je filtre par 111111 et j'ajoute 10000000
*/

static size_t	ft_putwc(wchar_t wchar, char *str, size_t i)
{
	if (wchar <= 0x7f)
		str[i++] = wchar;
	else if (wchar <= 0x7ff)
	{
		str[i++] = (wchar >> 6) + 0xC0;
		str[i++] = (wchar & 0x3F) + 0x80;
	}
	else if (wchar <= 0xffff)
	{
		str[i++] = (wchar >> 12) + 0xE0;
		str[i++] = ((wchar >> 6) & 0x3F) + 0x80;
		str[i++] = (wchar & 0x3F) + 0x80;
	}
	else
	{
		str[i++] = (wchar >> 18) + 0xF0;
		str[i++] = ((wchar >> 12) & 0x3F) + 0x80;
		str[i++] = ((wchar >> 6) & 0x3F) + 0x80;
		str[i++] = (wchar & 0x3F) + 0x80;
	}
	return (i);
}

/*
**		Transforme les wchar en char
*/

static char	*ft_putwcs(wchar_t *ws)
{
	char	*str_tmp;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!ws)
		return (0);
	i = 0;
	j = 0;
	len = ft_wcslen(ws) * sizeof(wchar_t) + 1;
	str_tmp = ft_memalloc(sizeof(char) * len);
	while (ws[j])
		i = ft_putwc(ws[j++], str_tmp, i);
	return (str_tmp);
}

static void	conv_char_c(va_list *ap, t_result *result, const char *format,
					size_t * i)
{
	if (format[*i] == 'c' && !I_MOD_L)
	{
		get_specifier_and_ajust_width('c', result);
		C = (unsigned char)va_arg(*ap, int);
		ajust_width_precision_itoa_base(result, 10);
	}
	else if ((format[*i] == 'c' && I_MOD_L) || format[*i] == 'C')
	{
		STR = ft_strnew(1);
		I_MOD_L = 1;
		get_specifier_and_ajust_width('c', result); // voir si 's' ok
		ft_putwc((wchar_t)va_arg(*ap, wint_t), STR, 0);
		//test vs code
	}
}

void		conv_str_s(va_list *ap, t_result *result, const char *format,
		size_t *i)
{
	char	*ret;

	ret = NULL;
	if (!IS_MODIFIER || I_MOD_L)
	{
		if (format[*i] == 's' && !I_MOD_L)
		{
			get_specifier_and_ajust_width('s', result);
			STR = ft_strdup(va_arg(*ap, char *));
			I_WIDTH_CPY -= ft_strlen(STR);
			I_PRECISION_CPY -= ft_strlen(STR);
		}
		else if ((format[*i] == 's' && I_MOD_L) || format[*i] == 'S')
		{
			I_MOD_L = 1;
			get_specifier_and_ajust_width('s', result);
			STR = ft_putwcs(va_arg(*ap, wchar_t *));
		}
		conv_char_c(ap, result, format, i);
	}
	else if (format[*i] == 's' || format[*i] == 'S' || format[*i] == 'c' ||
			format[*i] == 'C')
	{
		ft_putstr(ERR_C_S);
	}
}
