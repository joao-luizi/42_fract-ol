/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patterns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:38:09 by joaomigu          #+#    #+#             */
/*   Updated: 2024/11/19 14:38:10 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void paint_pixel(t_img *section, int pixel_size, t_ipoint pos, int color)
{
    int py;
    int px;
    int *data;

    data = (int *)section->pixels_ptr;
    py = 0;
    while (py < pixel_size)
    {
        px = 0;
        while(px < pixel_size)
        {
            data[(pos.y + py) * section->section_width + (pos.x + px)] = color;
            px++;
        }
        py++;
    }
}
void draw_char_to_image(int offset_x, int offset_y, t_img *section, int char_map[5][3])
{
    t_ipoint pos;
    int pixel_size = 3; 
    int j;
    int i;
    
    j = 0;
    while (j < 5)
    {
        i = 0;
        while (i < 3)
        {
            pos.x = offset_x + (i * pixel_size);
            pos.y = offset_y + (j * pixel_size);
            if (char_map[j][i] == 1) 
                paint_pixel(section, pixel_size, pos, 0xFFFFFFFF);
            else
                paint_pixel(section, pixel_size, pos, 0x00000000);
            i++;
        }
        j++;
    }
}

void fill_pattern(int src[5][3], int dst[5][3])
{
    int i;
    int j;

   
    i = 0;
    j = 0;
    while (i < 5)
    {
        j = 0;
        while (j < 3)
        {
            dst[i][j] = src[i][j];
            j++;
        }
        i++;
    }
}

void get_character_pattern(char c, int letter[5][3])
{
    if ((c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))
        get_pattern_a_f(c, letter);
    if ((c >= 'g' && c <= 'l') || (c >= 'G' && c <= 'L'))
        get_pattern_g_l(c, letter);
    if ((c >= 'm' && c <= 'r') || (c >= 'M' && c <= 'R'))
        get_pattern_m_r(c, letter);
    if ((c >= 's' && c <= 'x') || (c >= 'S' && c <= 'X'))
        get_pattern_s_x(c, letter);
    if ((c >= 'y' && c <= 'z') || (c >= 'Y' && c <= 'Z'))
        get_pattern_y_z(c, letter);
    if (c >= '0' && c <= '5')
        get_pattern_0_5(c, letter);
    if (c >= '6' && c <= '9')
        get_pattern_6_9(c, letter);
    if (c == '#' || c == '+' || c == '-' || c == ' ' || c == '.')
        get_pattern_signs(c, letter);

}
