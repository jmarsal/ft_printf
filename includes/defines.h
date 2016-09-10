/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 22:51:25 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/10 02:24:30 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/*
** f_conv
*/

# define STR v_args->f_conv[v_args->i_args]->type->str
# define U_L_INT v_args->f_conv[v_args->i_args]->type->u_l_nb
# define INT v_args->f_conv[v_args->i_args]->type->nb
# define L_INT v_args->f_conv[v_args->i_args]->type->l_nb
# define U_INT v_args->f_conv[v_args->i_args]->type->u_nb
# define C v_args->f_conv[v_args->i_args]->type->c
# define L_CONV v_args->f_conv[v_args->i_args]->l_conv
# define PTR v_args->f_conv[v_args->i_args]->type->ptr

/*
** conversion flags
*/

# define CARACTERS "-+ #0" // OK
# define F_WIDTH "123456789*" // OK
# define PRECISION ".*" // Warning avec * : si 1 * et pas de largeur, alors * vaut largeur.
										// si 1 * et largeur alors * vaut precision
										// 2 * impossible...!!
# define L_MODIFIER "hljz"
# define C_SPECIFIERS "dDioOuUxXcCsSbp" //reste a gerer le 'C' ou 'S'

/*
** colors
*/

# define GREEN "\033[32;1m"
# define RED "\033[31m"
# define BLUE "\033[34m"
# define PINK "\033[35;1m"
# define CYAN "\033[36;1m"
# define EOC "\033[0m"

/*
** Errors
*/

# define ERR_SHARP "oOxX"

# define ERR_SHARP_D "Error : flag '#' results in undefined behavior with 'd' or 'i' conversion specifier\n"
# define ERR_SHARP_LD "Error : flag '#' results in undefined behavior with 'ld' or 'D' conversion specifier\n"
# define ERR_SHARP_U "Error : flag '#' results in undefined behavior with 'u' conversion specifier\n"
# define ERR_SHARP_LU "Error : flag '#' results in undefined behavior with 'lu' or 'U' conversion specifier\n"
# define ERR_SHARP_C "Error : flag '#' results in undefined behavior with 'c' conversion specifier\n"
# define ERR_SHARP_LC "Error : flag '#' results in undefined behavior with 'lc' or 'C' conversion specifier\n"
# define ERR_SHARP_S "Error : flag '#' results in undefined behavior with 's' conversion specifier\n"
# define ERR_SHARP_LS "Error : flag '#' results in undefined behavior with 'ls' or 'S' conversion specifier\n"
# define ERR_SHARP_B "Error : flag '#' results in undefined behavior with 'b' conversion specifier\n"
# define ERR_SHARP_P "Error : flag '#' results in undefined behavior with 'p' conversion specifier\n"
#endif
