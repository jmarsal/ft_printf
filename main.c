/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 01:24:50 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/20 23:19:27 by jmarsal          ###   ########.fr       */
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

// int main()
//   {
// 	// wchar_t		test[50] = L"Schöne Grüße";
// 	// test = L"Schöne Grüße";
//     printf("%lc\n", c);
//     return 0;
//   }

int main()
{
	int	nb;
	int nb1;

	// nb1 = ft_printf("Hello%s%s world\n", " World !\n", "I am so happy");
	// ft_printf("%d\n", nb1);

	// nb1 = ft_printf("%s", "Hello World !\n");
	// ft_printf("%d\n", nb1);

	// nb1 = ft_printf("\n\n%s%s", "Hello World !\n", "C'est la fete !\n");
	// ft_printf("%d\n", nb1);

	nb1 = ft_printf("\n");
	ft_printf("%d\n", nb1);
	// ft_printf("%d\n", nb1);

	// nb1 = ft_printf("%%\n");
	// ft_printf("%d\n", nb1);

	// nb1 = ft_printf("Hello World\n");
	// ft_printf("%d\n", nb1);

	// nb1 = ft_printf("%%%s", "Hello World !\n");
	// ft_printf("%d\n", nb1);
// // ////////////////////////////////////////////////////////////////////////////////
	printf("Avec printf\n");	
// // ////////////////////////////////////////////////////////////////////////////////

	nb1 = printf("\n");
	printf("%d\n", nb1);
	// nb1 = printf("%d\n%d\n%d\n", nb, nb, nb);
	// printf("%d\n", nb1);
return (0);
}
