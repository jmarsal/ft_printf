/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_asprintf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 09:34:06 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/18 16:59:29 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	main()
{
	char	*ret;
	int		len;

	ret = NULL;
	ret = ft_strnew(100);
	len = ft_sprintf(ret, "{blue}coucou{eoc} {pink}c'est cool'{eoc}{green}la couleur{eoc}\n");
	printf("ft_asprintf = %s%d\n", ret, len);
	len = sprintf(ret, "{blue}coucou{eoc} {pink}c'est cool'{eoc}{green}la couleur{eoc}\n");
	printf("asprintf = %s%d\n", ret, len);
	// len = ft_printf("%c\n", 0);
	// ft_printf("%d\n", len);
	// len = printf("%c\n", 0);
	// printf("%d\n", len);
	// return (0);
}
