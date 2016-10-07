/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_conversion_S.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:19:24 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/07 14:46:58 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <locale.h>
#include <wchar.h>

int	main(void)
{
	wchar_t texte[50] = L"Schöne Grüße";
	int 	ret;

	if (!setlocale(LC_CTYPE, ""))
	{
		fprintf(stderr, "Can't set the specified locale! "
			"Check LANG, LC_CTYPE, LC_ALL.\n");
		return 1;
	}
	ret = ft_printf("%ls\n", texte);
	ft_printf("%d\n", ret);
	ret = ft_printf("{green}%ls{eoc} comment {green}va tu {eoc}?\n", texte);
	ft_printf("%d\n", ret);
	ret = ft_printf("{red}%ls{eoc} comment {red}va tu {eoc}?\n", texte);
	ft_printf("%d\n", ret);
	ret = ft_printf("{blue}%ls{eoc} comment {blue}va tu {eoc}?\n", texte);
	ft_printf("%d\n", ret);
	ret = ft_printf("{pink}%ls{eoc} comment {pink}va tu {eoc}?\n", texte);
	ft_printf("%d\n", ret);
	ret = ft_printf("{cyan}%ls{eoc} comment {cyan}va tu {eoc}?\n", texte);
	ft_printf("%d\n", ret);
	ret = ft_printf("{yan}%ls{eoc} comment {cyan}va tu {eoc}?\n", texte);
	ft_printf("%d\n", ret);

	return (0);
}
