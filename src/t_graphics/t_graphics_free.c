/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_graphics_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:38:56 by joaomigu          #+#    #+#             */
/*   Updated: 2024/11/19 14:38:57 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"
static void free_color_sections(t_graphics *g)
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

void free_sections(t_graphics *g)
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
    free_color_sections(g);
}

static int check_color_a_sections(t_graphics *g)
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
static int check_color_b_sections(t_graphics *g)
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
int check_sections(t_graphics *g)
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
