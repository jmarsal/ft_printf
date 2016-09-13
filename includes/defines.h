/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 22:51:25 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/13 16:07:33 by jmarsal          ###   ########.fr       */
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
** ret_ft_printf
*/

# define RET_STR v_args->ret_str

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

# define GOOD_SHARP "oOxX"
# define GOOD_ZERO "dDioOuUxX"
# define GOOD_SPACE "dDi"
# define GOOD_PLUS "dDi"

# define ERR_SHARP "Error : flag '#' results in undefined behavior without 'o' or 'x' conversion specifier\n"
# define ERR_ZERO "Error : flag '0' results in undefined behavior without 'dDioOuUxX' conversion specifier\n"
# define ERR_SPACE "Error : flag ' ' results in undefined behavior without 'd' or 'i' conversion specifier\n"
# define ERR_PLUS "Error : flag '+' results in undefined behavior without 'd' or 'i' conversion specifier\n"
# define ERR_PLUS_SPACE "Error : flag ' ' is ignored when flag '+' is present\n"
# define ERR_MEM "Error : flag 'p' results in undefined behavior with 'precision' conversion specifier\n"
#endif
