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
    ft_putendl_fd("  - color: Optional hexadecimal color (e.g., 0xFF000000)", 1);
    ft_putendl_fd("Examples:", 1);
    ft_putendl_fd("\033[31m./fractol Mandelbrot\033[0m", 1);
    ft_putendl_fd("\033[31m./fractol Julia -1.3 1.8 \"0xFF5733FF\"\033[0m", 1);
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
    (void)argc;
    (void)argv;
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
    //printf("Double C %f %f\n", f.julia_c.x, f.julia_c.y);
    //printf("Color %u %u\n", f.color_a, f.color_b);
    init_graphics(&s);
    
    //print_mapped_coordinates(&f);
    //visualize_color_scheme(g.mlx_conn, g.mlx_win, &f);
    init_events(&s);
    
    render_graphics(&s);
    mlx_loop(g.mlx_conn); 
    return (0);
}
// Function to draw a character to an image buffer


/* int main()
{
    void *mlx;
    void *win;
    void *img;
    char *img_data;
    int bits_per_pixel, size_line, endian;
    int pixel_size = 3; // Adjust this value to scale the character
    int color = 0xFFFFFF; // White color
	    int letter[5][3] = {
    {0, 0, 0 },
   	{0, 0, 0 },
    {0, 0, 0 },
    {0, 0, 0 },
    {0, 0, 0 },
};
    // Initialize MinilibX and create a window
    mlx = mlx_init();
    win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "Display Improved Character 0 with Image");

    // Create a new image with specified width and height
    img = mlx_new_image(mlx, IMG_WIDTH, IMG_HEIGHT);
    img_data = mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian);

    // Draw the character '0' to the image buffer
	char teste[] = "0123456789+-#";
	int i = 0;
	while (teste[i])
	{
		get_character_pattern(teste[i], letter);
		draw_char_to_image(i, (void *)img_data, IMG_WIDTH, pixel_size, color, letter);
		i++;
	}
	
    // Put the image onto the window at position (50, 50)
    mlx_put_image_to_window(mlx, win, img, 50, 50);

    // Keep the window open until the user closes it
    mlx_loop(mlx);

    // Free resources when the program exits (optional but good practice)
    mlx_destroy_image(mlx, img);
    mlx_destroy_window(mlx, win);
    return 0;
} */

/* int	main(int argc, char **argv)
{

	t_fractal	f;
	t_graphics	g;
	t_state		state;

	if (argc < 2)
		show_help_msg();
	
	clean_init(&f, &g);
	f = get_fractal(argc, argv);
	if (f.fractal_type == FRACTAL_INVALID)
		show_help_msg();
	init_graphics(f, &g);
	render_graphics(&f, &g);
	state.f = &f;
	state.g = &g;
	mlx_hook(g.mlx_win, ButtonPress, ButtonPressMask, mouse_handler, &state); 
	mlx_hook(g.mlx_win, KeyPress, KeyPressMask, key_handler, &state);
	mlx_hook(g.mlx_win, DestroyNotify, StructureNotifyMask, close_handler, &state);
	mlx_hook(g.mlx_win, MotionNotify, PointerMotionMask, mouse_move_handler, &g);
	mlx_loop(g.mlx_conn);
	return (0);
}  */

