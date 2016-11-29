/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 01:24:50 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/29 16:54:30 by jmarsal          ###   ########.fr       */
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
#define FRM_ARGS "% Zoooo"
#define PRINTF fprintf(fichier, FRM_ARGS)
#define FT_PRINTF ft_printf(FRM_ARGS)
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

	// ft_printf("Avec ft_printf :");
	ret = ft_printf(FRM_ARGS);
	ft_printf("%d\n", ret);
	ret = printf(FRM_ARGS);
	printf("%d\n", ret);

	//LEAKS

	// ft_printf("\n");
	// ft_printf("%%\n");
	// ft_printf("%d\n", 42);
	// ft_printf("%d%d\n", 42, 41);
	// ft_printf("%d%d%d\n", 42, 43, 44);
	// ft_printf("%ld\n", 2147483647);
	// ft_printf("%lld\n", 9223372036854775807);
	// ft_printf("%x\n", 505);
	// ft_printf("%X\n", 505);
	// ft_printf("%p\n", &ft_printf);
	// ft_printf("%20.15d\n", 54321);
	// ft_printf("%-10d\n", 3);
	// ft_printf("% d\n", 3);
	// ft_printf("%+d\n", 3);
	// ft_printf("%010d\n", 1);
	// ft_printf("%hhd\n", 0);
	// ft_printf("%jd\n", 9223372036854775807);
	// ft_printf("%zd\n", 4294967295);
	// ft_printf("%\n");
	// ft_printf("%U\n", 4294967295);
	// ft_printf("%u\n", 4294967295);
	// ft_printf("%o\n", 40);
	// ft_printf("%%#08x\n", 42);
	// ft_printf("%x\n", 1000);
	// ft_printf("%#X\n", 1000);
	// ft_printf("%s\n", NULL);
	// ft_printf("%S\n", L"ݗݜशব");
	// ft_printf("%s%s\n", "test", "test");
	// ft_printf("%s%s%s\n", "test", "test", "test");
	// ft_printf("%C\n", 15000);
	// while (1);
	return (0);
}
