#include "../inc/fractol.h"

void show_help_msg() 
{
    ft_putendl_fd("Available fractals:", 1);
	ft_putendl_fd("\tMandelbrot", 1);
	ft_putendl_fd("\tJulia", 1);
	ft_putendl_fd("\tBurningShip", 1);
    ft_putendl_fd("Usage:", 1);
    ft_putendl_fd("\033[31m./fractol <fractal_type> [a] [b] [color]\033[0m", 1);
    ft_putendl_fd("  - fractal_type: Mandelbrot, Julia or BurningShip", 1);
    ft_putendl_fd("  - a, b: Optional starting values (Julia fractal only!) (default: -0.8, 0.2; -2.0 to 2.0)", 1);
    ft_putendl_fd("  - color: Optional hexadecimal color (e.g., 0x000000)", 1);
    ft_putendl_fd("Examples:", 1);
    ft_putendl_fd("\033[31m./fractol Mandelbrot\033[0m", 1);
    ft_putendl_fd("\033[31m./fractol Julia -1.3 1.8 \"0x5733FF\"\033[0m", 1);
	exit(1);
}

void exit_error(char* msg, int fd)
{
	ft_putstr_fd(msg, fd);
	exit(1);
}


void clean_init(t_state *s)
{
	
	clean_f(s->f);
	clean_g(s->g);
	
}

int main(int argc, char **argv)
{
    t_graphics  g;
    t_fractal   f;
    t_state     s;

    if (argc != 2 && argc != 4 && argc != 6)
        show_help_msg();
    s.f = &f;
    s.g = &g;
    clean_init(&s);
    init_fractal(&f, argc, argv);
    if (f.fractal_type == FRACTAL_INVALID)
        show_help_msg();
    if (init_graphics(&s))
    {
        init_ui(&s);
        init_events(&s);
        render_graphics(&s);
        mlx_loop(g.mlx_conn); 
    }
    return (0);
}


