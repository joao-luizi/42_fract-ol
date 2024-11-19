/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fractal_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:38:51 by joaomigu          #+#    #+#             */
/*   Updated: 2024/11/19 14:55:19 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void clean_f(t_fractal *f)
{
	f->fractal_type = FRACTAL_INVALID;
	f->julia_c.x = 0.0;
	f->julia_c.y = 0.0;
	f->dreal.x = 0.0;
	f->dreal.y = 0.0;
	f->dimag.x = 0.0;
	f->dimag.y = 0.0;
	f->shift.x = 0.0;
	f->shift.y = 0.0;
	f->iterations = MAX_ITERATIONS;
	f->zoomx = 1.0;
	ft_memset(f->mapped_x, 0, sizeof(f->mapped_x));
	ft_memset(f->mapped_y, 0, sizeof(f->mapped_y));
	ft_memset(f->mouse_x, 0, sizeof(f->mouse_x));
	ft_memset(f->mouse_y, 0, sizeof(f->mouse_y));
	ft_memset(f->fractal_x, 0, sizeof(f->fractal_x));
	ft_memset(f->fractal_y, 0, sizeof(f->fractal_y));
	ft_memset(f->fractal_d_x_max, 0, sizeof(f->fractal_d_x_max));
	ft_memset(f->fractal_d_x_min, 0, sizeof(f->fractal_d_x_min));
	ft_memset(f->fractal_d_y_max, 0, sizeof(f->fractal_d_y_max));
	ft_memset(f->fractal_d_y_min, 0, sizeof(f->fractal_d_y_min));
	ft_memset(f->fractal_iter, 0, sizeof(f->fractal_iter));
}

void set_gradient_colors(t_fractal *f)
{
    int i;
    double fraction;
	int start[3] = {((f->color_a >> 16) & 0xFF),((f->color_a >> 8) & 0xFF),(f->color_a & 0xFF)};
	int end[3] = {((f->color_b >> 16) & 0xFF),((f->color_b >> 8) & 0xFF),(f->color_b & 0xFF)};
	int r;
    int g;
    int b;
	i = 0;
	while (i < f->iterations)
	{
		f->color_range[i] = 0;
        fraction = (double)i / (f->iterations - 1);
         r = start[0] + fraction * (end[0] - start[0]);
         g = start[1] + fraction * (end[1]  - start[1]);
         b = start[2] + fraction * (end[2]  - start[2]);
        f->color_range[i] = (r << 16) | (g << 8) | b;
		i++;
	}
}

void update_mapped_coordinates(t_fractal *f)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (y < IMAGE_HEIGHT)
	{
		f->mapped_y[y] = (f->dimag.y + (double)y * ((f->dimag.x - f->dimag.y) / IMAGE_HEIGHT));
		y++;
	}
	while (x < IMAGE_WIDTH)
	{
		f->mapped_x[x] = (f->dreal.y + (double)x * ((f->dreal.x - f->dreal.y) / IMAGE_WIDTH));
		x++;
	}
}

t_fractal_type get_fractal_type(char *input) 
{
    if (ft_strncmp(input, "Mandelbrot",10) == 0)
        return FRACTAL_MANDELBROT;
    else if (ft_strncmp(input, "Julia", 5) == 0)
        return FRACTAL_JULIA;
    else if (ft_strncmp(input, "BurningShip",11) == 0)
        return FRACTAL_BURNING_SHIP;
    else
        return FRACTAL_INVALID;
}


char *get_fractal_string(t_fractal_type fractal_type) 
{
	if (fractal_type == FRACTAL_MANDELBROT)
        return "Mandelbrot";
	else if (fractal_type == FRACTAL_JULIA)
        return "Julia";
	else if (fractal_type == FRACTAL_BURNING_SHIP)
        return "Burning Ship";
	else
        return "Invalid";
}

