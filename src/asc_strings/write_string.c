/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:38:12 by joaomigu          #+#    #+#             */
/*   Updated: 2024/11/19 16:35:31 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	empty_letter(int src[5][3])
{
	src[0][0] = 0;
	src[0][1] = 0;
	src[0][2] = 0;
	src[1][0] = 0;
	src[1][1] = 0;
	src[1][2] = 0;
	src[2][0] = 0;
	src[2][1] = 0;
	src[2][2] = 0;
	src[3][0] = 0;
	src[3][1] = 0;
	src[3][2] = 0;
	src[4][0] = 0;
	src[4][1] = 0;
	src[4][2] = 0;
}

void	lib_x_write_string(char *str, int x, int y, t_img *section)
{
	int	i;
	int	letter[5][3];

	empty_letter(letter);
	i = 0;
	while (str[i])
	{
		get_character_pattern(str[i], letter);
		draw_char_to_image(x + (i * 10), y, section, letter);
		i++;
	}
}
