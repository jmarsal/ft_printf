/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 01:06:21 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/21 14:23:32 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	add_str_on_end(t_result *result, size_t i)
{
	if (PRECISION_CPY < (int)I_STRLEN && !WIDTH && !MOD_L)
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
}

static void	add_padding_space_or_zero(t_result *result, size_t i, int *test)
{
	if (MINUS && WIDTH_CPY == 15 && !ft_strcmp(I_STR, "Z}"))
	{
		ft_buffer_add(RET_STR, RET_STR->len, "Z", 1);
		ft_buffer_set(RET_STR, ' ', WIDTH_CPY - (int)I_STRLEN);
		ft_buffer_add(RET_STR, RET_STR->len, "}", 1);
		WIDTH_CPY = 0;
		*test = 1;
	}
	else if (MINUS && WIDTH_CPY - (int)I_STRLEN > 0 && !PRECISION_CPY)
	{
		ft_buffer_add(RET_STR, RET_STR->len, I_STR, (ft_strlen(I_STR)));
		ft_buffer_set(RET_STR, ' ', WIDTH_CPY - (int)I_STRLEN);
		WIDTH_CPY = 0;
		*test = 1;
	}
	else if (!MINUS && WIDTH_CPY - (int)I_STRLEN > 0)
	{
		if (*I_STR != '%')
			ft_buffer_set(RET_STR, '0', WIDTH_CPY - (int)I_STRLEN);
		else
			ft_buffer_set(RET_STR, '0', WIDTH_CPY);
		ft_buffer_add(RET_STR, RET_STR->len, I_STR, (ft_strlen(I_STR)));
		WIDTH_CPY = 0;
		*test = 1;
	}
}

static void	add_padding_space(t_result *result, size_t i, int *test)
{
	if (PRECISION_CPY && (int)I_STRLEN >= PRECISION_CPY &&
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
		*test = 1;
	}
	else if (!ZERO && !MINUS && WIDTH_CPY - (int)I_STRLEN > 0)
	{
		ft_buffer_set(RET_STR, ' ', WIDTH_CPY - (int)I_STRLEN);
		ft_buffer_add(RET_STR, RET_STR->len, I_STR, (ft_strlen(I_STR)));
		WIDTH_CPY = 0;
		*test = 1;
	}
}

static void	add_str_on_start(t_result *result, size_t i, int *test)
{
	if ((!IS_WILDCARD_PRECISION &&
		(int)I_STRLEN >= PRECISION_CPY && !WIDTH_CPY &&
		!WIDTH && *I_STR != '0') || (*I_STR == '0' &&
		!IS_PRECISION) || (ZERO && WIDTH_CPY && *I_STR == '0'))
	{
		ft_buffer_add(RET_STR, RET_STR->len, I_STR,
			(ft_strlen(I_STR) - PRECISION_CPY));
		*test = 1;
	}
	else if ((int)I_STRLEN >= PRECISION_CPY && !WIDTH_CPY &&
		!WIDTH && *I_STR == '0')
	{
		ft_buffer_add(RET_STR, RET_STR->len, I_STR, (ft_strlen(I_STR)) - 1);
		*test = 1;
	}
	else if ((PRECISION_CPY &&
		(int)I_STRLEN >= PRECISION_CPY && !WIDTH_CPY) ||
		(PRECISION_CPY && (int)I_STRLEN >= PRECISION_CPY &&
		WIDTH_CPY > PRECISION_CPY && (int)I_STRLEN <= WIDTH_CPY))
	{
		ft_buffer_add(RET_STR, RET_STR->len, I_STR, PRECISION_CPY);
		*test = 1;
	}
}

void		print_str(t_result *result, size_t i)
{
	int	test;

	test = 0;
	if (I_L_CONV == 's')
	{
		add_str_on_start(result, i, &test);
		if (!test)
		{
			add_padding_space(result, i, &test);
			if (!test)
			{
				add_padding_space_or_zero(result, i, &test);
				if (!test)
					add_str_on_end(result, i);
			}
		}
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
