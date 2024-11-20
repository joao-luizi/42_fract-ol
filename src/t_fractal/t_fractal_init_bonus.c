/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fractal_init_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:38:54 by joaomigu          #+#    #+#             */
/*   Updated: 2024/11/20 13:12:27 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

/**
 * @brief Fills standard values for the fractal's
 *  real and imaginary axes.
 *
 * Initializes the range of real and imaginary coordinates (`dreal` and `dimag`)
 * based on the type of fractal. For Julia sets, the range spans [-2.0, 2.0] for
 * the real axis and is adjusted for aspect ratio. For other fractals, the range 
 * is set to fit the Mandelbrot set with proper aspect ratio adjustment.
 *
 * @param f Pointer to the fractal structure to initialize.
 */
static void	fill_standard_values(t_fractal *f)
{
	if (f->fractal_type == FRACTAL_JULIA)
	{
		f->dreal.y = -2.0;
		f->dreal.x = 2.0;
		f->dimag.y = -2.0;
		f->dimag.x = f->dimag.y + (f->dreal.x - f->dreal.y) * IMAGE_HEIGHT
			/ IMAGE_WIDTH;
	}
	else
	{
		f->dreal.y = -2.0;
		f->dreal.x = 1.0;
		f->dimag.y = -1.5;
		f->dimag.x = f->dimag.y + (f->dreal.x - f->dreal.y) * IMAGE_HEIGHT
			/ IMAGE_WIDTH;
	}
}

/**
 * @brief Extracts additional parameters 
 * for the Julia fractal.
 *
 * Parses user input to initialize the `julia_c`
 *  complex constant for Julia sets.
 * If no valid input is provided, default values are used.
 *  Validates that the 
 * provided coordinates are within the range [-2.0, 2.0]. 
 *
 * @param f Pointer to the fractal structure to initialize.
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line argument strings.
 *
 * @return Returns `TRUE` if parameters are valid or not required,
 *  `FALSE` on error.
 */
static int	extract_fractal_extras(t_fractal *f, int argc, char **argv)
{
	if (f->fractal_type == FRACTAL_JULIA)
	{
		f->julia_c.x = -0.8;
		f->julia_c.y = 0.2;
		if (argc == 4 || argc == 6)
		{
			if (!check_double_format(argv[2]) && !check_double_format(argv[3]))
			{
				f->julia_c.x = custom_atof(argv[2]);
				f->julia_c.y = custom_atof(argv[3]);
				if (f->julia_c.x < -2.0 || f->julia_c.x > 2.0)
					return (FALSE);
				if (f->julia_c.y < -2.0 || f->julia_c.y > 2.0)
					return (FALSE);
			}
			else if (check_color_format(argv[2]) && check_color_format(argv[3])
				&& argc == 4)
				return (TRUE);
			else
				return (FALSE);
		}
	}
	return (TRUE);
}

/**
 * @brief Extracts user-defined colors for the Julia fractal.
 *
 * Parses user input for colors (in hexadecimal format)
 *  for Julia sets. Depending
 * on the number of arguments, the colors may be at different
 *  positions in the input.
 *
 * @param f Pointer to the fractal structure to initialize.
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line argument strings.
 *
 * @return Returns `TRUE` if color inputs are valid or not required,
 *  `FALSE` on error.
 */
static int	extract_user_colors_julia(t_fractal *f, int argc, char **argv)
{
	if (argc == 4)
	{
		if (!check_double_format(argv[2]) && !check_double_format(argv[3]))
			return (TRUE);
		else if (check_color_format(argv[2]) && check_color_format(argv[3])
			&& argc == 4)
		{
			f->color_a = hex_string_to_int(argv[2]);
			f->color_b = hex_string_to_int(argv[3]);
		}
		else
			return (FALSE);
	}
	else if (argc == 6)
	{
		if (check_color_format(argv[4]) && check_color_format(argv[5]))
		{
			f->color_a = hex_string_to_int(argv[4]);
			f->color_b = hex_string_to_int(argv[5]);
		}
		else
			return (FALSE);
	}
	return (TRUE);
}

/**
 * @brief Extracts user-defined colors for fractals.
 *
 * Parses user input for two colors (in hexadecimal format)
 *  used to render the fractal.
 * Sets default colors if no input is provided. Handles 
 * Julia-specific color extraction 
 * through a separate helper function.
 *
 * @param f Pointer to the fractal structure to initialize.
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line argument strings.
 *
 * @return Returns `TRUE` if color inputs are valid, `FALSE` on error.
 */
static int	extract_user_colors(t_fractal *f, int argc, char **argv)
{
	f->color_a = COLOR_CYAN;
	f->color_b = COLOR_DARK_RED;
	if (f->fractal_type == FRACTAL_JULIA)
		return (extract_user_colors_julia(f, argc, argv));
	else
	{
		if (argc == 4)
		{
			if (check_color_format(argv[2]) && check_color_format(argv[3]))
			{
				f->color_a = hex_string_to_int(argv[2]);
				f->color_b = hex_string_to_int(argv[3]);
			}
			else
				return (FALSE);
		}
		else if (argc == 6)
			return (FALSE);
	}
	return (TRUE);
}

/**
 * @brief Initializes a fractal structure based
 *  on user input.
 *
 * Sets the fractal type, fills default ranges
 *  for real and imaginary coordinates,
 * extracts additional Julia-specific parameters,
 *  and validates user-provided colors.
 * Generates mapped coordinates and sets the gradient 
 * colors for rendering.
 *
 * @param f Pointer to the fractal structure to initialize.
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line argument strings.
 */
void	init_fractal(t_fractal *f, int argc, char **argv)
{
	f->fractal_type = get_fractal_type(argv[1]);
	if (f->fractal_type == FRACTAL_INVALID)
		return ;
	fill_standard_values(f);
	if (!extract_fractal_extras(f, argc, argv))
	{
		ft_putendl_fd("\033[31mJulia input error.\033[0m", 1);
		show_help_msg();
	}
	if (!extract_user_colors(f, argc, argv))
	{
		ft_putendl_fd("\033[31mColor input error.\033[0m", 1);
		show_help_msg();
	}
	update_mapped_coordinates(f);
	set_gradient_colors(f);
	f->color_a_edit = f->color_a;
	f->color_b_edit = f->color_b;
}
