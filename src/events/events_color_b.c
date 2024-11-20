/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_color_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:38:23 by joaomigu          #+#    #+#             */
/*   Updated: 2024/11/20 14:03:26 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

/**
 * @brief Handles interaction for adjusting
 *  the blue color channel in the user interface.
 * 
 * This function handles mouse interaction for
 *  modifying the blue channel of the color.
 * - It increases the blue channel if the mouse
 *  is in the region near the top of the bar.
 * - It decreases the blue channel if the mouse
 *  is in the region near the bottom of the bar.
 * - If the mouse is in the color adjustment area,
 *  the blue channel is set according to the vertical mouse position.
 * 
 * @param x The x-coordinate of the mouse cursor.
 * @param y The y-coordinate of the mouse cursor.
 * @param channel A pointer to the blue color 
 * channel value that will be modified.
 * 
 * @return TRUE if the channel was modified, 
 * otherwise FALSE.
 */
static int	color_b_area_b(int x, int y, int *channel)
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
		return (TRUE);
	}
	return (FALSE);
}

/**
 * @brief Handles interaction for adjusting the
 *  green color channel in the user interface.
 * 
 * This function handles mouse interaction for 
 * modifying the green channel of the color.
 * - It increases the green channel if the mouse 
 * is in the region near the top of the bar.
 * - It decreases the green channel if the mouse 
 * is in the region near the bottom of the bar.
 * - If the mouse is in the color adjustment area,
 *  the green channel is set according to the vertical mouse position.
 * 
 * @param x The x-coordinate of the mouse cursor.
 * @param y The y-coordinate of the mouse cursor.
 * @param channel A pointer to the green color channel 
 * value that will be modified.
 * 
 * @return TRUE if the channel was modified, otherwise
 *  FALSE.
 */
static int	color_b_area_g(int x, int y, int *channel)
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
		return (TRUE);
	}
	return (FALSE);
}

/**
 * @brief Handles interaction for adjusting the red
 *  color channel in the user interface.
 * 
 * This function handles mouse interaction for 
 * modifying the red channel of the color.
 * - It increases the red channel if the mouse is 
 * in the region near the top of the bar.
 * - It decreases the red channel if the mouse is 
 * in the region near the bottom of the bar.
 * - If the mouse is in the color adjustment area, 
 * the red channel is set according to the vertical mouse position.
 * 
 * @param x The x-coordinate of the mouse cursor.
 * @param y The y-coordinate of the mouse cursor.
 * @param channel A pointer to the red color channel 
 * value that will be modified.
 * 
 * @return TRUE if the channel was modified, otherwise
 *  FALSE.
 */
static int	color_b_area_r(int x, int y, int *channel)
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
		return (TRUE);
	}
	return (FALSE);
}

/**
 * @brief Handles the user input for modifying 
 * the color using mouse interaction.
 * 
 * This function updates the color by interacting 
 * with the color channels. It modifies 
 * the red, green, and blue channels based on the
 *  user's mouse interaction in the 
 * respective areas of the color selection bars.
 * - The modified color is stored back into 
 * `color_b_edit`.
 * 
 * @param x The x-coordinate of the mouse cursor.
 * @param y The y-coordinate of the mouse cursor.
 * @param s The state structure containing the 
 * current color values.
 * 
 * @return TRUE if the color was modified, 
 * otherwise FALSE.
 */
int	user_color_b(int x, int y, t_state *s)
{
	int	r;
	int	g;
	int	b;

	r = ((s->f->color_b_edit >> 16) & 0xFF);
	g = ((s->f->color_b_edit >> 8) & 0xFF);
	b = ((s->f->color_b_edit) & 0xFF);
	if (color_b_area_r(x, y, &r) || color_b_area_g(x, y, &g)
		|| color_b_area_b(x, y, &b))
	{
		s->f->color_b_edit = r << 16 | g << 8 | b;
		return (TRUE);
	}
	return (FALSE);
}

/**
 * @brief Draws the "apply" button and
 *  updates the user interface.
 * 
 * This function checks whether the user
 *  has modified either `color_a` or `color_b`. 
 * If a modification has occurred, it draws
 *  the "apply" button in the user interface. 
 * If no changes are made, the button is 
 * cleared. The "apply" button is displayed 
 * in the window at the predefined position.
 * 
 * @param s The state structure containing 
 * the graphical data and color information.
 */
void	draw_apply(t_state *s)
{
	t_ipoint	pos;
	t_ipoint	dim;

	if (s->f->color_a != s->f->color_a_edit
		|| s->f->color_b != s->f->color_b_edit)
	{
		pos.x = 0;
		pos.y = 0;
		dim.x = 100;
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
		dim.x = 100;
		dim.y = 30;
		fill_rect(&s->g->uc_apply, pos, dim, 0x00000000);
	}
	mlx_put_image_to_window(s->g->mlx_conn, s->g->mlx_win,
		s->g->uc_apply.img_ptr, 840, 720);
}
