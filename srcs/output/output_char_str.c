/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_char_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 01:06:21 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/22 00:59:21 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	print_char(t_result *result, size_t i, size_t *test_c)
{
	if (I_L_CONV == 'c' && !MOD_L)
	{
		if (*I_STR == 0)
		{
			RET_STR = ft_strjoin(RET_STR, "~");
			*test_c += 1;
		}
		else
			RET_STR = ft_strjoin(RET_STR, I_STR);
	}
	else if (I_L_CONV == 'c' && MOD_L)
		RET_STR = ft_strjoin(RET_STR, I_STR);
}

static void	print_str(t_result *result, size_t i)
{
	if (I_L_CONV == 's')
		RET_STR = ft_strjoin(RET_STR, I_STR);
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
