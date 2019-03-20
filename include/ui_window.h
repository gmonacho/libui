#ifndef WINDOW_H
# define WINDOW_H

# include "ui_struct_2d.h"
# include "ui_frame.h"
# include "ui_window_flag.h"

 /**
  *  ================================= PUBLIC =================================
  */

typedef struct		s_win
{
	SDL_Window		*ptr;
	SDL_Renderer	*rend;
	t_dot			pos;
	t_len			size;
	t_frame			*frames;
}					t_win;

t_win			*ui_open_window(const char *title, t_dot pos, t_len size, Uint32 flags);
void			ui_update_window(t_win *win);

void			ui_move_win(SDL_Window *win, int x, int y);
void			ui_set_win_pos(SDL_Window *win, int x, int y);
void			ui_set_win_size(SDL_Window *win, int w, int h);
t_dot			ui_get_win_pos(SDL_Window *win);
t_dot			ui_get_win_size(SDL_Window *win);

 /**
  *  ================================ PRIVATE ================================
  */

#endif