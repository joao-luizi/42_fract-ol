/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_gui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:38:48 by joaomigu          #+#    #+#             */
/*   Updated: 2024/11/19 14:38:49 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"


static void draw_static_string(t_img *section, char *f_name)
{
	lib_x_write_string("fractal", 810, 20, section);
	lib_x_write_string(f_name, 810, 40, section);
	lib_x_write_string("Iterations", 810, 60, section);
	lib_x_write_string("mouse x", 10, 810, section);
	lib_x_write_string("mouse y", 10, 830, section);
	lib_x_write_string("real", 150, 810, section);
	lib_x_write_string("imag", 150, 830, section);
}
static void draw_color_area(t_ipoint pos,t_ipoint dim, int y, t_img *section)
{
	int i;
	int letter[5][3] = { {0, 0, 0 }, {0, 0, 0 },
    {0, 0, 0 }, {0, 0, 0 }, {0, 0, 0 },};

	i = 0;
	while(i < 3)
	{
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
static void draw_static_elements(t_img *section)
{
	t_ipoint pos;
	t_ipoint dim;
	
	pos.x = 0;
	pos.y = 0;
	dim.x = 0;
	dim.y = 0;
	draw_color_area(pos, dim, 0, section);
	draw_color_area(pos, dim, 280, section);
}

void init_ui(t_state *s)
{
	draw_static_elements(&s->g->static_gui);
	draw_static_string(&s->g->static_gui, get_fractal_string(s->f->fractal_type));
	mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win, s->g->static_gui.img_ptr, 0,0);
	calc_axis(s);
	draw_mouse_hover_dimensions(s);
	draw_color_rect(s);
	calc_iter(s);
	draw_iter(s);
}


