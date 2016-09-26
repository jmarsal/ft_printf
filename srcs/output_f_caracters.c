/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_f_caracters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 01:07:28 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/27 01:19:40 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	is_caracters_is_neg_and_precision(t_args *v_args, size_t i) //un prob va se poser ici...
{
	if (MINUS && IS_WIDTH)
	{
		if (!v_args->f_conv[i]->is_modifier || v_args->f_conv[i]->modifier->l ||
			v_args->f_conv[i]->modifier->ll)
				while ((int)ft_strlen(RET_STR) < WIDTH)
					RET_STR = ft_strjoin(RET_STR, " ");
		else
		{
			if ((int)ft_strlen(RET_STR) < (WIDTH_CPY && PRECISION_CPY > 0) ||
				WIDTH != PRECISION_O)
			{
				while (WIDTH_CPY-- > 0)
					RET_STR = ft_strjoin(RET_STR, " ");
			}
		}
	}
}

void	is_width_precision_plus_minus(t_args *v_args, size_t i)
{
	if (IS_WIDTH && IS_PRECISION && MINUS && PLUS)
	{
		if (PRECISION_CPY > 0)
			WIDTH_CPY -= PRECISION_CPY;
		RET_STR = ft_strjoin(RET_STR, "+");
		while (PRECISION_CPY-- > 0)
			RET_STR = ft_strjoin(RET_STR, "0");
	}
	else if (IS_WIDTH && IS_PRECISION && SHARP && MINUS)
	{
		if (I_L_CONV == 'x' || I_L_CONV == 'X')
			WIDTH_CPY -= 2;
		else
			WIDTH_CPY -= 1;
		if (PRECISION_CPY > 0)
			WIDTH_CPY -= PRECISION_CPY;
		if (v_args->f_conv[i]->modifier->hh &&
			(I_L_CONV == 'x' || I_L_CONV == 'X'))
			PRECISION_CPY += 6;
		if (I_L_CONV == 'o' || I_L_CONV == 'O')
		{
			if (*RET_STR != '0')
				RET_STR = ft_strjoin(RET_STR, "0");
			if ((v_args->f_conv[i]->modifier->hh ||
				v_args->f_conv[i]->modifier->h) && PRECISION_CPY <= WIDTH_CPY)
				{
					PRECISION_CPY = ((WIDTH_CPY)
											- ft_strlen(ft_itoa_base(I_INT, 8)));
					WIDTH_CPY += 1;
				}
			else
				while (PRECISION_CPY-- > 1)
					RET_STR = ft_strjoin(RET_STR, "0");
		}
		while (PRECISION_CPY-- > 0)
			RET_STR = ft_strjoin(RET_STR, "0");
	}
	else if (IS_WIDTH && IS_PRECISION && MINUS)
	{
		if (WIDTH_CPY > PRECISION_CPY)
			WIDTH_CPY -= PRECISION_CPY;
		if ((I_INT < 0 || I_L_INT < 0) && (I_L_CONV == 'd' || I_L_CONV == 'D'))
		{
			I_INT = -I_INT;
			I_L_INT = -I_L_INT;
			RET_STR = ft_strjoin(RET_STR, "-");
			if ((int)ft_strlen(ft_litoa(I_INT + I_L_INT)) < PRECISION_O)
			{
				RET_STR = ft_strjoin(RET_STR, "0");
				if (WIDTH > PRECISION_O)
					WIDTH_CPY--;
			}
		}
		if ((I_L_CONV == 'u' || I_L_CONV == 'U'))
		{
			if (!v_args->f_conv[i]->is_modifier)
			{
				while ((int)ft_strlen(RET_STR) +
						(int)ft_strlen(ft_itoa(I_U_INT)) <= PRECISION_O)
					RET_STR = ft_strjoin(RET_STR, "0");
			}
			if (v_args->f_conv[i]->modifier->l ||
				v_args->f_conv[i]->modifier->ll)
			{
				while (WIDTH_CPY-- > 0)
				{
					RET_STR = ft_strjoin(RET_STR, "0");
					PRECISION_CPY--;
				}
			}
			if ((v_args->f_conv[i]->modifier->hh ||
				v_args->f_conv[i]->modifier->h) && WIDTH >= PRECISION_O)
			{
				while (PRECISION_CPY-- > 0)
					RET_STR = ft_strjoin(RET_STR, "0");
			}
		}
		if (v_args->f_conv[i]->modifier->hh || v_args->f_conv[i]->modifier->h)
		{
			if (PRECISION_CPY >= WIDTH_CPY)
			{
				if ((I_L_CONV == 'x' || I_L_CONV == 'X') &&
					(v_args->f_conv[i]->modifier->hh))
					PRECISION_CPY += 6;
				while (PRECISION_CPY-- > 0)
				{
					RET_STR = ft_strjoin(RET_STR, "0");
					WIDTH_CPY--;
				}
			}
			else
			{
				if ((I_L_CONV == 'x' || I_L_CONV == 'X') &&
					(v_args->f_conv[i]->modifier->hh))
					PRECISION_CPY += 6;
				while (PRECISION_CPY-- > 0)
					RET_STR = ft_strjoin(RET_STR, "0");
			}
		}
		else if (!(I_L_CONV == 'u' || I_L_CONV == 'U'))
			while (PRECISION_CPY-- > 0)
				RET_STR = ft_strjoin(RET_STR, "0");
		if (PRECISION_O > WIDTH && !(I_L_CONV == 'u' || I_L_CONV == 'U'))
			while (PRECISION_CPY-- > 0)
				RET_STR = ft_strjoin(RET_STR, "0");
	}
}

