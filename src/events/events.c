#include "../inc/fractol.h"

static void	pan(t_state *s, double distance, char direction)
{
	double min;
	double max;

	min = - 4.0;
	max = 4.0;
	if (direction == 'R')
	{
		if (s->f->dreal.y - distance > min)
		{
			s->f->dreal.y -= distance;
			s->f->dreal.x -= distance;
		}
	}
	else if (direction == 'L')
	{
		if (s->f->dreal.x + distance < max)
		{
			s->f->dreal.y += distance;
			s->f->dreal.x += distance;
		}
	}	
	else if (direction == 'U')
	{
		if (s->f->dimag.y - distance > min)
		{
			s->f->dimag.y -=  distance;
			s->f->dimag.x -=  distance;
		}
	}
	else if (direction == 'D')
	{
		if (s->f->dimag.x + distance < max)
		{
			s->f->dimag.y += distance;
			s->f->dimag.x += distance;
		}
	}
}

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
			ft_printf("Iterations increased");
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
			ft_printf("Iterations decerased");
		}
	}
	update_mapped_coordinates(s->f);
	render_graphics(s);
	return (0);
}
int close_handler(t_state *s)
{
	mlx_destroy_image(s->g->mlx_conn, s->g->f_section.img_ptr);
	mlx_destroy_image(s->g->mlx_conn, s->g->mousehvr_section_d.img_ptr);
	mlx_destroy_image(s->g->mlx_conn, s->g->mousehvr_section_w.img_ptr);
	mlx_destroy_image(s->g->mlx_conn, s->g->mousehvr_section_f.img_ptr);
	mlx_destroy_image(s->g->mlx_conn, s->g->static_gui.img_ptr);
	mlx_destroy_image(s->g->mlx_conn, s->g->uc_apply.img_ptr);
	mlx_destroy_image(s->g->mlx_conn, s->g->uca_r.img_ptr);
	mlx_destroy_image(s->g->mlx_conn, s->g->uca_g.img_ptr);
	mlx_destroy_image(s->g->mlx_conn, s->g->uca_b.img_ptr);
	mlx_destroy_image(s->g->mlx_conn, s->g->uca_c.img_ptr);
	mlx_destroy_image(s->g->mlx_conn, s->g->ucb_r.img_ptr);
	mlx_destroy_image(s->g->mlx_conn, s->g->ucb_g.img_ptr);
	mlx_destroy_image(s->g->mlx_conn, s->g->ucb_b.img_ptr);
	mlx_destroy_image(s->g->mlx_conn, s->g->ucb_c.img_ptr);
	mlx_destroy_window(s->g->mlx_conn, s->g->mlx_win);
	mlx_destroy_display(s->g->mlx_conn);
	free(s->g->mlx_conn);
	exit(0);
	return (0);
}

void user_color_b_b(int x, int y, t_state *s)
{
	int r = ((s->f->color_b_edit  >> 16) & 0xFF);
	int g = ((s->f->color_b_edit >> 8) & 0xFF);
	int b = ((s->f->color_b_edit) & 0xFF);
	if (x > 935 - 5 && x < 950 + 5)
	{
		if (y > 480 - 5 && y < 480 + 5 && g < 255)
		{
			b++;
			s->f->color_b_edit = r << 16 | g << 8 | b;
			draw_color_b_rect(s);
		}
		if (y > 640 - 5 && y < 640 + 5 && g > 0)
		{
			b--;
			s->f->color_b_edit = r << 16 | g << 8 | b;
			draw_color_b_rect(s);
		}
	}
	if (x > 935 && x < 950 && y > 500 && y < 625)
	{
		b = (625 - y) * 255 / 125;
		s->f->color_b_edit = r << 16 | g << 8 | b;
		draw_color_b_rect(s);
	}
}
void user_color_b_g(int x, int y, t_state *s)
{
	int r = ((s->f->color_b_edit  >> 16) & 0xFF);
	int g = ((s->f->color_b_edit >> 8) & 0xFF);
	int b = ((s->f->color_b_edit) & 0xFF);
	if (x > 890 - 5 && x < 890 + 5)
	{
		if (y > 480 - 5 && y < 480 + 5 && g < 255)
		{
			g++;
			s->f->color_b_edit = r << 16 | g << 8 | b;
			draw_color_b_rect(s);
		}
		if (y > 640 - 5 && y < 640 + 5 && g > 0)
		{
			g--;
			s->f->color_b_edit = r << 16 | g << 8 | b;
			draw_color_b_rect(s);
		}
	}
	if (x > 885 && x < 900 && y > 500 && y < 625)
	{
		g = (625 - y) * 255 / 125;
		s->f->color_b_edit = r << 16 | g << 8 | b;
		draw_color_b_rect(s);
	}
}

