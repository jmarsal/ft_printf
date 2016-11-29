/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 14:53:15 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/29 09:20:58 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_result	*init_result(va_list ap, const char *format)
{
	t_result	*result;

	result = NULL;
	if (!(result = ft_memalloc(sizeof(t_result))))
		return (NULL);
	va_copy(R_AP, ap);
	result->format = (char*)format;
	result->result_str = ft_buffer_new(0);
	result->test_c_zero = 0;
	result->index = 0;
	result->i_args = 0;
	result->sizemax = 0;
	result->tab_conv = NULL;
	return (result);
}

static void	tab_conv_destroy(t_result *result)
{
	t_conv	*del;
	size_t	i;

	i = 0;
	while (i <= result->sizemax)
	{
		del = result->tab_conv[i++];
		if (del)
		{
			ft_free(del->caracters);
			ft_free(del->type->str);
			ft_free(del->type);
			ft_free(del->modifier);
			ft_free(del->width_precision);
			ft_buffer_destroy(&del->ret_str);
			ft_free(del);
		}
	}
	ft_free(result->tab_conv);
}

void		destroy_result(t_result **result)
{
	t_result	*tmp_for_del;

	tmp_for_del = *result;
	va_end(tmp_for_del->ap);
	tab_conv_destroy(*result);
	ft_buffer_destroy(&tmp_for_del->result_str);
	ft_free(tmp_for_del);
	*result = NULL;
}
