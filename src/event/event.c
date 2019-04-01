#include "SDL.h"
#include "ui_event.h"

/*
** @brief  ui_update_event
** @note   mets a jour les evenements donnes en parametre a utiliser en debut de bouv;e
** @retval None
*/
void	ui_update_event(Uint32 event_flags)
{
	SDL_PumpEvents();
	if (event_flags & UI_KEY_UPDATE)
		ui_is_key_pressed(0, 1);
}

/*
** @brief  ui_set_event
** @note   recupere l'évenement
** @retVal None
*/
void	ui_set_event(SDL_Event *event)
{
		SDL_WaitEvent(event);
}
