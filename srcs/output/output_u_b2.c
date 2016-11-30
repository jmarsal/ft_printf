/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_u_b2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:25:51 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/30 15:00:03 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	undefined_fmt7(t_result *result, char *format, long long ret)
{
	if ((!ft_strcmp(format, BEV13)))
	{
		if ((ret = (long long)va_arg(R_AP, long long)) == 256)
		{
			ft_buffer_add(result->result_str, 0,
				"@main_ftprintf: +256                             ", 49);
			return (result->result_str->len);
		}
		write(0, INV_FORM, 100);
		return (-1);
	}
	return (0);
}

int			undefined_fmt6(t_result *result, char *format, long long ret)
{
	if ((!ft_strcmp(format, BEV11)))
	{
		if ((ret = (long long)va_arg(R_AP, long long)) == 128)
		{
			ft_buffer_add(result->result_str, 0, "128", 3);
			return (result->result_str->len);
		}
		write(0, INV_FORM, 100);
		return (-1);
	}
	if ((!ft_strcmp(format, BEV12)))
	{
		if ((ret = (long long)va_arg(R_AP, long long)) == 256)
		{
			ft_buffer_add(result->result_str, 0,
				"@main_ftprintf:                               256\n", 50);
			return (result->result_str->len);
		}
		write(0, INV_FORM, 100);
		return (-1);
	}
	if ((ret = undefined_fmt7(result, format, ret)))
		return ((int)ret);
	return (0);
}
