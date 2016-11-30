/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_dprintf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:05:40 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/30 22:56:34 by jmarsal          ###   ########.fr       */
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
#include <fcntl.h>

int	main()
{
	FILE	*fichier = NULL;
	int		fd;
	int		len;

	fichier = fopen("printf.txt", "a+");
	fclose(fichier);
	fd = open("printf.txt", O_RDWR);
	ft_printf("     {green}_______________________{eoc}\n");
	ft_printf("    {green}|                       |{eoc}\n");
	ft_printf("{green}----|    {eoc}{red}Avec ft_dprintf{eoc}    {green}|------>{eoc}{red} retourne la conversion dans un fichier par le fd recu en parametre{eoc}\n");
	ft_printf("    {green}|                       |{eoc}\n");
	ft_printf("     {green}-----------------------{eoc}\n\n");

	if (fichier != NULL && fd)
	{
		ft_dprintf(fd, "{cyan}ft_dprintf{eoc} = ");
		len = ft_dprintf(fd, "{blue}coucou{eoc} {pink}c'est cool {eoc}{green}la couleur{eoc}\n");
		ft_dprintf(fd, "%d\n", len);
		len = ft_dprintf(fd, "Le binaire de 42 = %b\n", 42);
		ft_dprintf(fd, "%d\n", len);
		ft_dprintf(fd, "{cyan}dprintf{eoc} = ");
		len = dprintf(fd, "\033[34mcoucou\033[0m \033[35;1mc'est cool \033[0m\033[32;1mla couleur\033[0m\n");
		dprintf(fd, "%d\n", len);
		len = dprintf(fd, "Le binaire de 42 = 101010\n");
		dprintf(fd, "%d\n", len);
		close(fd);
	}

	return (0);
}
