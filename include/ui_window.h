#ifndef WINDOW_H
# define WINDOW_H

# include "ui_window_flag.h"
# include "ui_struct_2d.h"

SDL_Window		*ui_open_window(const char *title, int width, int height, Uint32 flags);

 /**
  *  ================================= PUBLIC =================================
  */

void			ui_move_win(SDL_Window *win, int x, int y);
void			ui_set_win_pos(SDL_Window *win, int x, int y);
void			ui_set_win_size(SDL_Window *win, int w, int h);
t_dot			ui_get_win_pos(SDL_Window *win);
t_dot			ui_get_win_size(SDL_Window *win);

 /**
  *  ================================ PRIVATE ================================
  */

#endif