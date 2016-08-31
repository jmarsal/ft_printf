/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 22:51:25 by jmarsal           #+#    #+#             */
/*   Updated: 2016/08/29 22:34:41 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include "structs.h"
/*
** f_conv
*/

# define STR v_args->f_conv[v_args->i_args]->str
# define NB v_args->f_conv[v_args->i_args]->nb
# define L_NB v_args->f_conv[v_args->i_args]->l_nb
# define HEX v_args->f_conv[v_args->i_args]->hex
# define C v_args->f_conv[v_args->i_args]->c
# define L_CONV v_args->f_conv[v_args->i_args]->l_conv
# define BINARY v_args->f_conv[v_args->i_args]->binary
# define PTR v_args->f_conv[v_args->i_args]->ptr
# define OCT v_args->f_conv[v_args->i_args]->oct
# define L_OCT v_args->f_conv[v_args->i_args]->l_oct
#endif
