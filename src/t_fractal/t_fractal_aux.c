#include "../../inc/fractol.h"

int	calc_mandelbrot(double cr, double ci, int max_iter)
{
	int		n;
	double	zr;
	double	zi;
	double	tmp;

	zr = 0;
	zi = 0;
	n = 0;
	while (n < max_iter)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
		n++;
	}
	return (n);
}

int	calc_julia(t_fractal *f, double zr, double zi)
{
	int		n;
	double	tmp;

	n = 0;
	tmp = 0;
	
	while (n < f->iterations)
	{
		if ((zi * zi + zr * zr) > 4.0)
			break ;
		tmp = 2 * zr * zi + f->julia_c.y;
		zr = zr * zr - zi * zi + f->julia_c.x;
		zi = tmp;
		n++;
	}
	return (n);
}

int	calc_burning_ship(double cr, double ci, int max_iter)
{
	int		n;
	double	zr;
	double	zi;
	double	tmp;

	zr = 0;
	zi = 0;
	n = 0;
	while (n < max_iter)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		zr = fabs(zr);
		zi = fabs(zi);
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
		n++;
	}
	return (n);
}

void update_mapped_coordinates(t_fractal *f)
{
	int y;
	int x;

	y = 0;
	x = 0;
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
}

t_fractal_type get_fractal_type(char *input) 
{
    if (ft_strncmp(input, "Mandelbrot",10) == 0)
        return FRACTAL_MANDELBROT;
    else if (ft_strncmp(input, "Julia", 5) == 0)
        return FRACTAL_JULIA;
    else if (ft_strncmp(input, "BurningShip",11) == 0)
        return FRACTAL_BURNING_SHIP;
    else
        return FRACTAL_INVALID;
}

char *get_fractal_string(t_fractal_type fractal_type) 
{
	if (fractal_type == FRACTAL_MANDELBROT)
        return "Mandelbrot";
	else if (fractal_type == FRACTAL_JULIA)
        return "Julia";
	else if (fractal_type == FRACTAL_BURNING_SHIP)
        return "Burning Ship";
	else
        return "Invalid";
}

void print_fractal(t_fractal *fractal) 
{
    if (!fractal) {
        ft_printf("Fractal is NULL.\n");
        return;
    }
	ft_printf("Fractal Type: %s\n", get_fractal_string(fractal->fractal_type));

    printf("a: %.2f\n", fractal->julia_c.x);
    printf("b: %.2f\n", fractal->julia_c.y);
   
}
