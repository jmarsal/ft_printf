/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 14:53:15 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/13 16:26:30 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_args				*init_t_args(void)
{
	t_args	*v_args;

	v_args = NULL;
	if (!(v_args = ft_memalloc(sizeof(t_args))))
		return (NULL);
	v_args->index = 0;
	v_args->i_args = 0;
	v_args->f_conv = NULL;
	v_args->ret_str = ft_strnew(0);
	return (v_args);
}
