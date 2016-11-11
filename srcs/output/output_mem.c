/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_mem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 16:10:44 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/11 16:56:32 by jmarsal          ###   ########.fr       */
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
		number = ft_strjoin(number, "0");
	return (ft_strrev(number));
}

static char	*ft_get_ptr(int *ptr, char *size)
{
	char			*ret;
	unsigned char	p[sizeof(ptr)];
	int				i;

	ret = ft_strnew(0);
	i = sizeof(ptr);
	if (!ft_strcmp(size, "long"))
		i = sizeof(ptr) - 2;
	else if (!ft_strcmp(size, "short"))
		i = sizeof(ptr) - 7;
	ft_memcpy(p, &ptr, sizeof(ptr));
	ret = ft_strjoin(ret, "0x");
	while (i-- > 0)
		ret = ft_strjoin(ret, itoa_ptr(p[i]));
	return (ret);
}

void	print_ptr(t_result *result, size_t i)
{
	char	*mem_tmp;

	mem_tmp = NULL;
	if (I_L_CONV == 'p')
	{
		if (MOD_H || MOD_HH || MOD_L)
			mem_tmp = ft_get_ptr(I_PTR, "short");
		if (MOD_LL || MOD_J || MOD_Z || !I_IS_MODIFIER)
			mem_tmp = ft_get_ptr(I_PTR, "long");
		ft_buffer_add(RET_STR, RET_STR->len, mem_tmp, ft_strlen(mem_tmp));
	}
}
