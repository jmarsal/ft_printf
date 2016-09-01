/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 22:51:25 by jmarsal           #+#    #+#             */
/*   Updated: 2016/08/31 17:18:00 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include "structs.h"
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
#endif
