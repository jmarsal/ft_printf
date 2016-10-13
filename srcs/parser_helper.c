/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 00:33:03 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/13 15:14:38 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	move_index_get_color(t_result *result, size_t *i, const char *color)
{
	char *format;

	format = result->format;
	if ((ft_strncmp(format + *i, color, ft_strlen(color))) == 0)
	{
		*i += ft_strlen(color);
		if (!ft_strcmp(color, "{green}"))
			STR = ft_strdup(GREEN);
		else if (!ft_strcmp(color, "{red}"))
			STR = ft_strdup(RED);
		else if (!ft_strcmp(color, "{blue}"))
			STR = ft_strdup(BLUE);
		else if (!ft_strcmp(color, "{pink}"))
			STR = ft_strdup(PINK);
		else if (!ft_strcmp(color, "{cyan}"))
			STR = ft_strdup(CYAN);
		else
			STR = ft_strdup(EOC);
		return (0);
	}
	return (-1);
}

void	get_is_color(t_result *result, size_t *i)
{
	char *format;

	format = result->format;
	if ((move_index_get_color(result, i, "{green}") == -1) &&
		(move_index_get_color(result, i, "{red}") == -1) &&
		(move_index_get_color(result, i, "{blue}") == -1) &&
		(move_index_get_color(result, i, "{pink}") == -1) &&
		(move_index_get_color(result, i, "{cyan}") == -1) &&
		(move_index_get_color(result, i, "{eoc}") == -1))
		{
			*i += 1;
			STR = ft_strdup("{");
		}
}

void	find_is_color(t_result *result, size_t *i)
{
	char	*format;

	format = result->format;
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
