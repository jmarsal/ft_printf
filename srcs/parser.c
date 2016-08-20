/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 17:03:08 by jmarsal           #+#    #+#             */
/*   Updated: 2016/08/20 15:42:30 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	get_index(t_v_args *v_args, const char *format, size_t *i)
{
	if (format[*i + 1] && (format[*i + 1] == 's' ||
							format[*i + 1] == 'd'))
	{
		v_args->index += 1;
		printf("index = %d\n", v_args->index);
		*i += 2;
	}
	else if (format[*i + 1])
	{
		ft_putstr("warning: invalid conversion specifier '");
		ft_putchar(format[*i + 1]);
		ft_putstr("'");
		return (-1);
	}
	return (0);
}

static int	print_and_search_format(t_v_args *v_args, const char *format)
{
	size_t	i;

	i = 0;
	while (format[i])
	{
		if (i == 0 && format[i] != '%')
		{
			ft_putchar(format[i]);
			i++;
		}
		if ((i > 0 && format[i] != '%' && format[i - 1] != '%') ||
			(i > 1 && format[i] != '%' && format[i - 1] == '%' &&
			format[i - 2] == '%'))
		{
			ft_putchar(format[i]);
			i++;
		}
		if (format[i + 1] && (format[i] == '%' && format[i + 1] == '%'))
		{
			ft_putchar('%');
			i += 2;
		}
		else if (format[i] && format[i] == '%' &&
				(get_index(v_args, format, &i) == -1))
			return (-1);
	}
	(void)v_args;
	return (0);
}

int			treatment(va_list *args, const char *format)
{
	t_v_args	*v_args;
	// size_t		i;
	// size_t		test_flag;
	// char		*string;

	// i = 0;
	// test_flag = 0;
	/*
	** initialisation de t_v_args
	*/

	v_args = (t_v_args*)malloc(sizeof(t_v_args));
	v_args->index = 0;
	v_args->f_conv = NULL;

	/*
	** end
	*/
	if (print_and_search_format(v_args, format) == -1)
		return (-1);
	// while (format[i])
	// {
		/*
		** Cherche combien d'args
		*/

		// if (format[i] == 's' && format[i - 1] == '%')
		// {
		// 	v_args->index++;
		// 	test_flag = 1;
		// }
		// if (format[i] != '\0' && format[i] == '%' && format[i - 1] == '%')
		// {
		// 	v_args->index -= 2;
		// 	test_flag = 2;
		// 	ft_putchar('%');
		// }
		// if (test_flag == 1)
		// {
		// 	string = va_arg(*args, char *);
		// 	//penser a diminuer l'index de v_args->index !
		// 	ft_putstr(string);
		// }
		// test_flag = 0;
		// //Voir pour faire un realloc de v_args->f_conv pour chaque index++
		// i++;

		/*
		** end
		*/
	// }
	(void)args;
	return (v_args->index);
}
