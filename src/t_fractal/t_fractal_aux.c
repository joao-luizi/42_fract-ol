/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fractal_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:38:51 by joaomigu          #+#    #+#             */
/*   Updated: 2024/11/20 13:18:46 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

/**
 * @brief Resets the given fractal structure 
 * to its default values.
 *
 * This function initializes the `t_fractal` 
 * structure by resetting all its fields
 * to their default values. It ensures that any 
 * leftover state is cleared so that
 * the fractal can be used in subsequent computations
 *  without residual values.
 *
 * @param f The `t_fractal` structure to be reset.
 */
void	clean_f(t_fractal *f)
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

/**
 * @brief Sets the gradient color range 
 * based on two user-defined colors.
 *
 * This function computes a color gradient
 *  between two colors (`color_a` and `color_b`)
 * and stores the resulting color values in
 *  the `color_range` array. The gradient is
 * interpolated based on the number of iterations
 *  and is used to color the fractal.
 *
 * @param f The `t_fractal` structure containing
 *  the color values and iterations.
 */
void	set_gradient_colors(t_fractal *f)
{
	int		i;
	int		r;
	int		g;
	int		b;
	int		s[6];

	s[0] = ((f->color_a >> 16) & 0xFF);
	s[1] = ((f->color_a >> 8) & 0xFF);
	s[2] = (f->color_a & 0xFF);
	s[3] = ((f->color_b >> 16) & 0xFF);
	s[4] = ((f->color_b >> 8) & 0xFF);
	s[5] = (f->color_b & 0xFF);
	i = 0;
	while (i < f->iterations)
	{
		f->color_range[i] = 0;
		r = s[0] + ((double)i / (f->iterations - 1)) * (s[3] - s[0]);
		g = s[1] + ((double)i / (f->iterations - 1)) * (s[4] - s[1]);
		b = s[2] + ((double)i / (f->iterations - 1)) * (s[5] - s[2]);
		f->color_range[i] = (r << 16) | (g << 8) | b;
		i++;
	}
}

/**
 * @brief Updates the mapped coordinates 
 * for both real and imaginary axes.
 *
 * This function updates the `mapped_x` and
 *  `mapped_y` arrays with the calculated
 * coordinates for the fractal image. The 
 * mapping is based on the current bounds
 * (`dreal` and `dimag`) and scales the screen
 *  coordinates to fractal coordinates.
 *
 * @param f The `t_fractal` structure containing
 *  the fractal bounds.
 */
void	update_mapped_coordinates(t_fractal *f)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < IMAGE_HEIGHT)
	{
		f->mapped_y[y] = (f->dimag.y + (double)y * ((f->dimag.x - f->dimag.y)
					/ IMAGE_HEIGHT));
		y++;
	}
	while (x < IMAGE_WIDTH)
	{
		f->mapped_x[x] = (f->dreal.y + (double)x * ((f->dreal.x - f->dreal.y)
					/ IMAGE_WIDTH));
		x++;
	}
}

/**
 * @brief Retrieves the fractal type corresponding
 *  to the user input.
 *
 * This function maps the user input (a string) to
 *  a specific fractal type. It checks
 * if the input matches known fractal names (e.g.,
 *  "Mandelbrot", "Julia", "BurningShip")
 * and returns the corresponding fractal type. If no
 *  match is found, it returns `FRACTAL_INVALID`.
 *
 * @param input The string input provided by the user.
 * @return The corresponding `t_fractal_type` 
 * enumeration value.
 */
t_fractal_type	get_fractal_type(char *input)
{
	if (ft_strncmp(input, "Mandelbrot", 10) == 0)
		return (FRACTAL_MANDELBROT);
	else if (ft_strncmp(input, "Julia", 5) == 0)
		return (FRACTAL_JULIA);
	else if (ft_strncmp(input, "BurningShip", 11) == 0)
		return (FRACTAL_BURNING_SHIP);
	else
		return (FRACTAL_INVALID);
}

/**
 * @brief Converts a fractal type to its 
 * corresponding string representation.
 *
 * This function converts a given `t_fractal_type`
 *  enumeration value back into its
 * string representation (e.g., "Mandelbrot", "Julia",
 *  "Burning Ship"). This is used
 * for user-facing output or logging purposes.
 *
 * @param fractal_type The `t_fractal_type` to be
 *  converted.
 * @return A string representation of the fractal type.
 */
char	*get_fractal_string(t_fractal_type fractal_type)
{
	if (fractal_type == FRACTAL_MANDELBROT)
		return ("Mandelbrot");
	else if (fractal_type == FRACTAL_JULIA)
		return ("Julia");
	else if (fractal_type == FRACTAL_BURNING_SHIP)
		return ("Burning Ship");
	else
		return ("Invalid");
}
