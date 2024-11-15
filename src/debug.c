#include "../../inc/fractol.h"


void visualize_color_scheme(void *mlx, void *win, t_fractal *f)
{
    int color_width;
    int i;
    int x;
    int y;

    // Calculate how many pixels each color in color_range covers
    color_width = IMAGE_WIDTH / f->iterations * 100;
    if (color_width == 0)
        color_width = 1;
    ft_printf("Color Width is %d", color_width);
    x = 5;
    for (i = 0; i < f->iterations; i++)
    {
        int color = f->color_range[i];

        // Draw each color over the calculated width
        for (int j = 0; j < color_width; j++)
        {
            y = 5;
            while (y < 5 + 20)
            {
                mlx_pixel_put(mlx, win, x + j, y, color);
                y++;
            }
        }
        x += color_width; // Move to the next position for the next color
    }
}

void print_mapped_coordinates(t_fractal *f)
{
    int y;
    int x;

    y = 0;
    while (y < IMAGE_HEIGHT)
    {
        x = 0;
        while (x < IMAGE_WIDTH)
        {
            printf("Screen (x, y): (%d, %d) -> Real: %f, Imaginary: %f\n",
                   x, y, f->mapped_x[x], f->mapped_y[y]);
            x++;
        }
        y++;
    }
}