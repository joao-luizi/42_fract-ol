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

void draw_rect(t_img *section, t_ipoint pos, t_ipoint dim)
{
    int *pixels;

	pixels = (int *)section->pixels_ptr;
    for (int i = 0; i < dim.y; i++)
    {
        for (int j = 0; j < dim.x; j++)
        {
			if ((j < 3 || j > dim.x - 3) || (i == 0 || i == dim.y -1))
            	pixels[(pos.y + i) * (section->section_width) + (pos.x + j)] = 0xFFFFFFFF;
        }
    }
}

void fill_rect(t_img *section, t_ipoint pos, t_ipoint dim, int color)
{
    int *pixels;
	int i;
	int j;

	pixels = (int *)section->pixels_ptr;
	i = 0;
	while (i < dim.y)
	{
		j = 0;
		while (j < dim.x)
		{
			pixels[(pos.y + i) * (section->section_width) + (pos.x + j)] = color;
			j++;
		}
		i++;
	}
}


char get_col_top(int i)
{
    if (i == 0)
        return ('r');
    else if (i == 1)
        return ('g');
    else if (i == 2)
        return ('b');
    else
        return ('x');
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
//dynamic_elements

/* 
static void	set_pixel_color(t_graphics *g, int x, int y, int color)
{
	double blend_factor = 0.15; // Adjust this value to increase or decrease brightness

    // Calculate blended color components
    int r = ((color >> 16) & 0xFF) * (1 - blend_factor) + (255 * blend_factor);
    int g_color = ((color >> 8) & 0xFF) * (1 - blend_factor) + (255 * blend_factor);
    int b = (color & 0xFF) * (1 - blend_factor) + (255 * blend_factor);

    // Ensure values are within 0-255
    r = (r > 255) ? 255 : r;
    g_color = (g_color > 255) ? 255 : g_color;
    b = (b > 255) ? 255 : b;

    // Combine back to a single color value
    color = (r << 16) | (g_color << 8) | b;

		g->img.pixels_ptr[x * 4 + y * IMAGE_WIDTH * 4] = color;
		g->img.pixels_ptr[x * 4 + y * IMAGE_WIDTH * 4 + 1] = color >> 8;
		g->img.pixels_ptr[x * 4 + y * IMAGE_WIDTH * 4 + 2] = color >> 16;
		g->img.pixels_ptr[x * 4 + y * IMAGE_WIDTH * 4 + 3] = color >> 24;
} */


/* static int	calculate_fractal(t_fractal *f, double pr, double pi)
{
	int	iter;

	if (f->fractal_type == FRACTAL_MANDELBROT)
		iter = calc_mandelbrot(pr, pi, f->iterations);
	else if (f->fractal_type == FRACTAL_JULIA)
		iter = calc_julia(f, pr, pi);
	else if (f->fractal_type == FRACTAL_BURNING_SHIP)
		iter = calc_burning_ship(pr, pi, f->iterations);
	return (iter);
} */

/* void render_graphics(t_fractal *f, t_graphics *g)
{
	int		x;
	int		y;
	double	real;
	double	imag;
	int		iter;

	y = 0;
	iter = 0;
	imag = 0.0;
	real = 0.0;
	while (y < IMAGE_HEIGHT)
	{
		f->mapped_y[y] = f->dimag.x + (double)y * (f->dimag.y - f->dimag.x) / IMAGE_HEIGHT;
		y++;
	}
	while (x < IMAGE_WIDTH)
	{
		f->mapped_x[x] = f->dreal.y + (double)x * (f->dreal.x - f->dreal.y) / IMAGE_WIDTH;
		x++;
	}
	while (y < IMAGE_HEIGHT)
	{
		imag = f->dimag.x + (double)y * (f->dimag.y - f->dimag.x) / IMAGE_HEIGHT;
		x = 0;
		while (x < IMAGE_WIDTH)
		{
			real = f->dreal.y + (double)x * (f->dreal.x - f->dreal.y) / IMAGE_WIDTH;
			iter = calculate_fractal(f, real, imag);
			
			set_pixel_color(g, x, y, f->color_range[iter]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(g->mlx_conn, g->mlx_win, g->img.img_ptr, 50, 50);
} */
