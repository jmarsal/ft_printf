/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 00:33:03 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/11 16:02:15 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	get_is_color_suite(const char *format, size_t *i, t_result *result)
{
	if ((ft_strncmp(format + *i, "{cyan}", ft_strlen("{cyan}"))) == 0)
	{
		*i += ft_strlen("{cyan}");
		STR = ft_strdup(CYAN);
	}
	else if ((ft_strncmp(format + *i, "{eoc}", ft_strlen("{eoc}"))) == 0)
	{
		*i += ft_strlen("{eoc}");
		STR = ft_strdup(EOC);
	}
	else
	{
		*i += 1;
		STR = ft_strdup("{");
	}
}

void	get_is_color(const char *format, size_t *i, t_result *result)
{
	if ((ft_strncmp(format + *i, "{green}", ft_strlen("{green}"))) == 0)
	{
		*i += ft_strlen("{green}");
		STR = ft_strdup(GREEN);
	}
	else if ((ft_strncmp(format + *i, "{red}", ft_strlen("{red}"))) == 0)
	{
		*i += ft_strlen("{red}");
		STR = ft_strdup(RED);
	}
	else if ((ft_strncmp(format + *i, "{blue}", ft_strlen("{blue}"))) == 0)
	{
		*i += ft_strlen("{blue}");
		STR = ft_strdup(BLUE);
	}
	else if ((ft_strncmp(format + *i, "{pink}", ft_strlen("{pink}"))) == 0)
	{
		*i += ft_strlen("{pink}");
		STR = ft_strdup(PINK);
	}
	else
		get_is_color_suite(format, i, result);
}

void		find_is_color(const char *format, size_t *i, t_result *result)
{
	if (format[*i] == '{')
	{
		if ((ft_strncmp(format + *i, "{green}", ft_strlen("{green}"))) == 0)
			*i += ft_strlen("{green}");
		else if ((ft_strncmp(format + *i, "{red}", ft_strlen("{red}"))) == 0)
			*i += ft_strlen("{red}");
		else if ((ft_strncmp(format + *i, "{blue}", ft_strlen("{blue}"))) == 0)
			*i += ft_strlen("{blue}");
		else if ((ft_strncmp(format + *i, "{pink}", ft_strlen("{pink}"))) == 0)
			*i += ft_strlen("{pink}");
		else if ((ft_strncmp(format + *i, "{cyan}", ft_strlen("{cyan}"))) == 0)
			*i += ft_strlen("{cyan}");
		else if ((ft_strncmp(format + *i, "{eoc}", ft_strlen("{eoc}"))) == 0)
			*i += ft_strlen("{eoc}");
		else
			*i += 1;
		result->index++;
	}
}

int			is_conversion_flag(const char *format, size_t *i,
									const char *flags)
{
	if ((ft_strchr(flags, format[*i]) != NULL))
		return (1);
	return (-1);
}
