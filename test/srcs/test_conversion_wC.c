/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_conversion_wC.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 12:14:52 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/24 12:14:55 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int	main(void)
{
	wint_t texte = L'é';

	if (!setlocale(LC_CTYPE, ""))
	{
		fprintf(stderr, "Can't set the specified locale! "
			"Check LANG, LC_CTYPE, LC_ALL.\n");
		return 1;
	}
	printf("%lc\n", texte);
	return (0);
}