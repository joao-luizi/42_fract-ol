#include "../inc/fractol.h"

void	pan(t_state *s, double distance, char direction)
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
			draw_color_rect(s);
		}
		if (y > 640 - 5 && y < 640 + 5 && g > 0)
		{
			b--;
			s->f->color_b_edit = r << 16 | g << 8 | b;
			draw_color_rect(s);
		}
	}
	if (x > 935 && x < 950 && y > 500 && y < 625)
	{
		b = (625 - y) * 255 / 125;
		s->f->color_b_edit = r << 16 | g << 8 | b;
		draw_color_rect(s);
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
			draw_color_rect(s);
		}
		if (y > 640 - 5 && y < 640 + 5 && g > 0)
		{
			g--;
			s->f->color_b_edit = r << 16 | g << 8 | b;
			draw_color_rect(s);
		}
	}
	if (x > 885 && x < 900 && y > 500 && y < 625)
	{
		g = (625 - y) * 255 / 125;
		s->f->color_b_edit = r << 16 | g << 8 | b;
		draw_color_rect(s);
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
			draw_color_rect(s);
		}
		if (y > 640 - 5 && y < 640 + 5 && r > 0)
		{
			r--;
			s->f->color_b_edit = r << 16 | g << 8 | b;
			draw_color_rect(s);
		}
	}
	if (x > 833 && x < 848 && y > 500 && y < 625)
	{
		r = (625 - y) * 255 / 125;
		s->f->color_b_edit = r << 16 | g << 8 | b;
		draw_color_rect(s);
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
			draw_color_rect(s);
		}
		if (y > 360 - 5 && y < 360 + 5 && b > 0)
		{
			b--;
			s->f->color_a_edit = r << 16 | g << 8 | b;
			draw_color_rect(s);
		}
	}
	if (x > 935 && x < 950 && y > 220 && y < 345)
	{
		b = (345 - y) * 255 / 125;
		s->f->color_a_edit = r << 16 | g << 8 | b;
		draw_color_rect(s);
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
			draw_color_rect(s);
		}
		if (y > 360 - 5 && y < 360 + 5 && g > 0)
		{
			g--;
			s->f->color_a_edit = r << 16 | g << 8 | b;
			draw_color_rect(s);
		}
	}
	if (x > 885 && x < 900 && y > 220 && y < 345)
	{
		g = (345 - y) * 255 / 125;
		s->f->color_a_edit = r << 16 | g << 8 | b;
		draw_color_rect(s);
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
			draw_color_rect(s);
		}
		if (y > 360 - 5 && y < 360 + 5 && r > 0)
		{
			r--;
			s->f->color_a_edit = r << 16 | g << 8 | b;
			draw_color_rect(s);
		}
	}
	if (x > 833 && x < 848 && y > 220 && y < 345)
	{
		r = (345 - y) * 255 / 125;
		s->f->color_a_edit = r << 16 | g << 8 | b;
		draw_color_rect(s);
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
		lib_x_write_string("apply", 25, 8, &s->g->uc_apply);
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
