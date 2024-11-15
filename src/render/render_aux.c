#include "../../inc/fractol.h"


void draw_rect(t_img *section, t_ipoint pos, t_ipoint dim)
{
    int *pixels;

	pixels = (int *)section->pixels_ptr;
    for (int i = 0; i < dim.y; i++)
    {
        for (int j = 0; j < dim.x; j++)
        {
			if ((j < 3 || j > dim.x - 3) || (i == 0 || i == dim.y -1))
            	pixels[(pos.y + i) * (section->section_width) + (pos.x + j)] = 0xFFFFFFFF;
        }
    }
}

void fill_rect(t_img *section, t_ipoint pos, t_ipoint dim, int color)
{
    int *pixels;
	int i;
	int j;

	pixels = (int *)section->pixels_ptr;
	i = 0;
	while (i < dim.y)
	{
		j = 0;
		while (j < dim.x)
		{
			pixels[(pos.y + i) * (section->section_width) + (pos.x + j)] = color;
			j++;
		}
		i++;
	}
}
char get_col_top(int i)
{
    if (i == 0)
        return ('r');
    else if (i == 1)
        return ('g');
    else if (i == 2)
        return ('b');
    else
        return ('x');
}


