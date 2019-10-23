#ifndef UI_EVENT_H
# define UI_EVENT_H

# include "ui_win.h"


typedef enum		s_mouse_button
{
	UI_MOUSE_NONE = 0,
	UI_MOUSE_LEFT = 1,
	UI_MOUSE_RIGHT = 2,
	UI_MOUSE_MIDDLE = 4
}					ui_mouse_button;

typedef struct	s_mouse
{
	ui_dot			pos;
	ui_mouse_button clicked;
}				ui_mouse;



void	ui_poll_event(ui_win *win);
void	ui_wait_event(ui_win *win);

#endif