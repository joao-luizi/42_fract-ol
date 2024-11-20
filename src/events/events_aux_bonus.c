/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_aux_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:38:17 by joaomigu          #+#    #+#             */
/*   Updated: 2024/11/20 14:10:18 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

/**
 * @brief Handles the iteration count adjustment
 *  based on key press input.
 * 
 * This function checks for key presses related
 *  to iteration count adjustments. The keys 
 * `XK_plus` and `65451` are used to increase the
 *  iteration count by 10, while `XK_minus` 
 * and `65453` are used to decrease the count by 
 * 10. It ensures the iteration count remains 
 * within a defined range (40 to 100 iterations).
 *  After adjusting the iteration count, the 
 * function recalculates the iterations and updates
 *  the gradient colors.
 * 
 * @param keysym The key symbol representing the 
 * pressed key.
 * @param s A pointer to the state structure containing
  the fractal and iteration data.
 * 
 * @return TRUE if the iteration count was modified,
 *  otherwise FALSE.
 */
int	key_handler_iter_check(int keysym, t_state *s)
{
	if (keysym != XK_plus && keysym != 65451 && keysym != XK_minus
		&& keysym != 65453)
		return (FALSE);
	if (keysym == XK_plus || keysym == 65451)
	{
		if (s->f->iterations + 10 > 100)
			return (FALSE);
		else
			s->f->iterations += 10;
	}
	else if (keysym == XK_minus || keysym == 65453)
	{
		if (s->f->iterations - 10 < 40)
			return (FALSE);
		else
			s->f->iterations -= 10;
	}
	calc_iter(s);
	draw_iter(s);
	set_gradient_colors(s->f);
	return (TRUE);
}

/**
 * @brief Handles the panning operation 
 * based on arrow key input.
 * 
 * This function processes arrow key inputs 
 (`XK_Right`, `XK_Left`, `XK_Up`, `XK_Down`) 
 * to pan the fractal's view in the respective 
 direction. It computes the panning distance 
 * based on the current zoom level and moves 
 the view accordingly. After panning, it recalculates 
 * the axis limits and updates the graphics to
  reflect the change.
 * 
 * @param keysym The key symbol representing 
 * the pressed arrow key.
 * @param s A pointer to the state structure 
 * containing the fractal and panning data.
 * 
 * @return TRUE if the panning operation was 
 * performed, otherwise FALSE.
 */
int	key_handler_pan_check(int keysym, t_state *s)
{
	double	distance;

	if (keysym != XK_Right && keysym != XK_Left && keysym != XK_Up
		&& keysym != XK_Down)
		return (FALSE);
	distance = fabs((s->f->dreal.x - s->f->dreal.y) / 50);
	if (distance == 0)
		distance = 0.000001;
	if (keysym == XK_Right)
		pan_handler(s, distance, 'R');
	else if (keysym == XK_Left)
		pan_handler(s, distance, 'L');
	else if (keysym == XK_Up)
		pan_handler(s, distance, 'U');
	else if (keysym == XK_Down)
		pan_handler(s, distance, 'D');
	calc_axis(s);
	draw_mouse_hover_dimensions(s);
	return (TRUE);
}

/**
 * @brief Handles zooming in or out 
 * based on mouse button scroll input.
 * 
 * This function allows the user to
 *  zoom in or out on the fractal using the mouse scroll wheel. 
 * Scrolling up (Button4) zooms in, 
 * while scrolling down (Button5) zooms out. The function adjusts 
 * the real and imaginary axis ranges
 *  based on the zoom direction and updates the fractal's 
 * visualization accordingly, including
 *  recalculating the axis limits and re-rendering the graphics.
 * 
 * @param button The mouse button event 
 * (Button4 for zooming in, Button5 for zooming out).
 * @param x The x-coordinate of the mouse
 *  cursor.
 * @param y The y-coordinate of the mouse
 *  cursor.
 * @param s A pointer to the state structure 
 * containing the fractal data.
 */
void	zoom_handler(int button, int x, int y, t_state *s)
{
	double	new_real_range;
	double	new_imag_range;

	if (button == Button4)
	{
		new_real_range = (s->f->dreal.x - s->f->dreal.y) * 0.9;
		new_imag_range = (s->f->dimag.x - s->f->dimag.y) * 0.9;
	}
	else if (Button5)
	{
		new_real_range = (s->f->dreal.x - s->f->dreal.y) * 1.2;
		new_imag_range = (s->f->dimag.x - s->f->dimag.y) * 1.2;
	}
	s->f->dreal.y = s->f->mapped_x[x] - new_real_range / 2;
	s->f->dreal.x = s->f->mapped_x[x] + new_real_range / 2;
	s->f->dimag.y = s->f->mapped_y[y] - new_imag_range / 2;
	s->f->dimag.x = s->f->mapped_y[y] + new_imag_range / 2;
	calc_axis(s);
	draw_mouse_hover_dimensions(s);
	update_mapped_coordinates(s->f);
	render_graphics(s);
}

/**
 * @brief Handles the panning operation 
 * based on direction input and distance.
 * 
 * This function updates the fractal's view
 *  position based on the specified direction 
 * ('R' for right, 'L' for left, 'U' for up,
 *  'D' for down) and the calculated panning distance. 
 * The view is adjusted within defined axis 
 * limits, and the function ensures that the fractal 
 * does not exceed the predefined boundaries.
 * 
 * @param s A pointer to the state structure 
 * containing the fractal and panning data.
 * @param distance The calculated distance for
 *  the panning operation.
 * @param direction The direction of the pan 
 * ('R' for right, 'L' for left, 'U' for up, 'D' for down).
 */
void	pan_handler(t_state *s, double distance, char direction)
{
	if (direction == 'R' && s->f->dreal.y - distance > -4.0)
	{
		s->f->dreal.y -= distance;
		s->f->dreal.x -= distance;
	}
	else if (direction == 'L' && s->f->dreal.x + distance < 4.0)
	{
		s->f->dreal.y += distance;
		s->f->dreal.x += distance;
	}
	else if (direction == 'U' && s->f->dimag.y - distance > -4.0)
	{
		s->f->dimag.y -= distance;
		s->f->dimag.x -= distance;
	}
	else if (direction == 'D' && s->f->dimag.x + distance < 4.0)
	{
		s->f->dimag.y += distance;
		s->f->dimag.x += distance;
	}
}
