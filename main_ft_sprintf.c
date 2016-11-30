/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_sprintf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 09:34:06 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/30 22:55:03 by jmarsal          ###   ########.fr       */
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

	ret = ft_strnew(0);
	ft_printf("     {green}_______________________{eoc}\n");
	ft_printf("    {green}|                       |{eoc}\n");
	ft_printf("{green}----|    {eoc}{red}Avec ft_sprintf{eoc}    {green}|------>{eoc}{red} Idem que ft_asprintf, mais le char * doit etre allouer{eoc}\n");
	ft_printf("    {green}|                       |{eoc}\n");
	ft_printf("     {green}-----------------------{eoc}\n\n");

	len = ft_sprintf(ret, "{blue}coucou{eoc} {pink}c'est cool {eoc}{green}la couleur{eoc}\n");
	ft_printf("{cyan}ft_sprintf{eoc} = %s%d\n", ret, len);
	len = ft_sprintf(ret, "Le binaire de 42 = %b\n", 42);
	ft_printf("{cyan}ft_sprintf{eoc} = %s%d\n", ret, len);

	len = sprintf(ret, "\033[34mcoucou\033[0m \033[35;1mc'est cool \033[0m\033[32;1mla couleur\033[0m\n");
	ft_printf("{cyan}sprintf{eoc} = %s%d\n", ret, len);
	len = sprintf(ret, "Le binaire de 42 = 101010\n");
	ft_printf("{cyan}sprintf{eoc} = %s%d\n", ret, len);
	return (0);
}
