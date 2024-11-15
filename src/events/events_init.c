#include "../inc/fractol.h"

void init_events(t_state *s)
{
	mlx_hook(s->g->mlx_win, MotionNotify, PointerMotionMask, mouse_move_handler, s);
	mlx_hook(s->g->mlx_win, ButtonPress, ButtonPressMask, mouse_handler, s); 
	mlx_hook(s->g->mlx_win, KeyPress, KeyPressMask, key_handler, s);
	mlx_hook(s->g->mlx_win, DestroyNotify, StructureNotifyMask, close_handler, s);
}

