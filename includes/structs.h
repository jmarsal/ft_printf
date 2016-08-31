/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 16:59:05 by jmarsal           #+#    #+#             */
/*   Updated: 2016/08/29 22:01:19 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "ft_printf.h"

typedef struct		s_conversion
{
	long int				l_oct;
	long int				l_nb;
	char					*str;
	int						nb;
	int						hex;
	int						oct;
	int						binary;
	char					c;
	int						*ptr;
	char					l_conv;
							//Besoin d'une variable de taille de champ
							//Besoin d'une variable de precision (par default 1)
							//Besoin d'une variable modificateur de longueur (hh, h, l, ll, etc...)
}								t_conversion;

typedef struct	s_v_args
{
	t_conversion	**f_conv; //stoque les flags de format dans l'ordre dans un tab
	size_t				i_args;
	size_t				index; // nb d'args
	int						ret_ft_printf;
}								t_v_args;

#endif
