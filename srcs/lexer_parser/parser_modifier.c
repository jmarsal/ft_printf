/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_modifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:54:36 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/30 15:02:21 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	find_witch_modifier(t_result *result, char *tmp_modifier)
{
	if (ft_strcmp(tmp_modifier, "hh") == 0)
		I_MOD_HH = 1;
	else if (ft_strcmp(tmp_modifier, "h") == 0)
		I_MOD_H = 1;
	else if (ft_strcmp(tmp_modifier, "l") == 0)
		I_MOD_L = 1;
	else if (ft_strcmp(tmp_modifier, "ll") == 0)
		I_MOD_LL = 1;
	else if (ft_strcmp(tmp_modifier, "j") == 0)
		I_MOD_J = 1;
	else if (ft_strcmp(tmp_modifier, "z") == 0)
		I_MOD_Z = 1;
}

int			parser_modifier(t_result *result, size_t *i)
{
	char	*format;
	char	tmp_modifier[3];
	size_t	index;

	format = result->format;
	ft_bzero(tmp_modifier, 3);
	index = 0;
	while (format[*i] && ft_strchr(L_MODIFIER, format[*i]))
	{
		if ((tmp_modifier[0] == 'j' || tmp_modifier[0] == 'z') ||
			(tmp_modifier[0] == 'h' && format[*i] != 'h') ||
			(tmp_modifier[0] == 'l' && format[*i] != 'l'))
			return (-1);
		tmp_modifier[index++] = format[*i];
		*i += 1;
		IS_MODIFIER = 1;
	}
	tmp_modifier[index] = '\0';
	if (IS_MODIFIER == 1)
		find_witch_modifier(result, tmp_modifier);
	if (format[*i] && (ft_strchr(CARACTERS, format[*i]) ||
		ft_strchr(F_WIDTH, format[*i]) || ft_strchr(PRECISION, format[*i])))
		return (-1);
	return (0);
}
