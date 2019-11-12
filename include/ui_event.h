#ifndef UI_EVENT_H
# define UI_EVENT_H

# include "ui_shape.h"
# include "SDL.h"

typedef enum		e_mouse_button
{
	UI_MOUSE_NONE = 0,
	UI_MOUSE_LEFT = 1,
	UI_MOUSE_RIGHT = 2,
	UI_MOUSE_MIDDLE = 4
}					t_mouse_button;

typedef struct		s_mouse
{
	ui_dot			pos;
	ui_mouse_button clicked;
	ui_mouse_button	clicking;
	ui_mouse_button	releasing;
}					t_mouse;

void				ui_poll_event(SDL_Event *event);
void				ui_wait_event(SDL_Event *event);

#endif
