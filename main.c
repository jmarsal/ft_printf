/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 01:24:50 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/05 02:24:52 by jmarsal          ###   ########.fr       */
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
	// short nb;
	// int nb1;
	// int nb2;
	// long int lnb;
	// unsigned int u_nb;
	// unsigned long	u_l_nb;
	// wint_t wc = E2 82 AC;     /* UNICODE X */
	int ret;
	// int *p;
	// signed char test;
	// char *so;
	// ret = ft_printf("%+d\n", 0);
	// ft_printf("%d\n", ret);
	// ret = ft_printf("%+d\n", 42);
	// ft_printf("%d\n", ret);
	// ret = ft_printf("%+d\n", -42);
	// ft_printf("%d\n", ret);
	// ft_printf("\n");
	ret = ft_printf("\033[35;1m%s\033[0m\n", "hello");
	printf("%d\n", ret);
	// ret = printf("%+d\n", 42);
	// printf("%d\n", ret);
	// ret = printf("%+d\n", -42);
	// printf("%d\n", ret);
	// ret = ft_printf("%+d\n", -42);
	// ft_printf("%d\n", ret);
	// printf("%+d\n", -42);
	// printf("%d\n", ret);
	// p = &nb;
	// ret = ft_printf("%p\n", p);
	// // ft_printf("%d\n", ret);
	//
	// ret = printf("%p\n", p);
	// // printf("%d\n", ret);
	// setlocale(LC_ALL, "fr_FR.UTF-8");
    // setlocale(LC_ALL, "");
    // wprintf(L"ο Δικαιοπολις εν αγρω εστιν\n");  // wide output
    // freopen(NULL, "w", stdout);                 // lets me switch
	// printf("ο Δικαιοπολις εν αγρω εστιν\n");	// lnb = LONG_MIN;
	// ret = ft_printf("%D\n", lnb);
	// ft_printf("%d\n", ret);
	// ret = printf("%ld\n", lnb);
	// printf("%d\n", ret);
	// u_nb = UINT_MAX;
	// u_l_nb = ULONG_MAX;
	// ret = ft_printf("%s%s\n", "hello", " world");
	// ft_printf("%d\n", ret);
 // 	u_l_nb = 17002442;
 // ret = printf("%d\n", 12345);
 // printf("%d\n", ret);
 // ret = printf("%+d\n", 12345);
 // printf("%d\n", ret);
 // ret = printf("%-8d\n", 12345);
 // printf("%d\n", ret);
 // ret = printf("%.8d\n", 12345);
 // printf("%d\n", ret);
 // ret = printf("% 30.8d\n", -12345);
 // printf("%d\n", ret);
	// nb = 42;

	// ret = printf("%ld\n", lnb);
	// ft_printf("%d\n", ret);
	// ret = ft_printf("%D\n", lnb);
	// ft_printf("%d\n", ret);
	// lnb = -42;
	// nb = -42;
	// ret = printf("%d\n", nb);
	// ft_printf("%d\n", ret);
	// ret = ft_printf("%i\n", nb);
	// ft_printf("%i\n", ret);
	// p = &nb;
	// nb1 = ft_printf("%p\n", p);
	// ft_printf("%d\n", nb1);
	//
	// nb2 = printf("%p\n", p);
	// printf("%d\n", nb2);
	//
	// so = &test;
	// nb1 = ft_printf("%p\n", so);
	// ft_printf("%d\n", nb1);
	//
	// nb2 = printf("%p\n", so);
	// printf("%d\n", nb2);

	// nb1 = ft_printf("%b\n", "Hello World");
	// ft_printf("%d\n", nb1);

return (0);
}
