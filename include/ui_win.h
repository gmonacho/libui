#ifndef UI_WIN_H
# define UI_WIN_H

#include "SDL.h"
#include "ui_event.h"
#include "ui_button.h"
#include "ui_shape.h"

typedef struct		s_win
{
	SDL_Window		*ptr;
	SDL_Renderer	*rend;
	SDL_Event		event;
	SDL_Color		color;
	ui_button		*on_mouse_button;
	ui_mouse		mouse;
}					ui_win;


ui_win	*ui_create_win(const char *title, ui_rect rect, Uint32 sdl_win_flags, Uint32 sdl_rend_flags);

void	ui_set_win_size(ui_win *win, int w, int h);
ui_dot	ui_get_win_size(ui_win *win);
void	ui_lock_win_size(ui_win *win);
void	ui_unlock_win_size(ui_win *win);

void	ui_set_draw_color(ui_win *win, SDL_Color color);
void	ui_clear_win(ui_win *win);
void	ui_draw_rend(ui_win *win);


#endif	//	UI_WIN_H