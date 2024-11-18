#include "../inc/fractol.h"

int	key_handler(int keysym, t_state *s)
{
	double distance;

	distance = fabs((s->f->dreal.x - s->f->dreal.y) / 50);
	if (distance == 0)
		distance = 0.000001;
	if (keysym == XK_Escape)
	{
		close_handler(s);
	}
	else if (keysym == XK_Right)
	{
		pan(s, distance, 'R');
		calc_axis(s);
		draw_mouse_hover_dimensions(s);
	}
	else if (keysym == XK_Left)
	{
		pan(s, distance, 'L');
		calc_axis(s);
		draw_mouse_hover_dimensions(s);
	}
	else if (keysym == XK_Up)
	{
		pan(s, distance, 'U');
		calc_axis(s);
		draw_mouse_hover_dimensions(s);
	}
	else if (keysym == XK_Down)
	{
		pan(s, distance, 'D');
		calc_axis(s);
		draw_mouse_hover_dimensions(s);
	}
	else if (keysym == XK_plus)
	{

		if (s->f->iterations + 10 > 100)
			s->f->iterations = 100;
		else
		{
			s->f->iterations += 10;
			calc_iter(s);
			draw_iter(s);
			set_gradient_colors(s->f);
		}
	}
	else if (keysym == XK_minus)
	{
		if (s->f->iterations - 10 < 40)
			s->f->iterations = 40;
		else
		{
			s->f->iterations -= 10;
			calc_iter(s);
			draw_iter(s);
			set_gradient_colors(s->f);
		}
	}
	update_mapped_coordinates(s->f);
	render_graphics(s);
	return (0);
}
int close_handler(t_state *s)
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
	if (button == Button1)
	{
		user_color_a_r(x, y, s);
		user_color_a_g(x, y, s);
		user_color_a_b(x, y, s);
		user_color_b_r(x, y, s);
		user_color_b_g(x, y, s);
		user_color_b_b(x, y, s);
		draw_apply(s);
		user_apply(x, y, s);
	}
	else if (button == Button4)
	{
		double real_range = s->f->dreal.x - s->f->dreal.y;
    	double imag_range = s->f->dimag.x - s->f->dimag.y;

    	// Calculate new range after zoom
    	double new_real_range = real_range * 0.9;
    	double new_imag_range = imag_range * 0.9;

    	// Set new min and max values, centered on the target point
    	s->f->dreal.y = s->f->mapped_x[x] - new_real_range / 2;
    	s->f->dreal.x = s->f->mapped_x[x] + new_real_range / 2;
    	s->f->dimag.y = s->f->mapped_y[y] - new_imag_range / 2;
    	s->f->dimag.x = s->f->mapped_y[y] + new_imag_range / 2;

		calc_axis(s);
		draw_mouse_hover_dimensions(s);
		update_mapped_coordinates(s->f);
		render_graphics(s);
	}
	else if (button == Button5)
	{
		double real_range = s->f->dreal.x - s->f->dreal.y;
    	double imag_range = s->f->dimag.x - s->f->dimag.y;

    	// Calculate new range after zoom
    	double new_real_range = real_range * 1.2;
    	double new_imag_range = imag_range * 1.2;

    	// Set new min and max values, centered on the target point
    	s->f->dreal.y = s->f->mapped_x[x] - new_real_range / 2;
    	s->f->dreal.x = s->f->mapped_x[x] + new_real_range / 2;
    	s->f->dimag.y = s->f->mapped_y[y] - new_imag_range / 2;
    	s->f->dimag.x = s->f->mapped_y[y] + new_imag_range / 2;
			
		calc_axis(s);
		draw_mouse_hover_dimensions(s);
		update_mapped_coordinates(s->f);
		render_graphics(s);
		
	}
	return (0);
}
int	mouse_move_handler(int x, int y, t_state *s)
{
	t_ipoint pos;
	
	if (x < 800 && y < 800)
	{
		calc_mouse_coord(x, y, s);
		calc_fractal_coord(x, y, s);
		pos.x = 0;
		pos.y = 0;
		lib_x_write_string(s->f->mouse_x, 0, 0, &s->g->mousehvr_section_w);
		pos.y += 20;
		lib_x_write_string(s->f->mouse_y, 0, 20, &s->g->mousehvr_section_w);
		mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win, s->g->mousehvr_section_w.img_ptr, 85, 810);

		pos.y -= 20;
		lib_x_write_string(s->f->fractal_x, 0,0, &s->g->mousehvr_section_f);
		pos.y += 20;
		lib_x_write_string(s->f->fractal_y, 0, 20, &s->g->mousehvr_section_f);
		mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win, s->g->mousehvr_section_f.img_ptr, 200, 810);
	}
	return (0);
}
