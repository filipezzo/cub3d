#include "cub3d.h"

static int	is_walkable(t_world *w, double x, double y)
{
	int ix = (int)x;
	int iy = (int)y;

	if (iy < 0 || iy >= w->h || ix < 0 || ix >= w->w)
		return (0);
	return (w->grid[iy][ix] != '1');
}

static void	try_move(t_world *w, double nx, double ny)
{
	if (is_walkable(w, nx, w->py))
		w->px = nx;
	if (is_walkable(w, w->px, ny))
		w->py = ny;
}

static void	rotate_view(t_world *w, double ang)
{
	double old_dir_x = w->dir_x;
	double old_plane_x = w->plane_x;

	w->dir_x = w->dir_x * cos(ang) - w->dir_y * sin(ang);
	w->dir_y = old_dir_x * sin(ang) + w->dir_y * cos(ang);

	w->plane_x = w->plane_x * cos(ang) - w->plane_y * sin(ang);
	w->plane_y = old_plane_x * sin(ang) + w->plane_y * cos(ang);
}

void	player_update(t_game *game)
{
	t_world *w;
	t_input *in;
	double nx, ny;
	double strafe_x, strafe_y;

	if (!game)
		return;
	w = &game->world;
	in = &game->in;

	if (in->w)
	{
		nx = w->px + w->dir_x * MOVE;
		ny = w->py + w->dir_y * MOVE;
		try_move(w, nx, ny);
	}
	if (in->s)
	{
		nx = w->px - w->dir_x * MOVE;
		ny = w->py - w->dir_y * MOVE;
		try_move(w, nx, ny);
	}

	strafe_x = -w->dir_y;
	strafe_y =  w->dir_x;

	if (in->a)
	{
		nx = w->px - strafe_x * MOVE;
		ny = w->py - strafe_y * MOVE;
		try_move(w, nx, ny);
	}
	if (in->d)
	{
		nx = w->px + strafe_x * MOVE;
		ny = w->py + strafe_y * MOVE;
		try_move(w, nx, ny);
	}

	/* rotação */
	if (in->left)
		rotate_view(w, -rot);
	if (in->right)
		rotate_view(w, rot);
}
