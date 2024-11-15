#ifndef ASC_STRINGS_H
#define ASC_STRINGS_H

void	get_pattern_a_f(char c, int letter[5][3]);
void	get_pattern_g_l(char c, int letter[5][3]);
void	get_pattern_m_r(char c, int letter[5][3]);
void	get_pattern_s_x(char c, int letter[5][3]);
void	get_pattern_y_z(char c, int letter[5][3]);

void	get_pattern_signs(char c, int letter[5][3]);
void	get_pattern_6_9(char c, int letter[5][3]);
void	get_pattern_0_5(char c, int letter[5][3]);

void	fill_pattern(int src[5][3], int dst[5][3]);
void	get_character_pattern(char c, int letter[5][3]);

#endif