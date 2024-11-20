/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_string_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:38:12 by joaomigu          #+#    #+#             */
/*   Updated: 2024/11/20 14:11:34 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

/**
 * @brief Initializes a 5x3 array to 
 * represent an empty letter pattern.
 * 
 * This function sets all elements of
 *  the 5x3 array `src` to zero, effectively creating 
 * an empty letter pattern. The array
 *  is intended to represent a character in a 5x3 grid, 
 * and this function ensures the grid
 *  is cleared before use.
 * 
 * @param src A 5x3 integer array representing
 *  the letter's pattern to be cleared.
 */
void	empty_letter(int src[5][3])
{
	src[0][0] = 0;
	src[0][1] = 0;
	src[0][2] = 0;
	src[1][0] = 0;
	src[1][1] = 0;
	src[1][2] = 0;
	src[2][0] = 0;
	src[2][1] = 0;
	src[2][2] = 0;
	src[3][0] = 0;
	src[3][1] = 0;
	src[3][2] = 0;
	src[4][0] = 0;
	src[4][1] = 0;
	src[4][2] = 0;
}

/**
 * @brief Writes a string of characters to an 
 * image at a specified position.
 * 
 * This function iterates over the input string
 *  `str` and writes each character to an image 
 * at the given `x` and `y` coordinates. Each 
 * character is represented using a 5x3 pattern, 
 * which is fetched by the `get_character_pattern`
 *  function and then drawn onto the image 
 * using the `draw_char_to_image` function. The 
 * characters are placed side by side with a 
 * horizontal spacing of 10 pixels.
 * 
 * @param str The string of characters to be written
  to the image.
 * @param x The x-coordinate of the starting position
  for writing the string.
 * @param y The y-coordinate of the starting position
  for writing the string.
 * @param section A pointer to the `t_img` structure
  that represents the image section 
 *                where the string will be drawn.
 */
void	lib_x_write_string(char *str, int x, int y, t_img *section)
{
	int	i;
	int	letter[5][3];

	empty_letter(letter);
	i = 0;
	while (str[i])
	{
		get_character_pattern(str[i], letter);
		draw_char_to_image(x + (i * 10), y, section, letter);
		i++;
	}
}
