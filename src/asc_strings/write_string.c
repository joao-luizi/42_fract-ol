/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:38:12 by joaomigu          #+#    #+#             */
/*   Updated: 2024/11/19 14:38:13 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void lib_x_write_string(char *str, int x, int y, t_img *section)
{
    int i;
    int letter[5][3] = {  {0, 0, 0},{0, 0, 0},
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
    i = 0;
    while (str[i])
    {   
        get_character_pattern(str[i], letter);
        draw_char_to_image(x + (i * 10), y, section, letter);
        i++;
        
    }
}


