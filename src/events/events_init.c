/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:38:25 by joaomigu          #+#    #+#             */
/*   Updated: 2024/11/20 14:00:11 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

/**
 * @brief Handles keyboard input events.
 * 
 * This function processes key events
 *  and takes actions based on the key pressed. 
 * - If the Escape key is pressed, it 
 * calls the `close_handler()` to exit the program.
 * - If a key related to panning or iteration 
 * is pressed, the coordinates are updated 
 *   and the graphics are re-rendered.
 * 
 * @param keysym The key symbol of the key
 *  that was pressed.
 * @param s The state structure that contains 
 * the current fractal and graphical data.
 * 
 * @return Always returns 0.
 */
int	key_handler(int keysym, t_state *s)
{
	if (keysym == XK_Escape)
		close_handler(s);
	else if (key_handler_pan_check(keysym, s) || key_handler_iter_check(keysym,
			s))
	{
		update_mapped_coordinates(s->f);
		render_graphics(s);
	}
	return (0);
}

/**
 * @brief Handles the close event by 
 * freeing allocated resources.
 * 
 * This function is triggered when the 
 * window is closed. It frees memory used by 
 * the graphical sections, destroys the 
 * window, and closes the display connection.
 * Finally, the program exits with a status
 *  of 0.
 * 
 * @param s The state structure containing
 *  the graphical and other relevant data.
 * 
 * @return Always returns 0.
 */
int	close_handler(t_state *s)
{
	free_sections(s->g);
	mlx_destroy_window(s->g->mlx_conn, s->g->mlx_win);
	mlx_destroy_display(s->g->mlx_conn);
	free(s->g->mlx_conn);
	exit(0);
	return (0);
}

/**
 * @brief Handles mouse input events
 *  such as button presses.
 * 
 * This function handles mouse button
 *  presses. It:
 * - Handles left mouse button press (Button1) 
 by updating the user-defined color 
 *   rectangles and applying any changes.
 * - Handles mouse wheel scroll (Button4 
 * and Button5) for zooming in and out.
 * 
 * @param button The mouse button that was pressed.
 * @param x The x-coordinate of the mouse 
 * pointer when the button was pressed.
 * @param y The y-coordinate of the mouse 
 * pointer when the button was pressed.
 * @param s The state structure that contains
 *  the current fractal and graphical data.
 * 
 * @return Always returns 0.
 */
int	mouse_handler(int button, int x, int y, t_state *s)
{
	int	result_color_a;
	int	result_color_b;

	if (button == Button1)
	{
		result_color_a = user_color_a(x, y, s);
		result_color_b = user_color_b(x, y, s);
		if (result_color_a || result_color_b)
		{
			if (result_color_a)
				draw_color_rect_a(s);
			if (result_color_b)
				draw_color_rect_b(s);
			draw_apply(s);
		}
		user_apply(x, y, s);
	}
	else if (button == Button4 || button == Button5)
		zoom_handler(button, x, y, s);
	return (0);
}

/**
 * @brief Handles mouse movement events
 *  and updates information displays.
 * 
 * This function is triggered when the mouse
 *  moves inside the window. It updates 
 * and displays the following information:
 * - The current mouse coordinates.
 * - The corresponding fractal coordinates 
 * for the mouse position.
 * It also handles drawing and updating the
 *  graphical interface with this information.
 * 
 * @param x The x-coordinate of the mouse 
 * pointer during the movement.
 * @param y The y-coordinate of the mouse 
 * pointer during the movement.
 * @param s The state structure containing 
 * the graphical and fractal data.
 * 
 * @return Always returns 0.
 */
int	mouse_move_handler(int x, int y, t_state *s)
{
	t_ipoint	pos;

	if (x < 800 && y < 800)
	{
		calc_mouse_coord(x, y, s);
		calc_fractal_coord(x, y, s);
		pos.x = 0;
		pos.y = 0;
		lib_x_write_string(s->f->mouse_x, 0, 0, &s->g->mousehvr_section_w);
		pos.y += 20;
		lib_x_write_string(s->f->mouse_y, 0, 20, &s->g->mousehvr_section_w);
		mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win,
			s->g->mousehvr_section_w.img_ptr, 85, 810);
		pos.y -= 20;
		lib_x_write_string(s->f->fractal_x, 0, 0, &s->g->mousehvr_section_f);
		pos.y += 20;
		lib_x_write_string(s->f->fractal_y, 0, 20, &s->g->mousehvr_section_f);
		mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win,
			s->g->mousehvr_section_f.img_ptr, 200, 810);
	}
	return (0);
}

/**
 * @brief Initializes the event 
 * handling system.
 * 
 * This function sets up event hooks 
 * for various events including mouse movement,
 * mouse button presses, keyboard 
 * presses, and window destruction events. 
 * Each event is associated with its 
 * corresponding handler function.
 * 
 * @param s The state structure that 
 * holds references to the graphical and window data.
 */
void	init_events(t_state *s)
{
	mlx_hook(s->g->mlx_win, MotionNotify, PointerMotionMask, mouse_move_handler,
		s);
	mlx_hook(s->g->mlx_win, ButtonPress, ButtonPressMask, mouse_handler, s);
	mlx_hook(s->g->mlx_win, KeyPress, KeyPressMask, key_handler, s);
	mlx_hook(s->g->mlx_win, DestroyNotify, StructureNotifyMask, close_handler,
		s);
}
