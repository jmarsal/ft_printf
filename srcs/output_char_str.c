/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_char_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 01:06:21 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/13 17:56:54 by jmarsal          ###   ########.fr       */
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

void		print_char_if_zero(t_result *result)
{
	char	*str_c;
	size_t	i;
	int		len;

	i = 0;
	while (RET_STR[i])
	{
		if (-1 != (len = ft_strchrpos(RET_STR + i, '~')))
		{
			str_c = ft_strsub(RET_STR, i, len);
			ft_putstr(str_c);
			ft_putchar('\0');
			i += 1;
		}
		else
		{
			str_c = ft_strsub(RET_STR, i, ft_strlen(RET_STR + i));
			ft_putstr(str_c);
		}
		i += ft_strlen(str_c);
		ft_bzero(str_c, ft_strlen(str_c));
	}
	free (str_c);
	str_c = NULL;
}
