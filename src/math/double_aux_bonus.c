/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_aux_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:38:31 by joaomigu          #+#    #+#             */
/*   Updated: 2024/11/20 13:45:04 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

/**
 * @brief Extracts the integer part of a 
 * string representation of a number.
 * 
 * This function parses and converts the integer
 *  part of a string (starting from the current pointer
 *  in `*str`) into a `double` result.
 * It processes each digit, multiplying the result by 
 * 10 and adding the new digit, then advances the string pointer.
 *
 * @param str A pointer to the string to parse. It is
 *  updated to point to the first non-digit character.
 * @param result A pointer to the `double` where the 
 * integer part of the number will be stored.
 */
static void	get_integer_part(char **str, double *result)
{
	while (ft_isdigit(**str))
	{
		*result = *result * 10 + (**str - '0');
		(*str)++;
	}
}

/**
 * @brief Extracts the decimal part of a 
 * string representation of a number.
 * 
 * This function parses and converts the decimal
 *  part of a string (if present) into a `double` result.
 * The decimal part is handled by multiplying the 
 * current digit by the appropriate power of 10 
 * (starting from 0.1 for the first decimal place).
 * The string pointer is updated as it processes each digit.
 *
 * @param str A pointer to the string to parse. It is 
 * updated to point to the first non-digit character after the decimal point.
 * @param result A pointer to the `double` where the 
 * decimal part of the number will be added.
 */
static void	get_decimal_part(char **str, double *result)
{
	double	decimal_place;

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
 * @brief Custom implementation of `atof`
 *  to convert a string to a double.
 * 
 * This function converts a string representation
 *  of a floating-point number into a `double` value.
 * It handles the integer and decimal parts separately
 *  and also manages optional leading whitespace and signs.
 *
 * @param str The string to be converted.
 * @return The floating-point value represented 
 * by the string.
 */
double	custom_atof(char *str)
{
	double	result;
	int		sign;

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
