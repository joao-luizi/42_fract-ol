/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_itoa_f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:38:29 by joaomigu          #+#    #+#             */
/*   Updated: 2024/11/20 13:56:44 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

/**
 * @brief Custom implementation of 
 * integer-to-string conversion.
 * 
 * This function converts a double value
 *  into a string representation of its integer part.
 * It handles negative numbers by adding a 
 * minus sign and stores the integer part in the provided `dst` buffer.
 * The function also stores a decimal point
 *  after the integer part, but no decimal digits are added.
 *
 * @param dst The destination buffer where 
 the string representation will be stored.
 * @param value The double value to be 
 converted to a string.
 */
static void	custom_itoa(char *dst, double value)
{
	int	sign;

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

/**
 * @brief Custom implementation of 
 * floating-point-to-string conversion.
 * 
 * This function converts a double value 
 * into a string representation of both
 *  its integer and fractional parts.
 * It handles negative values by making
 *  them 
 * positive and stores the result in the
 *  provided `dst` buffer.
 * It assumes a precision of 6 decimal 
 * places and stores the fractional part accordingly.
 *
 * @param dst The destination buffer where 
 * the string representation will be stored.
 * @param value The double value to be 
 * converted to a string.
 */
static void	custom_ftoa(char *dst, double value)
{
	int	pow;
	int	integer;
	int	i;

	if (value < 0)
		value *= -1;
	integer = (int)value;
	pow = (1 + (value - integer)) * 1000000;
	i = 8;
	while (pow >= 10)
	{
		dst[i--] = pow % 10 + '0';
		pow /= 10;
	}
	dst[9] = '\0';
}

/**
 * @brief Calculates and converts the fractal
 *  coordinates for a given point in the fractal.
 * 
 * This function calculates the fractal coordinates
 *  for the x and y values corresponding to
 * a specific point in the fractal, and converts 
 * these coordinates into their string representation
 * using both integer and floating-point conversion 
 * functions (`custom_itoa` and `custom_ftoa`).
 * 
 * The x-coordinate is obtained from `s->f->mapped_x[x]`
 *  and the y-coordinate is obtained from
 * `s->f->mapped_y[y]`, where the y-coordinate is 
 * multiplied by -1 to invert its direction.
 *
 * @param x The x-coordinate index in the mapped fractal space.
 * @param y The y-coordinate index in the mapped fractal space.
 * @param s The state object containing the fractal data and coordinate mappings.
 */
void	calc_fractal_coord(int x, int y, t_state *s)
{
	custom_itoa(s->f->fractal_x, s->f->mapped_x[x]);
	custom_ftoa(s->f->fractal_x, s->f->mapped_x[x]);
	custom_itoa(s->f->fractal_y, s->f->mapped_y[y] * -1);
	custom_ftoa(s->f->fractal_y, s->f->mapped_y[y] * -1);
}

/**
 * @brief Converts mouse coordinates into string format.
 * 
 * This function takes the mouse cursor's x 
 * and y screen coordinates and converts them into a
 * 3-digit string format, which is stored in 
 * `s->f->mouse_x` and `s->f->mouse_y`.
 * The x and y coordinates are stored as characters
 *  representing their digits in reverse order.
 *
 * The mouse coordinates are split into individual
 *  digits and stored in the `mouse_x` and `mouse_y` arrays
 * for further display or processing.
 * 
 * @param x The x-coordinate of the mouse cursor on the screen.
 * @param y The y-coordinate of the mouse cursor on the screen.
 * @param s The state object that holds the mouse 
 * coordinates as strings.
 */
void	calc_mouse_coord(int x, int y, t_state *s)
{
	int	i;

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

/**
 * @brief Converts the fractal axis limits 
 * into string format.
 * 
 * This function takes the maximum and minimum 
 * values of the fractal axes and converts
 * these values into string representations for
 *  both the real and imaginary axes.
 * The conversion is performed using both integer 
 * and floating-point conversion functions (`custom_itoa` and `custom_ftoa`).
 * 
 * The function processes the following values:
 * - `s->f->fractal_d_x_max` and 
 * `s->f->fractal_d_x_min` for the x-axis.
 * - `s->f->fractal_d_y_max` and 
 * `s->f->fractal_d_y_min` for the y-axis.
 * 
 * Each of these values is converted 
 * into its string representation and stored in `s->f->dreal.x`, 
 * `s->f->dreal.y`, `s->f->dimag.x`, and `s->f->dimag.y`
 *  respectively.
 *
 * @param s The state object containing the
 *  fractal axis limits.
 */
void	calc_axis(t_state *s)
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
