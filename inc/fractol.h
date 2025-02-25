/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:39:16 by joaomigu          #+#    #+#             */
/*   Updated: 2024/11/19 18:34:47 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/libft/include/libft.h"
# include "../lib/minilibx-linux/mlx.h"
# include "X11/X.h"
# include "X11/keysym.h"
# include <ctype.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>

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
}					t_fractal_type;

typedef enum e_color
{
	COLOR_BLACK = 0x000000,
	COLOR_WHITE = 0xFFFFFF,
	COLOR_RED = 0xFF0000,
	COLOR_GREEN = 0x00FF00,
	COLOR_BLUE = 0x0000FF,
	COLOR_YELLOW = 0xFFFF00,
	COLOR_CYAN = 0x00FFFF,
	COLOR_MAGENTA = 0xFF00FF,
	COLOR_ORANGE = 0xFFA500,
	COLOR_PURPLE = 0x800080,
	COLOR_PINK = 0xFFC0CB,
	COLOR_BROWN = 0xA52A2A,
	COLOR_GRAY = 0x808080,
	COLOR_DARK_RED = 0x8B0000,
	COLOR_DARK_GREEN = 0x006400,
	COLOR_DARK_BLUE = 0x00008B,
	COLOR_DARK_ORANGE = 0xFF8C00,
	COLOR_SALMON = 0xFA8072,
	COLOR_TURQUOISE = 0x40E0D0,
	COLOR_LIME = 0x00FF00,
	COLOR_VIOLET = 0xEE82EE
}					t_color;

typedef struct s_dpoint
{
	double			x;
	double			y;
}					t_dpoint;

typedef struct s_ipoint
{
	int				x;
	int				y;
}					t_ipoint;

typedef struct s_fractal
{
	t_fractal_type	fractal_type;
	t_dpoint		julia_c;
	t_dpoint		dreal;
	t_dpoint		dimag;
	t_dpoint		shift;
	double			zoomx;
	unsigned int	color_a;
	unsigned int	color_b;
	unsigned int	color_a_edit;
	unsigned int	color_b_edit;
	int				iterations;
	int				color_range[MAX_ITERATIONS];
	double			mapped_x[IMAGE_WIDTH];
	double			mapped_y[IMAGE_HEIGHT];
	char			mouse_x[4];
	char			mouse_y[4];
	char			fractal_iter[4];
	char			fractal_x[10];
	char			fractal_y[10];
	char			fractal_d_x_min[10];
	char			fractal_d_x_max[10];
	char			fractal_d_y_min[10];
	char			fractal_d_y_max[10];

}					t_fractal;

typedef struct s_img
{
	void			*img_ptr;
	char			*pixels_ptr;
	int				bpp;
	int				endian;
	int				len;
	int				top;
	int				left;
	int				section_width;
	int				section_height;
}					t_img;

typedef struct s_graphics
{
	void			*mlx_conn;
	void			*mlx_win;
	t_img			f_section;
	t_img			static_gui;
	t_img			uca_r;
	t_img			uca_g;
	t_img			uca_b;
	t_img			uca_c;
	t_img			ucb_r;
	t_img			ucb_g;
	t_img			ucb_b;
	t_img			ucb_c;
	t_img			uc_apply;
	t_img			mousehvr_section_w;
	t_img			mousehvr_section_f;
	t_img			mousehvr_section_d;
	t_img			iter_img;
	int				win_width;
	int				win_height;
}					t_graphics;

typedef struct s_state
{
	t_graphics		*g;
	t_fractal		*f;
}					t_state;

// asc_strings
void				empty_letter(int src[5][3]);
void				get_character_pattern(char c, int letter[5][3]);
void				get_pattern_a(int src[5][3]);
void				get_pattern_b(int src[5][3]);
void				get_pattern_c(int src[5][3]);
void				get_pattern_d(int src[5][3]);
void				get_pattern_e(int src[5][3]);
void				get_pattern_f(int src[5][3]);
void				get_pattern_g(int src[5][3]);
void				get_pattern_h(int src[5][3]);
void				get_pattern_i(int src[5][3]);
void				get_pattern_j(int src[5][3]);
void				get_pattern_k(int src[5][3]);
void				get_pattern_l(int src[5][3]);
void				get_pattern_m(int src[5][3]);
void				get_pattern_n(int src[5][3]);
void				get_pattern_o(int src[5][3]);
void				get_pattern_p(int src[5][3]);
void				get_pattern_q(int src[5][3]);
void				get_pattern_k(int src[5][3]);
void				get_pattern_r(int src[5][3]);
void				get_pattern_s(int src[5][3]);
void				get_pattern_t(int src[5][3]);
void				get_pattern_u(int src[5][3]);
void				get_pattern_v(int src[5][3]);
void				get_pattern_w(int src[5][3]);
void				get_pattern_x(int src[5][3]);
void				get_pattern_y(int src[5][3]);
void				get_pattern_z(int src[5][3]);
void				get_pattern_zero(int src[5][3]);
void				get_pattern_one(int src[5][3]);
void				get_pattern_two(int src[5][3]);
void				get_pattern_three(int src[5][3]);
void				get_pattern_four(int src[5][3]);
void				get_pattern_five(int src[5][3]);
void				get_pattern_six(int src[5][3]);
void				get_pattern_seven(int src[5][3]);
void				get_pattern_eight(int src[5][3]);
void				get_pattern_nine(int src[5][3]);
void				get_pattern_hash(int src[5][3]);
void				get_pattern_plus(int src[5][3]);
void				get_pattern_minus(int src[5][3]);
void				get_pattern_dot(int src[5][3]);

// write_string.c
void				lib_x_write_string(char *str, int x, int y, t_img *section);

// t_fractal_init.c
void				init_fractal(t_fractal *f, int argc, char **argv);

// t_fractal_aux.c
void				clean_f(t_fractal *f);
void				update_mapped_coordinates(t_fractal *f);
void				set_gradient_colors(t_fractal *f);
t_fractal_type		get_fractal_type(char *input);
char				*get_fractal_string(t_fractal_type fractal_type);

// parser.c
int					check_color_format(char *str);
int					check_double_format(char *str);

// fractol.c
void				show_help_msg(void);
void				clean_init(t_state *s);

// math_aux.c
unsigned int		hex_string_to_int(char *hex_string);
int					calc_mandelbrot(double cr, double ci, int max_iter);
int					calc_julia(t_fractal *f, double zr, double zi);
int					calc_burning_ship(double cr, double ci, int max_iter);

// double.aux
double				custom_atof(char *str);

// custom_itoa_f.c
void				calc_axis(t_state *s);
void				calc_mouse_coord(int x, int y, t_state *s);
void				calc_fractal_coord(int x, int y, t_state *s);
void				calc_iter(t_state *s);

// render.aux
char				get_col_top(int i);
void				fill_rect(t_img *section, t_ipoint pos, t_ipoint dim,
						int color);
void				draw_rect(t_img *section, t_ipoint pos, t_ipoint dim);

// render_gui.c
void				init_ui(t_state *s);

// render_dynamic.c
void				draw_mouse_hover_elements(t_state *s);
void				draw_mouse_hover_dimensions(t_state *s);
void				draw_color_rect(t_state *s);
void				draw_color_rect_a(t_state *s);
void				draw_color_rect_b(t_state *s);
void				draw_iter(t_state *s);

// render_fractal
void				render_graphics(t_state *s);

// t_graphics_init.c
void				clean_g(t_graphics *g);
int					init_graphics(t_state *s);

// t_graphics_free
int					check_sections(t_graphics *g);
void				free_sections(t_graphics *g);

// events_init
void				init_events(t_state *s);
int					mouse_move_handler(int x, int y, t_state *s);
int					key_handler(int keysym, t_state *s);
int					mouse_handler(int button, int x, int y, t_state *s);
int					close_handler(t_state *s);

// events_color.c
void				draw_apply(t_state *s);
void				user_apply(int x, int y, t_state *s);

// events.c
int					user_color_a(int x, int y, t_state *s);
int					user_color_b(int x, int y, t_state *s);

// events_aux.c
int					key_handler_iter_check(int keysym, t_state *s);
int					key_handler_pan_check(int keysym, t_state *s);
void				zoom_handler(int button, int x, int y, t_state *s);
void				pan_handler(t_state *s, double distance, char direction);

void				get_character_pattern(char c, int letter[5][3]);
void				draw_char_to_image(int x, int y, t_img *section,
						int char_map[5][3]);
double				custom_atof(char *str);

#endif