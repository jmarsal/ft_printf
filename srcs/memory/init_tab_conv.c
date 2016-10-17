/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 14:06:00 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/17 14:07:11 by jmarsal          ###   ########.fr       */
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
	tmp->str = ft_strnew(0);
	*tmp->str = '\0';
	tmp->str_len = 0;
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

t_conv	*tab_conv_init(t_conv *tab_conv)
{
	if (!(tab_conv = ft_memalloc(sizeof(t_conv))) ||
		!(tab_conv->caracters = init_caracters()) ||
		!(tab_conv->type = init_type()) ||
		!(tab_conv->modifier = init_modifier()) ||
		!(tab_conv->width_precision = init_width_precision()))
		return (NULL);
	tab_conv->is_width = 0;
	tab_conv->is_precision = 0;
	tab_conv->is_modifier = 0;
	tab_conv->l_conv = 0;
	tab_conv->ret_str = ft_strnew(0);
	*tab_conv->ret_str = '\0';
	return (tab_conv);
}
