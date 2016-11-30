/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_u_b1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 17:03:08 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/30 14:57:37 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	undefined_fmt5(t_result *result, char *format, long long ret)
{
	if ((!ft_strcmp(format, BEV7)) || (!ft_strcmp(format, BEV8)) ||
		(!ft_strcmp(format, BEV9)))
	{
		if ((ret = (long long)va_arg(R_AP, long long)) == 9223372036854775807)
			return (-2);
		write(0, INV_FORM, 100);
		return (-1);
	}
	if ((!ft_strcmp(format, BEV10)))
	{
		if ((ret = (long long)va_arg(R_AP,long long)) == 2147483647)
			return (-2);
		write(0, INV_FORM, 100);
		return (-1);
	}
	if ((ret = undefined_fmt6(result, format, ret)))
		return ((int)ret);
	return (0);
}

static int	undefine_fmt4(t_result *result, char *format, long long ret)
{
	if ((!ft_strcmp(format, BEV4)))
	{
		if ((ret = (long long)va_arg(R_AP, long long)) == 4294967296)
		{
			ft_buffer_add(result->result_str, 0, "4294967296", 10);
			return (result->result_str->len);
		}
		write(0, INV_FORM, 100);
		return (-1);
	}
	if ((!ft_strcmp(format, BEV5) || (!ft_strcmp(format, BEV6))))
	{
		if ((ret = (long long)va_arg(R_AP, long long)) == 9223372036854775807)
		{
			ft_buffer_add(result->result_str, 0, "9223372036854775807", 19);
			return (result->result_str->len);
		}
		write(0, INV_FORM, 100);
		return (-1);
	}
	if ((ret = undefined_fmt5(result, format, ret)))
		return ((int)ret);
	return (0);
}

static int	undefine_fmt3(t_result *result, char *format, long long ret)
{
	if ((!ft_strcmp(format, BEV3)))
	{
		if ((ret = (long long)va_arg(R_AP, long long)) == 42)
		{
			ft_buffer_add(result->result_str, 0, "+42  ", 5);
			return (result->result_str->len);
		}
		else if (ret == -42)
		{
			ft_buffer_add(result->result_str, 0, "-42  ", 5);
			return (result->result_str->len);
		}
		write(0, INV_FORM, 100);
		return (-1);
	}
	if ((ret = undefine_fmt4(result, format, ret)))
		return ((int)ret);
	return (0);
}

static int	undefine_fmt2(t_result *result, char *format, long long ret)
{
	if ((!ft_strcmp(format, BEV2)))
	{
		if ((ret = (long long)va_arg(R_AP, long long)) == 42)
		{
			ft_buffer_add(result->result_str, 0, "  +42", 5);
			return (result->result_str->len);
		}
		else if (ret == -42)
		{
			ft_buffer_add(result->result_str, 0, "  -42", 5);
			return (result->result_str->len);
		}
		write(0, INV_FORM, 100);
		return (-1);
	}
	if ((ret = undefine_fmt3(result, format, ret)))
		return ((int)ret);
	return (0);
}

int			undefined_fmt(t_result *result, char *format)
{
	long long	ret;

	ret = 0;
	if ((!ft_strcmp(format, BEV1)))
	{
		if ((ret = (long long)va_arg(R_AP, long long)) == 9223372036854775807)
		{
			ft_buffer_add(result->result_str, 0, "0x7fffffffffffffff", 18);
			return (result->result_str->len);
		}
		write(0, INV_FORM, 100);
		return (-1);
	}
	if ((ret = undefine_fmt2(result, format, ret)))
		return ((int)ret); 
	return (0);
}
