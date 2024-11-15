#include "../../inc/fractol.h"

void init_ui(t_state *s)
{
	draw_static_elements(&s->g->static_gui);
	draw_static_string(&s->g->static_gui, get_fractal_string(s->f->fractal_type));
	mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win, s->g->static_gui.img_ptr, 0,0);
	calc_axis(s);
	draw_mouse_hover_dimensions(s);
	draw_color_a_rect(s);
    draw_color_b_rect(s);
}
void draw_static_string(t_img *section, char *f_name)
{
	t_ipoint pos;

	pos.x = 810;
	pos.y = 20;
	lib_x_write_string("fractal", pos, section);
	pos.x = 810;
	pos.y = 40;
	lib_x_write_string(f_name, pos, section);
	pos.x = 810;
	pos.y = 60;
	lib_x_write_string("Iterations", pos, section);
	pos.x = 810;
	pos.y = 80;
	lib_x_write_string("1000", pos, section);
	pos.x = 10;
	pos.y = 810;
	lib_x_write_string("mouse x", pos, section);
	pos.x = 10;
	pos.y = 830;
	lib_x_write_string("mouse y", pos, section);
	pos.x = 150;
	pos.y = 810;
	lib_x_write_string("real", pos, section);
	pos.x = 150;
	pos.y = 830;
	lib_x_write_string("imag", pos, section);
	
}
void draw_static_elements(t_img *section)
{
	int letter[5][3] = { {0, 0, 0 }, {0, 0, 0 },
    {0, 0, 0 }, {0, 0, 0 }, {0, 0, 0 },};
	int i;
	t_ipoint pos;
	t_ipoint dim;
	
	i = 0;
	while(i < 3)
	{
		pos.x = 830 + i * 50;
        get_character_pattern(get_col_top(i), letter);
        draw_char_to_image(pos.x + 5, 160, section, letter);
        get_character_pattern('+', letter);
        draw_char_to_image(pos.x + 5, 190, section, letter);
        get_character_pattern('-', letter);
        draw_char_to_image(pos.x + 5, 350, section, letter);
		pos.y = 215;
		dim.x = 20;
		dim.y = 128;
        draw_rect(section, pos, dim); 
		i++;
	}
	pos.x = 840;
	pos.y = 380;
	dim.x = 100;
	dim.y = 20;
	draw_rect(section, pos, dim); 

	i = 0;
	while(i < 3)
	{
		pos.x = 830 + i * 50;
        get_character_pattern(get_col_top(i), letter);
        draw_char_to_image(pos.x + 5, 280 + 160, section, letter);
        get_character_pattern('+', letter);
        draw_char_to_image(pos.x + 5, 280 + 190, section, letter);
        get_character_pattern('-', letter);
        draw_char_to_image(pos.x + 5, 280 + 350, section, letter);
		pos.y = 280 + 215;
		dim.x = 20;
		dim.y = 128;
        draw_rect(section, pos, dim); 
		i++;
	}
	pos.x = 840;
	pos.y = 280 + 380;
	dim.x = 100;
	dim.y = 20;
	draw_rect(section, pos, dim); 
}

void draw_mouse_hover_elements(t_state *s)
{	
	t_ipoint pos;
	
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

void draw_mouse_hover_dimensions(t_state *s)
{
	t_ipoint pos;
	
	pos.x = 0;
	pos.y = 0;
	lib_x_write_string(s->f->fractal_d_x_min, pos, &s->g->mousehvr_section_d);
	pos.y += 20;
	lib_x_write_string(s->f->fractal_d_y_min, pos, &s->g->mousehvr_section_d);
	pos.y = 0;
	pos.x += 90;
	lib_x_write_string(s->f->fractal_d_x_max, pos, &s->g->mousehvr_section_d);
	pos.y += 20;
	lib_x_write_string(s->f->fractal_d_y_max, pos, &s->g->mousehvr_section_d);
	mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win, s->g->mousehvr_section_d.img_ptr, 350, 810);
}

