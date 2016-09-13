/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 01:24:50 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/14 01:14:01 by jmarsal          ###   ########.fr       */
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
	int nb1;

	nb = 42;
	nb1 = ft_printf("%b\n", nb);
	ft_printf("%d\n", nb1);

	nb = INT_MAX;
	nb1 = ft_printf("%b\n", nb);
	ft_printf("%d\n", nb1);

	nb = INT_MIN;
	nb1 = ft_printf("%b\n", nb);
	ft_printf("%d\n", nb1);

////////////////////////////////////////////////////////////////////////////////
	printf("Avec printf\n");
////////////////////////////////////////////////////////////////////////////////

int ret;

//nb = 42
ret = printf("%s\n", "101010");
printf("%d\n", ret);

//INT_MAX
ret = printf("%s\n", "1111111111111111111111111111111");
printf("%d\n", ret);

//INT_MIN
ret = printf("%s\n", "10000000000000000000000000000000");
printf("%d\n", ret);

///////////////////////////////////////////////////////////////////////////////
	// // ret = ft_printf("%p\n", &nb2);
	// // ft_printf("%d\n", ret);
	// ft_printf("%p\n", &nb2);
	// // ret = ft_printf("%+8.3d\n", nb2);
	// // ft_printf("%d\n", ret);
	//
	// printf("avec printf\n");
	// ret = printf("%p\n", &nb2);
	// printf("%d\n", ret);
	//
	// // ret = printf("%-+8.2d\n", nb2);
	// // printf("%d\n", ret);
	// // ret = printf("%+-8.3d\n", nb2);
	// // printf("%d\n", ret);
	// // ret = printf("%-+8.4d\n", nb2);
	// // printf("%d\n", ret);
	// // ret = printf("%-+8.5d\n", nb2);
	// // printf("%d\n", ret);
	// // ret = printf("%-+8.6d\n", nb2);
	// // printf("%d\n", ret);
	// // ret = printf("%-+8.7d\n", nb2);
	// // printf("%d\n", ret);
	// // ret = printf("%-+8.3d\n", nb2);
	// // ret = printf("%+o\n", nb2);
	// // ret = printf("%+u\n", nb2);
	// // ret = printf("%+x\n", nb2);
	// // ret = printf("%+c\n", 't');
	// // ret = printf("%+s\n", "coucou");
	// // printf("%d\n", ret);
	// // ret = printf("%-+*.10d\n", 9, nb2);
	// // printf("%d\n", ret);

return (0);
}
