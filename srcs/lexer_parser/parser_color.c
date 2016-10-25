/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 12:05:23 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/25 17:27:00 by jmarsal          ###   ########.fr       */
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

void		lexer_parser_color(t_result *result, size_t *i)
{
	char	*format;

	format = result->format;
	if (format[*i] == '{')
		{
			tab_conv_add(result, result->i_args);		
			L_CONV = 's';
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
			result->i_args++;
		}
}
