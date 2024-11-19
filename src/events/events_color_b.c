/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_color_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:38:23 by joaomigu          #+#    #+#             */
/*   Updated: 2024/11/19 14:38:24 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"


static int color_b_area_b(int x, int y, int *channel)
{
	if (x > 935 - 5 && x < 950 + 5)
	{
		if (y > 480 - 5 && y < 480 + 5 && *channel < 255)
		{
			(*channel)++;
			return (TRUE);
		}
		else if (y > 640 - 5 && y < 640 + 5 && *channel > 0)
		{
			(*channel)--;
			return (TRUE);
		}
	}
	if (x > 935 && x < 950 && y > 500 && y < 625)
	{
		*channel = (625 - y) * 255 / 125;
		return (TRUE);;
	}
	return (FALSE);
}

static int color_b_area_g(int x, int y, int *channel)
{
	if (x > 890 - 5 && x < 890 + 5)
	{
		if (y > 480 - 5 && y < 480 + 5 && *channel < 255)
		{
			(*channel)++;
			return (TRUE);
		}
		else if (y > 640 - 5 && y < 640 + 5 && *channel > 0)
		{
			(*channel)--;
			return (TRUE);
		}
	}
	if (x > 885 && x < 900 && y > 500 && y < 625)
	{
		*channel = (625 - y) * 255 / 125;
		return (TRUE);;
	}
	return (FALSE);
}

static int color_b_area_r(int x, int y, int *channel)
{
	if (x > 840 - 5 && x < 840 + 5)
	{
		if (y > 480 - 5 && y < 480 + 5 && *channel < 255)
		{
			(*channel)++;
			return (TRUE);
		}
		else if (y > 640 - 5 && y < 640 + 5 && *channel > 0)
		{
			(*channel)--;
			return (TRUE);
		}
	}
	if (x > 833 && x < 848 && y > 500 && y < 625)
	{
		*channel = (625 - y) * 255 / 125;
		return (TRUE);;
	}
	return (FALSE);
}

int user_color_b(int x, int y, t_state *s)
{
	int r;
	int g;
	int b;

	r = ((s->f->color_b_edit  >> 16) & 0xFF);
	g = ((s->f->color_b_edit >> 8) & 0xFF);
	b = ((s->f->color_b_edit) & 0xFF);
	if (color_b_area_r(x, y, &r) 
		|| color_b_area_g(x, y, &g)
		|| color_b_area_b(x, y, &b))
	{
		s->f->color_b_edit = r << 16 | g << 8 | b;
		ft_printf("Color_b returns TRUE\n");
		return (TRUE);
	}
	ft_printf("Color_b returns FALSe\n");
	return (FALSE);

}

void draw_apply(t_state *s)
{
	t_ipoint pos;
	t_ipoint dim;

	if (s->f->color_a != s->f->color_a_edit
		|| s->f->color_b != s->f->color_b_edit)
	{
		pos.x = 0;
		pos.y = 0;
		dim.x= 100;
		dim.y = 30;
		draw_rect(&s->g->uc_apply, pos, dim);
		pos.x = 25;
		pos.y = 8;
		lib_x_write_string("apply", 25, 8, &s->g->uc_apply);
	}
	else
	{
		pos.x = 0;
		pos.y = 0;
		dim.x= 100;
		dim.y = 30;
		fill_rect(&s->g->uc_apply, pos, dim, 0x00000000);
	}
	mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win, s->g->uc_apply.img_ptr, 840, 720);
}
