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


