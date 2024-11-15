#include "../inc/fractol.h"



double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
	return ((new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min);
}

t_dpoint vector_sum(t_dpoint v1, t_dpoint v2)
{
	t_dpoint result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	return (result);
}

t_dpoint	 vector_square(t_dpoint v)
{
	t_dpoint result;

	result.x = (v.x * v.x) - (v.y * v.y);
	result.y = 2 * v.x * v.y;
	return (result);
}

unsigned int hex_string_to_int(char *hex_string) 
{
    unsigned int result;
	char c;
	int i;

	result = 0;
	i = 2;
	while (hex_string[i])
	{
		c = hex_string[i];
		if (ft_isdigit(c)) 
			result = result * 16 + (c - '0');
        else if (ft_isalpha(c))
            result = result * 16 + (ft_toupper(c) - 'A' + 10);
		i++;
	}
    return result;
}
