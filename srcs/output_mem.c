/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_mem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 16:10:44 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/19 02:00:05 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*malloc_str()
{
	char	*str;
	int		i;

	i = 0;
	if ((str = malloc(65)) == NULL)
		return (NULL);
	while (i < 65)
		str[i++] = 0;
	return (str);
}

static char	*itoa_ptr(unsigned char value)
{
	int		i;
	long	val;
	char	*number;
	char	*charset;

	charset = "0123456789abcdef";
	i = 0;
	val = value;
	if ((number = malloc_str()) == NULL)
		return (NULL);
	if (value == 0)
		number[i] = '0';
	while (val)
	{
		number[i++] = charset[val % 16];
		val /= 16;
	}
	if (value < 16)
		number = ft_strcat(number, "0");
	return (ft_strrev(number));
}

char	*ft_get_ptr(int *ptr)
{
	char			*ret;
	unsigned char	p[sizeof(ptr)];
	int				i;

	ret = ft_strnew(0);
	i = sizeof(ptr);
	i -= 2;
	ft_memcpy(p, &ptr, sizeof(ptr));
	ret = ft_strcat(ret, "0x");
	while (i-- > 0)
		ret = ft_strjoin(ret, itoa_ptr(p[i]));
	return (ret);
}

void	print_ptr(t_args *v_args, size_t i)
{
	if (I_L_CONV == 'p')
	{
		RET_STR = ft_get_ptr(I_PTR);
	}
}
