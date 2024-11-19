/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:38:31 by joaomigu          #+#    #+#             */
/*   Updated: 2024/11/19 14:38:32 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void get_integer_part(char **str, double *result)
{
	while (ft_isdigit(**str))
	{
		*result = *result * 10 + (**str - '0');
		(*str)++;
	}
}

static void get_decimal_part(char **str, double *result)
{
	double decimal_place;

	decimal_place = 0.1;
	if (**str == '.')
	{
		(*str)++;
		while (ft_isdigit(**str))
		{	
			*result = *result + (**str - '0') * decimal_place;
			decimal_place /= 10;
			(*str)++;
		}
	}
}

/**
 * @brief Converts a string to a floating-point number, with error handling for invalid formats.
 * 
 * @param str Input string to convert.
 * @param error Pointer to the error flag (set to TRUE if the string is not a valid floating-point number).
 * @return double The converted floating-point number (or 0.0 if an error occurred).
 */
double custom_atof(char *str)
{
	double result;
	int sign;

	result = 0.0;
	sign = 1;
	while (ft_iswhitespace(*str))
		str++;
	if (*str == '+' || *str == '-')
    {
        if (*str == '-')
			sign *= -1;
        str++;
    }
	get_integer_part(&str, &result);
	get_decimal_part(&str, &result);
	return (sign * result);
}
