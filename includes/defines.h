/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 22:51:25 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/11 16:02:13 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/*
** type
*/

# define STR result->f_conv[result->i_ap]->type->str
# define I_STR result->f_conv[i]->type->str
# define U_L_INT result->f_conv[result->i_ap]->type->u_l_nb
# define I_U_L_INT result->f_conv[i]->type->u_l_nb
# define INT result->f_conv[result->i_ap]->type->nb
# define I_INT result->f_conv[i]->type->nb
# define L_INT result->f_conv[result->i_ap]->type->l_nb
# define I_L_INT result->f_conv[i]->type->l_nb
# define U_INT result->f_conv[result->i_ap]->type->u_nb
# define I_U_INT result->f_conv[i]->type->u_nb
# define C result->f_conv[result->i_ap]->type->c
# define I_C result->f_conv[i]->type->c
# define L_CONV result->f_conv[result->i_ap]->l_conv
# define I_L_CONV result->f_conv[i]->l_conv
# define PTR result->f_conv[result->i_ap]->type->ptr
# define I_PTR result->f_conv[i]->type->ptr

/*
** width_precision
*/

#define IS_WIDTH result->f_conv[i]->is_width
#define I_IS_WIDTH result->f_conv[result->i_ap]->is_width
#define WIDTH result->f_conv[i]->width_precision->width
#define I_WIDTH result->f_conv[result->i_ap]->width_precision->width
#define WIDTH_CPY result->f_conv[i]->width_precision->width_cpy
#define I_WIDTH_CPY result->f_conv[result->i_ap]->width_precision->width_cpy
#define PRECISION_O result->f_conv[i]->width_precision->precision
#define I_PRECISION_O result->f_conv[result->i_ap]->width_precision->precision
#define PRECISION_CPY result->f_conv[i]->width_precision->precision_cpy
#define I_PRECISION_CPY result->f_conv[result->i_ap]->width_precision->precision_cpy
#define IS_PRECISION result->f_conv[i]->is_precision
#define I_IS_PRECISION result->f_conv[result->i_ap]->is_precision

/*
** caracters
*/

#define MINUS result->f_conv[i]->caracters->minus
#define A_MINUS result->f_conv[result->i_ap]->caracters->minus
#define PLUS result->f_conv[i]->caracters->plus
#define A_PLUS result->f_conv[result->i_ap]->caracters->plus
#define SPACE result->f_conv[i]->caracters->space
#define A_SPACE result->f_conv[result->i_ap]->caracters->space
#define SHARP result->f_conv[i]->caracters->sharp
#define A_SHARP result->f_conv[result->i_ap]->caracters->sharp
#define ZERO result->f_conv[i]->caracters->zero
#define A_ZERO result->f_conv[result->i_ap]->caracters->zero

/*
** modifier
*/

# define IS_MODIFIER result->f_conv[result->i_ap]->is_modifier
# define I_IS_MODIFIER result->f_conv[i]->is_modifier
# define MOD_HH result->f_conv[i]->modifier->hh
# define MOD_H result->f_conv[i]->modifier->h
# define MOD_L result->f_conv[i]->modifier->l
# define MOD_LL result->f_conv[i]->modifier->ll
# define MOD_J result->f_conv[i]->modifier->j
# define MOD_Z result->f_conv[i]->modifier->z
# define I_MOD_HH result->f_conv[result->i_ap]->modifier->hh
# define I_MOD_H result->f_conv[result->i_ap]->modifier->h
# define I_MOD_L result->f_conv[result->i_ap]->modifier->l
# define I_MOD_LL result->f_conv[result->i_ap]->modifier->ll
# define I_MOD_J result->f_conv[result->i_ap]->modifier->j
# define I_MOD_Z result->f_conv[result->i_ap]->modifier->z

/*
** ret_ft_printf
*/

# define RET_STR result->ret_str

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
# define ERR_MOD_J "error : invalid modifier 'j' with modifier 'h' or 'l'\n"
# define ERR_MOD_Z "error : invalid modifier 'z' with modifier 'h' or 'l'\n"
# define ERR_C_S "error : use another modifier that 'l' results in undefined behavior with 'c', 'C', 's' or 'S' specifier\n"
#endif
