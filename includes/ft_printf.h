/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 00:40:21 by jmarsal           #+#    #+#             */
/*   Updated: 2016/08/11 17:21:51 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "structs.h"

#include <stdio.h> // WARNING !!!!

int		ft_printf(const char *format, ...);
int	treatment(va_list *args, const char *format);

void	ft_putchar_fd(char c, int fd);
void	ft_putchar(char c);
void	ft_putstr(char const *str);

#endif
