/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 14:53:15 by jmarsal           #+#    #+#             */
/*   Updated: 2016/08/21 15:51:03 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_v_args		*init_t_v_args(void)
{
	t_v_args	*v_args;

	v_args = NULL;
	if (!(v_args = ft_memalloc(sizeof(t_v_args))))
		return (NULL);
	v_args->index = 0;
	v_args->i_args = 0;
	v_args->f_conv = NULL;
	return (v_args);
}

t_conversion	**init_tab_args(t_v_args *v_args)
{
	t_conversion	**f_conv;
	size_t			i;

	f_conv = NULL;
	i = 0;
	if (!(f_conv = ft_memalloc(sizeof(t_conversion*)
										* v_args->index + 1)))
		return (NULL);
	while (i < v_args->index)
	{
		if (!(f_conv[i] = ft_memalloc(sizeof(t_conversion*))))
			return (NULL);
		f_conv[i]->c = 0;
		f_conv[i]->l_conv = 0;
		f_conv[i]->str = NULL;
		f_conv[i]->nb = 0;
		i++;
	}
	return (f_conv);
}
