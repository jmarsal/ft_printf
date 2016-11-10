/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 01:24:50 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/10 16:31:01 by jmarsal          ###   ########.fr       */
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
	int	nb;
	int nb2;

	nb = ft_printf("%-16.8hhd\n", (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-16.8hd\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-16.8d\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-16.8ld\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-16.8lld\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);

/*	nb = ft_printf("%-8.16hhd\n", (char)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.16hd\n", (short)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.16d\n", (int)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.16ld\n", (long)-2147483649051561567);
	ft_printf("%d\n", nb);
	nb = ft_printf("%-8.16lld\n", (long long)-2147483649051561567);
	ft_printf("%d\n", nb);
*/
// // ////////////////////////////////////////////////////////////////////////////////
	printf("Avec printf\n");	
// // ////////////////////////////////////////////////////////////////////////////////

	nb = printf("%-16.8hhd\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-16.8hd\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-16.8d\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-16.8ld\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-16.8lld\n", (long long)-2147483649051561567);
	printf("%d\n", nb);

/*	nb = printf("%-8.16hhd\n", (char)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.16hd\n", (short)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.16d\n", (int)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.16ld\n", (long)-2147483649051561567);
	printf("%d\n", nb);
	nb = printf("%-8.16lld\n", (long long)-2147483649051561567);
	printf("%d\n", nb);
*/
	return (0);
}
