#include "../inc/fractol.h"

void get_pattern_y_z(char c, int letter[5][3])
{
    int letter_y[5][3] = {{1, 0, 1}, {1, 0, 1},
    {1, 1, 1}, {0, 0, 1}, {0, 1, 1}};
    int letter_z[5][3] = {{1, 1, 1}, {0, 0, 1},
    {0, 1, 0}, {1, 0, 0}, {1, 1, 1}};
    

    if (c == 'y' || c == 'Y')
        fill_pattern(letter_y, letter);
    if (c == 'z' || c == 'Z')
        fill_pattern(letter_z, letter);
}

void get_pattern_s_x(char c, int letter[5][3])
{
    int letter_s[5][3] = {{0, 1, 1}, {1, 0, 0},
    {1, 1, 1}, {0, 0, 1}, {0, 1, 1}};
    int letter_t[5][3] = { {1, 1, 1}, {0, 1, 0},
    {0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    int letter_u[5][3] = { {1, 0, 1}, {1, 0, 1},
    {1, 0, 1}, {1, 0, 1}, {0, 1, 0}};
    int letter_v[5][3] = {{1, 0, 1}, {1, 0, 1},
    {1, 0, 1}, {0, 1, 0}, {0, 1, 0}};
    int letter_w[5][3] = {{1, 0, 1}, {1, 0, 1},
    {1, 0, 1}, {1, 1, 1}, {1, 0, 1}};
    int letter_x[5][3] = {{1, 0, 1}, {0, 1, 0},
    {0, 1, 0}, {0, 1, 0}, {1, 0, 1}};

    if (c == 's' || c == 'S')
        fill_pattern(letter_s, letter);
    if (c == 't' || c == 'T')
        fill_pattern(letter_t, letter);
    if (c == 'u' || c == 'U')
        fill_pattern(letter_u, letter);
    if (c == 'v' || c == 'V')
        fill_pattern(letter_v, letter);
    if (c == 'w' || c == 'W')
        fill_pattern(letter_w, letter);
    if (c == 'x' || c == 'X')
        fill_pattern(letter_x, letter);
}
void get_pattern_m_r(char c, int letter[5][3])
{
    int letter_m[5][3] = {{1, 0, 1}, {1, 1, 1},
    {1, 0, 1}, {1, 0, 1},{1, 0, 1}};
    int letter_n[5][3] = {  {1, 0, 1}, {1, 1, 0},
    {1, 0, 1}, {1, 0, 1}, {1, 0, 1}};
    int letter_o[5][3] = {  {0, 1, 0}, {1, 0, 1},
    {1, 0, 1}, {1, 0, 1}, {0, 1, 0}};
    int letter_p[5][3] = {  {1, 1, 1}, {1, 0, 1}, 
    {1, 1, 1}, {1, 0, 0}, {1, 0, 0}};
    int letter_q[5][3] = {  {0, 1, 0}, {1, 0, 1},
    {1, 0, 1}, {1, 1, 1}, {0, 0, 1}};
    int letter_r[5][3] = {  {1, 1, 0}, {1, 0, 1},
    {1, 1, 0}, {1, 0, 1}, {1, 0, 1}};

    if (c == 'm' || c == 'M')
        fill_pattern(letter_m, letter);
    if (c == 'n' || c == 'N')
        fill_pattern(letter_n, letter);
    if (c == 'o' || c == 'O')
        fill_pattern(letter_o, letter);
    if (c == 'p' || c == 'P')
        fill_pattern(letter_p, letter);
    if (c == 'q' || c == 'Q')
        fill_pattern(letter_q, letter);
    if (c == 'r' || c == 'R')
        fill_pattern(letter_r, letter);
}
void get_pattern_g_l(char c, int letter[5][3])
{
    int letter_g[5][3] = {  {0, 1, 1},{1, 0, 0},
    {1, 0, 1}, {1, 0, 1}, {0, 1, 1} };
    int letter_h[5][3] = {{1, 0, 1}, {1, 0, 1},
    {1, 1, 1}, {1, 0, 1}, {1, 0, 1}};
    int letter_i[5][3] = { {0, 1, 0}, {0, 1, 0},
    {0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    int letter_j[5][3] = {  {0, 1, 1}, {0, 0, 1},
    {0, 0, 1}, {1, 0, 1},{0, 1, 1} };
    int letter_k[5][3] = {{1, 0, 1}, {1, 0, 0},
    {1, 1, 0},{1, 0, 1}, {1, 0, 1} };
    int letter_l[5][3] = { {1, 0, 0}, {1, 0, 0},
    {1, 0, 0}, {1, 0, 0},{1, 1, 1}};

    if (c == 'g' || c == 'G')
        fill_pattern(letter_g, letter);
    if (c == 'h'|| c == 'H')
        fill_pattern(letter_h, letter);
    if (c == 'i' || c == 'I')
        fill_pattern(letter_i, letter);
    if (c == 'j' || c == 'J')
        fill_pattern(letter_j, letter);
    if (c == 'k' || c == 'K')
        fill_pattern(letter_k, letter);
    if (c == 'l' || c == 'L')
        fill_pattern(letter_l, letter);
}
void get_pattern_a_f(char c, int letter[5][3])
{
    int letter_a[5][3] = { {0, 1, 0 }, {1, 0, 1 }, 
    {1, 1, 1 }, {1, 0, 1 }, {1, 0, 1 }, };
    int letter_b[5][3] = { {1, 1, 0 }, {1, 0, 1 }, 
    {1, 1, 1 }, {1, 0, 1 }, {1, 1, 0 }, };
    int letter_c[5][3] = { {0, 1, 1 }, {1, 0, 0 }, 
    {1, 0, 0 }, {1, 0, 0 }, {0, 1, 1 }, };
    int letter_d[5][3] = { {1, 1, 0 }, {1, 0, 1 }, 
    {1, 0, 1 }, {1, 0, 1 }, {1, 1, 0 }, };
    int letter_e[5][3] = { {1, 1, 1 }, {1, 0, 0 }, 
    {1, 1, 0 }, {1, 0, 0 }, {1, 1, 1 }, };
    int letter_f[5][3] = { {1, 1, 1 }, {1, 0, 0 },
    {1, 1, 0 }, {1, 0, 0 }, {1, 0, 0 }, };

    if (c == 'a' || c == 'A')
        fill_pattern(letter_a, letter);
    if (c == 'b' || c == 'B')
        fill_pattern(letter_b, letter);
    if (c == 'c' || c == 'C')
        fill_pattern(letter_c, letter);
    if (c == 'd' || c == 'D')
        fill_pattern(letter_d, letter);
    if (c == 'e' || c == 'E')
        fill_pattern(letter_e, letter);
    if (c == 'f' || c == 'F')
        fill_pattern(letter_f, letter);
}


