#ifndef UI_WIN_H
# define UI_WIN_H

# include "ui_button.h"
# include "ui_event.h"
# include "ui_shape.h"
# include "ui_texture.h"
# include "SDL.h"


typedef struct		s_ui
{
	ui_button		*buttons;
	ui_button		*on_mouse_button;
	ui_button		*clicked_button;
	TTF_Font		*button_font;
	SDL_Color		button_text_color;
	float			button_text_ratio;
}					ui_ui;

typedef struct		s_win
{
	SDL_Window		*ptr;
	SDL_Renderer	*rend;
	SDL_Event		event;
	ui_mouse		mouse;
	ui_ui			ui;
}					ui_win;


ui_win	*ui_new_win(const char *title, ui_rect rect, Uint32 sdl_win_flags, Uint32 sdl_rend_flags);

void	ui_set_win_size(ui_win *win, int w, int h);
ui_dot	ui_get_win_size(ui_win *win);
void	ui_lock_win_size(ui_win *win);
void	ui_unlock_win_size(ui_win *win);

void	ui_clear_win(ui_win *win);
void	ui_draw_rend(ui_win *win);

void	ui_event_update_mouse(ui_mouse *mouse);

void	ui_update_buttons(ui_win *win);
void	ui_display_buttons(ui_win *win, ui_button *buttons);

void	ui_resolve_buttons_event(ui_win *win);
void	ui_update_buttons_rect(ui_win *win, SDL_bool force_update);
void	ui_update_ui(ui_win *win);


#endif	//	UI_WIN_H