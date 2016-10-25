/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_conv_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 14:05:29 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/25 17:31:58 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static t_conv	**tab_conv_resize(t_result *result)
{
	void	*new;
	size_t	newsize;

	newsize = sizeof(void *) * result->sizemax * 2;
	if (!(new = ft_realloc(result->tab_conv, sizeof(void *) * 
		newsize, sizeof(void *) * result->sizemax)))
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

void			tab_conv_add(t_result *result, size_t tab_index)
{
	if (!result->tab_conv)
		result->tab_conv = tab_conv_create();
	if (tab_index >= result->sizemax)
	{
		if (result->sizemax == 0)
			result->sizemax = INIT_SIZE_TAB_CONV;
		if (tab_conv_resize(result) == NULL)
			exit (-1);
		while (tab_index <= result->sizemax)
		{
			result->tab_conv[tab_index] = tab_conv_init(result->tab_conv[tab_index]);
			tab_index++;
		}
	}
}

