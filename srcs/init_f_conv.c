/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_f_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 14:53:15 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/10 01:44:48 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static t_caracters	*init_caracters(void)
{
	t_caracters	*tmp;

	if (!(tmp = ft_memalloc(sizeof(t_caracters))))
		return (NULL);
	tmp->minus = 0;
	tmp->plus = 0;
	tmp->sharp = 0;
	tmp->space = 0;
	tmp->zero = 0;
	return (tmp);
}

static t_type		*init_type(void)
{
	t_type	*tmp;

	if (!(tmp = ft_memalloc(sizeof(t_type))))
		return (NULL);
	tmp->ptr = NULL;
	tmp->str = NULL;
	tmp->c = 0;
	tmp->l_nb = 0;
	tmp->nb = 0;
	tmp->u_l_nb = 0;
	tmp->u_nb = 0;
	return (tmp);
}

static t_modifier	*init_modifier(void)
{
	t_modifier	*tmp;

	if (!(tmp = ft_memalloc(sizeof(t_modifier))))
		return (NULL);
	tmp->hh = 0;
	tmp->h = 0;
	tmp->l = 0;
	tmp->ll = 0;
	tmp->j = 0;
	tmp->z = 0;
	return (tmp);
}

static t_w_or_p	*init_width_precision(void)
{
	t_w_or_p	*tmp;

	if (!(tmp = ft_memalloc(sizeof(t_w_or_p))))
		return (NULL);
	tmp->width = 0;
	tmp->width_cpy = 0;
	tmp->precision = 0;
	tmp->precision_cpy = 0;
	return (tmp);
}

t_conv			**init_tab_args(t_args *v_args)
{
	t_conv	**f_conv;
	size_t	i;

	i = 0;
	if (!(f_conv = ft_memalloc(sizeof(t_conv*) * v_args->index + 1)))
		return (NULL);
	while (i < v_args->index)
	{
		if (!(f_conv[i] = ft_memalloc(sizeof(t_conv))))
			return (NULL);
		if (!(f_conv[i]->caracters = init_caracters()))
			return (NULL);
		if (!(f_conv[i]->type = init_type()))
			return (NULL);
		if (!(f_conv[i]->modifier = init_modifier()))
			return (NULL);
		if (!(f_conv[i]->width_precision = init_width_precision()))
			return (NULL);
		f_conv[i]->is_width = 0;
		f_conv[i]->is_precision = 0;
		f_conv[i]->is_modifier = 0;
		f_conv[i]->l_conv = 0;
		i++;
	}
	return (f_conv);
}
