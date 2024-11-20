/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_graphics_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:38:56 by joaomigu          #+#    #+#             */
/*   Updated: 2024/11/20 13:05:55 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

/**
 * @brief Frees resources for all color-related 
 * sections in the graphics structure.
 *
 * This function destroys images associated with 
 * color selection sections (both 
 * user color A and user color B) using the MiniLibX library.
 *
 * @param g Pointer to the graphics structure containing
 *  the color sections.
 */
static void	free_color_sections(t_graphics *g)
{
	if (g->uca_r.img_ptr)
		mlx_destroy_image(g->mlx_conn, g->uca_r.img_ptr);
	if (g->uca_g.img_ptr)
		mlx_destroy_image(g->mlx_conn, g->uca_g.img_ptr);
	if (g->uca_b.img_ptr)
		mlx_destroy_image(g->mlx_conn, g->uca_b.img_ptr);
	if (g->uca_c.img_ptr)
		mlx_destroy_image(g->mlx_conn, g->uca_c.img_ptr);
	if (g->ucb_r.img_ptr)
		mlx_destroy_image(g->mlx_conn, g->ucb_r.img_ptr);
	if (g->ucb_g.img_ptr)
		mlx_destroy_image(g->mlx_conn, g->ucb_g.img_ptr);
	if (g->ucb_b.img_ptr)
		mlx_destroy_image(g->mlx_conn, g->ucb_b.img_ptr);
	if (g->ucb_c.img_ptr)
		mlx_destroy_image(g->mlx_conn, g->ucb_c.img_ptr);
}

/**
 * @brief Frees resources for all initialized
 *  sections in the graphics structure.
 *
 * This function destroys images associated with 
 * general sections (e.g., fractal 
 * rendering, GUI, and mouse hover effects) and 
 * also frees color-related sections 
 * by calling `free_color_sections`.
 *
 * @param g Pointer to the graphics structure 
 * containing the sections.
 */
void	free_sections(t_graphics *g)
{
	if (g->f_section.img_ptr)
		mlx_destroy_image(g->mlx_conn, g->f_section.img_ptr);
	if (g->mousehvr_section_d.img_ptr)
		mlx_destroy_image(g->mlx_conn, g->mousehvr_section_d.img_ptr);
	if (g->mousehvr_section_w.img_ptr)
		mlx_destroy_image(g->mlx_conn, g->mousehvr_section_w.img_ptr);
	if (g->mousehvr_section_f.img_ptr)
		mlx_destroy_image(g->mlx_conn, g->mousehvr_section_f.img_ptr);
	if (g->static_gui.img_ptr)
		mlx_destroy_image(g->mlx_conn, g->static_gui.img_ptr);
	if (g->uc_apply.img_ptr)
		mlx_destroy_image(g->mlx_conn, g->uc_apply.img_ptr);
	if (g->iter_img.img_ptr)
		mlx_destroy_image(g->mlx_conn, g->iter_img.img_ptr);
	free_color_sections(g);
}

/**
 * @brief Checks if all user color 
 * A sections are initialized correctly.
 *
 * This function ensures that all image
 *  pointers for user color A sections 
 * are not `NULL`.
 *
 * @param g Pointer to the graphics structure 
 * containing user color A sections.
 * 
 * @return Returns `TRUE` if all sections are 
 * initialized, `FALSE` otherwise.
 */
static int	check_color_a_sections(t_graphics *g)
{
	if (!g->uca_r.img_ptr)
		return (FALSE);
	if (!g->uca_g.img_ptr)
		return (FALSE);
	if (!g->uca_b.img_ptr)
		return (FALSE);
	if (!g->uca_c.img_ptr)
		return (FALSE);
	return (TRUE);
}

/**
 * @brief Checks if all user color B
 *  sections are initialized correctly.
 *
 * This function ensures that all image
 *  pointers for user color B sections 
 * are not `NULL`.
 *
 * @param g Pointer to the graphics structure
 *  containing user color B sections.
 * 
 * @return Returns `TRUE` if all sections are
 *  initialized, `FALSE` otherwise.
 */
static int	check_color_b_sections(t_graphics *g)
{
	if (!g->ucb_r.img_ptr)
		return (FALSE);
	if (!g->ucb_g.img_ptr)
		return (FALSE);
	if (!g->ucb_b.img_ptr)
		return (FALSE);
	if (!g->ucb_c.img_ptr)
		return (FALSE);
	return (TRUE);
}

/**
 * @brief Validates that all sections in the graphics
 *  structure are properly initialized.
 *
 * This function checks the initialization of the main
 *  sections (e.g., fractal rendering, 
 * GUI, and hover effects) as well as color sections 
 * (both user color A and user color B).
 *
 * @param g Pointer to the graphics structure containing
 *  all sections.
 * 
 * @return Returns `TRUE` if all sections are properly
 *  initialized, `FALSE` otherwise.
 */
int	check_sections(t_graphics *g)
{
	if (!g->static_gui.img_ptr)
		return (FALSE);
	if (!g->f_section.img_ptr)
		return (FALSE);
	if (!g->mousehvr_section_w.img_ptr)
		return (FALSE);
	if (!g->mousehvr_section_f.img_ptr)
		return (FALSE);
	if (!g->mousehvr_section_d.img_ptr)
		return (FALSE);
	if (!check_color_a_sections(g))
		return (FALSE);
	if (!check_color_b_sections(g))
		return (FALSE);
	if (!g->uc_apply.img_ptr)
		return (FALSE);
	return (TRUE);
}
