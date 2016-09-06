/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 22:51:25 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/06 01:02:24 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/*
** f_conv
*/

# define STR v_args->f_conv[v_args->i_args]->str
# define U_L_INT v_args->f_conv[v_args->i_args]->u_l_nb
# define INT v_args->f_conv[v_args->i_args]->nb
# define L_INT v_args->f_conv[v_args->i_args]->l_nb
# define U_INT v_args->f_conv[v_args->i_args]->u_nb
# define C v_args->f_conv[v_args->i_args]->c
# define L_CONV v_args->f_conv[v_args->i_args]->l_conv
# define PTR v_args->f_conv[v_args->i_args]->ptr

/*
** conversion flags
*/

# define C_SPECIFIERS "dDioOuUxXcCsSbp" //reste a gerer le 'C' ou 'S'
# define F_CARACTERS "-+ #0" // reste a gerer le ' ' et le '#'
# define F_WIDTH "123456789*" // OK
# define PRECISION ".*"
# define L_MODIFIER "hljz"

/*
** colors
*/

# define GREEN "\033[32;1m"
# define RED "\033[31m"
# define BLUE "\033[34m"
# define PINK "\033[35;1m"
# define CYAN "\033[36;1m"
# define EOC "\033[0m"

#endif
