/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 01:24:50 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/02 23:26:06 by jmarsal          ###   ########.fr       */
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
	unsigned int	nb;
	// int nb1;
	long nb2;
	// int ret;
	// nb2 = 10;
	wint_t		c = L'é';
	wchar_t		test[50] = L"Schöne Grüße";
	int			ret;

	if (!setlocale(LC_CTYPE, ""))
	{
		fprintf(stderr, "Can't set the specified locale! "
			"Check LANG, LC_CTYPE, LC_ALL.\n");
		return 1;
	}

	// test with modifier
	ret = ft_printf(NULL);
	ft_printf("%d\n", ret);
	ret = ft_printf("%C\n", NULL);
	ft_printf("%d\n", ret);
	ret = ft_printf("%S\n", test);
	ft_printf("%d\n", ret);
	ret = ft_printf("%ls\n", test);
	ft_printf("%d\n", ret);

// // ////////////////////////////////////////////////////////////////////////////////
	printf("Avec printf\n");
// // ////////////////////////////////////////////////////////////////////////////////

	ret = printf("%ls\n", test);
	printf("%d\n", ret);
	ret = printf("%p\n", &test);
	printf("%d\n", ret);
	printf("{\n");

	// // ret = printf("%-+*.10d\n", 9, nb2);
	// // printf("%d\n", ret);

return (0);
}
