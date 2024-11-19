/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fractal_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:38:54 by joaomigu          #+#    #+#             */
/*   Updated: 2024/11/19 18:11:22 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

static void	fill_standard_values(t_fractal *f)
{
	if (f->fractal_type == FRACTAL_JULIA)
	{
		f->dreal.y = -2.0;
		f->dreal.x = 2.0;
		f->dimag.y = -2.0;
		f->dimag.x = f->dimag.y + (f->dreal.x - f->dreal.y) * IMAGE_HEIGHT
			/ IMAGE_WIDTH;
	}
	else
	{
		f->dreal.y = -2.0;
		f->dreal.x = 1.0;
		f->dimag.y = -1.5;
		f->dimag.x = f->dimag.y + (f->dreal.x - f->dreal.y) * IMAGE_HEIGHT
			/ IMAGE_WIDTH;
	}
}

static int	extract_fractal_extras(t_fractal *f, int argc, char **argv)
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
			else if (check_color_format(argv[2]) && check_color_format(argv[3])
				&& argc == 4)
				return (TRUE);
			else
				return (FALSE);
		}
	}
	return (TRUE);
}

static int	extract_user_colors_julia(t_fractal *f, int argc, char **argv)
{
	if (argc == 4)
	{
		if (!check_double_format(argv[2]) && !check_double_format(argv[3]))
			return (TRUE);
		else if (check_color_format(argv[2]) && check_color_format(argv[3])
			&& argc == 4)
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

static int	extract_user_colors(t_fractal *f, int argc, char **argv)
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

void	init_fractal(t_fractal *f, int argc, char **argv)
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
