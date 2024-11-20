/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_graphics_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:38:59 by joaomigu          #+#    #+#             */
/*   Updated: 2024/11/20 13:13:37 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

/**
 * @brief Resets a section's attributes to 
 * their default uninitialized values.
 *
 * This function clears the attributes of a 
 * given `t_img` section, setting pointers 
 * to `NULL` and numerical values to `0`.
 *
 * @param sec Pointer to the section (`t_img`) to be cleaned.
 */
static void	clean_section(t_img *sec)
{
	sec->bpp = 0;
	sec->endian = 0;
	sec->img_ptr = NULL;
	sec->left = 0;
	sec->len = 0;
	sec->pixels_ptr = NULL;
	sec->section_height = 0;
	sec->section_width = 0;
	sec->top = 0;
}

/**
 * @brief Cleans and resets the graphics
 *  structure to its default state.
 *
 * This function clears all attributes of 
 * the `t_graphics` structure and 
 * cleans up all associated sections by 
 * calling `clean_section`.
 *
 * @param g Pointer to the graphics structure 
 * (`t_graphics`) to be cleaned.
 */
void	clean_g(t_graphics *g)
{
	g->mlx_conn = NULL;
	g->mlx_win = NULL;
	g->win_height = 0;
	g->win_width = 0;
	clean_section(&g->f_section);
	clean_section(&g->static_gui);
	clean_section(&g->mousehvr_section_w);
	clean_section(&g->mousehvr_section_f);
	clean_section(&g->mousehvr_section_d);
	clean_section(&g->uca_r);
	clean_section(&g->uca_g);
	clean_section(&g->uca_b);
	clean_section(&g->uca_c);
	clean_section(&g->ucb_r);
	clean_section(&g->ucb_g);
	clean_section(&g->ucb_b);
	clean_section(&g->ucb_c);
	clean_section(&g->uc_apply);
	clean_section(&g->iter_img);
}

/**
 * @brief Initializes a specific 
 * image section with the given dimensions.
 *
 * This function creates a new image
 *  using the MiniLibX library, assigns it to 
 * the section, and retrieves its pixel data.
 *
 * @param gfx Pointer to the graphics 
 * structure containing the MiniLibX connection.
 * @param section Pointer to the section (`t_img`) to be initialized.
 * @param width Width of the section in pixels.
 * @param height Height of the section in pixels.
 */
static void	init_section(t_graphics *gfx, t_img *section, int width, int height)
{
	section->img_ptr = mlx_new_image(gfx->mlx_conn, width, height);
	section->pixels_ptr = mlx_get_data_addr(section->img_ptr, &section->bpp,
			&section->len, &section->endian);
	section->section_height = height;
	section->section_width = width;
}

/**
 * @brief Initializes all image sections 
 * in the graphics structure.
 *
 * This function initializes multiple image 
 * sections with predefined dimensions, 
 * preparing them for use in rendering or GUI display.
 *
 * @param g Pointer to the graphics structure 
 * containing the sections.
 */
static void	init_sections(t_graphics *g)
{
	init_section(g, &g->static_gui, WINDOW_WIDTH, WINDOW_HEIGHT);
	init_section(g, &g->f_section, IMAGE_WIDTH, IMAGE_HEIGHT);
	init_section(g, &g->mousehvr_section_w, 50, 50);
	init_section(g, &g->mousehvr_section_f, 100, 100);
	init_section(g, &g->mousehvr_section_d, 400, 100);
	init_section(g, &g->uca_r, 15, 125);
	init_section(g, &g->uca_g, 15, 125);
	init_section(g, &g->uca_b, 15, 125);
	init_section(g, &g->uca_c, 95, 15);
	init_section(g, &g->ucb_r, 15, 125);
	init_section(g, &g->ucb_g, 15, 125);
	init_section(g, &g->ucb_b, 15, 125);
	init_section(g, &g->ucb_c, 95, 15);
	init_section(g, &g->uc_apply, 100, 30);
	init_section(g, &g->iter_img, 80, 20);
}

/**
 * @brief Initializes the graphics system and all its components.
 *
 * This function sets up the MiniLibX connection, creates the program's main 
 * window, initializes sections for rendering and UI, and checks their validity.
 *
 * @param s Pointer to the program's state structure containing 
 * graphics information.
 * 
 * @return Returns `TRUE` on successful initialization, `FALSE` otherwise.
 * 
 * @note Frees resources and handles cleanup if initialization fails.
 */
int	init_graphics(t_state *s)
{
	s->g->mlx_conn = mlx_init();
	if (!s->g->mlx_conn)
		return (FALSE);
	s->g->win_height = WINDOW_HEIGHT;
	s->g->win_width = WINDOW_WIDTH;
	s->g->mlx_win = mlx_new_window(s->g->mlx_conn, s->g->win_width,
			s->g->win_height, get_fractal_string(s->f->fractal_type));
	if (!s->g->mlx_win)
	{
		mlx_destroy_display(s->g->mlx_conn);
		free(s->g->mlx_conn);
		return (FALSE);
	}
	init_sections(s->g);
	if (!check_sections(s->g))
	{
		free_sections(s->g);
		mlx_destroy_window(s->g->mlx_conn, s->g->mlx_win);
		mlx_destroy_display(s->g->mlx_conn);
		free(s->g->mlx_conn);
		return (FALSE);
	}
	return (TRUE);
}
