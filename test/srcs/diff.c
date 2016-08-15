/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 00:02:43 by jmarsal           #+#    #+#             */
/*   Updated: 2016/08/15 01:50:18 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int			main(void)
{
	int		fd;
	int		len;
	int		test;
	char	buffer[4096];

	test = 0;
	//test diffs sur les conversions

	// %s
	if ((fd = open("diff_output/diff_conv_s.txt", O_RDONLY)) < 1)
	{
		printf("Erreur : Pas de fichier diff_conv_s.txt");
		return (-1);
	}
	if ((len = read(fd, buffer, 4096)) == 0)
	{
		printf("\033[32m%s\033[0m\n", "---> test de conversion \%s ok !");
		close(fd);
		remove("diff_output/diff_conv_s.txt");
	}
	else
	{
		printf("\033[31m%s\033[0m\n\n", "---> probleme avec le test de\
										conversion \%s!");
		printf("%s\n", buffer);
		close(fd);
		test = 1;
		printf("%s\n", "Le fichier de diff se trouve dans le repertoire\
		 				\"diff_output\".");
	}

	// %S
	if ((fd = open("diff_output/diff_conv_S.txt", O_RDONLY)) < 1)
	{
		printf("Erreur : Pas de fichier diff_conv_S.txt");
		return (-1);
	}
	if ((len = read(fd, buffer, 4096)) == 0)
	{
		printf("\033[32m\n%s\033[0m\n", "---> test de conversion \%S ok !");
		close(fd);
		remove("diff_output/diff_conv_S.txt");
	}
	else
	{
		printf("\033[31m\n%s\033[0m\n\n", "---> probleme avec le test de\
										conversion \%S!");
		printf("%s\n", buffer);
		close(fd);
		test = 1;
		printf("%s\n", "Le fichier de diff se trouve dans le repertoire\
						\"diff_output\".");
	}

	// %p
	if ((fd = open("diff_output/diff_conv_p.txt", O_RDONLY)) < 1)
	{
		printf("Erreur : Pas de fichier diff_conv_p.txt");
		return (-1);
	}
	if ((len = read(fd, buffer, 4096)) == 0)
	{
		printf("\033[32m\n%s\033[0m\n", "---> test de conversion \%p ok !");
		close(fd);
		remove("diff_output/diff_conv_p.txt");
	}
	else
	{
		printf("\033[31m\n%s\033[0m\n\n", "---> probleme avec le test de\
										conversion \%p!");
		printf("%s\n", buffer);
		close(fd);
		test = 1;
		printf("%s\n", "Le fichier de diff se trouve dans le repertoire\
						\"diff_output\".");
	}

	// Fin de test
	if (test == 0)
	{
		printf("\n\033[32m%s\033[0m\n", "---> ft_printf OK ! Well Done ;-)\n");
		remove("diff_output");
	}

	return (0);
}
