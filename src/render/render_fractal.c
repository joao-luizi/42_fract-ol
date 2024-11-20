/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:38:46 by joaomigu          #+#    #+#             */
/*   Updated: 2024/11/20 13:24:57 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

/**
 * @brief Sets the color of a specific pixel 
 * in the graphics section.
 *
 * This function calculates the offset for the 
 * pixel at the given (x, y) coordinates 
 * and sets its color by writing the provided color 
 * value into the pixel data buffer.
 *
 * @param g The graphics structure containing the image
 *  section where the pixel is located.
 * @param x The x-coordinate of the pixel to be modified.
 * @param y The y-coordinate of the pixel to be modified.
 * @param color The color value to set for the specified pixel.
 */
static void	set_pixel_color(t_graphics *g, int x, int y, int color)
{
	int	offs;

	offs = (y * g->f_section.len) + (x * (g->f_section.bpp / 8));
	*(unsigned int *)(g->f_section.pixels_ptr + offs) = color;
}

/**
 * @brief Calculates the iteration count for
 *  a given point in the fractal.
 *
 * This function determines the number of 
 * iterations required to calculate the 
 * fractal value for a given complex coordinate
 *  (pr, pi) based on the selected fractal type. 
 * It calls the appropriate fractal calculation 
 * function depending on the fractal type 
 * (Mandelbrot, Julia, or Burning Ship).
 *
 * @param f The fractal structure containing the 
 * current fractal type and iteration settings.
 * @param pr The real part of the complex coordinate.
 * @param pi The imaginary part of the complex coordinate.
 * 
 * @return The number of iterations before reaching 
 * the fractal's escape condition.
 */
static int	calculate_fractal(t_fractal *f, double pr, double pi)
{
	int	iter;

	if (f->fractal_type == FRACTAL_MANDELBROT)
		iter = calc_mandelbrot(pr, pi, f->iterations);
	else if (f->fractal_type == FRACTAL_JULIA)
		iter = calc_julia(f, pr, pi);
	else
		iter = calc_burning_ship(pr, pi, f->iterations);
	return (iter);
}

/**
 * @brief Renders the fractal graphics to 
 * the screen.
 *
 * This function iterates over all the pixels 
 * of the image and calculates the fractal 
 * value for each pixel by calling the 
 * `calculate_fractal` function. Once the iteration 
 * count is determined, the corresponding 
 * pixel color is set using `set_pixel_color`. 
 * After processing all the pixels, the 
 * final image is rendered to the window.
 *
 * @param s The state structure containing the 
 * fractal and graphics information, including the 
 *          current fractal, mapped coordinates, 
 * and color range.
 */
void	render_graphics(t_state *s)
{
	int	x;
	int	y;
	int	iter;

	y = 0;
	while (y < IMAGE_HEIGHT)
	{
		iter = 0;
		x = 0;
		while (x < IMAGE_WIDTH)
		{
			iter = calculate_fractal(s->f, s->f->mapped_x[x],
					s->f->mapped_y[y]);
			set_pixel_color(s->g, x, y, s->f->color_range[iter]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win,
		s->g->f_section.img_ptr, 0, 0);
}

/**
 * @brief Draws the iteration count text
 *  to the window.
 *
 * This function writes the current iteration
 *  count (stored in the fractal iteration string) 
 * to an image section and then displays it in
 *  the window at a specified position.
 *
 * @param s The state structure containing the
 *  current fractal and graphics information.
 */
void	draw_iter(t_state *s)
{
	lib_x_write_string(s->f->fractal_iter, 0, 0, &s->g->iter_img);
	mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win,
		s->g->iter_img.img_ptr, 920, 60);
}
