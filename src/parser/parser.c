#include "../../inc/fractol.h"
static int is_hex_digit(char c)
{
	int i;

	i = 0;
	char hex[] = "abcdefABCDEF0123456789";
	while (hex[i])
	{
		if (c == hex[i])
			return (TRUE);
		i++;
	}
	return (FALSE);
}
int check_color_format(char *str)
{
	int i;
    int length;

	length = ft_strlen(str);
    if (length == 0 || (str[0] != '0' && str[1] != 'x'))
		return (FALSE);
	length -=2;
	if (length != 8)
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
 * @brief Checks if the character is a digit and increments 
 * the count of digits before or after the decimal point.
 * 
 * @param digit_before Pointer to the count of digits before the decimal point.
 * @param digit_after Pointer to the count of digits after the decimal point.
 * @param c The current character in the string.
 * @param has_point Flag indicating whether a decimal point has been encountered.
 */
static void check_digits(int *digit_before, int *digit_after, char c, int has_point)
{
	if (ft_isdigit(c))
	{
		if (has_point)
			(*digit_after)++;
		else
			(*digit_before)++;
	}
}

int check_double_format(char *str)
{
	int digit_before;
	int digit_after;
	int has_point;
	int has_sign;
	int i;

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
	return (digit_before == 0 || digit_after == 0 || digit_before > 1 || digit_after > 2
		|| has_point > 1 || has_sign > 1);
}

