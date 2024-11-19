/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:38:25 by joaomigu          #+#    #+#             */
/*   Updated: 2024/11/19 17:55:37 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

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

int	close_handler(t_state *s)
{
	free_sections(s->g);
	mlx_destroy_window(s->g->mlx_conn, s->g->mlx_win);
	mlx_destroy_display(s->g->mlx_conn);
	free(s->g->mlx_conn);
	exit(0);
	return (0);
}

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

void	init_events(t_state *s)
{
	mlx_hook(s->g->mlx_win, MotionNotify, PointerMotionMask, mouse_move_handler,
		s);
	mlx_hook(s->g->mlx_win, ButtonPress, ButtonPressMask, mouse_handler, s);
	mlx_hook(s->g->mlx_win, KeyPress, KeyPressMask, key_handler, s);
	mlx_hook(s->g->mlx_win, DestroyNotify, StructureNotifyMask, close_handler,
		s);
}