void user_color_b_r(int x, int y, t_state *s)
{
	int r = ((s->f->color_b_edit  >> 16) & 0xFF);
	int g = ((s->f->color_b_edit >> 8) & 0xFF);
	int b = ((s->f->color_b_edit) & 0xFF);
	if (x > 840 - 5 && x < 840 + 5)
	{
		if (y > 480 - 5 && y < 480 + 5 && r > 255)
		{
			r++;
			s->f->color_b_edit = r << 16 | g << 8 | b;
			draw_color_b_rect(s);
		}
		if (y > 640 - 5 && y < 640 + 5 && r > 0)
		{
			r--;
			s->f->color_b_edit = r << 16 | g << 8 | b;
			draw_color_b_rect(s);
		}
	}
	if (x > 833 && x < 848 && y > 500 && y < 625)
	{
		r = (625 - y) * 255 / 125;
		s->f->color_b_edit = r << 16 | g << 8 | b;
		draw_color_b_rect(s);
	}
}

void user_color_a_b(int x, int y, t_state *s)
{
	int r = ((s->f->color_a_edit  >> 16) & 0xFF);
	int g = ((s->f->color_a_edit >> 8) & 0xFF);
	int b = ((s->f->color_a_edit) & 0xFF);
	if (x > 940 - 5 && x < 940 + 5)
	{
		if (y > 200 - 5 && y < 200 + 5 && b < 255)
		{
			b++;
			s->f->color_a_edit = r << 16 | g << 8 | b;
			draw_color_a_rect(s);
		}
		if (y > 360 - 5 && y < 360 + 5 && b > 0)
		{
			b--;
			s->f->color_a_edit = r << 16 | g << 8 | b;
			draw_color_a_rect(s);
		}
	}
	if (x > 935 && x < 950 && y > 220 && y < 345)
	{
		b = (345 - y) * 255 / 125;
		s->f->color_a_edit = r << 16 | g << 8 | b;
		draw_color_a_rect(s);
	}
}
void user_color_a_g(int x, int y, t_state *s)
{
	int r = ((s->f->color_a_edit  >> 16) & 0xFF);
	int g = ((s->f->color_a_edit >> 8) & 0xFF);
	int b = ((s->f->color_a_edit) & 0xFF);
	if (x > 890 - 5 && x < 890 + 5 && g < 255)
	{
		if (y > 200 - 5 && y < 200 + 5)
		{
			g++;
			s->f->color_a_edit = r << 16 | g << 8 | b;
			draw_color_a_rect(s);
		}
		if (y > 360 - 5 && y < 360 + 5 && g > 0)
		{
			g--;
			s->f->color_a_edit = r << 16 | g << 8 | b;
			draw_color_a_rect(s);
		}
	}
	if (x > 885 && x < 900 && y > 220 && y < 345)
	{
		g = (345 - y) * 255 / 125;
		s->f->color_a_edit = r << 16 | g << 8 | b;
		draw_color_a_rect(s);
	}
}
void user_color_a_r(int x, int y, t_state *s)
{
	int r = ((s->f->color_a_edit  >> 16) & 0xFF);
	int g = ((s->f->color_a_edit >> 8) & 0xFF);
	int b = ((s->f->color_a_edit) & 0xFF);
	if (x > 840 - 5 && x < 840 + 5)
	{
		if (y > 200 - 5 && y < 200 + 5 && r > 255)
		{
			r++;
			s->f->color_a_edit = r << 16 | g << 8 | b;
			draw_color_a_rect(s);
		}
		if (y > 360 - 5 && y < 360 + 5 && r > 0)
		{
			r--;
			s->f->color_a_edit = r << 16 | g << 8 | b;
			draw_color_a_rect(s);
		}
	}
	if (x > 833 && x < 848 && y > 220 && y < 345)
	{
		r = (345 - y) * 255 / 125;
		s->f->color_a_edit = r << 16 | g << 8 | b;
		draw_color_a_rect(s);
	}
}
void draw_apply(t_state *s)
{
	t_ipoint pos;
	t_ipoint dim;

	if (s->f->color_a != s->f->color_a_edit
		|| s->f->color_b != s->f->color_b_edit)
	{
		pos.x = 0;
		pos.y = 0;
		dim.x= 100;
		dim.y = 30;
		draw_rect(&s->g->uc_apply, pos, dim);
		pos.x = 25;
		pos.y = 8;
		lib_x_write_string("apply", pos, &s->g->uc_apply);
	}
	else
	{
		pos.x = 0;
		pos.y = 0;
		dim.x= 100;
		dim.y = 30;
		fill_rect(&s->g->uc_apply, pos, dim, 0x00000000);
	}
	mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win, s->g->uc_apply.img_ptr, 840, 720);
}

