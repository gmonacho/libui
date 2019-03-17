#include "SDL.h"
#include "ui_error.h"
#include "ui_event.h"

/**
 * @brief  ui_is_key_pressed
 * @note   recuperation de l'etat clavier
 * @param  key_flags: les touches testes
 * @param  update: mise a jour ou non de l'etat du clavier, conseille en debut de boucle seulement
 * @retval 1 si les touches sont pressees 0 sinon
 */
int					ui_is_key_pressed(Uint32 key_flags, int update)
{
	static Uint8	*keyboard_state = NULL;
	int				i;

	if (update)
		keyboard_state = (Uint8*)SDL_GetKeyboardState(NULL);	
	if (key_flags != 0)
	{
		if (keyboard_state)
		{
			if (!(key_flags & UI_AT_LEAST_ONE))
				return (keyboard_state[key_flags]) ? 1 : 0;
			i = 0;
			while (i < SDL_NUM_SCANCODES)
			{
				if (keyboard_state[i++])
					return (1);
			}
		}
		else
			return (ui_error("ui_is_key_pressed : events not initialised"));
	}
	return (0);
}
