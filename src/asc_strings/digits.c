/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:37:54 by joaomigu          #+#    #+#             */
/*   Updated: 2024/11/19 14:37:55 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void get_pattern_signs(char c, int letter[5][3])
{
    int sign_hash[5][3] = {{1, 0, 1}, {1, 1, 1},
    {1, 0, 1}, {1, 1, 1}, {1, 0, 1}};
    int sign_plus[5][3] = { {0, 0, 0}, {0, 1, 0},
    {1, 1, 1}, {0, 1, 0}, {0, 0, 0}};
    int sign_minus[5][3] = { {0, 0, 0}, {0, 0, 0},
    {1, 1, 1}, {0, 0, 0}, {0, 0, 0}};
    int sign_space[5][3] = { {0, 0, 0}, {0, 0, 0},
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int sign_dot[5][3] = { {0, 0, 0}, {0, 0, 0},
    {0, 0, 0}, {0, 1, 0}, {0, 0, 0}};

    if (c == '#')
        fill_pattern(sign_hash, letter);
    if (c == '+')
        fill_pattern(sign_plus, letter);
    if (c == '-')
        fill_pattern(sign_minus, letter);
    if (c == ' ')
        fill_pattern(sign_space, letter);
    if (c == '.')
        fill_pattern(sign_dot, letter);
}
void get_pattern_6_9(char c, int letter[5][3])
{
    int six[5][3] = {    {0, 1, 0}, {1, 0, 0},
    {1, 1, 1}, {1, 0, 1}, {0, 1, 0}};
    int seven[5][3] = { {1, 1, 1},{0, 0, 1},
    {0, 0, 1}, {0, 0, 1}, {0, 0, 1}};
    int eight[5][3] = {{0, 1, 0}, {1, 0, 1},
    {0, 1, 0}, {1, 0, 1}, {0, 1, 0}};
    int nine[5][3] = { {0, 1, 0}, {1, 0, 1},
    {0, 1, 1}, {0, 0, 1}, {0, 1, 1}};
    
    if (c == '6')
        fill_pattern(six, letter);
    if (c == '7')
        fill_pattern(seven, letter);
    if (c == '8')
        fill_pattern(eight, letter);
    if (c == '9')
        fill_pattern(nine, letter);
}
void get_pattern_0_5(char c, int letter[5][3])
{
    int zero[5][3] = { {1, 1, 0}, {1, 0, 1},
    {1, 0, 1}, {1, 0, 1}, {0, 1, 0}};
    int one[5][3] = {{0, 0, 1}, {0, 1, 1},
    {0, 0, 1}, {0, 0, 1}, {0, 1, 1}};
    int two[5][3] = {{0, 1, 1}, {0, 0, 1},
    {1, 1, 1}, {1, 0, 0}, {1, 1, 1}};
    int three[5][3] = { {0, 1, 1},{0, 0, 1},
    {0, 1, 1}, {0, 0, 1}, {0, 1, 1}};
    int four[5][3] = {{1, 0, 1}, {1, 0, 1},
    {1, 1, 1}, {0, 0, 1}, {0, 0, 1}};
    int five[5][3] = {{1, 1, 1}, {1, 0, 0},
    {1, 1, 1}, {0, 0, 1}, {0, 1, 1}};

    if (c == '0')
        fill_pattern(zero, letter);
    if (c == '1')
        fill_pattern(one, letter);
    if (c == '2')
        fill_pattern(two, letter);
    if (c == '3')
        fill_pattern(three, letter);
    if (c == '4')
        fill_pattern(four, letter);
    if (c == '5')
        fill_pattern(five, letter);
}


