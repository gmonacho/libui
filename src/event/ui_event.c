#include "ui_event.h"

void	ui_poll_event(SDL_Event *event)
{
	SDL_PollEvent(event);
}

void	ui_wait_event(SDL_Event *event)
{
	SDL_WaitEvent(event);
}