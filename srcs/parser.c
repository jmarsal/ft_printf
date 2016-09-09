/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 17:03:08 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/09 17:00:29 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// static void	get_content_flags(va_list *args, t_args *v_args,
// 								const char *format, size_t *i)
// {
// 	char	*get_width;
// 	char	*get_precision;
// 	size_t	len;
//
// 	get_width = NULL;
// 	get_precision = NULL;
// 	len = 0;
// 	*i += 1;
// 	while (is_conversion_specifiers(format, i, caracters) == 1)
// 	{
// 		if (format[*i] == '-')
// 			v_args->f_conv[v_args->i_args]->caracters->minus = 1;
// 		if (format[*i] == '+')
// 			v_args->f_conv[v_args->i_args]->caracters->plus = 1;
// 		if (format[*i] == ' ')
// 			v_args->f_conv[v_args->i_args]->caracters->space = 1;
// 		if (format[*i] == '#')
// 			v_args->f_conv[v_args->i_args]->caracters->sharp = 1;
// 		if (format[*i] == '0')
// 			v_args->f_conv[v_args->i_args]->caracters->zero = 1;
// 		*i += 1;
// 	}
// 	if (is_conversion_specifiers(format, i, F_WIDTH) == 1)
// 	{
// 		get_width = ft_get_number(format, i);
// 		v_args->f_conv[v_args->i_args]->f_width = ft_atoi(get_width);
// 		free(get_width);
// 		v_args->f_conv[v_args->i_args]->is_width = 1;
// 	}
// 	if (is_conversion_specifiers(format, i, PRECISION) == 1)
// 	{
// 		*i += 1;
// 		get_precision = ft_get_number(format, i);
// 		if (ft_atoi(get_precision) != 0)
// 		{
// 			v_args->f_conv[v_args->i_args]->precision = ft_atoi(get_precision);
// 			v_args->f_conv[v_args->i_args]->is_precision = 1;
// 			free(get_precision);
// 		}
// 		else
// 			v_args->f_conv[v_args->i_args]->is_precision = 0;
// 	}
// 	if (is_conversion_specifiers(format, i, C_SPECIFIERS) == 1)
// 	{
// 		conv_str_s(args, v_args, format, i);
// 		conv_decimal_d(args, v_args, format, i);
// 		conv_decimal_ld(args, v_args, format, i);
// 		conv_char_c(args, v_args, format, i);
// 		conv_hex_x(args, v_args, format, i);
// 		conv_hex_lx(args, v_args, format, i);
// 		conv_binary_b(args, v_args, format, i);
// 		conv_mem_p(args, v_args, format, i);
// 		conv_octal_o(args, v_args, format, i);
// 		conv_octal_lo(args, v_args, format, i);
// 		conv_u_decimal_u(args, v_args, format, i);
// 		conv_lu_decimal_lu(args, v_args, format, i);
// 		v_args->i_args++;
// 		*i += 1;
// 	}
// }
//
// static void	get_content_format(va_list *args, const char *format,
// 								t_args *v_args)
// {
// 	size_t		i;
//
// 	i = 0;
// 	while (format[i])
// 	{
// 		if (format[i] && format[i] != '%')
// 		{
// 			L_CONV = 's';
// 			STR = ft_strdup(ft_strchr_bef(format + i, '%'));
// 			i += ft_strlen(STR);
// 			v_args->ret_ft_printf += ft_strlen(STR);
// 			v_args->i_args++;
// 		}
// 		if (format[i + 1] && (format[i] == '%' && format[i + 1] == '%'))
// 		{
// 			L_CONV = '%';
// 			STR = "%";
// 			i += 2;
// 			v_args->i_args++;
// 			v_args->ret_ft_printf++;
// 		}
// 		if (format[i + 1] && format[i] == '%' && format[i + 1] != '%')
// 			get_content_flags(args, v_args, format, &i);
// 	}
// }
//
static int	get_index(t_args *v_args, const char *format, size_t *i)
{
	int	is_width;
	int	is_precision;

	is_width = 0;
	is_precision = 0;
	*i += 1;
	while (is_conversion_specifiers(format, i, CARACTERS) == 1)
		*i += 1;
	if (is_conversion_specifiers(format, i, F_WIDTH) == 1)
	{
		while (ft_isalnum(format[*i]))
			*i += 1;
		is_width = 1;
	}
	if (is_conversion_specifiers(format, i, PRECISION) == 1)
	{
		*i += 1;
		while (ft_isalnum(format[*i]))
			*i += 1;
		is_precision = 1;
	}
	// if (is_conversion_specifiers(format, i, L_MODIFIER) == 1)
	if (is_width == 1 || is_precision == 1)
		*i -= 1;
	if (is_conversion_specifiers(format, i, C_SPECIFIERS) == 1)
	{
		v_args->index += 1;
		*i += 1;
	}
	else
	{
		ft_putstr("warning: invalid conversion specifier '");
		ft_putchar(format[*i]);
		ft_putstr("'");
		return (-1);
	}
	return (0);
}

static int	search_flags_in_format(t_args *v_args, const char *format)
{
	size_t	i;

	i = 0;
	while (format[i])
	{
		while (format[i] && format[i] != '%')
		{
			if ((format[i + 1] && format[i + 1] == '%') ||
				(format[i + 1] == '\0'))
				v_args->index++;
			i++;
		}
		if (format[i + 1] && (format[i] == '%' && format[i + 1] == '%'))
		{
			i += 2;
			v_args->index++;
		}
		else if (format[i + 1] && format[i] == '%' &&
				(get_index(v_args, format, &i) == -1))
			return (-1);
	}
	return (0);
}

int			treatment(va_list *args, const char *format)
{
	t_args	*v_args;

	if (!(v_args = init_t_args()))
		return (-1);
	if (search_flags_in_format(v_args, format) == -1)
		return (-1);
	if (!(v_args->f_conv = init_tab_args(v_args)))
		return (-1);
	(void)args;
	// get_content_format(args, format, v_args);
	// //Gestion d'erreurs ici !!!!!!!!!!!
	// if ((print_format(v_args)) == -1)
	// 	return (-1);
	return (v_args->ret_ft_printf);
}
