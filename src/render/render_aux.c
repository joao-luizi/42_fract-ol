/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:38:40 by joaomigu          #+#    #+#             */
/*   Updated: 2024/11/19 18:08:26 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void	draw_rect(t_img *section, t_ipoint pos, t_ipoint dim)
{
	int	*pixels;
	int	i;
	int	j;

	pixels = (int *)section->pixels_ptr;
	i = 0;
	while (i < dim.y)
	{
		j = 0;
		while (j < dim.x)
		{
			if ((j < 3 || j > dim.x - 3) || (i == 0 || i == dim.y - 1))
				pixels[(pos.y + i) * (section->section_width) + (pos.x
						+ j)] = 0xFFFFFFFF;
			j++;
		}
		i++;
	}
}

void	fill_rect(t_img *section, t_ipoint pos, t_ipoint dim, int color)
{
	int	*pixels;
	int	i;
	int	j;

	pixels = (int *)section->pixels_ptr;
	i = 0;
	while (i < dim.y)
	{
		j = 0;
		while (j < dim.x)
		{
			pixels[(pos.y + i) * (section->section_width) + (pos.x
					+ j)] = color;
			j++;
		}
		i++;
	}
}

char	get_col_top(int i)
{
	if (i == 0)
		return ('r');
	else if (i == 1)
		return ('g');
	else if (i == 2)
		return ('b');
	else
		return ('x');
}

void	paint_pixel(t_img *section, int pixel_size, t_ipoint pos, int color)
{
	int	py;
	int	px;
	int	*data;

	data = (int *)section->pixels_ptr;
	py = 0;
	while (py < pixel_size)
	{
		px = 0;
		while (px < pixel_size)
		{
			data[(pos.y + py) * section->section_width + (pos.x + px)] = color;
			px++;
		}
		py++;
	}
}

void	draw_char_to_image(int offset_x, int offset_y, t_img *section,
		int char_map[5][3])
{
	t_ipoint	pos;
	int			pixel_size;
	int			j;
	int			i;

	pixel_size = 3;
	j = 0;
	while (j < 5)
	{
		i = 0;
		while (i < 3)
		{
			pos.x = offset_x + (i * pixel_size);
			pos.y = offset_y + (j * pixel_size);
			if (char_map[j][i] == 1)
				paint_pixel(section, pixel_size, pos, 0xFFFFFFFF);
			else
				paint_pixel(section, pixel_size, pos, 0x00000000);
			i++;
		}
		j++;
	}
}
