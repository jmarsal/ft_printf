/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 14:53:15 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/14 22:55:53 by jmarsal          ###   ########.fr       */
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

static void	tab_conv_destroy(t_conv *conv)
{
	free(conv->caracters);
	conv->caracters = NULL;
	ft_strdel(&conv->type->str);
	free(conv->type);
	conv->type = NULL;
	free(conv->modifier);
	conv->modifier = NULL;
	free(conv->width_precision);
	conv->width_precision = NULL;
	ft_strdel(&conv->ret_str);
	free(conv);
	conv = NULL;
}

void		destroy_result(t_result **result)
{
	t_result	*tmp_for_del;
	t_conv		*tab_for_del;
	size_t		i;

	tmp_for_del = *result;
	tab_for_del = NULL;
	va_end(tmp_for_del->ap);
	i = 0;
	while (i < tmp_for_del->i_args)
	{
		tab_for_del = tmp_for_del->tab_conv[i++];
		tab_conv_destroy(tab_for_del);
	}
	ft_strdel(&tmp_for_del->result_str);
	free(tmp_for_del);
	*result = NULL;
}
