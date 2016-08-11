/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 17:03:08 by jmarsal           #+#    #+#             */
/*   Updated: 2016/08/12 00:09:23 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	treatment(va_list *args, const char *format)
{
	t_v_args	*v_args;
	size_t		i;

	i = 0;
	v_args = (t_v_args*)malloc(sizeof(t_v_args));
	v_args->index = 0;
	while (format[i])
	{
		/*
		** Cherche combien d'args
		*/
		
		if (format[i] == '%')
			v_args->index++;
		if (format[i] != 0 && format[i] == '%' && format[i - 1] == '%')
			v_args->index -= 2;
		i++;

		/*
		** end
		*/
	}
	printf("v_args->index = %d\n", v_args->index);
	(void)args;
	return (v_args->index);
}
