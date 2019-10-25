#include "ui_win.h"
#include "ui_error.h"
#include "libft.h"
#include "ui_shape.h"

ui_win	*ui_create_win(const char *title, ui_rect rect, Uint32 sdl_win_flags, Uint32 sdl_rend_flags)
{
	ui_win	*win;

	if (!(win = (ui_win*)ft_memalloc(sizeof(ui_win))))
		return (ui_ret_null_error("ui_create_win", "ui_win allocation failed", NULL));
	if (!(win->ptr = SDL_CreateWindow(title, rect.x, rect.y, rect.w, rect.h, sdl_win_flags)))
		return (ui_ret_null_error("ui_create_win", SDL_GetError(), NULL));
	if (!(win->rend = SDL_CreateRenderer(win->ptr, -1, sdl_rend_flags)))
		return (ui_ret_null_error("ui_create_win", SDL_GetError(), NULL));
	return (win);
}

void	ui_set_win_size(ui_win *win, int w, int h)
{
	SDL_SetWindowSize(win->ptr, w, h);
}

ui_dot	ui_get_win_size(ui_win *win)
{
	ui_dot	size;

	SDL_GetWindowSize(win->ptr, &size.x, &size.y);
	return (size);
}

void	ui_lock_win_size(ui_win *win)
{
	SDL_SetWindowResizable(win->ptr, SDL_FALSE);
}

void	ui_unlock_win_size(ui_win *win)
{
	SDL_SetWindowResizable(win->ptr, SDL_TRUE);
}

void	ui_set_draw_color(ui_win *win, SDL_Color color)
{
	SDL_SetRenderDrawColor(win->rend, color.r, color.g, color.b, color.a);
}

void	ui_clear_win(ui_win *win)
{
	SDL_RenderClear(win->rend);
}

void	ui_draw_rend(ui_win *win)
{
	SDL_RenderPresent(win->rend);
}
