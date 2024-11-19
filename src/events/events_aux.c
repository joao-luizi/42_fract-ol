/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:38:17 by joaomigu          #+#    #+#             */
/*   Updated: 2024/11/19 14:38:18 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
int key_handler_iter_check(int keysym, t_state *s)
{
	if (keysym != XK_plus && keysym != 65451
	&& keysym != XK_minus && keysym != 65453)
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
int key_handler_pan_check(int keysym, t_state *s)
{
	double distance;

	if (keysym != XK_Right && keysym != XK_Left
		&& keysym != XK_Up && keysym != XK_Down)
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
void zoom_handler(int button, int x, int y, t_state *s)
{
	double new_real_range;
    double new_imag_range;

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
		s->f->dimag.y -=  distance;
		s->f->dimag.x -=  distance;
	}
	else if (direction == 'D' && s->f->dimag.x + distance < 4.0)
	{
		s->f->dimag.y += distance;
		s->f->dimag.x += distance;
	}
}
