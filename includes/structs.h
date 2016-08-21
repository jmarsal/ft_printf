/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 16:59:05 by jmarsal           #+#    #+#             */
/*   Updated: 2016/08/22 00:23:06 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "ft_printf.h"

typedef struct		s_conversion
{
	char			*str;
	int				nb;
	int				hex;
	char			c;
	// size_t			index;
	char			l_conv; //le flag de conversion. Peut etre besoin d'un char *
							//Besoin d'une variable de taille de champ
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
