#include "../../inc/fractol.h"

/* void initialize_usercolor_section(t_img *section)
{
    int letter[5][3] = { {0, 0, 0 }, {0, 0, 0 },
    {0, 0, 0 }, {0, 0, 0 }, {0, 0, 0 },};
    unsigned int colors[4] = {0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF};
    for (int i = 0; i < 4; i++)
    {
        int x = 10 + i * 45;
        get_character_pattern(get_col_top(i), letter);
        draw_char_to_image(x, 10, section, letter);
        get_character_pattern('+', letter);
        draw_char_to_image(x, 30, section, letter);
        get_character_pattern('-', letter);
        draw_char_to_image(x, 135, section, letter);
        draw_rect(section, x - 3, 50 - 3, 25 + 6, 80 + 6, 0xFFFFFFFF);
        draw_rect(section, x, 50, 25, 80, colors[i]);
    }
    draw_rect(section, 10 - 3, 160 - 3, 170 + 6, 25 + 6, 0xFFFFFFFF);
    draw_rect(section, 10, 160, 170, 25, 0);
} */








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
