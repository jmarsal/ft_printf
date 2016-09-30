/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 16:05:15 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/29 02:08:38 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ret_modifier(char *get_conversion, size_t len, char *tmp)
{
	size_t	index;
	size_t	i;

	i = 0;
	index = (len <= ft_strlen(tmp)) ? ft_strlen(tmp) - len : 0;
	while (tmp[index])
		get_conversion[i++] = tmp[index++];
	free(tmp);
	return (get_conversion);
}

static char	*modifier_x(t_args *v_args, size_t i, size_t len)
{
	char	*tmp;
	char	*get_conversion;

	if ((tmp = ft_strnew(0)) == NULL)
		return (NULL);
	if (!(get_conversion = ft_memalloc(sizeof(char) * len + 1)))
		return (NULL);
	if (I_L_CONV == 'x')
		tmp = (!(MOD_LL || MOD_L)) ?
				ft_strjoin(tmp, ft_strtolower(ft_itoa_base(I_INT, 16))) :
				ft_strjoin(tmp, ft_strtolower(ft_ulitoa_base(I_U_L_INT, 16)));
	else if (I_L_CONV == 'X')
		tmp = (!(MOD_LL || MOD_L)) ? ft_strjoin(tmp, ft_itoa_base(I_INT, 16)) :
								ft_strjoin(tmp, ft_ulitoa_base(I_U_L_INT, 16));
	return (get_conversion = ret_modifier(get_conversion, len, tmp));
}

void		print_hex_x(t_args *v_args, size_t i)
{
	if (I_L_CONV == 'x' || I_L_CONV == 'X')
	{
		if (!I_IS_MODIFIER)
			RET_STR = I_L_CONV == 'x' ?
				ft_strjoin(RET_STR, ft_strtolower(ft_itoa_base(I_INT, 16))) :
				ft_strjoin(RET_STR, ft_itoa_base(I_INT, 16));
		else if (MOD_HH == 1)
			RET_STR = ft_strjoin(RET_STR, modifier_x(v_args, i, 2));
		else if (MOD_H == 1)
			RET_STR = ft_strjoin(RET_STR, modifier_x(v_args, i, 4));
		else if (MOD_L == 1)
			RET_STR = ft_strjoin(RET_STR, modifier_x(v_args, i, 16));
		else if (MOD_LL == 1)
			RET_STR = ft_strjoin(RET_STR, modifier_x(v_args, i, 64));

	}
}
