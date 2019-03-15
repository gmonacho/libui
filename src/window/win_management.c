#include "SDL.h"
#include "error.h"
#include "window.h"

/**
 * @brief  open_window
 * @note   Cree une nouvelle fenetre
 * @param  *title: titre de la fenetre
 * @param  w: (width) largeur de la fenetre
 * @param  h: (height) hauteur de la fenetre
 * @param  flags: flags voir readme
 * @retval retourne un pointeur sur la fenetre cree ou null en affichant le message d'erreur correspondant
 */
SDL_Window			*open_window(const char *title, int w, int h, Uint32 flags)
{
	SDL_Window		*win;

	win = NULL;
	if (!(win = SDL_CreateWindow(title, 0, 0, w, h, flags)))
		return (null_error(SDL_GetError()));
	return (win);
}
