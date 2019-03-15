#include "SDL.h"
#include "error.h"
#include "draw.h"

/**
 * @brief  draw_point
 * @note   dessine un point sur l'ecran
 * @param  *rend: pointeur sur le rendu
 * @param  x: position x du point
 * @param  y: position y du point
 * @retval None
 */
void	draw_point(SDL_Renderer *rend, int	x, int y)
{
	if (SDL_RenderDrawPoint(rend, x, y) < 0)
		error(SDL_GetError());
}