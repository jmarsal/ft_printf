/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:44:21 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/21 13:47:08 by jmarsal          ###   ########.fr       */
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
	while (RESULT_STR[i])
	{
		str_c = NULL;
		if ((len = ft_strchrpos(RESULT_STR + i, 140)) != -1)
		{
			str_c = ft_strsub(RESULT_STR, i, len);
			write(1, str_c, len - i);
			write(1, "\0", 1);
			i += 1;
		}
		else
		{
			str_c = ft_strsub(RESULT_STR, i,
								RESULT_LEN + i);
			write(1, str_c, RESULT_LEN - i);
		}
		i += ft_strlen(str_c);
	}
	ft_free_null(str_c);
}
