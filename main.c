/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 01:24:50 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/10 16:32:54 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <wchar.h>
#include <limits.h>
#include <locale.h>
#include <stdio.h>

// Voir a ajouter une variable width_cpy pour garder en memoire la largeur de base
// Peut etre une variable qui compte chaques caracteres ajoute pour le deduire
// de la largeur (width_cpy)

// IMPORTANT !

// Prendre le temps de factoriser voir repenser les fonctions,
// mtn que l'essenssiel des flags sont gerer afin de pouvoir travailler
// plus proprement et plus efficacement !
// Et peut etre aussi des structs...


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

// int main()
//   {
// 	// wchar_t		test[50] = L"Schöne Grüße";
// 	wint_t		c = L'é';
// 	// test = L"Schöne Grüße";
//     if (!setlocale(LC_CTYPE, "")) {
//       fprintf(stderr, "Can't set the specified locale! "
//               "Check LANG, LC_CTYPE, LC_ALL.\n");
//       return 1;
//     }
//     printf("%lc\n", c);
//     return 0;
//   }

int main()
{
 	int	nb;
	int nb2;
	int ret;

	nb2 = 42;
	nb = 42;

	// nb = ft_printf("%d\n", 42);
	// ft_printf("%d\n", nb);
	// nb = ft_printf("%d\n", -42);
	// ft_printf("%d\n", nb);
	// nb = ft_printf("%d\n", INT_MIN);
	// ft_printf("%d\n", nb);
	// nb = ft_printf("%d\n", INT_MAX);
	// ft_printf("%d\n", nb);
	// nb = ft_printf("%i\n", 42);
	// ft_printf("%d\n", nb);
	// nb = ft_printf("%i\n", -42);
	// ft_printf("%d\n", nb);
	// nb = ft_printf("%i\n", INT_MIN);
	// ft_printf("%d\n", nb);
	// nb = ft_printf("%i\n", INT_MAX);
	// ft_printf("%d\n", nb);
	//
	// // test Flags caracters
	//
	// nb = ft_printf("%+d\n", 0);
	// ft_printf("%d\n", nb);
	// nb = ft_printf("%+d\n", 42);
	// ft_printf("%d\n", nb);
	// nb = ft_printf("%+d\n", -42);
	// ft_printf("%d\n", nb);
	//
	// nb2 = 42;
	// nb = ft_printf("%8d\n", nb2);
	// ft_printf("%d\n", nb);
	// nb = ft_printf("%-8d\n", nb2);
	// ft_printf("%d\n", nb);
	// nb = ft_printf("%08d\n", nb2);
	// ft_printf("%d\n", nb);
	//
	// printf("avec printf\n");
	//
	// nb = printf("%d\n", 42);
	// printf("%d\n", nb);
	// nb = printf("%d\n", -42);
	// printf("%d\n", nb);
	// nb = printf("%d\n", INT_MIN);
	// printf("%d\n", nb);
	// nb = printf("%d\n", INT_MAX);
	// printf("%d\n", nb);
	// nb = printf("%i\n", 42);
	// printf("%d\n", nb);
	// nb = printf("%i\n", -42);
	// printf("%d\n", nb);
	// nb = printf("%i\n", INT_MIN);
	// printf("%d\n", nb);
	// nb = printf("%i\n", INT_MAX);
	// printf("%d\n", nb);
	//
	// // test Flags caracters
	//
	// nb = printf("%+d\n", 0);
	// printf("%d\n", nb);
	// nb = printf("%+d\n", 42);
	// printf("%d\n", nb);
	// nb = printf("%+d\n", -42);
	// printf("%d\n", nb);
	//
	// nb2 = 42;
	// nb = printf("%8d\n", nb2);
	// printf("%d\n", nb);
	// nb = printf("%-8d\n", nb2);
	// printf("%d\n", nb);
	// nb = printf("%08d\n", nb2);
	// printf("%d\n", nb);

///////////////////////////////////////////////////////////////////////////////

	ret = ft_printf("%c\n", nb2);
	// ft_printf("%d\n", ret);
	// ret = ft_printf("%+8.3d\n", nb2);
	// ft_printf("%d\n", ret);

	printf("avec printf\n");

	// ret = printf("%-+8.2d\n", nb2);
	// printf("%d\n", ret);
	// ret = printf("%+-8.3d\n", nb2);
	// printf("%d\n", ret);
	// ret = printf("%-+8.4d\n", nb2);
	// printf("%d\n", ret);
	// ret = printf("%-+8.5d\n", nb2);
	// printf("%d\n", ret);
	// ret = printf("%-+8.6d\n", nb2);
	// printf("%d\n", ret);
	// ret = printf("%-+8.7d\n", nb2);
	// printf("%d\n", ret);
	ret = printf("%-+8.3d\n", nb2);
	printf("%d\n", ret);
	// ret = printf("%-+*.10d\n", 9, nb2);
	// printf("%d\n", ret);

return (0);
}
