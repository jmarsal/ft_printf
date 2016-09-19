/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 01:24:50 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/19 02:20:17 by jmarsal          ###   ########.fr       */
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

	// int	nb;
	// int nb1;
	// int nb2;
	// int ret;

	// nb2 = 10;

	int			ret;


	ret = ft_printf("%+D\n", LONG_MIN - 1);
	ft_printf("%d\n", ret);

// 	ret = ft_printf("%#-8.0X\n", nb2);
// 	ft_printf("%d\n", ret);
// 	ret = ft_printf("%#-8.1X\n", nb2);
// 	ft_printf("%d\n", ret);
// 	ret = ft_printf("%#-8.2X\n", nb2);
// 	ft_printf("%d\n", ret);
// 	ret = ft_printf("%#-8.3X\n", nb2);
// 	ft_printf("%d\n", ret);
// 	ret = ft_printf("%#-8.4X\n", nb2);
// 	ft_printf("%d\n", ret);
// 	ret = ft_printf("%#-8.5X\n", nb2);
// 	ft_printf("%d\n", ret);
// 	ret = ft_printf("%#-8.6X\n", nb2);
// 	ft_printf("%d\n", ret);
// 	ret = ft_printf("%#-8.7X\n", nb2);
// 	ft_printf("%d\n", ret);
// 	ret = ft_printf("%#-8.8X\n", nb2);
// 	ft_printf("%d\n", ret);
//
// ////////////////////////////////////////////////////////////////////////////////
	printf("Avec printf\n");
// ////////////////////////////////////////////////////////////////////////////////
//

ret = printf("%+ld\n", LONG_MIN - 1);
printf("%d\n", ret);


// 	// printf("avec printf\n");
// 	// ret = printf("%p\n", &nb2);
// 	// printf("%d\n", ret);
// 	//
// 	ret = printf("%#-8.0X\n", nb2);
// 	printf("%d\n", ret);
// 	ret = printf("%#-8.1X\n", nb2);
// 	printf("%d\n", ret);
// 	ret = printf("%#-8.2X\n", nb2);
// 	printf("%d\n", ret);
// 	ret = printf("%#-8.3X\n", nb2);
// 	printf("%d\n", ret);
// 	ret = printf("%#-8.4X\n", nb2);
// 	printf("%d\n", ret);
// 	ret = printf("%#-8.5X\n", nb2);
// 	printf("%d\n", ret);
// 	ret = printf("%#-8.6X\n", nb2);
// 	printf("%d\n", ret);
// 	ret = printf("%#-8.7X\n", nb2);
// 	printf("%d\n", ret);
// 	ret = printf("%#-8.8X\n", nb2);
// 	printf("%d\n", ret);

	// // ret = printf("%-+*.10d\n", 9, nb2);
	// // printf("%d\n", ret);

return (0);
}
