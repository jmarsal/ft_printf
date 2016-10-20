/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 00:02:43 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/20 23:09:41 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "ft_printf.h"

int			main(void)
{
	int		fd;
	int		len;
	int		test;
	char	buffer[4096];
	int		nb, nb1, nb2;
	int		*ptr_nb;

	test = 0;
	//test diffs sur les conversions
////////////////////////////////////////////////////////////////////////////////
	// %s
	if ((fd = open("test/diff_output/diff_conv_s.txt", O_RDONLY)) < 1)
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
////////////////////////////////////////////////////////////////////////////////
	// %S
	if ((fd = open("test/diff_output/diff_conv_S.txt", O_RDONLY)) < 1)
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
////////////////////////////////////////////////////////////////////////////////
	// %p
	printf("\n<<<<<\t\ttest pointeur %%p\t\t>>>>>\n");
	ptr_nb = &nb;
	nb1 = ft_printf("%p\n", ptr_nb);
	ft_printf("%d\n", nb1);
	//
	nb2 = printf("%p\n", ptr_nb);
	printf("%d\n", nb2);
	if (nb1 == nb2)
		printf("\033[32m\n%s\033[0m\n", "---> test de conversion \%p ok !");
	else
	{
		printf("\033[31m\n%s\033[0m\n\n", "---> probleme avec le test de\
										conversion \%p!");
		test = 1;
	}
////////////////////////////////////////////////////////////////////////////////
	// %d
	if ((fd = open("test/diff_output/diff_conv_d_i.txt", O_RDONLY)) < 1)
	{
		printf("Erreur : Pas de fichier diff_conv_d_i.txt");
		return (-1);
	}
	if ((len = read(fd, buffer, 4096)) == 0)
	{
		printf("\033[32m\n%s\033[0m\n", "---> test de conversion \%d ou \%i ok !");
		close(fd);
		remove("diff_output/diff_conv_d.txt");
	}
	else
	{
		printf("\033[31m\n%s\033[0m\n\n", "---> probleme avec le test de\
										conversion \%d ou \%i!");
		printf("%s\n", buffer);
		close(fd);
		test = 1;
		printf("%s\n", "Le fichier de diff se trouve dans le repertoire\
						\"diff_output\".");
	}
////////////////////////////////////////////////////////////////////////////////
	// %D
	if ((fd = open("test/diff_output/diff_conv_D.txt", O_RDONLY)) < 1)
	{
		printf("Erreur : Pas de fichier diff_conv_D.txt");
		return (-1);
	}
	if ((len = read(fd, buffer, 4096)) == 0)
	{
		printf("\033[32m\n%s\033[0m\n", "---> test de conversion \%D ok !");
		close(fd);
		remove("diff_output/diff_conv_d.txt");
	}
	else
	{
		printf("\033[31m\n%s\033[0m\n\n", "---> probleme avec le test de\
										conversion \%D!");
		printf("%s\n", buffer);
		close(fd);
		test = 1;
		printf("%s\n", "Le fichier de diff se trouve dans le repertoire\
						\"diff_output\".");
	}
////////////////////////////////////////////////////////////////////////////////
// %o
if ((fd = open("test/diff_output/diff_conv_o.txt", O_RDONLY)) < 1)
{
	printf("Erreur : Pas de fichier diff_conv_o.txt");
	return (-1);
}
if ((len = read(fd, buffer, 4096)) == 0)
{
	printf("\033[32m\n%s\033[0m\n", "---> test de conversion \%o ok !");
	close(fd);
	remove("diff_output/diff_conv_d.txt");
}
else
{
	printf("\033[31m\n%s\033[0m\n\n", "---> probleme avec le test de\
									conversion \%o!");
	printf("%s\n", buffer);
	close(fd);
	test = 1;
	printf("%s\n", "Le fichier de diff se trouve dans le repertoire\
					\"diff_output\".");
}
////////////////////////////////////////////////////////////////////////////////
// %O
if ((fd = open("test/diff_output/diff_conv_O.txt", O_RDONLY)) < 1)
{
	printf("Erreur : Pas de fichier diff_conv_O.txt");
	return (-1);
}
if ((len = read(fd, buffer, 4096)) == 0)
{
	printf("\033[32m\n%s\033[0m\n", "---> test de conversion \%O ok !");
	close(fd);
	remove("diff_output/diff_conv_d.txt");
}
else
{
	printf("\033[31m\n%s\033[0m\n\n", "---> probleme avec le test de\
									conversion \%O!");
	printf("%s\n", buffer);
	close(fd);
	test = 1;
	printf("%s\n", "Le fichier de diff se trouve dans le repertoire\
					\"diff_output\".");
}
////////////////////////////////////////////////////////////////////////////////
// %u
if ((fd = open("test/diff_output/diff_conv_u.txt", O_RDONLY)) < 1)
{
	printf("Erreur : Pas de fichier diff_conv_u.txt");
	return (-1);
}
if ((len = read(fd, buffer, 4096)) == 0)
{
	printf("\033[32m\n%s\033[0m\n", "---> test de conversion \%u ok !");
	close(fd);
	remove("diff_output/diff_conv_d.txt");
}
else
{
	printf("\033[31m\n%s\033[0m\n\n", "---> probleme avec le test de\
									conversion \%u!");
	printf("%s\n", buffer);
	close(fd);
	test = 1;
	printf("%s\n", "Le fichier de diff se trouve dans le repertoire\
					\"diff_output\".");
}
////////////////////////////////////////////////////////////////////////////////
// %U
if ((fd = open("test/diff_output/diff_conv_U.txt", O_RDONLY)) < 1)
{
	printf("Erreur : Pas de fichier diff_conv_U.txt");
	return (-1);
}
if ((len = read(fd, buffer, 4096)) == 0)
{
	printf("\033[32m\n%s\033[0m\n", "---> test de conversion \%U ok !");
	close(fd);
	remove("diff_output/diff_conv_d.txt");
}
else
{
	printf("\033[31m\n%s\033[0m\n\n", "---> probleme avec le test de\
									conversion \%U!");
	printf("%s\n", buffer);
	close(fd);
	test = 1;
	printf("%s\n", "Le fichier de diff se trouve dans le repertoire\
					\"diff_output\".");
}
////////////////////////////////////////////////////////////////////////////////
// %x %X
if ((fd = open("test/diff_output/diff_conv_x_X.txt", O_RDONLY)) < 1)
{
	printf("Erreur : Pas de fichier diff_conv_x_X.txt");
	return (-1);
}
if ((len = read(fd, buffer, 4096)) == 0)
{
	printf("\033[32m\n%s\033[0m\n", "---> test de conversion \%x ou \%X ok !");
	close(fd);
	remove("diff_output/diff_conv_d.txt");
}
else
{
	printf("\033[31m\n%s\033[0m\n\n", "---> probleme avec le test de\
									conversion \%x ou \%X!");
	printf("%s\n", buffer);
	close(fd);
	test = 1;
	printf("%s\n", "Le fichier de diff se trouve dans le repertoire\
					\"diff_output\".");
}
////////////////////////////////////////////////////////////////////////////////
// %c
if ((fd = open("test/diff_output/diff_conv_c.txt", O_RDONLY)) < 1)
{
	printf("Erreur : Pas de fichier diff_conv_c.txt");
	return (-1);
}
if ((len = read(fd, buffer, 4096)) == 0)
{
	printf("\033[32m\n%s\033[0m\n", "---> test de conversion \%c ok !");
	close(fd);
	remove("diff_output/diff_conv_d.txt");
}
else
{
	printf("\033[31m\n%s\033[0m\n\n", "---> probleme avec le test de\
									conversion \%c!");
	printf("%s\n", buffer);
	close(fd);
	test = 1;
	printf("%s\n", "Le fichier de diff se trouve dans le repertoire\
					\"diff_output\".");
}
////////////////////////////////////////////////////////////////////////////////
// %C
if ((fd = open("test/diff_output/diff_conv_C.txt", O_RDONLY)) < 1)
{
	printf("Erreur : Pas de fichier diff_conv_C.txt");
	return (-1);
}
if ((len = read(fd, buffer, 4096)) == 0)
{
	printf("\033[32m\n%s\033[0m\n", "---> test de conversion \%C ok !");
	close(fd);
	remove("diff_output/diff_conv_d.txt");
}
else
{
	printf("\033[31m\n%s\033[0m\n\n", "---> probleme avec le test de\
									conversion \%C!");
	printf("%s\n", buffer);
	close(fd);
	test = 1;
	printf("%s\n", "Le fichier de diff se trouve dans le repertoire\
					\"diff_output\".");
}
////////////////////////////////////////////////////////////////////////////////
// %b
if ((fd = open("test/diff_output/diff_conv_b.txt", O_RDONLY)) < 1)
{
	printf("Erreur : Pas de fichier diff_conv_b.txt");
	return (-1);
}
if ((len = read(fd, buffer, 4096)) == 0)
{
	printf("\033[32m\n%s\033[0m\n", "---> test de conversion \%b ok !");
	close(fd);
	remove("diff_output/diff_conv_d.txt");
}
else
{
	printf("\033[31m\n%s\033[0m\n\n", "---> probleme avec le test de\
									conversion \%b!");
	printf("%s\n", buffer);
	close(fd);
	test = 1;
	printf("%s\n", "Le fichier de diff se trouve dans le repertoire\
					\"diff_output\".");
}
////////////////////////////////////////////////////////////////////////////////
	// Fin de test
	if (test == 0)
	{
		printf("\n\033[32m%s\033[0m\n", "---> ft_printf OK ! Well Done ;-)\n");
		remove("diff_output");
	}
	return (0);
}