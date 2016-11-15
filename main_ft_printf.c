/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 01:24:50 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/15 16:49:32 by jmarsal          ###   ########.fr       */
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

// Modifier ici
#define FRM_ARGS "%2.9p", 1234

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

	fichier = fopen("printf.txt", "a+");

	if (!setlocale(LC_CTYPE, "en_US.UTF-8"))
	{
		fprintf(stderr, "Can't set the specified locale! "
			"Check LANG, LC_CTYPE, LC_ALL.\n");
		return 1;
	}
	printf("Format + ARGS = %s\n", FRM_ARGS);
	ret = FT_PRINTF;
	ft_printf("%d\n", ret);
	if (fichier != NULL)
    {
        ret = PRINTF;
		fprintf(fichier, "%d\n", ret);
        fclose(fichier);
    }

	return (0);
}
