/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 22:51:25 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/14 23:52:40 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/*
** type
*/

# define STR result->tab_conv[result->i_args]->type->str
# define I_STR result->tab_conv[i]->type->str
# define STRLEN result->tab_conv[result->i_args]->type->str_len
# define I_STRLEN (int)result->tab_conv[i]->type->str_len
# define PTR result->tab_conv[result->i_args]->type->ptr
# define I_PTR result->tab_conv[i]->type->ptr
# define L_CONV result->tab_conv[result->i_args]->l_conv
# define I_L_CONV result->tab_conv[i]->l_conv

/*
** width_precision
*/

#define IS_WIDTH result->tab_conv[i]->is_width
#define I_IS_WIDTH result->tab_conv[result->i_args]->is_width
#define WIDTH result->tab_conv[i]->width_precision->width
#define I_WIDTH result->tab_conv[result->i_args]->width_precision->width
#define WIDTH_CPY result->tab_conv[i]->width_precision->width_cpy
#define I_WIDTH_CPY result->tab_conv[result->i_args]->width_precision->width_cpy
#define PRECISION_O result->tab_conv[i]->width_precision->precision
#define I_PRECISION_O result->tab_conv[result->i_args]->width_precision->precision
#define PRECISION_CPY result->tab_conv[i]->width_precision->precision_cpy
#define I_PRECISION_CPY result->tab_conv[result->i_args]->width_precision->precision_cpy
#define IS_PRECISION result->tab_conv[i]->is_precision
#define I_IS_PRECISION result->tab_conv[result->i_args]->is_precision

/*
** caracters
*/

#define MINUS result->tab_conv[i]->caracters->minus
#define A_MINUS result->tab_conv[result->i_args]->caracters->minus
#define PLUS result->tab_conv[i]->caracters->plus
#define A_PLUS result->tab_conv[result->i_args]->caracters->plus
#define SPACE result->tab_conv[i]->caracters->space
#define A_SPACE result->tab_conv[result->i_args]->caracters->space
#define SHARP result->tab_conv[i]->caracters->sharp
#define A_SHARP result->tab_conv[result->i_args]->caracters->sharp
#define ZERO result->tab_conv[i]->caracters->zero
#define A_ZERO result->tab_conv[result->i_args]->caracters->zero

/*
** modifier
*/

# define IS_MODIFIER result->tab_conv[result->i_args]->is_modifier
# define I_IS_MODIFIER result->tab_conv[i]->is_modifier
# define MOD_HH result->tab_conv[i]->modifier->hh
# define MOD_H result->tab_conv[i]->modifier->h
# define MOD_L result->tab_conv[i]->modifier->l
# define MOD_LL result->tab_conv[i]->modifier->ll
# define MOD_J result->tab_conv[i]->modifier->j
# define MOD_Z result->tab_conv[i]->modifier->z
# define I_MOD_HH result->tab_conv[result->i_args]->modifier->hh
# define I_MOD_H result->tab_conv[result->i_args]->modifier->h
# define I_MOD_L result->tab_conv[result->i_args]->modifier->l
# define I_MOD_LL result->tab_conv[result->i_args]->modifier->ll
# define I_MOD_J result->tab_conv[result->i_args]->modifier->j
# define I_MOD_Z result->tab_conv[result->i_args]->modifier->z

/*
** ret_ft_printf
*/

# define RET_STR result->tab_conv[i]->ret_str

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
