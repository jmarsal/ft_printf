/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 15:38:50 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/30 17:06:52 by jmarsal          ###   ########.fr       */
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

static void	conv_char_c(va_list *args, t_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i] == 'c' && !I_MOD_L)
	{
		get_specifier_and_ajust_width('c', v_args);
		C = (unsigned char)va_arg(*args, int);
		ajust_width_precision_itoa_base(v_args, 10);
	}
	else if ((format[*i] == 'c' && I_MOD_L) || format[*i] == 'C')
	{
		STR = ft_strnew(0);
		I_MOD_L = 1;
		get_specifier_and_ajust_width('c', v_args); // voir si 's' ok
		wctomb(STR, va_arg(*args, wint_t));
	}
}

void		conv_str_s(va_list *args, t_args *v_args, const char *format,
					size_t * i)
{
	wchar_t	*tmp;
	size_t	tmp_len;
	size_t	j;
	char	*ret;

	tmp = NULL;
	ret = NULL;
	tmp_len = 0;
	j = 0;
	if (format[*i] == 's' && !I_MOD_L)
	{
		get_specifier_and_ajust_width('s', v_args);
		STR = ft_strdup(va_arg(*args, char *));
		I_WIDTH_CPY -= ft_strlen(STR);
		I_PRECISION_CPY -= ft_strlen(STR);
	}
	else if ((format[*i] == 's' && I_MOD_L) || format[*i] == 'S')
	{
		I_MOD_L = 1;
		get_specifier_and_ajust_width('s', v_args);
		tmp = va_arg(*args, wchar_t *);
		tmp_len = ft_wcslen(tmp) * sizeof(wchar_t) + 1;
		STR = ft_memalloc(sizeof(char) * tmp_len);
		while (tmp[j] != L'\0')
		{
			ret = ft_strnew(0);
			wctomb(ret, tmp[j++]);
			STR = ft_strjoin(STR, ret);
			free(ret);
		}
	}
	conv_char_c(args, v_args, format, i);
}
