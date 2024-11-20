/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_gui_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:38:48 by joaomigu          #+#    #+#             */
/*   Updated: 2024/11/20 13:21:52 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

/**
 * @brief Draws static text strings on
 *  the provided image section.
 *
 * This function writes several static 
 * strings (e.g., "fractal", "Iterations", "mouse x") 
 * on the image section at predefined coordinates.
 *  These strings are part of the static UI 
 * that displays information about the fractal and
 *  user interactions.
 *
 * @param section The image section on which the 
 * strings will be drawn.
 * @param f_name The name of the fractal to be 
 * displayed.
 */
static void	draw_static_string(t_img *section, char *f_name)
{
	lib_x_write_string("fractal", 810, 20, section);
	lib_x_write_string(f_name, 810, 40, section);
	lib_x_write_string("Iterations", 810, 60, section);
	lib_x_write_string("mouse x", 10, 810, section);
	lib_x_write_string("mouse y", 10, 830, section);
	lib_x_write_string("real", 150, 810, section);
	lib_x_write_string("imag", 150, 830, section);
}

/**
 * @brief Draws the color adjustment area
 *  on the provided image section.
 *
 * This function creates a color adjustment
 *  area for user input, drawing several visual elements
 * such as the '+' and '-' buttons and color 
 * sliders. The color sliders allow the user to adjust
 * the color channels, and the buttons allow 
 * for incrementing or decrementing values.
 *
 * @param pos The starting position for drawing
 *  the color area.
 * @param dim The dimensions for the color sliders.
 * @param y The vertical offset to position the color
 *  area on the screen.
 * @param section The image section on which to draw
 *  the color adjustment area.
 */
static void	draw_color_area(t_ipoint pos, t_ipoint dim, int y, t_img *section)
{
	int	i;
	int	letter[5][3];

	i = 0;
	while (i < 3)
	{
		empty_letter(letter);
		pos.x = 830 + i * 50;
		get_character_pattern(get_col_top(i), letter);
		draw_char_to_image(pos.x + 5, 160 + y, section, letter);
		get_character_pattern('+', letter);
		draw_char_to_image(pos.x + 5, 190 + y, section, letter);
		get_character_pattern('-', letter);
		draw_char_to_image(pos.x + 5, 350 + y, section, letter);
		pos.y = 215 + y;
		dim.x = 20;
		dim.y = 128;
		draw_rect(section, pos, dim);
		i++;
	}
	pos.x = 840;
	pos.y = 380 + y;
	dim.x = 100;
	dim.y = 20;
	draw_rect(section, pos, dim);
}

/**
 * @brief Draws all the static UI elements
 *  on the provided image section.
 *
 * This function calls the `draw_color_area`
 *  function to render color adjustment sections and other 
 * static UI components, such as buttons and 
 * sliders, at specific locations on the screen.
 *
 * @param section The image section on which the
 *  static UI elements will be drawn.
 */
static void	draw_static_elements(t_img *section)
{
	t_ipoint	pos;
	t_ipoint	dim;

	pos.x = 0;
	pos.y = 0;
	dim.x = 0;
	dim.y = 0;
	draw_color_area(pos, dim, 0, section);
	draw_color_area(pos, dim, 280, section);
}

/**
 * @brief Initializes the user interface
 *  by drawing all UI elements.
 *
 * This function initializes the user interface
 *  by drawing all static and dynamic UI elements, 
 * including the fractal name, iteration count,
 *  mouse coordinates, color sliders, and the calculated
 * fractal iterations. It also handles the calculation 
 * of axis values, mouse hover information, 
 * and color rects.
 *
 * @param s The state structure containing the current state 
 * of the program, including the fractal
 *          type and GUI configuration.
 */
void	init_ui(t_state *s)
{
	draw_static_elements(&s->g->static_gui);
	draw_static_string(&s->g->static_gui,
		get_fractal_string(s->f->fractal_type));
	mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win,
		s->g->static_gui.img_ptr, 0, 0);
	calc_axis(s);
	draw_mouse_hover_dimensions(s);
	draw_color_rect_a(s);
	draw_color_rect_b(s);
	calc_iter(s);
	draw_iter(s);
}
