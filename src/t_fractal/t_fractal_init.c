#include "../../inc/fractol.h"

void clean_f(t_fractal *f)
{
	f->fractal_type = FRACTAL_INVALID;
	f->julia_c.x = 0.0;
	f->julia_c.y = 0.0;
	f->dreal.x = 0.0;
	f->dreal.y = 0.0;
	f->dimag.x = 0.0;
	f->dimag.y = 0.0;
	f->shift.x = 0.0;
	f->shift.y = 0.0;
	f->iterations = MAX_ITERATIONS;
	f->zoomx = 1.0;
	ft_memset(f->mapped_x, 0, sizeof(f->mapped_x));
	ft_memset(f->mapped_y, 0, sizeof(f->mapped_y));
	ft_memset(f->mouse_x, 0, sizeof(f->mouse_x));
	ft_memset(f->mouse_y, 0, sizeof(f->mouse_y));
	ft_memset(f->fractal_x, 0, sizeof(f->fractal_x));
	ft_memset(f->fractal_y, 0, sizeof(f->fractal_y));
	ft_memset(f->fractal_d_x_max, 0, sizeof(f->fractal_d_x_max));
	ft_memset(f->fractal_d_x_min, 0, sizeof(f->fractal_d_x_min));
	ft_memset(f->fractal_d_y_max, 0, sizeof(f->fractal_d_y_max));
	ft_memset(f->fractal_d_y_min, 0, sizeof(f->fractal_d_y_min));
}

void fill_standard_values(t_fractal *f)
{
	if (f->fractal_type == FRACTAL_JULIA)
	{
		f->dreal.y = -2.0;
		f->dreal.x = 2.0;
		f->dimag.y = -2.0;
		f->dimag.x = f->dimag.y + (f->dreal.x - f->dreal.y) * IMAGE_HEIGHT / IMAGE_WIDTH;
	}
	else if (f->fractal_type == FRACTAL_MANDELBROT)
	{
		f->dreal.y = -2.0;
		f->dreal.x = 1.0;
		f->dimag.y = -1.5;
		f->dimag.x = f->dimag.y + (f->dreal.x - f->dreal.y) * IMAGE_HEIGHT / IMAGE_WIDTH;
	}
	else 
	{
		f->dreal.y = -2.0;
		f->dreal.x = 1.0;
		f->dimag.x = -1.5;
		f->dimag.y = f->dimag.x + (f->dreal.x - f->dreal.y) * IMAGE_HEIGHT / IMAGE_WIDTH;
	}
}

int extract_fractal_extras(t_fractal *f, int argc, char **argv)
{
	if (f->fractal_type == FRACTAL_JULIA)
	{
		f->julia_c.x = -0.8;
 		f->julia_c.y = 0.2;
		if (argc == 4 || argc == 6)
		{
			if (!check_double_format(argv[2]) && !check_double_format(argv[3]))
			{
				f->julia_c.x = custom_atof(argv[2]);
				f->julia_c.y = custom_atof(argv[3]);
				if (f->julia_c.x < -2.0 || f->julia_c.x > 2.0)
					return (FALSE);
				if (f->julia_c.y < -2.0 || f->julia_c.y > 2.0)
					return (FALSE);
			}
			else if (check_color_format(argv[2]) && check_color_format(argv[3]) && argc == 4)
				return (TRUE);
			else
				return (FALSE);
		}
	}
	return (TRUE);
}
int extract_user_colors_julia(t_fractal *f, int argc, char **argv)
{
	if (argc == 4)
	{
		if (!check_double_format(argv[2]) && !check_double_format(argv[3]))
			return (TRUE);
		else if (check_color_format(argv[2]) && check_color_format(argv[3]) && argc == 4)
		{
			f->color_a = hex_string_to_int(argv[2]);
			f->color_b = hex_string_to_int(argv[3]);
		}
		else
			return (FALSE);
	}
	else if (argc == 6)
	{
		if (check_color_format(argv[4]) && check_color_format(argv[5]))
		{
			f->color_a = hex_string_to_int(argv[4]);
			f->color_b = hex_string_to_int(argv[5]);
		}
		else
			return (FALSE);
	}
	return (TRUE);
}

int extract_user_colors(t_fractal *f, int argc, char **argv)
{
	f->color_a = COLOR_CYAN;
	f->color_b = COLOR_DARK_RED;
	if (f->fractal_type == FRACTAL_JULIA)
		return (extract_user_colors_julia(f, argc, argv));
	else
	{
		if (argc == 4)
		{
			if (check_color_format(argv[2]) && check_color_format(argv[3]))
			{
				f->color_a = hex_string_to_int(argv[2]);
				f->color_b = hex_string_to_int(argv[3]);
			}
			else
				return (FALSE);
		}
		else if (argc == 6)
			return (FALSE);
	}
	return (TRUE);
}

void set_gradient_colors(t_fractal *f)
{
    int i;
    double fraction;
    int  start_r, start_g, start_b;
    int  end_r, end_g, end_b;

    start_r = (f->color_a >> 16) & 0xFF;
    start_g = (f->color_a >> 8) & 0xFF;
    start_b = f->color_a & 0xFF;

    end_r = (f->color_b >> 16) & 0xFF;
    end_g = (f->color_b >> 8) & 0xFF;
    end_b = f->color_b & 0xFF;

    for (i = 0; i < f->iterations; i++)
    {
		f->color_range[i] = 0;
        fraction = (double)i / (f->iterations - 1);

        int r = start_r + fraction * (end_r - start_r);
        int g = start_g + fraction * (end_g - start_g);
        int b = start_b + fraction * (end_b - start_b);

        f->color_range[i] = (r << 16) | (g << 8) | b;
    }
}

void  init_fractal(t_fractal *f, int argc, char **argv)
{
	f->fractal_type = get_fractal_type(argv[1]);
	if (f->fractal_type == FRACTAL_INVALID)
		return ;
	fill_standard_values(f);
	if (!extract_fractal_extras(f, argc, argv))
	{
		ft_putendl_fd("\033[31mJulia input error.\033[0m", 1);
		show_help_msg();
	}
	if (!extract_user_colors(f, argc, argv))
	{
		ft_putendl_fd("\033[31mColor input error.\033[0m", 1);
		show_help_msg();
	}
	update_mapped_coordinates(f);
	set_gradient_colors(f);
	f->color_a_edit = f->color_a;
	f->color_b_edit = f->color_b;
}
