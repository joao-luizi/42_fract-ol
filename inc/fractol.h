#ifndef FRACTAL_O_H
#define FRACTAL_O_H

# include "../lib/libft/include/libft.h"
# include "../lib/minilibx-linux/mlx.h"
# include "X11/X.h"
# include "X11/keysym.h"
# include "asc_strings.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <stdbool.h>
# include <sys/time.h>
# include <time.h>
# include <limits.h>
# include <float.h>
# include <stdio.h>

# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 900
# define IMAGE_WIDTH 800
# define IMAGE_HEIGHT 800
# define MAX_ITERATIONS 100



typedef enum e_fractal_type
{
    FRACTAL_INVALID = -1,
    FRACTAL_MANDELBROT,
    FRACTAL_JULIA,
    FRACTAL_BURNING_SHIP
} t_fractal_type;

typedef enum e_color 
{
    COLOR_BLACK       = 0x000000, // Black
    COLOR_WHITE       = 0xFFFFFF, // White
    COLOR_RED         = 0xFF0000, // Red
    COLOR_GREEN       = 0x00FF00, // Green
    COLOR_BLUE        = 0x0000FF, // Blue
    COLOR_YELLOW      = 0xFFFF00, // Yellow
    COLOR_CYAN        = 0x00FFFF, // Cyan
    COLOR_MAGENTA     = 0xFF00FF, // Magenta
    COLOR_ORANGE      = 0xFFA500, // Orange
    COLOR_PURPLE      = 0x800080, // Purple
    COLOR_PINK        = 0xFFC0CB, // Pink
    COLOR_BROWN       = 0xA52A2A, // Brown
    COLOR_GRAY        = 0x808080, // Gray
    COLOR_DARK_RED    = 0x8B0000, // Dark Red
    COLOR_DARK_GREEN  = 0x006400, // Dark Green
    COLOR_DARK_BLUE   = 0x00008B, // Dark Blue
    COLOR_DARK_ORANGE = 0xFF8C00, // Dark Orange
    COLOR_SALMON      = 0xFA8072, // Salmon
    COLOR_TURQUOISE   = 0x40E0D0, // Turquoise
    COLOR_LIME        = 0x00FF00, // Lime
    COLOR_VIOLET      = 0xEE82EE  // Violet
} t_color;


typedef struct s_dpoint
{
    double  x;
    double  y;
}   t_dpoint;

typedef struct s_ipoint
{
    int  x;
    int  y;
}   t_ipoint;

typedef struct s_fractal
{
    t_fractal_type	fractal_type;
    t_dpoint        julia_c;
    t_dpoint        dreal;
    t_dpoint        dimag;
    t_dpoint        shift;
    double          zoomx;
    unsigned int    color_a;
    unsigned int    color_b;
    unsigned int    color_a_edit;
    unsigned int    color_b_edit;
    int             iterations;
    int             color_range[MAX_ITERATIONS];
    double          mapped_x[IMAGE_WIDTH];
    double          mapped_y[IMAGE_HEIGHT];
    char            mouse_x[4];
    char            mouse_y[4];
    char            fractal_x[10];
    char            fractal_y[10];
    char            fractal_d_x_min[10];
    char            fractal_d_x_max[10];
    char            fractal_d_y_min[10];
    char            fractal_d_y_max[10];

} t_fractal;


typedef struct s_img
{
    void    *img_ptr;
    char    *pixels_ptr;
    int     bpp;
	int 	endian;
	int 	len;
    int     top;
    int     left;
    int     section_width;
    int     section_height;
}	t_img;

typedef struct s_graphics
{
	void	*mlx_conn;        
	void	*mlx_win;        
	t_img	f_section;
    t_img	static_gui;
    t_img	uca_r;
    t_img	uca_g;
    t_img	uca_b;
    t_img   uca_c;
    t_img	ucb_r;
    t_img	ucb_g;
    t_img	ucb_b;
    t_img   ucb_c;
    t_img   uc_apply;
    t_img	mousehvr_section_w;
    t_img	mousehvr_section_f;
    t_img	mousehvr_section_d;
    int     win_width;
    int     win_height;
}	t_graphics;

typedef struct s_state
{
	t_graphics *g;
    t_fractal *f;
}	t_state;

//debug
void            print_mapped_coordinates(t_fractal *f);
void            visualize_color_scheme(void *mlx, void *win, t_fractal *f);
// write_string.c
void            lib_x_write_string(char *str, t_ipoint pos, t_img *section);

//t_fractal_init.c
void			clean_f(t_fractal *f);
void			init_fractal(t_fractal *f, int argc, char **argv); 

//t_fractal_aux.c
void			update_mapped_coordinates(t_fractal *f);
void            set_gradient_colors(t_fractal *f);

//fractol.c
void			show_help_msg();

//math_aux.c
unsigned int	hex_string_to_int(char *hex_string);

//render_gui
void draw_mouse_hover_elements(t_state *s);
void draw_static_elements(t_img *section);
void draw_static_string(t_img *section, char *f_name);
void draw_mouse_hover_dimensions(t_state *s);
void draw_rect(t_img *section, t_ipoint pos, t_ipoint dim);
void fill_rect(t_img *section, t_ipoint pos, t_ipoint dim, int color);
void draw_color_a_rect(t_state *s);
void draw_color_b_rect(t_state *s);

//render_fractal
void render_graphics(t_state *s);

//t_graphics_init.c
void    clean_g(t_graphics *g);
int     init_graphics(t_state *s);
void    init_ui(t_state *s);

//t_graphics_free
int check_sections(t_graphics *g);
void free_sections(t_graphics *g);

//events_init
void init_events(t_state *s);
int close_handler(t_state *s);

//events.c
int	mouse_move_handler(int x, int y, t_state *s);
int count_digits(int i);
void draw_apply(t_state *s);

//custim_itoa_f.c
void calc_mouse_coord(int x, int y, t_state *s);
void calc_fractal_coord(int x, int y, t_state *s);
void calc_axis(t_state *s);
void custom_ftoa(char *dst, double value);
void custom_itoa(char *dst, double value);

void            get_character_pattern(char c, int letter[5][3]);
void            draw_char_to_image(int x, int y, t_img *section, int char_map[5][3]);



int	            calc_mandelbrot(double cr, double ci, int max_iter);
int	            calc_julia(t_fractal *f, double zr, double zi);
int	            calc_burning_ship(double cr, double ci, int max_iter);

char 			*get_fractal_string(t_fractal_type fractal_type);
t_fractal_type	get_fractal_type(char *input);
void 			print_fractal(t_fractal *fractal);





//void 			init_graphics(t_fractal fractal, t_graphics *graphics);
//void            render_graphics(t_fractal *fractal, t_graphics *graphics);

int             key_handler(int keysym, t_state *s);

int             mouse_handler(int button, int x, int y, t_state *s);


double          map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_dpoint        vector_sum(t_dpoint v1, t_dpoint v2);
t_dpoint	    vector_square(t_dpoint v);

int 			check_color_format(char *str);
int				check_double_format(char *str);
int 			hex_to_int(char *hex_string);

double 			custom_atof(char *str);
//t_dpoint        get_z(t_fractal_type ftype, t_dpoint z, t_dpoint c);

#endif