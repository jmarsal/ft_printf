/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_char_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 01:06:21 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/25 17:39:42 by jmarsal          ###   ########.fr       */
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
			ft_buffer_add(RET_STR, RET_STR->len, I_STR, ft_strlen(I_STR));
	}
	else if (I_L_CONV == 'c' && MOD_L)
		ft_buffer_add(RET_STR, RET_STR->len, I_STR, ft_strlen(I_STR));
}

static void	print_str(t_result *result, size_t i)
{
	if (I_L_CONV == 's')
		ft_buffer_add(RET_STR, RET_STR->len, I_STR, ft_strlen(I_STR));
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
	while (result->result_str[i])
	{
		if (-1 != (len = ft_strchrpos(result->result_str + i, '~')))
		{
			str_c = ft_strsub(result->result_str, i, len);
			ft_putstr(str_c);
			ft_putchar('\0');
			i += 1;
		}
		else
		{
			str_c = ft_strsub(result->result_str, i,
					ft_strlen(result->result_str + i));
			ft_putstr(str_c);
		}
		i += ft_strlen(str_c);
		ft_bzero(str_c, ft_strlen(str_c));
	}
	ft_free_null(str_c);
}