void user_apply(int x, int y, t_state *s)
{
	if (x > 840 && x < 940 && y > 720 && y < 750)
	{
		if (s->f->color_a != s->f->color_a_edit 
		|| s->f->color_b != s->f->color_b_edit)
		{
			s->f->color_a = s->f->color_a_edit;
			s->f->color_b = s->f->color_b_edit;
			draw_apply(s);
			set_gradient_colors(s->f);
			render_graphics(s);
		}
	}
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
		double check;

		check = s->f->dreal.y;
		if (s->f->dreal.y * 0.95 != check)
		{
			s->f->dreal.y *= 0.95;
			s->f->dreal.x *= 0.95;
			s->f->dimag.x *= 0.95;
			s->f->dimag.y *= 0.95;

			x -= IMAGE_WIDTH / 2;
			y -= IMAGE_HEIGHT / 2;
			double distance_x = 0.0;
			double distance_y = 0.0;
			if (y < 0)
				distance_y = fabs(s->f->dimag.x - s->f->dimag.y) * (y * -1) / 800;
			else
				distance_y = fabs(s->f->dimag.x - s->f->dimag.y) * y  / 800;
			if (x < 0)
				distance_x = fabs(s->f->dreal.x - s->f->dreal.y) * (x * -1) / 800;
			else
				distance_x = fabs(s->f->dreal.x - s->f->dreal.y) * x / 800;	
			if (x < 0)
				pan(s, fabs(distance_x) / 10, 'R');
			else if (x > 0)
				pan(s, fabs(distance_x) / 10, 'L');
			if (y < 0)
				pan(s, fabs(distance_y) / 10, 'D');
			else if (y > 0)
				pan(s, fabs(distance_y) / 10, 'U');
			calc_axis(s);
			draw_mouse_hover_dimensions(s);
			update_mapped_coordinates(s->f);
			render_graphics(s);
		}
	}
	else if (button == Button5)
	{
		if (s->f->dreal.x - s->f->dreal.y < 5.0)
		{
			s->f->dreal.y *= 1.15;
			s->f->dreal.x *= 1.15;
			s->f->dimag.x *= 1.15;
			s->f->dimag.y *= 1.15;
			
			calc_axis(s);
			draw_mouse_hover_dimensions(s);
			update_mapped_coordinates(s->f);
			render_graphics(s);
		}
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
		lib_x_write_string(s->f->mouse_x, pos, &s->g->mousehvr_section_w);
		pos.y += 20;
		lib_x_write_string(s->f->mouse_y, pos, &s->g->mousehvr_section_w);
		mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win, s->g->mousehvr_section_w.img_ptr, 85, 810);

		pos.y -= 20;
		lib_x_write_string(s->f->fractal_x, pos, &s->g->mousehvr_section_f);
		pos.y += 20;
		lib_x_write_string(s->f->fractal_y, pos, &s->g->mousehvr_section_f);
		mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win, s->g->mousehvr_section_f.img_ptr, 200, 810);
		
		
	}
	return (0);
}
