#include "ui_event.h"

void	ui_poll_event(ui_win *win)
{
	SDL_PollEvent(&win->event);
}

void	ui_wait_event(ui_win *win)
{
	SDL_WaitEvent(&win->event);
}