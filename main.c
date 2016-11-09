/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 01:24:50 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/09 15:24:50 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <wchar.h>
#include <limits.h>
#include <locale.h>
#include <stdio.h>

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
	unsigned int	nb;
	int				ret;

	nb = ft_printf("%#-8.8hho\n", (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-8.8ho\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-8.8o\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-8.8lo\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-8.8llo\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);

/*	nb = ft_printf("%#-16.8hho\n", (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-16.8ho\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-16.8o\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-16.8lo\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-16.8llo\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);

	nb = ft_printf("%#-8.16hho\n", (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-8.16ho\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-8.16o\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-8.16lo\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#-8.16llo\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);

	nb = ft_printf("%-8.8hho\n", (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.8ho\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.8o\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.8lo\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.8llo\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);

	nb = ft_printf("%-16.8hho\n", (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-16.8ho\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-16.8o\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-16.8lo\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-16.8llo\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);

	nb = ft_printf("%-8.16hho\n", (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.16ho\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.16o\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.16lo\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.16llo\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);

	nb = ft_printf("%#8.8hho\n", (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#8.8ho\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#8.8o\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#8.8lo\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#8.8llo\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);

	nb = ft_printf("%#16.8hho\n", (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#16.8ho\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#16.8o\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#16.8lo\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#16.8llo\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);

	nb = ft_printf("%#8.16hho\n", (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#8.16ho\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#8.16o\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#8.16lo\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%#8.16llo\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);
*/
// // ////////////////////////////////////////////////////////////////////////////////
	printf("Avec printf\n");	
// // ////////////////////////////////////////////////////////////////////////////////

	nb = printf("%#-8.8hho\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-8.8ho\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-8.8o\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-8.8lo\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-8.8llo\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

/*	nb = printf("%#-16.8hho\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-16.8ho\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-16.8o\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-16.8lo\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-16.8llo\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

	nb = printf("%#-8.16hho\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-8.16ho\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-8.16o\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-8.16lo\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#-8.16llo\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

	nb = printf("%-8.8hho\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.8ho\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.8o\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.8lo\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.8llo\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

	nb = printf("%-16.8hho\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-16.8ho\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-16.8o\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-16.8lo\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-16.8llo\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

	nb = printf("%-8.16hho\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.16ho\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.16o\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.16lo\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.16llo\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

	nb = printf("%#8.8hho\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#8.8ho\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#8.8o\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#8.8lo\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#8.8llo\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

	nb = printf("%#16.8hho\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#16.8ho\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#16.8o\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#16.8lo\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#16.8llo\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

	nb = printf("%#8.16hho\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#8.16ho\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#8.16o\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#8.16lo\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%#8.16llo\n", (long long)-2147483649051561567);
	printf("%d\n", nb);
*/	
	return (0);
}
