/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_conv_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 14:05:29 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/29 10:53:07 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		*ft_realloctab(t_conv **ptr, size_t size, size_t oldsize)
{
	t_conv	*p;
	size_t	i;

	i = 0;
	if (!ptr)
		return (ft_memalloc(sizeof(t_conv) * size));
	if (size == 0)
	{
		ft_free(ptr);
		return (NULL);
	}
	if (!(p = ft_memalloc(sizeof(t_conv) * size)))
		return (NULL);
	ft_memcpy(p, ptr, sizeof(t_conv) * oldsize);
	ft_free(ptr);
	return (p);
}

static t_conv	**tab_conv_resize(t_result *result)
{
	void	*new;
	size_t	newsize;

	newsize = sizeof(t_result *) * (result->sizemax * 2);
	if (!(new = ft_realloctab(result->tab_conv, newsize, sizeof(t_result *) *
							result->sizemax)))
		return (NULL);
	result->sizemax *= 2;
	result->tab_conv = new;
	return (result->tab_conv);
}

void			tab_conv_add(t_result *result, size_t tab_index)
{
	if (tab_index >= result->sizemax)
	{
		if (result->sizemax == 0)
			result->sizemax = sizeof(t_result *) * INIT_SIZE_TAB_CONV;
		if (tab_conv_resize(result) == NULL)
			exit(-1);
		while (tab_index <= result->sizemax)
		{
			result->tab_conv[tab_index] =
				tab_conv_init(result->tab_conv[tab_index]);
			tab_index++;
		}
	}
}
