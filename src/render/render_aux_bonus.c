/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_aux_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:38:40 by joaomigu          #+#    #+#             */
/*   Updated: 2024/11/20 13:33:24 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

/**
 * @brief Draws a rectangle with a white
 *  border on the given section of the image.
 * 
 * This function draws a rectangle on the
 *  specified section by setting the 
 * pixels on the border to white (0xFFFFFFFF).
 *  The rectangle's position 
 * and dimensions are determined by the given
 *  parameters.
 *
 * @param section Pointer to the image section
 *  where the rectangle will be drawn.
 * @param pos The position (top-left corner) 
 * where the rectangle starts.
 * @param dim The dimensions (width and height)
 *  of the rectangle.
 */
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

/**
 * @brief Fills a rectangle with a
 *  specified color on the given section of the image.
 * 
 * This function fills a rectangle 
 * with the specified color by setting all 
 * pixels inside the rectangle to the
 *  given color. The rectangle's position 
 * and dimensions are determined by the
 *  given parameters.
 *
 * @param section Pointer to the image 
 * section where the rectangle will be filled.
 * @param pos The position (top-left corner)
 *  where the rectangle starts.
 * @param dim The dimensions (width and height)
 *  of the rectangle.
 * @param color The color to fill the 
 * rectangle with.
 */
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

/**
 * @brief Returns the character for the
 *  top color channel based on the given index.
 * 
 * This function returns a character 
 * ('r', 'g', 'b', or 'x') based on the index 
 * provided. The index is used to determine 
 * the color channel (Red, Green, Blue)
 * or an invalid index ('x').
 *
 * @param i The index representing the 
 * color channel (0 for red, 1 for green, 2 for blue).
 * @return A character representing the 
 * top color channel ('r', 'g', 'b', or 'x').
 */
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

/**
 * @brief Paints a square of pixels at the given
 *  position with the specified color.
 * 
 * This function paints a square of pixels
 *  (pixel_size x pixel_size) on the specified
 * image section at the given position. The
 *  color of the square is determined by
 * the `color` parameter.
 *
 * @param section Pointer to the image section
 *  where the pixels will be painted.
 * @param pixel_size The size of each square
 *  pixel.
 * @param pos The position (top-left corner) 
 * where the square will be painted.
 * @param color The color to paint the square 
 * pixels.
 */
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

/**
 * @brief Draws a character on the specified 
 * image section using a 5x3 pixel map.
 * 
 * This function draws a character on the
 *  image section by mapping a 5x3 matrix 
 * of pixels to the section. The pixels are
 *  either black (0x00000000) or white 
 * (0xFFFFFFFF) depending on the character map. The position of the character 
 * is determined by the offset values.
 *
 * @param offset_x The x-offset for the 
 * character's position.
 * @param offset_y The y-offset for the 
 * character's position.
 * @param section Pointer to the image section
 *  where the character will be drawn.
 * @param char_map A 5x3 matrix representing 
 * the pixel map of the character.
 */
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
