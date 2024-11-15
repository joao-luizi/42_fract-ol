#include "../../inc/fractol.h"

void draw_mouse_hover_elements(t_state *s)
{	
	lib_x_write_string(s->f->mouse_x, 0, 0 , &s->g->mousehvr_section_w);
	lib_x_write_string(s->f->mouse_y, 0, 20, &s->g->mousehvr_section_w);
	mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win, s->g->mousehvr_section_w.img_ptr, 85, 810);
	lib_x_write_string(s->f->fractal_x, 0, 0, &s->g->mousehvr_section_f);
	lib_x_write_string(s->f->fractal_y, 0, 20, &s->g->mousehvr_section_f);
	mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win, s->g->mousehvr_section_f.img_ptr, 200, 810);
}

void draw_mouse_hover_dimensions(t_state *s)
{
	lib_x_write_string(s->f->fractal_d_x_min, 0,0, &s->g->mousehvr_section_d);
	lib_x_write_string(s->f->fractal_d_y_min, 0, 20, &s->g->mousehvr_section_d);
	lib_x_write_string(s->f->fractal_d_x_max, 90, 0, &s->g->mousehvr_section_d);
	lib_x_write_string(s->f->fractal_d_y_max, 90, 20, &s->g->mousehvr_section_d);
	mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win, s->g->mousehvr_section_d.img_ptr, 350, 810);
}
static void draw_color(int channel, t_img *uc, int color_fill)
{
	t_ipoint pos;
	t_ipoint dim;
	int percent_channel;

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

void draw_color_rect(t_state *s)
{
	t_ipoint pos;
	t_ipoint dim;
	
	draw_color(((s->f->color_a_edit  >> 16) & 0xFF), &s->g->uca_r, 0x00FF0000);
	draw_color(((s->f->color_a_edit  >> 8) & 0xFF), &s->g->uca_g, 0x0000FF00);
	draw_color((s->f->color_a_edit& 0xFF), &s->g->uca_b, 0x000000FF);
	draw_color(((s->f->color_b_edit  >> 16) & 0xFF), &s->g->ucb_r, 0x00FF0000);
	draw_color(((s->f->color_b_edit  >> 8) & 0xFF), &s->g->ucb_g, 0x0000FF00);
	draw_color((s->f->color_b_edit& 0xFF), &s->g->ucb_b, 0x000000FF);
	pos.x = 0;
	pos.y = 0;
	dim.x = 95;
	dim.y = 15;
	fill_rect(&s->g->uca_c, pos, dim, s->f->color_a_edit);
	fill_rect(&s->g->ucb_c, pos, dim, s->f->color_b_edit);
	mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win, s->g->ucb_r.img_ptr, 833, 496);
	mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win, s->g->ucb_g.img_ptr, 883, 496);
	mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win, s->g->ucb_b.img_ptr, 933, 496);
	mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win, s->g->ucb_c.img_ptr, 843, 662);
	mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win, s->g->uca_r.img_ptr, 833, 216);
	mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win, s->g->uca_g.img_ptr, 883, 216);
	mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win, s->g->uca_b.img_ptr, 933, 216);
	mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win, s->g->uca_c.img_ptr, 843, 382);
}


