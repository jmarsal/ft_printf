/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_asprintf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 09:34:06 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/30 17:05:01 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	main()
{
	char	*ret;
	int		len;

	ret = NULL;

	ft_printf("{green}_____    {eoc}{red}Avec ft_asprintf{eoc}    {green}_____{eoc}\n\n");


	len = ft_asprintf(&ret, "{blue}coucou{eoc} {pink}c'est cool {eoc}{green}la couleur{eoc}\n");
	printf("ft_asprintf = %s%d\n", ret, len);
	len = asprintf(&ret, "\033[34mcoucou\033[0m \033[35;1mc'est cool \033[0m\033[32;1mla couleur\033[0m\n");
	printf("asprintf = %s%d\n", ret, len);

	return (0);
}