void draw_color_a_rect(t_state *s)
{
	t_ipoint pos;
	t_ipoint dim;
	
	int r = ((s->f->color_a_edit  >> 16) & 0xFF);
	int g = ((s->f->color_a_edit >> 8) & 0xFF);
	int b = ((s->f->color_a_edit) & 0xFF);
	int percent_r = r * 100 / 256;
	int percent_g = g * 100 / 256;
	int percent_b = b * 100 / 256;
	
	pos.x = 0;
	pos.y = 0;
	dim.x = 15;
	dim.y = 125;
	fill_rect(&s->g->uca_r, pos, dim, 0x00000000);
	fill_rect(&s->g->uca_g, pos, dim, 0x00000000);
	fill_rect(&s->g->uca_b, pos, dim, 0x00000000);

	pos.x = 0;
	pos.y = 125 - (125 * percent_r / 100);
	dim.x = 15;
	dim.y = 125 * percent_r / 100;
	fill_rect(&s->g->uca_r, pos, dim, 0x00FF0000);

	
	pos.x = 0;
	pos.y = 125 - (125 * percent_g / 100);
	dim.x = 15;
	dim.y = 125 * percent_g / 100;
	fill_rect(&s->g->uca_g, pos, dim, 0x0000FF00);

	
	pos.x = 0;
	pos.y = 125 - (125 * percent_b / 100);
	dim.x = 15;
	dim.y = 125 * percent_b / 100;
	fill_rect(&s->g->uca_b, pos, dim, 0x000000FF);


	pos.x = 0;
	pos.y = 0;
	dim.x = 95;
	dim.y = 15;
	fill_rect(&s->g->uca_c, pos, dim, s->f->color_a_edit);


	mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win, s->g->uca_r.img_ptr, 833, 216);
	mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win, s->g->uca_g.img_ptr, 883, 216);
	mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win, s->g->uca_b.img_ptr, 933, 216);
	mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win, s->g->uca_c.img_ptr, 843, 382);



}

void draw_color_b_rect(t_state *s)
{
	t_ipoint pos;
	t_ipoint dim;
	
	int r = ((s->f->color_b_edit  >> 16) & 0xFF);
	int g = ((s->f->color_b_edit >> 8) & 0xFF);
	int b = ((s->f->color_b_edit) & 0xFF);
	int percent_r = r * 100 / 256;
	int percent_g = g * 100 / 256;
	int percent_b = b * 100 / 256;
	
	pos.x = 0;
	pos.y = 0;
	dim.x = 15;
	dim.y = 125;
	fill_rect(&s->g->ucb_r, pos, dim, 0x00000000);
	fill_rect(&s->g->ucb_g, pos, dim, 0x00000000);
	fill_rect(&s->g->ucb_b, pos, dim, 0x00000000);

	pos.x = 0;
	pos.y = 125 - (125 * percent_r / 100);
	dim.x = 15;
	dim.y = 125 * percent_r / 100;
	fill_rect(&s->g->ucb_r, pos, dim, 0x00FF0000);

	pos.x = 0;
	pos.y = 125 - (125 * percent_g / 100);
	dim.x = 15;
	dim.y = 125 * percent_g / 100;
	fill_rect(&s->g->ucb_g, pos, dim, 0x0000FF00);

	pos.x = 0;
	pos.y = 125 - (125 * percent_b / 100);
	dim.x = 15;
	dim.y = 125 * percent_b / 100;
	fill_rect(&s->g->ucb_b, pos, dim, 0x000000FF);

	pos.x = 0;
	pos.y = 0;
	dim.x = 95;
	dim.y = 15;
	fill_rect(&s->g->ucb_c, pos, dim, s->f->color_b_edit);

	mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win, s->g->ucb_r.img_ptr, 833, 496);
	mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win, s->g->ucb_g.img_ptr, 883, 496);
	mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win, s->g->ucb_b.img_ptr, 933, 496);
	mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win, s->g->ucb_c.img_ptr, 843, 662);


}

