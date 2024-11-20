/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_color_a_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:38:20 by joaomigu          #+#    #+#             */
/*   Updated: 2024/11/20 14:34:00 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

/**
 * @brief Handles interaction for adjusting the
 *  blue color channel of color_a.
 * 
 * This function handles mouse interaction for 
 * modifying the blue channel of color_a. It allows 
 * the user to increase or decrease the blue channel 
 * by interacting with specific areas of the 
 * user interface or adjust it based on vertical
 *  mouse position within a designated region.
 * 
 * @param x The x-coordinate of the mouse cursor.
 * @param y The y-coordinate of the mouse cursor.
 * @param channel A pointer to the blue channel 
 * value of color_a that will be modified.
 * 
 * @return TRUE if the channel was modified, 
 * otherwise FALSE.
 */
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

/**
 * @brief Handles interaction for adjusting
 *  the green color channel of color_a.
 * 
 * This function handles mouse interaction for 
 * modifying the green channel of color_a. It allows 
 * the user to increase or decrease the green 
 * channel by interacting with specific areas of the 
 * user interface or adjust it based on vertical
 *  mouse position within a designated region.
 * 
 * @param x The x-coordinate of the mouse cursor.
 * @param y The y-coordinate of the mouse cursor.
 * @param channel A pointer to the green channel 
 * value of color_a that will be modified.
 * 
 * @return TRUE if the channel was modified, 
 * otherwise FALSE.
 */
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

/**
 * @brief Handles interaction for adjusting 
 * the red color channel of color_a.
 * 
 * This function handles mouse interaction for
 *  modifying the red channel of color_a. It allows 
 * the user to increase or decrease the red 
 * channel by interacting with specific areas of the 
 * user interface or adjust it based on vertical
 *  mouse position within a designated region.
 * 
 * @param x The x-coordinate of the mouse cursor.
 * @param y The y-coordinate of the mouse cursor.
 * @param channel A pointer to the red channel 
 * value of color_a that will be modified.
 * 
 * @return TRUE if the channel was modified, 
 * otherwise FALSE.
 */
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

/**
 * @brief Handles user input for modifying 
 * the color_a channels (red, green, blue).
 * 
 * This function updates the `color_a_edit` 
 * value based on mouse interaction. It modifies the 
 * red, green, and blue channels of color_a 
 * using the user's mouse input and updates the 
 * corresponding color value. The updated 
 * color is stored back into `color_a_edit`.
 * 
 * @param x The x-coordinate of the mouse cursor.
 * @param y The y-coordinate of the mouse cursor.
 * @param s The state structure containing
 *  the current color values.
 * 
 * @return TRUE if the color was modified, 
 * otherwise FALSE.
 */
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

/**
 * @brief Applies the edited colors to color_a 
 * and color_b when the user clicks the "apply" button.
 * 
 * This function checks whether the user has 
 * modified the `color_a` or `color_b` values and, if 
 * a change has occurred, updates the stored 
 * colors. The new colors are then applied, the gradient 
 * is updated, and the graphics are re-rendered 
 * to reflect the changes.
 * 
 * @param x The x-coordinate of the mouse cursor.
 * @param y The y-coordinate of the mouse cursor.
 * @param s The state structure containing the 
 * color and graphical data.
 */
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
