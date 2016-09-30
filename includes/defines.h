/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 22:51:25 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/29 15:52:35 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/*
** type
*/

# define STR v_args->f_conv[v_args->i_args]->type->str
# define I_STR v_args->f_conv[i]->type->str
# define U_L_INT v_args->f_conv[v_args->i_args]->type->u_l_nb
# define I_U_L_INT v_args->f_conv[i]->type->u_l_nb
# define INT v_args->f_conv[v_args->i_args]->type->nb
# define I_INT v_args->f_conv[i]->type->nb
# define L_INT v_args->f_conv[v_args->i_args]->type->l_nb
# define I_L_INT v_args->f_conv[i]->type->l_nb
# define U_INT v_args->f_conv[v_args->i_args]->type->u_nb
# define I_U_INT v_args->f_conv[i]->type->u_nb
# define C v_args->f_conv[v_args->i_args]->type->c
# define I_C v_args->f_conv[i]->type->c
# define L_CONV v_args->f_conv[v_args->i_args]->l_conv
# define I_L_CONV v_args->f_conv[i]->l_conv
# define PTR v_args->f_conv[v_args->i_args]->type->ptr
# define I_PTR v_args->f_conv[i]->type->ptr

/*
** width_precision
*/

#define IS_WIDTH v_args->f_conv[i]->is_width
#define I_IS_WIDTH v_args->f_conv[v_args->i_args]->is_width
#define WIDTH v_args->f_conv[i]->width_precision->width
#define I_WIDTH v_args->f_conv[v_args->i_args]->width_precision->width
#define WIDTH_CPY v_args->f_conv[i]->width_precision->width_cpy
#define I_WIDTH_CPY v_args->f_conv[v_args->i_args]->width_precision->width_cpy
#define PRECISION_O v_args->f_conv[i]->width_precision->precision
#define I_PRECISION_O v_args->f_conv[v_args->i_args]->width_precision->precision
#define PRECISION_CPY v_args->f_conv[i]->width_precision->precision_cpy
#define I_PRECISION_CPY v_args->f_conv[v_args->i_args]->width_precision->precision_cpy
#define IS_PRECISION v_args->f_conv[i]->is_precision
#define I_IS_PRECISION v_args->f_conv[v_args->i_args]->is_precision

/*
** caracters
*/

#define MINUS v_args->f_conv[i]->caracters->minus
#define A_MINUS v_args->f_conv[v_args->i_args]->caracters->minus
#define PLUS v_args->f_conv[i]->caracters->plus
#define A_PLUS v_args->f_conv[v_args->i_args]->caracters->plus
#define SPACE v_args->f_conv[i]->caracters->space
#define A_SPACE v_args->f_conv[v_args->i_args]->caracters->space
#define SHARP v_args->f_conv[i]->caracters->sharp
#define A_SHARP v_args->f_conv[v_args->i_args]->caracters->sharp
#define ZERO v_args->f_conv[i]->caracters->zero
#define A_ZERO v_args->f_conv[v_args->i_args]->caracters->zero

/*
** modifier
*/

# define IS_MODIFIER v_args->f_conv[v_args->i_args]->is_modifier
# define I_IS_MODIFIER v_args->f_conv[i]->is_modifier
# define MOD_HH v_args->f_conv[i]->modifier->hh
# define MOD_H v_args->f_conv[i]->modifier->h
# define MOD_L v_args->f_conv[i]->modifier->l
# define MOD_LL v_args->f_conv[i]->modifier->ll
# define MOD_J v_args->f_conv[i]->modifier->j
# define MOD_Z v_args->f_conv[i]->modifier->z
# define I_MOD_HH v_args->f_conv[v_args->i_args]->modifier->hh
# define I_MOD_H v_args->f_conv[v_args->i_args]->modifier->h
# define I_MOD_L v_args->f_conv[v_args->i_args]->modifier->l
# define I_MOD_LL v_args->f_conv[v_args->i_args]->modifier->ll
# define I_MOD_J v_args->f_conv[v_args->i_args]->modifier->j
# define I_MOD_Z v_args->f_conv[v_args->i_args]->modifier->z

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
# define GOOD_SPACE "dDib"
# define GOOD_PLUS "dDi"

# define ERR_SHARP "Error : flag '#' results in undefined behavior without 'o' or 'x' conversion specifier\n"
# define ERR_ZERO "Error : flag '0' results in undefined behavior without 'dDioOuUxX' conversion specifier\n"
# define ERR_SPACE "Error : flag ' ' results in undefined behavior without 'd' or 'i' conversion specifier\n"
# define ERR_PLUS "Error : flag '+' results in undefined behavior without 'd' or 'i' conversion specifier\n"
# define ERR_PLUS_SPACE "Error : flag ' ' is ignored when flag '+' is present\n"
# define ERR_MEM "Error : flag 'p' results in undefined behavior with 'precision' conversion specifier\n"
# define ERR_BIN "Error : flag 'b' results in undefined behavior with 'precision' conversion specifier\n"
#endif
