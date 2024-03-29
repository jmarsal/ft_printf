/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_conv_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 14:05:29 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/30 15:21:12 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static t_conv	**tab_conv_resize(t_result *result)
{
	void	*new;
	size_t	newsize;

	newsize = sizeof(t_result *) * (result->sizemax * 2);
	if (!(new = ft_realloc(result->tab_conv, newsize, sizeof(t_result *) *
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
