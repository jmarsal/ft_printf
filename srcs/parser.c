/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 17:03:08 by jmarsal           #+#    #+#             */
/*   Updated: 2016/08/19 02:10:38 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <libft.h>

int	treatment(va_list *args, const char *format)
{
	t_v_args	*v_args;
	size_t		i;
	size_t		test_flag;
	char		*string;

	i = 0;
	test_flag = 0;
	/*
	** initialisation de t_v_args
	*/

	v_args = (t_v_args*)malloc(sizeof(t_v_args));
	v_args->index = 0;
	v_args->f_conv = NULL;

	/*
	** end
	*/

	while (format[i])
	{
		/*
		** Cherche combien d'args
		*/

		if (format[i] == 's' && format[i - 1] == '%')
		{
			v_args->index++;
			test_flag = 1;
		}
		if (format[i] != '\0' && format[i] == '%' && format[i - 1] == '%')
		{
			v_args->index -= 2;
			test_flag = 2;
			ft_putchar('%');
		}
		if (test_flag == 1)
		{
			string = va_arg(*args, char *);
			//penser a diminuer l'index de v_args->index !
			ft_putstr(string);
		}
		test_flag = 0;
		//Voir pour faire un realloc de v_args->f_conv pour chaque index++
		i++;

		/*
		** end
		*/
	}
	(void)args;
	return (v_args->index);
}
