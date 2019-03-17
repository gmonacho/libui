#include "SDL.h"
#include "ui_struct_2d.h"
#include "ui_window.h"

/*
** @brief  get_win_size
** @note   recupere la taile de la fenetre
** @param  *win: pointeur sur la fenetre
** @retval taille de la fenetre (t_dot)
*/
t_dot		ui_get_win_size(SDL_Window *win)
{
	t_dot	win_size;

	SDL_GetWindowSize(win, &(win_size.x), &(win_size.y));
	return (win_size);
}

/*
** @brief  set_win_size
** @note   set la taille de la fenetre
** @param  *win: pointeur sur la fenetre
** @param  w: (width) largeur de la fenetre
** @param  h: (height) hauteur de la fenetre
** @retval None
*/
void		ui_set_win_size(SDL_Window *win, int w, int h)
{
	SDL_SetWindowSize(win, w, h);
}
