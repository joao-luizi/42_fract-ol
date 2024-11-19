/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_color_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:38:20 by joaomigu          #+#    #+#             */
/*   Updated: 2024/11/19 17:56:54 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static int	color_a_area_b(int x, int y, int *channel)
{
	if (x > 940 - 5 && x < 940 + 5)
	{
		if (y > 200 - 5 && y < 200 + 5 && *channel < 255)
		{
			(*channel)++;
			return (TRUE);
		}
		else if (y > 360 - 5 && y < 360 + 5 && *channel > 0)
		{
			(*channel)--;
			return (TRUE);
		}
	}
	if (x > 935 && x < 950 && y > 220 && y < 345)
	{
		*channel = (345 - y) * 255 / 125;
		return (TRUE);
	}
	return (FALSE);
}

static int	color_a_area_g(int x, int y, int *channel)
{
	if (x > 890 - 5 && x < 890 + 5)
	{
		if (y > 200 - 5 && y < 200 + 5 && *channel < 255)
		{
			(*channel)++;
			return (TRUE);
		}
		else if (y > 360 - 5 && y < 360 + 5 && *channel > 0)
		{
			(*channel)--;
			return (TRUE);
		}
	}
	if (x > 885 && x < 900 && y > 220 && y < 345)
	{
		*channel = (345 - y) * 255 / 125;
		return (TRUE);
	}
	return (FALSE);
}

static int	color_a_area_r(int x, int y, int *channel)
{
	int	result;

	result = FALSE;
	if (x > 840 - 5 && x < 840 + 5)
	{
		if (y > 200 - 5 && y < 200 + 5 && *channel < 255)
		{
			(*channel)++;
			result = TRUE;
		}
		else if (y > 360 - 5 && y < 360 + 5 && *channel > 0)
		{
			(*channel)--;
			result = TRUE;
		}
	}
	if (x > 833 && x < 848 && y > 220 && y < 345)
	{
		*channel = (345 - y) * 255 / 125;
		result = TRUE;
	}
	return (result);
}

int	user_color_a(int x, int y, t_state *s)
{
	int	r;
	int	g;
	int	b;

	r = ((s->f->color_a_edit >> 16) & 0xFF);
	g = ((s->f->color_a_edit >> 8) & 0xFF);
	b = ((s->f->color_a_edit) & 0xFF);
	if (color_a_area_r(x, y, &r) || color_a_area_g(x, y, &g)
		|| color_a_area_b(x, y, &b))
	{
		s->f->color_a_edit = r << 16 | g << 8 | b;
		return (TRUE);
	}
	return (FALSE);
}

void	user_apply(int x, int y, t_state *s)
{
	if (x > 840 && x < 940 && y > 720 && y < 750)
	{
		if (s->f->color_a != s->f->color_a_edit
			|| s->f->color_b != s->f->color_b_edit)
		{
			s->f->color_a = s->f->color_a_edit;
			s->f->color_b = s->f->color_b_edit;
			draw_apply(s);
			set_gradient_colors(s->f);
			render_graphics(s);
		}
	}
}
