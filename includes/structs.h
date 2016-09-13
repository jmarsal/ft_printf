/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 16:59:05 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/13 16:26:06 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "ft_printf.h"

typedef struct		s_type
{
	unsigned long	u_l_nb;
	long int		l_nb;
	unsigned int	u_nb;
	char			*str;
	int				*ptr;
	int				nb;
	char			c;
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
	int				is_width;
	int				is_precision;
	int				is_modifier;
	char			l_conv;
}					t_conv;

typedef struct		s_args
{
	t_conv			**f_conv;
	size_t			i_args;
	size_t			index;
	char			*ret_str;
}					t_args;

#endif
