/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 17:03:08 by jmarsal           #+#    #+#             */
/*   Updated: 2016/08/21 00:20:50 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	get_content_flags(va_list *args, t_v_args *v_args,
								const char *format, size_t *i)
{
	if (format[*i + 1] && (format[*i + 1] == 's' ||
							format[*i + 1] == 'd'))
	{
		if (!(v_args->f_conv[v_args->i_args] = ft_memalloc(sizeof(t_conversion*))))
			return (-1);
		if (format[*i + 1] == 's')
		{
			v_args->f_conv[v_args->i_args]->str = va_arg(*args, char *);
			printf("%s", v_args->f_conv[v_args->i_args]->str);
			v_args->i_args++;
			*i += 2;
		}
		if (format[*i + 1] == 'd')
		{
			v_args->f_conv[v_args->i_args]->nb = va_arg(*args, int);
			printf("%d", v_args->f_conv[v_args->i_args]->nb);
			v_args->i_args++;
			*i += 2;
		}
	}
	return (0);
}

static int	get_index(t_v_args *v_args, const char *format, size_t *i)
{
	if (format[*i + 1] && (format[*i + 1] == 's' ||
							format[*i + 1] == 'd'))
	{
		v_args->index += 1;
		// printf("index = %d\n", v_args->index);
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

static int	search_flags_in_format(t_v_args *v_args, const char *format)
{
	size_t	i;

	i = 0;
	while (format[i])
	{
		// tant que str continue && index++
		while (format[i] && format[i] != '%')
		{
			i++;
			if (format[i + 1] && format[i + 1] == '%')
				v_args->index++;
		}
		if (format[i + 1] && (format[i] == '%' && format[i + 1] == '%'))
		{
			i += 2;
			v_args->index++;
		}
		else if (format[i] == '%' &&
				(get_index(v_args, format, &i) == -1))
			return (-1);
		i++;
	}
	return (0);
}

int			treatment(va_list *args, const char *format)
{
	t_v_args	*v_args;
	size_t		i;

	i = 0;
	/*
	** initialisation de t_v_args
	*/

	v_args = (t_v_args*)malloc(sizeof(t_v_args));
	v_args->index = 0;
	v_args->i_args = 0;

	// memalloc tab_of_structs
	if (!(v_args->f_conv = ft_memalloc(sizeof(t_conversion**))))
		return (-1);

	// count flags
	if (search_flags_in_format(v_args, format) == -1)
		return (-1);

	// get in tab
	while (format[i])
	{
	// recupere string dans format
		if (format[i] && format[i] != '%')
		{
			if (!(v_args->f_conv[v_args->i_args] = ft_memalloc(sizeof(t_conversion*))))
				return (-1);
			v_args->f_conv[v_args->i_args]->str = ft_strdup(ft_strchr_bef(format + i, '%'));
			i += ft_strlen(v_args->f_conv[v_args->i_args]->str);
			printf("%s", v_args->f_conv[v_args->i_args]->str);
			v_args->i_args++;
		}
	// recupere %% dans format
		if (format[i + 1] && (format[i] == '%' && format[i + 1] == '%'))
		{
			if (!(v_args->f_conv[v_args->i_args] = ft_memalloc(sizeof(t_conversion*))))
				return (-1);
			v_args->f_conv[v_args->i_args]->str = "%";
			i += 2;
			printf("%s", v_args->f_conv[v_args->i_args]->str);
			v_args->i_args++;
		}
	// recupere flags conversion dans format (%s, %d, etc...)
		else if (format[i] == '%' &&
				(get_content_flags(args, v_args, format, &i) == -1))
			return (-1);
	}
	return (v_args->index);
}
