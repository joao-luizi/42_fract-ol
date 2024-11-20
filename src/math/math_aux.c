/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:38:34 by joaomigu          #+#    #+#             */
/*   Updated: 2024/11/20 13:47:34 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

/**
 * @brief Calculates the Mandelbrot 
 * set iteration count for a given point.
 * 
 * This function calculates the number
  of iterations it takes for a point 
 * (specified by the real and imaginary
  parts `cr` and `ci`) to escape 
 * the Mandelbrot set, based on the provided
  maximum iteration limit.
 * The iteration count is returned when the
  point escapes, or the 
 * maximum iteration count is reached.
 *
 * @param cr The real part of the point.
 * @param ci The imaginary part of the point.
 * @param max_iter The maximum number of iterations
 *  to compute.
 * @return The number of iterations before escaping,
 *  or `max_iter` if the point does not escape.
 */
int	calc_mandelbrot(double cr, double ci, int max_iter)
{
	int		n;
	double	zr;
	double	zi;
	double	tmp;

	zr = 0;
	zi = 0;
	n = 0;
	while (n < max_iter)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		tmp = (2 * zr * zi + ci);
		zr = (zr * zr - zi * zi + cr);
		zi = tmp;
		n++;
	}
	return (n);
}

/**
 * @brief Calculates the Julia set
 *  iteration count for a given point.
 * 
 * This function calculates the number
 *  of iterations it takes for a point 
 * (specified by `zr` and `zi`) to escape
 *  the Julia set, based on the given 
 * Julia constant `f->julia_c` and the 
 * maximum iteration limit `f->iterations`. 
 * The iteration count is returned when 
 * the point escapes, or the maximum iteration 
 * count is reached.
 *
 * @param f The fractal structure containing
 *  parameters for the Julia set.
 * @param zr The real part of the point.
 * @param zi The imaginary part of the point.
 * @return The number of iterations before 
 * escaping, or `f->iterations` if the point does not escape.
 */
int	calc_julia(t_fractal *f, double zr, double zi)
{
	int		n;
	double	tmp;

	n = 0;
	tmp = 0;
	while (n < f->iterations)
	{
		if ((zi * zi + zr * zr) > 4.0)
			break ;
		tmp = 2 * zr * zi + f->julia_c.y;
		zr = zr * zr - zi * zi + f->julia_c.x;
		zi = tmp;
		n++;
	}
	return (n);
}

/**
 * @brief Calculates the Burning Ship 
 * fractal iteration count for a given point.
 * 
 * This function calculates the number
 *  of iterations it takes for a point 
 * (specified by the real and imaginary 
 * parts `cr` and `ci`) to escape 
 * the Burning Ship fractal, based on the
 *  provided maximum iteration limit. 
 * The iteration count is returned when 
 * the point escapes, or the maximum 
 * iteration count is reached. Unlike Mandelbrot,
 *  the Burning Ship fractal 
 * applies the absolute value operation to both
 *  the real and imaginary parts.
 *
 * @param cr The real part of the point.
 * @param ci The imaginary part of the point.
 * @param max_iter The maximum number of iterations 
 * to compute.
 * @return The number of iterations before escaping,
 *  or `max_iter` if the point does not escape.
 */
int	calc_burning_ship(double cr, double ci, int max_iter)
{
	int		n;
	double	zr;
	double	zi;
	double	tmp;

	zr = 0;
	zi = 0;
	n = 0;
	while (n < max_iter)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		zr = fabs(zr);
		zi = fabs(zi);
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
		n++;
	}
	return (n);
}

/**
 * @brief Converts a hexadecimal
 *  string to an unsigned integer.
 * 
 * This function converts a string 
 * representing a hexadecimal number 
 * (e.g., "0x1F3") into its corresponding
 *  unsigned integer value. 
 * It assumes the string starts with 
 "0x" and processes the following 
 * characters as hexadecimal digits.
 *
 * @param hex_string The hexadecimal 
 * string to convert.
 * @return The corresponding unsigned 
 * integer value.
 */
unsigned int	hex_string_to_int(char *hex_string)
{
	unsigned int	result;
	char			c;
	int				i;

	result = 0;
	i = 2;
	while (hex_string[i])
	{
		c = hex_string[i];
		if (ft_isdigit(c))
			result = result * 16 + (c - '0');
		else if (ft_isalpha(c))
			result = result * 16 + (ft_toupper(c) - 'A' + 10);
		i++;
	}
	return (result);
}

/**
 * @brief Calculates the fractal iteration 
 * digits for the state.
 * 
 * This function computes the fractal iteration
 *  count digits and stores them 
 * in `s->f->fractal_iter`. The iteration count
 *  is broken down into individual 
 * digits and stored in reverse order, starting 
 * from the least significant digit.
 *
 * @param s The state structure containing the 
 * fractal iteration count.
 */
void	calc_iter(t_state *s)
{
	int	i;
	int	x;

	x = s->f->iterations;
	i = 2;
	while (i >= 0)
	{
		s->f->fractal_iter[i] = (x % 10) + '0';
		x /= 10;
		i--;
	}
}
