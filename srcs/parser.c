/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 17:03:08 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/16 22:31:37 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*static int get_modifier(const char *format, size_t *i)
{
	size_t	count;
	size_t	j;

	count = 0;
	j = *i + 1;
	while ((is_conversion_flag(format, i, L_MODIFIER) == 1) && count < 2)
	{
		if ((count == 1 && is_conversion_flag(format, &j, L_MODIFIER) == 1) ||
			(count == 1 && (format[*i] == 'j' || format[*i] == 'z')))
			return (-1);
		*i += 1;
		j = *i + 1;
		count++;
	}
	return (0);
}

static int	if_specifier(const char *format, t_w_or_p tmp, size_t *i,
							size_t *index)
{
	while (is_conversion_flag(format, i, CARACTERS) == 1)
		*i += 1;
	if (is_conversion_flag(format, i, F_WIDTH) == 1)
	{
		while (ft_isalnum(format[*i]))
			*i += 1;
		tmp.width = 1;
	}
	if (is_conversion_flag(format, i, PRECISION) == 1)
	{
		*i += 1;
		while (ft_isalnum(format[*i]))
			*i += 1;
		tmp.precision = 1;
	}
	*i = (tmp.width == 1 || tmp.precision == 1) ? *i - 1 : *i;
	if (get_modifier(format, i) == -1)
		return (-1);
	if (is_conversion_flag(format, i, C_SPECIFIERS) == 1)
	{
		*index += 1;
		*i += 1;
		return (0);
	}
	return (-1);
}

static int	get_index(t_result *result, size_t *i)
{
	t_w_or_p	tmp;
	char		*format;

	tmp.width = 0;
	tmp.precision = 0;
	format = result->format;
	*i += 1;
	if (if_specifier(format, tmp, i, &result->index) != -1)
		return(0);
	else
	{
		ft_putstr("error : invalid conversion specifier '");
		format[*i] == '.' ?
				ft_putchar(format[*i + 1]) : ft_putchar(format[*i]);
		ft_putstr("'\n");
	}
	return (-1);
}

static int	search_flags_in_format(t_result *result)
{
	char	*format;
	size_t	i;

	format = result->format;
	i = 0;
	while (format[i])
	{
		while (format[i] != '%' && format[i] != '{')
		{
			if (format[i + 1] == '%' || format[i + 1] == '{' ||
				format[i] == '\0' || format[i + 1] == '\n')
			{
				result->index++;
				if (format[i])
					i++;
				break;
			}
			i++;
		}
		find_is_color(result, &i);
		if (format[i + 1] && (format[i] == '%' && format[i + 1] == '%'))
		{
			i += 2;
			result->index++;
		}
		else if (format[i + 1] && format[i] == '%' &&
				(get_index(result, &i) == -1))
			return (-1);
	}
	return (0);
}*/

int			treatment(t_result *result)
{
	// if (search_flags_in_format(result) == -1)
	// 	return (-1);
	// if (!(result->tab_conv = tab_conv_create(result)))
	// 	return (-1);
	result->tab_conv = tab_conv_add(result, result->i_args);
	get_content_format(result);
	result->index = result->i_args;
	return (0);
}
