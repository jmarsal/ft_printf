/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 00:40:21 by jmarsal           #+#    #+#             */
/*   Updated: 2016/08/21 15:50:34 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "structs.h"
# include <libft.h>

#include <stdio.h> // WARNING !!!!

int				ft_printf(const char *format, ...);
int				treatment(va_list *args, const char *format);

/*
** print_format
*/

void			print_format(t_v_args *v_args);

/*
** init.c
*/

t_v_args		*init_t_v_args(void);
t_conversion	**init_tab_args(t_v_args *v_args);

#endif
