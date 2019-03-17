#include "SDL.h"
#include "ui_error.h"
#include "ui_draw.h"

/**
 * @brief  draw_point
 * @note   dessine un point sur l'ecran
 * @param  *rend: pointeur sur le rendu
 * @param  x: position x du point
 * @param  y: position y du point
 * @retval None
 */
void	ui_draw_point(SDL_Renderer *rend, int	x, int y)
{
	if (SDL_RenderDrawPoint(rend, x, y) < 0)
		ui_error(SDL_GetError());
}