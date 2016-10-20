/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_conversion_S.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:19:46 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/20 23:15:34 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int	main(void)
{
	wchar_t texte[50] = L"Schöne Grüße";
	int		ret;

	if (!setlocale(LC_CTYPE, ""))
	{
		fprintf(stderr, "Can't set the specified locale! "
			"Check LANG, LC_CTYPE, LC_ALL.\n");
		return 1;
	}
	ret = printf("%ls\n", texte);
	printf("%d\n", ret);
	ret = printf("\033[32;1m%ls\033[0m comment \033[32;1mva tu \033[0m?\n", texte);
	printf("%d\n", ret);
	ret = printf("\033[31m%ls\033[0m comment \033[31mva tu \033[0m?\n", texte);
	printf("%d\n", ret);
	ret = printf("\033[34m%ls\033[0m comment \033[34mva tu \033[0m?\n", texte);
	printf("%d\n", ret);
	ret = printf("\033[35;1m%ls\033[0m comment \033[35;1mva tu \033[0m?\n", texte);
	printf("%d\n", ret);
	ret = printf("\033[36;1m%ls\033[0m comment \033[36;1mva tu \033[0m?\n", texte);
	printf("%d\n", ret);
	ret = printf("{yan}%ls\033[0m comment \033[36;1mva tu \033[0m?\n", texte);
	printf("%d\n", ret);
	return (0);
}