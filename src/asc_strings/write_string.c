#include "../inc/fractol.h"

void lib_x_write_string(char *str, t_ipoint pos, t_img *section)
{
    int i;
    int letter[5][3] = {  {0, 0, 0},{0, 0, 0},
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
    i = 0;
    while (str[i])
    {   
        get_character_pattern(str[i], letter);
        draw_char_to_image(pos.x + (i * 10), pos.y, section, letter);
        i++;
        
    }
}


