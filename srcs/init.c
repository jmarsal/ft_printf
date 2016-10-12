/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 14:53:15 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/12 10:46:17 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_result	*init_t_result(va_list ap, const char *format)
{
	t_result	*result;

	result = NULL;
	if (!(result = ft_memalloc(sizeof(t_result))))
		return (NULL);
	va_copy(result->ap, ap);
	result->format = ft_strdup(format);
	result->index = 0;
	result->i_args = 0;
	result->tab_conv = NULL;
	result->ret_str = ft_strnew(0);
	return (result);
}
