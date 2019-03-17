#include "SDL.h"
#include "ui_struct_2d.h"
#include "ui_window.h"

/**
 * @brief  set_win_pos
 * @note   set la position de la fenetre
 * @param  *win: pointeur sur la fenetre
 * @param  x: position x voulue
 * @param  y: position y voulue
 * @retval None
 */
void		ui_set_win_pos(SDL_Window *win, int x, int y)
{
	SDL_SetWindowPosition(win, x, y);
}

/**
 * @brief  get_win_pos
 * @note   recupere la position de la fenetre
 * @param  *win: pointeur sur la fenetre
 * @retval La position de la fenetre (t_dot)
 */
t_dot		ui_get_win_pos(SDL_Window *win)
{
	t_dot	win_pos;

	SDL_GetWindowPosition(win, &(win_pos.x), &(win_pos.y));
	return (win_pos);
}

/**
 * @brief  move_win
 * @note   deplace la fenetre
 * @param  *win: pointeur sur la fenetre
 * @param  dx: deplacement en x
 * @param  dy: deplacement en y
 * @retval None
 */
void		ui_move_win(SDL_Window *win, int dx, int dy)
{
	t_dot	win_pos;

	win_pos = ui_get_win_pos(win);
	ui_set_win_pos(win, win_pos.x + dx, win_pos.y + dy);
}
