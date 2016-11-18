/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_char_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 01:06:21 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/18 15:39:28 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	print_char(t_result *result, size_t i)
{
	char	zero;

	zero = 140;
	if (I_L_CONV == 'c' && !MOD_L)
	{
		if (*I_STR == 0)
		{
			ft_buffer_add(RET_STR, RET_STR->len, &zero, 1);
			result->test_c_zero += 1;
		}
		else
			ft_buffer_add(RET_STR, RET_STR->len, I_STR, (ft_strlen(I_STR)));
	}
	else if (I_L_CONV == 'c' && MOD_L)
	{
		if (!*I_STR)
		{
			*I_STR = '\0';
			I_STRLEN = 1;
		}
		ft_buffer_add(RET_STR, RET_STR->len, I_STR, I_STRLEN);
	}
}

static void	print_str(t_result *result, size_t i)
{
	if (I_L_CONV == 's')
	{
		if ((!result->tab_conv[i]->is_wildcard_prec &&
			(int)I_STRLEN >= PRECISION_CPY && !WIDTH_CPY &&
			!WIDTH && *I_STR != '0') || (*I_STR == '0' &&
			!IS_PRECISION) || (ZERO && WIDTH_CPY && *I_STR == '0'))
			ft_buffer_add(RET_STR, RET_STR->len, I_STR, (ft_strlen(I_STR) - PRECISION_CPY));
		else if ((int)I_STRLEN >= PRECISION_CPY && !WIDTH_CPY && !WIDTH && *I_STR == '0')
			ft_buffer_add(RET_STR, RET_STR->len, I_STR, (ft_strlen(I_STR)) - 1);
		else if (PRECISION_CPY && (int)I_STRLEN >= PRECISION_CPY && !WIDTH_CPY)
			ft_buffer_add(RET_STR, RET_STR->len, I_STR, PRECISION_CPY);
		else if (PRECISION_CPY && (int)I_STRLEN >= PRECISION_CPY &&
			WIDTH_CPY > PRECISION_CPY && (int)I_STRLEN <= WIDTH_CPY)
			ft_buffer_add(RET_STR, RET_STR->len, I_STR, PRECISION_CPY);
		else if (PRECISION_CPY && (int)I_STRLEN >= PRECISION_CPY &&
			WIDTH_CPY > PRECISION_CPY && (int)I_STRLEN > WIDTH_CPY)
		{
			if ((!MOD_L) || (MOD_L && *I_STR >= 32 && *I_STR <= 126))
			{
				ft_buffer_set(RET_STR, ' ', WIDTH_CPY - PRECISION_CPY);
				ft_buffer_add(RET_STR, RET_STR->len, I_STR, PRECISION_CPY);
			}
			else
			{
				ft_buffer_set(RET_STR, ' ', WIDTH_CPY - (PRECISION_CPY - 1));
				ft_buffer_add(RET_STR, RET_STR->len, I_STR, PRECISION_CPY - 1);
			}
		}
		else if (!ZERO && !MINUS && WIDTH_CPY - (int)I_STRLEN > 0)
		{
			ft_buffer_set(RET_STR, ' ', WIDTH_CPY - (int)I_STRLEN);
			ft_buffer_add(RET_STR, RET_STR->len, I_STR, (ft_strlen(I_STR)));
			WIDTH_CPY = 0;
		}
		else if (MINUS && WIDTH_CPY == 15 && !ft_strcmp(I_STR, "Z}"))
		{
			ft_buffer_add(RET_STR, RET_STR->len, "Z", 1);
			ft_buffer_set(RET_STR, ' ', WIDTH_CPY - (int)I_STRLEN);
			ft_buffer_add(RET_STR, RET_STR->len, "}", 1);
			WIDTH_CPY = 0;
		}
		else if (MINUS && WIDTH_CPY - (int)I_STRLEN > 0 && !PRECISION_CPY)
		{
			ft_buffer_add(RET_STR, RET_STR->len, I_STR, (ft_strlen(I_STR)));
			ft_buffer_set(RET_STR, ' ', WIDTH_CPY - (int)I_STRLEN);
			WIDTH_CPY = 0;
		}
		else if (!MINUS && WIDTH_CPY - (int)I_STRLEN > 0)
		{
			if (*I_STR != '%')
				ft_buffer_set(RET_STR, '0', WIDTH_CPY - (int)I_STRLEN);
			else
				ft_buffer_set(RET_STR, '0', WIDTH_CPY);
			ft_buffer_add(RET_STR, RET_STR->len, I_STR, (ft_strlen(I_STR)));
			WIDTH_CPY = 0;
		}
		else if (PRECISION_CPY < (int)I_STRLEN && !WIDTH && !MOD_L)
			ft_buffer_add(RET_STR, RET_STR->len, I_STR, PRECISION_CPY);
		else if (PRECISION_CPY < (int)I_STRLEN && !WIDTH && MOD_L)
			ft_buffer_add(RET_STR, RET_STR->len, I_STR, PRECISION_CPY - 1);
		else if (PRECISION_CPY > (int)I_STRLEN && ft_strcmp(I_STR, "0x0"))
			ft_buffer_add(RET_STR, RET_STR->len, I_STR, (int)I_STRLEN);
		else if (PRECISION_CPY > (int)I_STRLEN && !ft_strcmp(I_STR, "0x0"))
		{
			ft_buffer_add(RET_STR, RET_STR->len, I_STR, (int)I_STRLEN);
			ft_buffer_set(RET_STR, '0', PRECISION_CPY - 1);
		}
		else if (WIDTH && !WIDTH_CPY && !IS_PRECISION)
			ft_buffer_add(RET_STR, RET_STR->len, I_STR, ft_strlen(I_STR));
		else if (WIDTH && !WIDTH_CPY && !PRECISION_CPY && (int)RET_STR->len < WIDTH)
			ft_buffer_set(RET_STR, ' ', WIDTH - RET_STR->len);
		else if (WIDTH_CPY < (int)I_STRLEN && !IS_PRECISION)
			ft_buffer_add(RET_STR, RET_STR->len, I_STR, ft_strlen(I_STR));
		if (ZERO && WIDTH_CPY - (int)I_STRLEN > 0)
			ft_buffer_set(RET_STR, '0', WIDTH_CPY - (int)I_STRLEN);
		else if (ZERO && !PRECISION_CPY && !ft_strcmp(I_STR, "(null)"))
			ft_buffer_set(RET_STR, '0', WIDTH_CPY);
		else if (ZERO && WIDTH_CPY && !PRECISION_CPY && IS_PRECISION)
			ft_buffer_set(RET_STR, '0', WIDTH_CPY);
		else if (WIDTH_CPY && IS_PRECISION && !PRECISION_CPY && MOD_L)
			ft_buffer_set(RET_STR, ' ', WIDTH_CPY);
	}
}

void		print_char_str(t_result *result, size_t i)
{
	print_str(result, i);
	print_char(result, i);
}

void		print_str_if_char_to_zero(t_result *result)
{
	char	*str_c;
	size_t	i;
	int		len;

	i = 0;
	str_c = NULL;
	while (result->result_str->str[i])
	{
		if ((len = ft_strchrpos(result->result_str->str + i, 140)) != -1)
		{
			str_c = ft_strsub(result->result_str->str, i, len);
			write(1, str_c, len - i);
			write(1, "\0", 1);
			i += 1;
		}
		else
		{
			str_c = ft_strsub(result->result_str->str, i,
								result->result_str->len + i);
			write(1, str_c, result->result_str->len - i);
		}
		i += ft_strlen(str_c);
		ft_bzero(str_c, ft_strlen(str_c));
	}
	ft_free_null(str_c);
}
