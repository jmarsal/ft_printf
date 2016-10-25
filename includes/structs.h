/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 16:59:05 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/25 16:54:47 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "ft_printf.h"

typedef struct		s_type
{
	char			*str;
	size_t			str_len;
	int				*ptr;
}					t_type;

typedef struct		s_modifier
{
	int				hh;
	int				h;
	int				l;
	int				ll;
	int				j;
	int				z;
}					t_modifier;

typedef struct		s_w_or_p
{
	int				width;
	int				width_cpy;
	int				precision;
	int				precision_cpy;
}					t_w_or_p;

typedef struct		s_caracters
{
	int				minus;
	int				plus;
	int				space;
	int				sharp;
	int				zero;
}					t_caracters;

typedef struct		s_conv
{
	t_caracters		*caracters;
	t_type			*type;
	t_modifier		*modifier;
	t_w_or_p		*width_precision;
	t_buffer		*ret_str;
	int				is_width;
	int				is_precision;
	int				is_modifier;
	char			l_conv;
}					t_conv;

typedef struct		s_result
{
	t_conv			**tab_conv;
	va_list			ap;
	char			*format;
	char			*result_str; // remplacer par un t_buffer *
	size_t			i_args;
	size_t			index;
	size_t			sizemax;
}					t_result;

#endif