static void is_width_precision(t_args *v_args, size_t i)
{
	size_t	j;
	int		test_o;

	j = 0;
	test_o = 0;
	if (SHARP && (I_L_CONV == 'o' || I_L_CONV == 'O') &&
		ft_strlen(ft_itoa_base(I_INT, 8)) &&
		(!(v_args->f_conv[i]->modifier->hh || v_args->f_conv[i]->modifier->h)))
		WIDTH_CPY--;
	if (I_L_CONV == 'o' || I_L_CONV == 'O' || I_L_CONV == 'd' || I_L_CONV == 'D')
	{
		if (PRECISION_CPY > 0)
			WIDTH_CPY -= PRECISION_CPY;
		while (WIDTH_CPY-- > 0)
			RET_STR = ft_strjoin(RET_STR, " ");
	}
	if (IS_PRECISION && PLUS)
		RET_STR = ft_strjoin(RET_STR, "+");
	if (SHARP && PRECISION_O >= WIDTH)
		PRECISION_CPY--;
	if (I_L_CONV == 'x' || I_L_CONV == 'X')
	{
		if (PRECISION_O >= WIDTH)
		{
			if (I_L_CONV == 'x')
				RET_STR = ft_strjoin(RET_STR, "0x");
			else if (I_L_CONV == 'X')
				RET_STR = ft_strjoin(RET_STR, "0X");
			PRECISION_O += 2;
			if (v_args->f_conv[i]->modifier->hh)
			 	PRECISION_O += 6;
			while (((int)ft_strlen(RET_STR) +
					(int)ft_strlen(ft_itoa_base(I_INT, 16)) +
					(int)ft_strlen(ft_litoa_base(I_U_L_INT, 16))) <= PRECISION_O)
				RET_STR = ft_strjoin(RET_STR, "0");
		}
		if (WIDTH > PRECISION_O)
		{
			if ((int)ft_strlen(ft_itoa_base(I_INT, 16)) +
				(int)ft_strlen(ft_litoa_base(I_U_L_INT, 16)) < WIDTH)
			{
				while ((int)ft_strlen(RET_STR) + ((PRECISION_O + 3) -
						((int)ft_strlen(ft_itoa_base(I_INT, 16)) +
						(int)ft_strlen(ft_litoa_base(I_U_L_INT, 16))))
						< WIDTH_CPY)
					RET_STR = ft_strjoin(RET_STR, " ");
			}
			if (I_L_CONV == 'x')
				RET_STR = ft_strjoin(RET_STR, "0x");
			else if (I_L_CONV == 'X')
				RET_STR = ft_strjoin(RET_STR, "0X");
			if (v_args->f_conv[i]->modifier->hh)
				WIDTH_CPY += 6;
			while ((int)ft_strlen(RET_STR) < WIDTH_CPY)
			{
				RET_STR = ft_strjoin(RET_STR, "0");
			}
		}
	}
	else
		while (PRECISION_CPY-- > 0)
			RET_STR = ft_strjoin(RET_STR, "0");
	if (SHARP && (I_L_CONV == 'o' || I_L_CONV == 'O'))
	{
		while (RET_STR[j])
		{
			if (RET_STR[j] == '0')
				test_o = 1;
			j++;
		}
		if (test_o == 0)
			RET_STR = ft_strjoin(RET_STR, "0");
	}
	if (PLUS == 1 && MINUS == 0 && !IS_PRECISION)
		RET_STR = ft_strjoin(RET_STR, "+");
}

void	is_width_precision_and_not_minus(t_args *v_args, size_t i)
{
	if (IS_WIDTH && !MINUS)
	{
		if (ZERO && !IS_PRECISION)
		{
			if (PLUS)
				RET_STR = ft_strjoin(RET_STR, "+");
			if ((I_INT < 0 || I_L_INT < 0) &&
				(I_L_CONV != 'x' && I_L_CONV != 'X'))
				{
					I_INT = -I_INT;
					I_L_INT = -I_L_INT;
					RET_STR = ft_strjoin(RET_STR, "-");
				}
			while (WIDTH_CPY > 0)
			{
				RET_STR = ft_strjoin(RET_STR, "0");
				WIDTH_CPY--;
			}
		}
		else
			is_width_precision(v_args, i);
	}
}

void	is_caracters_is_sharp(t_args *v_args, size_t i)
{
	if (SHARP == 1)
	{
		if ((I_L_CONV == 'o' || I_L_CONV == 'O') && WIDTH <= PRECISION_O)
			RET_STR = ft_strjoin(RET_STR, "0");
		if (MINUS && (I_L_CONV == 'x' || I_L_CONV == 'X'))
		{
			if (I_L_CONV == 'x')
				RET_STR = ft_strjoin(RET_STR, "0x");
			else if (I_L_CONV == 'X')
				RET_STR = ft_strjoin(RET_STR, "0X");
		}
		if (!WIDTH && !PRECISION_O && (I_L_CONV == 'x' || I_L_CONV == 'X'))
		{
			if (I_L_CONV == 'x')
				RET_STR = ft_strjoin(RET_STR, "0x");
			else if (I_L_CONV == 'X')
				RET_STR = ft_strjoin(RET_STR, "0X");
		}
	}
}
