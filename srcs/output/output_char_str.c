/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_char_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 01:06:21 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/11 15:23:16 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	print_char(t_result *result, size_t i, size_t *test_c)
{
	if (I_L_CONV == 'c' && !MOD_L)
	{
		if (*I_STR == 0)
		{
			ft_buffer_add(RET_STR, RET_STR->len, "~", 1);
			*test_c += 1;
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
		if ((int)I_STRLEN >= PRECISION_O)
			ft_buffer_add(RET_STR, RET_STR->len, I_STR, (ft_strlen(I_STR)) - PRECISION_O);
		else
			ft_buffer_add(RET_STR, RET_STR->len, I_STR, (ft_strlen(I_STR)));
	}
}

void		print_char_str(t_result *result, size_t i, size_t *test_c)
{
	print_str(result, i);
	print_char(result, i, test_c);
}

void		print_str_if_char_to_zero(t_result *result)
{
	char	*str_c;
	size_t	i;
	int		len;

	i = 0;
	while (result->result_str->str[i])
	{
		if (-1 != (len = ft_strchrpos(result->result_str->str + i, '~')))
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
