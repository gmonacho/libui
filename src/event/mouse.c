#include "SDL.h"
#include "ui_event.h"

/**
 * @brief  ui_is_mouse_pressed
 * @note   recuperation de l'etat souris
 * @param  mouse_flags: les boutons testes
 * @param  *x: pointeur x pour recuperer la position x de la souris
 * @param  *y: pointeur y pour recuperer la position y de la souris
 * @retval 
 */
int		ui_is_mouse_pressed(Uint32 mouse_flags, int *x, int *y)
{
	int		i;

	if (!(mouse_flags & UI_AT_LEAST_ONE))
	{
		if (SDL_GetMouseState(x , y) & mouse_flags)
			return (1);
	}
	else
	{
		i = 1;
		while (i < 6)
		{
			if (SDL_GetMouseState(x ,y) & i++)
				return (1);			
		}
	}
	return (0);
}