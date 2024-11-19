/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:38:34 by joaomigu          #+#    #+#             */
/*   Updated: 2024/11/19 18:00:13 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

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
