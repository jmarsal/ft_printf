/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 01:24:50 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/30 17:02:26 by jmarsal          ###   ########.fr       */
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

// Modifier ici
#define FRM_ARGS "{blue}coucou{eoc} {pink}c'est cool {eoc}{green}la couleur{eoc}\n"

/*
** % [drapeaux] [largeur] [.precision] [modificateur] type
**
** Apres %	1) ->	Gerer les flags caracters (spécificateurs de format)
**					--> ('-', '+', ' ', '#')
**					--> justifié à droite et complété à gauche par des espaces
**			2) ->	Gerer field width (largeur)
**					--> (n = affiche n carcateres)
**					--> (0n = affiche n caracteres eventuelement completer par des 0)
**					--> (* = l'argument suivant de la liste indique la largeur)
**			3) ->	Gerer precision
**					--> (rien = précision par défaut :
**								d,i,o,u,x : 1 chiffre
**								e, E, f : 6 chiffres pour la partie décimale.)
**					--> (.0 =  d,i,o,u,x : précision par défaut
**								e, E, f : pas de point décimal)
**					--> (.n = n caractères au plus)
**					--> (* = l'argument suivant de la liste contient la précision)
**			4) ->	Gerer length modifier (modificateur)
**					--> ('h', 'hh', 'l', 'll', 'j', 'z')
*/

int main()
{
	wchar_t texte[50] = L"Schöne Grüße";
	int 				ret;
	int					test_simple_mix;
	unsigned long int	nb;
	int 				pointer_valueLargerThanMinWidth_zeroFlag;
	char 				*retour_str;
	FILE				*fichier = NULL;
	int					t;
	int					fd;
	int					ft_pr;

	// fichier = fopen("printf.txt", "a+");
	// fclose(fichier);
	// fd = open("printf.txt", O_RDWR);
	if (!setlocale(LC_CTYPE, ""))
	{
		fprintf(stderr, "Can't set the specified locale! "
			"Check LANG, LC_CTYPE, LC_ALL.\n");
		return 1;
	}
	// if (fichier != NULL && fd)
	// {
	// 	// ret = FT_PRINTF;
	// 	ret = ft_dprintf(fd, FRM_ARGS);
	// 	ft_dprintf(fd, "%d\n", ret);
	// 	// ret = PRINTF;
	// 	ret = dprintf(fd, FRM_ARGS);
	// 	dprintf(fd, "%d\n", ret);
	// 	close(fd);
	// }

	ft_printf("{green}_____    {eoc}{red}Avec ft_printf{eoc}    {green}_____{eoc}\n\n");

	
	ft_printf("ft_printf = ");
	ret = ft_printf("{blue}coucou{eoc} {pink}c'est cool {eoc}{green}la couleur{eoc}\n");
	ft_printf("%d\n", ret);
	printf("printf = ");
	ret = printf("\033[34mcoucou\033[0m \033[35;1mc'est cool \033[0m\033[32;1mla couleur\033[0m\n");
	printf("%d\n", ret);

	return (0);
}
