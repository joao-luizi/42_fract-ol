/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:38:37 by joaomigu          #+#    #+#             */
/*   Updated: 2024/11/20 13:38:54 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

/**
 * @brief Checks if a character is
 *  a valid hexadecimal digit.
 * 
 * This function checks if the given
 *  character is one of the valid hexadecimal 
 * digits (0-9, a-f, A-F). It returns
 *  `TRUE` if the character is valid, 
 * otherwise returns `FALSE`.
 *
 * @param c The character to check.
 * @return `TRUE` if the character is a 
 * valid hexadecimal digit, otherwise `FALSE`.
 */
static int	is_hex_digit(char c)
{
	int		i;
	char	*hex;

	hex = "abcdefABCDEF0123456789";
	i = 0;
	while (hex[i])
	{
		if (c == hex[i])
			return (TRUE);
		i++;
	}
	return (FALSE);
}

/**
 * @brief Validates if the given string 
 * represents a valid color in hexadecimal format.
 * 
 * This function checks if the given string
 *  is a valid hexadecimal color code. 
 * A valid color code should start with "0x"
 *  followed by exactly six valid hexadecimal digits.
 *
 * @param str The string to validate.
 * @return `TRUE` if the string is a valid 
 color code in the "0xRRGGBB" format, otherwise `FALSE`.
 */
int	check_color_format(char *str)
{
	int	i;
	int	length;

	length = ft_strlen(str);
	if (length < 2 || (str[0] != '0' && str[1] != 'x'))
		return (FALSE);
	length -= 2;
	if (length != 6)
		return (FALSE);
	i = 2;
	while (str[i])
	{
		if (!is_hex_digit(str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

/**
 * @brief Helper function to count the digits
 *  before and after the decimal point in a string.
 * 
 * This function checks if the character is 
 * a digit and updates the counters for 
 * digits before and after the decimal point.
 *  It handles the presence of a decimal 
 * point to differentiate between the two parts of a number.
 *
 * @param digit_before Pointer to the count
 *  of digits before the decimal point.
 * @param digit_after Pointer to the count 
 * of digits after the decimal point.
 * @param c The character to check.
 * @param has_point A flag indicating if a 
 * decimal point has been encountered.
 */
static void	check_digits(int *digit_before, int *digit_after, char c,
		int has_point)
{
	if (ft_isdigit(c))
	{
		if (has_point)
			(*digit_after)++;
		else
			(*digit_before)++;
	}
}

/**
 * @brief Validates if the given string
 *  represents a valid double (floating point number).
 * 
 * This function checks if the given string 
 * is a valid representation of a double number.
 * A valid double may contain digits, one 
 * decimal point, and an optional sign (+ or -).
 * The number must also have at least one 
 * digit before and one after the decimal point.
 *
 * @param str The string to validate.
 * @return `TRUE` if the string is a valid 
 * double format, otherwise `FALSE`.
 */
int	check_double_format(char *str)
{
	int	digit_before;
	int	digit_after;
	int	has_point;
	int	has_sign;
	int	i;

	digit_after = 0;
	digit_before = 0;
	has_point = 0;
	has_sign = 0;
	i = 0;
	if (!str)
		return (FALSE);
	while (str[i])
	{
		check_digits(&digit_before, &digit_after, str[i], has_point);
		if (str[i] == '.')
			has_point++;
		if (str[i] == '+' || str[i] == '-')
			has_sign++;
		i++;
	}
	return (digit_before == 0 || digit_after == 0 || digit_before > 1
		|| digit_after > 2 || has_point > 1 || has_sign > 1);
}
