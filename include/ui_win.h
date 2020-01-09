#ifndef UI_WIN_H
# define UI_WIN_H

# include "ui_button.h"
# include "ui_frame.h"
# include "ui_event.h"
# include "ui_shape.h"
# include "ui_texture.h"
# include "SDL.h"

typedef struct		s_ui
{
	t_frame				*frames;
	t_button			*on_mouse_button;
	t_button			*clicked_button;
	TTF_Font			*button_font;
	SDL_Color			button_text_color;
	float				button_text_ratio;
	int					cursor_position;
	t_draw_text_flag	text_enrty_flags;
	SDL_Color			cursor_color;
}					t_ui;

typedef struct		s_win
{
	SDL_Window		*ptr;
	SDL_Renderer	*rend;
	SDL_Event		event;
	t_mouse			mouse;
	t_ui			ui;
}					t_win;

t_win				*ui_new_win(const char *title,
								t_rect rect,
								Uint32 sdl_win_flags,
								Uint32 sdl_rend_flags);

void				ui_set_win_size(t_win *win, int w, int h);
t_dot				ui_get_win_size(t_win *win);
void				ui_lock_win_size(t_win *win);
void				ui_unlock_win_size(t_win *win);

void				ui_clear_win(t_win *win);
void				ui_draw_rend(t_win *win);

void				ui_event_update_mouse(t_mouse *mouse);

void				ui_update_buttons(t_win *win);

void				ui_display_simple(t_win *win,
								t_simple_button *simple_button,
								const t_rect *rect);
void            	ui_display_text_entry(t_win *win, t_text_entry_button *text_entry_button, const t_rect *rect);
void				ui_display_buttons(t_win *win, t_button *buttons);
void				ui_update_buttons_textures(t_win *win, t_button *on_mouse_button, t_button *clicked_button);
void				ui_display_frames(t_win *win, t_frame *frames);
void				ui_display_simple_frame(t_win *win, t_simple_frame *simple_frame, const t_rect *rect);

void				ui_resolve_buttons_event(t_win *win);
void				ui_update_frames(t_win *win);
void				ui_update_frames_rect(t_win *win, SDL_bool force_update);
void				ui_update_buttons_rect(t_win *win, SDL_bool force_update);
void				ui_update_ui(t_win *win);

#endif
