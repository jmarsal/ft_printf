/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 14:53:15 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/15 23:52:51 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_result	*init_result(va_list ap, const char *format)
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
	result->result_str = ft_strnew(0);
	*result->result_str = '\0';
	return (result);
}

static void	tab_conv_destroy(t_conv **conv)
{
	t_conv	*del;

	del = *conv;
	if (del)
	{
		ft_free_null(del->caracters);
		ft_free_null(del->type);
		ft_free_null(del->modifier);
		ft_free_null(del->width_precision);
		ft_strdel(&del->ret_str);
		ft_free_null(del);
	}
}

void		destroy_result(t_result **result)
{
	t_result	*tmp_for_del;
	t_conv		*tab_for_del;
	size_t		i;

	tmp_for_del = *result;
	va_end(tmp_for_del->ap);
	i = 0;
	while (i < tmp_for_del->i_args)
	{
		tab_for_del = tmp_for_del->tab_conv[i++];
		tab_conv_destroy(&tab_for_del);
	}
	ft_strdel(&tmp_for_del->result_str);
	ft_free_null(tmp_for_del);
	*result = NULL;
}
