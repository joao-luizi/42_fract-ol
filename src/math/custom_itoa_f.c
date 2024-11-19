/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_itoa_f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:38:29 by joaomigu          #+#    #+#             */
/*   Updated: 2024/11/19 14:38:30 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

static void custom_itoa(char *dst, double value)
{
    int sign;
    
    sign = 1;
    if (value < 0.0)
    {
        sign = -1;
        value *= sign;
        dst[0] = '-';
    }
	else
		dst[0] = ' ';
    dst[1] = (int)value % 10 + '0';
    dst[2] = '.';
}

static void custom_ftoa(char *dst, double value)
{
    int pow;
    int integer;
	int i;

    if (value < 0)
        value *= -1;
    integer = (int)value;

    pow = (1 + (value - integer)) * 1000000;

	i = 8;
 	while(pow >= 10)
	{
		dst[i--] = pow % 10 + '0';
		pow /= 10;
	} 
	dst[9] = '\0';
}

void calc_iter(t_state *s)
{
	int i;
	int x;

	x = s->f->iterations,
	i = 2;
	while (i >= 0)
	{
		s->f->fractal_iter[i] = (x % 10) + '0';
		x /= 10;
		i--;
	}
}
void calc_fractal_coord(int x, int y, t_state *s)
{
	custom_itoa(s->f->fractal_x, s->f->mapped_x[x]);
	custom_ftoa(s->f->fractal_x, s->f->mapped_x[x]);
	custom_itoa(s->f->fractal_y, s->f->mapped_y[y]);
	custom_ftoa(s->f->fractal_y, s->f->mapped_y[y]);
}
void calc_mouse_coord(int x, int y, t_state *s)
{
	int i;

	i = 2;
	while (i >= 0)
	{
		s->f->mouse_x[i] = (x % 10) + '0';
		s->f->mouse_y[i] = (y % 10) + '0';
		x /= 10;
		y /= 10;
		i--;
	}
	
}
void calc_axis(t_state *s)
{
	custom_itoa(s->f->fractal_d_x_max, s->f->dreal.x);
	custom_ftoa(s->f->fractal_d_x_max, s->f->dreal.x);
	custom_itoa(s->f->fractal_d_x_min, s->f->dreal.y);
	custom_ftoa(s->f->fractal_d_x_min, s->f->dreal.y);
	custom_itoa(s->f->fractal_d_y_max, s->f->dimag.x);
	custom_ftoa(s->f->fractal_d_y_max, s->f->dimag.x);
	custom_itoa(s->f->fractal_d_y_min, s->f->dimag.y);
	custom_ftoa(s->f->fractal_d_y_min, s->f->dimag.y);
}
