/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_dynamic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:38:43 by joaomigu          #+#    #+#             */
/*   Updated: 2024/11/20 13:29:59 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

/**
 * @brief Draws the mouse hover elements
 *  for the fractal display.
 *
 * This function displays the mouse cursor 
 * position (x and y coordinates) as well as 
 * the corresponding fractal coordinates 
 * (real and imaginary) in specific image sections. 
 * These values are updated in real-time and displayed
 *  in the window at predefined positions.
 *
 * @param s The state structure containing fractal 
 * data and graphics information.
 */
void	draw_mouse_hover_elements(t_state *s)
{
	lib_x_write_string(s->f->mouse_x, 0, 0, &s->g->mousehvr_section_w);
	lib_x_write_string(s->f->mouse_y, 0, 20, &s->g->mousehvr_section_w);
	mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win,
		s->g->mousehvr_section_w.img_ptr, 85, 810);
	lib_x_write_string(s->f->fractal_x, 0, 0, &s->g->mousehvr_section_f);
	lib_x_write_string(s->f->fractal_y, 0, 20, &s->g->mousehvr_section_f);
	mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win,
		s->g->mousehvr_section_f.img_ptr, 200, 810);
}

/**
 * @brief Draws the mouse hover dimensions
 *  (x and y axis min/max values).
 *
 * This function displays the minimum and 
 * maximum values of both the x and y axes 
 * of the fractal at the current mouse hover
 *  position. These values are rendered in a 
 * specific image section and displayed in 
 * the window.
 *
 * @param s The state structure containing 
 * the fractal data and graphics information.
 */
void	draw_mouse_hover_dimensions(t_state *s)
{
	lib_x_write_string(s->f->fractal_d_x_min, 0, 0, &s->g->mousehvr_section_d);
	lib_x_write_string(s->f->fractal_d_y_min, 0, 20, &s->g->mousehvr_section_d);
	lib_x_write_string(s->f->fractal_d_x_max, 90, 0, &s->g->mousehvr_section_d);
	lib_x_write_string(s->f->fractal_d_y_max, 90, 20,
		&s->g->mousehvr_section_d);
	mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win,
		s->g->mousehvr_section_d.img_ptr, 350, 810);
}

/**
 * @brief Draws the color bar for a 
 * specific color channel.
 *
 * This function renders the color bar 
 * representing the intensity of a specific color channel 
 * (red, green, or blue) as a vertical bar.
 *  The height of the bar is determined by the intensity 
 * of the channel (0-256), and the bar is 
 * filled with the appropriate color.
 *
 * @param channel The value representing the 
 * intensity of the color channel (0-255).
 * @param uc The image structure where the color
 *  bar is drawn.
 * @param color_fill The color used to fill the 
 * bar (based on the channel).
 */
static void	draw_color(int channel, t_img *uc, int color_fill)
{
	t_ipoint	pos;
	t_ipoint	dim;
	int			percent_channel;

	percent_channel = channel * 100 / 256;
	pos.x = 0;
	pos.y = 0;
	dim.x = 15;
	dim.y = 125;
	fill_rect(uc, pos, dim, 0x00000000);
	pos.x = 0;
	pos.y = 125 - (125 * percent_channel / 100);
	dim.x = 15;
	dim.y = 125 * percent_channel / 100;
	fill_rect(uc, pos, dim, color_fill);
}

/**
 * @brief Draws the color selection 
 * rectangle for color A.
 *
 * This function renders the color selection
 *  interface for color A, displaying the RGB channels 
 * separately and allowing the user to edit
 *  each channel. The color rectangle is drawn 
 * and the corresponding values are updated 
 * in the window.
 *
 * @param s The state structure containing the
  fractal data and graphics information, 
 *          including the color A data.
 */
void	draw_color_rect_a(t_state *s)
{
	t_ipoint	pos;
	t_ipoint	dim;

	draw_color(((s->f->color_a_edit >> 16) & 0xFF), &s->g->uca_r, 0x00FF0000);
	draw_color(((s->f->color_a_edit >> 8) & 0xFF), &s->g->uca_g, 0x0000FF00);
	draw_color((s->f->color_a_edit & 0xFF), &s->g->uca_b, 0x000000FF);
	pos.x = 0;
	pos.y = 0;
	dim.x = 95;
	dim.y = 15;
	fill_rect(&s->g->uca_c, pos, dim, s->f->color_a_edit);
	mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win, s->g->uca_r.img_ptr,
		833, 216);
	mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win, s->g->uca_g.img_ptr,
		883, 216);
	mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win, s->g->uca_b.img_ptr,
		933, 216);
	mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win, s->g->uca_c.img_ptr,
		843, 382);
}

/**
 * @brief Draws the color selection 
 * rectangle for color B.
 *
 * This function renders the color 
 * selection interface for color B, similar to 
 * `draw_color_rect_a`, displaying and 
 * allowing the user to edit each color channel. 
 * The color rectangle is drawn and updated 
 * in the window.
 *
 * @param s The state structure containing 
 * the fractal data and graphics information, 
 *          including the color B data.
 */
void	draw_color_rect_b(t_state *s)
{
	t_ipoint	pos;
	t_ipoint	dim;

	draw_color(((s->f->color_b_edit >> 16) & 0xFF), &s->g->ucb_r, 0x00FF0000);
	draw_color(((s->f->color_b_edit >> 8) & 0xFF), &s->g->ucb_g, 0x0000FF00);
	draw_color((s->f->color_b_edit & 0xFF), &s->g->ucb_b, 0x000000FF);
	pos.x = 0;
	pos.y = 0;
	dim.x = 95;
	dim.y = 15;
	fill_rect(&s->g->ucb_c, pos, dim, s->f->color_b_edit);
	mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win, s->g->ucb_r.img_ptr,
		833, 496);
	mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win, s->g->ucb_g.img_ptr,
		883, 496);
	mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win, s->g->ucb_b.img_ptr,
		933, 496);
	mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win, s->g->ucb_c.img_ptr,
		843, 662);
}
