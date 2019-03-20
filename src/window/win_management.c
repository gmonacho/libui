#include "SDL.h"
#include "ui_error.h"
#include "libft.h"
#include "ui_renderer.h"
#include "ui_window.h"
		
t_win			*ui_open_window(const char *title, t_dot pos, t_len size, Uint32 flags)
{
	t_win		*win;

	win = NULL;
	if (!(win->ptr = SDL_CreateWindow(title, pos.x, pos.y, size.x, size.y, flags)))
	{
		ft_putstr_fd(SDL_GetError(), 2);
		return (ui_null_error(SDL_GetError()));
	}
	if (!(win->rend = ui_create_renderer(win->ptr, -1, 0)))
	{
		ft_putstr_fd(SDL_GetError(), 2);
		return (ui_null_error(SDL_GetError()));
	}
	win->pos = pos;
	win->size = size;
	win->frames = NULL;
	return (win);
}

void			ui_update_window(t_win *win)
{
	SDL_GetWindowPosition(win->ptr, &(win->pos.x), &(win->pos.y));
	SDL_GetWindowSize(win->ptr, (int*)&(win->size.x), (int*)&(win->size.y));
}