/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifier.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 00:12:09 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/23 01:58:01 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*modifier_x(t_args *v_args, size_t i, size_t len)
{
	char	*tmp;
	char	*get_conversion;
	size_t	index;
	size_t	j;

	if ((tmp = ft_strnew(0)) == NULL)
		return (NULL);
	if (!(get_conversion = ft_memalloc(sizeof(char) * len + 1)))
		return (NULL);
	if (I_L_CONV == 'x' && (!(v_args->f_conv[i]->modifier->ll ||
									v_args->f_conv[i]->modifier->l)))
		tmp = ft_strjoin(tmp, ft_strtolower(ft_itoa_base(I_INT, 16)));
	else if (I_L_CONV == 'x' && (v_args->f_conv[i]->modifier->l ||
								v_args->f_conv[i]->modifier->ll))
		tmp = ft_strjoin(tmp, ft_strtolower(ft_ulitoa_base(I_U_L_INT, 16)));
	else if (I_L_CONV == 'X' && (!(v_args->f_conv[i]->modifier->ll ||
									v_args->f_conv[i]->modifier->l)))
		tmp = ft_strjoin(tmp, ft_itoa_base(I_INT, 16));
	else if (I_L_CONV == 'X' && (v_args->f_conv[i]->modifier->l ||
								v_args->f_conv[i]->modifier->ll))
		tmp = ft_strjoin(tmp, ft_ulitoa_base(I_U_L_INT, 16));
	if (len <= ft_strlen(tmp))
		index = ft_strlen(tmp)- len;
	else
		index = 0;
	j = 0;
	while (tmp[index])
		get_conversion[j++] = tmp[index++];
	get_conversion[j] = '\0';
	return (get_conversion);
}
