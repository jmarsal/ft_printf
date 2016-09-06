/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 16:59:05 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/06 00:34:26 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "ft_printf.h"

typedef struct		s_conversion
{
	unsigned long	u_l_nb;
	long int		l_nb;
	unsigned int	u_nb;
	char			*str;
	int				*ptr;
	int				nb;
	int				f_width;
	int				f_width_zero;
	char			c;
	char			l_conv;
	char			f_caracters;
					//Besoin d'une variable de precision (par default 1)
					//Besoin d'une variable modificateur de longueur (hh, h, l, ll, etc...)
}					t_conversion;

typedef struct		s_v_args
{
	t_conversion	**f_conv; //stoque les flags de format dans l'ordre dans un tab
	size_t			i_args;
	size_t			index; // nb d'args
	int				ret_ft_printf;
}					t_v_args;

#endif
