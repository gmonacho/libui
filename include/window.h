#ifndef WINDOW_H
# define WINDOW_H

# include "window_flag.h"
# include "struct_2d.h"

SDL_Window			*open_window(const char *title, int width, int height, Uint32 flags);

 /**
  *  ================================= PUBLIC =================================
  */

void		    move_win(SDL_Window *win, int x, int y);
void            set_win_pos(SDL_Window *win, int x, int y);
void            set_win_size(SDL_Window *win, int w, int h);
t_dot		    get_win_pos(SDL_Window *win);
t_dot           get_win_size(SDL_Window *win);

 /**
  *  ================================ PRIVATE ================================
  */

#endif