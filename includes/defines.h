/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 01:06:21 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/30 09:13:40 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/*
**	result
*/

# define R_AP result->ap

/*
** tab_conv
*/

# define INIT_SIZE_TAB_CONV 1
# define I_ARGS result->i_args
# define W_P width_precision
# define IS_WILDCARD_PRECISION result->tab_conv[i]->is_wildcard_prec
# define IS_WILDCARD_WIDTH result->tab_conv[i]->is_wildcard_width

/*
** type
*/

# define STR result->tab_conv[I_ARGS]->type->str
# define I_STR result->tab_conv[i]->type->str
# define STRLEN result->tab_conv[I_ARGS]->type->str_len
# define I_STRLEN result->tab_conv[i]->type->str_len
# define L_CONV result->tab_conv[I_ARGS]->l_conv
# define I_L_CONV result->tab_conv[i]->l_conv

/*
** width_precision
*/

# define IS_WIDTH result->tab_conv[i]->is_width
# define I_IS_WIDTH result->tab_conv[I_ARGS]->is_width
# define WIDTH result->tab_conv[i]->W_P->width
# define I_WIDTH result->tab_conv[I_ARGS]->W_P->width
# define WIDTH_CPY result->tab_conv[i]->W_P->width_cpy
# define I_WIDTH_CPY result->tab_conv[I_ARGS]->W_P->width_cpy
# define PRECISION_O result->tab_conv[i]->W_P->precision
# define I_PRECISION_O result->tab_conv[I_ARGS]->W_P->precision
# define PRECISION_CPY result->tab_conv[i]->W_P->precision_cpy
# define I_PRECISION_CPY result->tab_conv[I_ARGS]->W_P->precision_cpy
# define IS_PRECISION result->tab_conv[i]->is_precision
# define I_IS_PRECISION result->tab_conv[I_ARGS]->is_precision

/*
** caracters
*/

# define MINUS result->tab_conv[i]->caracters->minus
# define A_MINUS result->tab_conv[I_ARGS]->caracters->minus
# define PLUS result->tab_conv[i]->caracters->plus
# define A_PLUS result->tab_conv[I_ARGS]->caracters->plus
# define SPACE result->tab_conv[i]->caracters->space
# define A_SPACE result->tab_conv[I_ARGS]->caracters->space
# define SHARP result->tab_conv[i]->caracters->sharp
# define A_SHARP result->tab_conv[I_ARGS]->caracters->sharp
# define ZERO result->tab_conv[i]->caracters->zero
# define A_ZERO result->tab_conv[I_ARGS]->caracters->zero

/*
** modifier
*/

# define IS_MODIFIER result->tab_conv[I_ARGS]->is_modifier
# define I_IS_MODIFIER result->tab_conv[i]->is_modifier
# define MOD_HH result->tab_conv[i]->modifier->hh
# define MOD_H result->tab_conv[i]->modifier->h
# define MOD_L result->tab_conv[i]->modifier->l
# define MOD_LL result->tab_conv[i]->modifier->ll
# define MOD_J result->tab_conv[i]->modifier->j
# define MOD_Z result->tab_conv[i]->modifier->z
# define I_MOD_HH result->tab_conv[I_ARGS]->modifier->hh
# define I_MOD_H result->tab_conv[I_ARGS]->modifier->h
# define I_MOD_L result->tab_conv[I_ARGS]->modifier->l
# define I_MOD_LL result->tab_conv[I_ARGS]->modifier->ll
# define I_MOD_J result->tab_conv[I_ARGS]->modifier->j
# define I_MOD_Z result->tab_conv[I_ARGS]->modifier->z

/*
** ret_ft_printf
*/

# define RET_STR result->tab_conv[i]->ret_str

/*
** conversion flags
*/

# define CARACTERS "-+ #0"
# define F_WIDTH "123456789*"
# define PRECISION ".*"
# define L_MODIFIER "hljz"
# define C_SPECIFIERS "dDioOuUxXcCsSbp"

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
** Output
*/

# define RESULT_STR result->result_str->str
# define RESULT_LEN result->result_str->len

/*
** Errors
*/

# define GOOD_SHARP "oOxX"
# define GOOD_ZERO "dDioOuUxX"
# define GOOD_SPACE "dDib"
# define GOOD_PLUS "dDi"

# define ERR_BIN_1 "Error : flag 'b' results in undefined behavior with "
# define ERR_BIN ERR_BIN_1 "precision conversion specifier\n"
# define GOODFORM "[caracters][width][precision][modifier][specifier]\n"
# define INV_FORM RED"Error "EOC ": format have to be formated like "GOODFORM

#endif
