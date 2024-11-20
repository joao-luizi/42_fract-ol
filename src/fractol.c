/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:39:02 by joaomigu          #+#    #+#             */
/*   Updated: 2024/11/20 12:56:18 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

/**
 * @brief Displays the help message and usage 
 * instructions for the fractal program.
 *
 * This function prints information about available 
 * fractals, usage syntax, 
 * and examples for running the program. It then 
 * terminates the program.
 *
 * @note This function always exits the program with status `1`.
 */
void	show_help_msg(void)
{
	ft_putendl_fd("Available fractals:", 1);
	ft_putendl_fd("\tMandelbrot", 1);
	ft_putendl_fd("\tJulia", 1);
	ft_putendl_fd("\tBurningShip", 1);
	ft_putendl_fd("Usage:", 1);
	ft_putendl_fd("\033[31m./fractol <fractal_type> [a] [b] [color]\033[0m", 1);
	ft_putendl_fd("  - fractal_type: Mandelbrot, Julia or BurningShip", 1);
	ft_putendl_fd("  - a,\
		b: Optional starting values (Julia fractal only!) (default: -0.8, 0.2;\
		-2.0 to 2.0)", 1);
	ft_putendl_fd("  - color: Optional hexadecimal color (e.g., 0x000000)", 1);
	ft_putendl_fd("Examples:", 1);
	ft_putendl_fd("\033[31m./fractol Mandelbrot\033[0m", 1);
	ft_putendl_fd("\033[31m./fractol Julia -0.3 0.8 \"0x5733FF\"\033[0m", 1);
	exit(1);
}

/**
 * @brief Cleans and initializes the state structure.
 *
 * This function resets the state by cleaning its components, 
 * preparing it for fresh initialization.
 *
 * @param s Pointer to the program's state structure to be cleaned.
 */
void	clean_init(t_state *s)
{
	clean_f(s->f);
	clean_g(s->g);
}

/**
 * @brief Entry point for the fractal program.
 *
 * This function validates input arguments, initializes program state, 
 * and enters the main rendering loop.
 *
 * @param argc Argument count.
 * @param argv Argument vector containing the program name and parameters.
 * 
 * @return Always returns `0` (success).
 *
 * @note Exits the program with an error message if invalid arguments are passed
 *       or if graphics initialization fails.
 */
int	main(int argc, char **argv)
{
	t_graphics	g;
	t_fractal	f;
	t_state		s;

	if (argc != 2 && argc != 4 && argc != 6)
		show_help_msg();
	s.f = &f;
	s.g = &g;
	clean_init(&s);
	init_fractal(&f, argc, argv);
	if (f.fractal_type == FRACTAL_INVALID)
		show_help_msg();
	if (!init_graphics(&s))
	{
		ft_putendl_fd("\033[31mUnrecoverable graphics error.\033[0m", 1);
		exit(1);
	}
	init_ui(&s);
	init_events(&s);
	render_graphics(&s);
	mlx_loop(g.mlx_conn);
	return (0);
}
