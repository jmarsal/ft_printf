/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 14:53:15 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/11 17:37:12 by jmarsal          ###   ########.fr       */
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

/*t_conv			**init_tab_conv(t_result *result)
{
	t_conv	**tab_conv;
	size_t	i;

	i = 0;
	if (!(tab_conv = ft_memalloc(sizeof(t_conv*) * result->index + 2)))
		return (NULL);
	while (i <= result->index)
	{
		if (!(tab_conv[i] = ft_memalloc(sizeof(t_conv))) ||
			!(tab_conv[i]->caracters = init_caracters()) ||
			!(tab_conv[i]->type = init_type()) ||
			!(tab_conv[i]->modifier = init_modifier()) ||
			!(tab_conv[i]->width_precision = init_width_precision()))
			return (NULL);
		tab_conv[i]->is_width = 0;
		tab_conv[i]->is_precision = 0;
		tab_conv[i]->is_modifier = 0;
		tab_conv[i]->l_conv = 0;
		tab_conv[i]->ret_str = ft_strnew(0);
		*tab_conv[i]->ret_str = '\0';
		i++;
	}
	// tab_conv[i] = NULL;
	return (tab_conv);
}*/

static t_conv	*tab_conv_init(t_conv *tab_conv)
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

static t_conv	**tab_conv_resize(t_result *result)
{
	void	*new;
	size_t	newsize;

	newsize = sizeof(void*) * result->sizemax * 2;
	if (!(new = ft_realloc(result->tab_conv, newsize, sizeof(void *) * result->sizemax)))
		return (NULL);
	result->sizemax *= 2;
	result->tab_conv = new;
	return (result->tab_conv);
}

static t_conv	**tab_conv_create()
{
	t_conv	**tab_conv;

	tab_conv = NULL;
	if (!tab_conv)
		if (!(tab_conv = ft_memalloc(sizeof(t_conv**))))
			return (NULL);
	return (tab_conv);
}

t_conv			**tab_conv_add(t_result *result, size_t tab_index)
{
	if (!result->tab_conv)
		result->tab_conv = tab_conv_create();
	if (tab_index >= result->sizemax)
	{
		if (result->sizemax == 0)
			result->sizemax = INIT_SIZE_TAB_CONV;
		if (tab_conv_resize(result) == NULL)
			return (NULL);
		while (tab_index <= result->sizemax)
		{
			result->tab_conv[tab_index] = tab_conv_init(result->tab_conv[tab_index]);
			tab_index++;
		}
	}
	return (result->tab_conv);
}

