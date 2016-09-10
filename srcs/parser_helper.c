/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 00:33:03 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/09 18:03:11 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_conversion_specifiers(const char *format, size_t *i,
									const char *flags)
{
	if ((ft_strchr(flags, format[*i]) != NULL))
		return (1);
	return (-1);
}
