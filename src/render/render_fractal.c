/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:38:46 by joaomigu          #+#    #+#             */
/*   Updated: 2024/11/19 14:38:47 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

static void	set_pixel_color(t_graphics *g, int x, int y, int color)
{
	int offs;
	
	offs = (y * g->f_section.len) + (x * (g->f_section.bpp / 8));
    *(unsigned int *)(g->f_section.pixels_ptr + offs) = color;
} 


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

void render_graphics(t_state *s)
{
	int		x;
	int		y;
	int		iter;

	y = 0;
	while (y < IMAGE_HEIGHT)
	{
		iter = 0;
		x = 0;
		while (x < IMAGE_WIDTH)
		{
			iter = calculate_fractal(s->f, s->f->mapped_x[x], s->f->mapped_y[y]);
			set_pixel_color(s->g, x, y, s->f->color_range[iter]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win, s->g->f_section.img_ptr, 0, 0);
}
