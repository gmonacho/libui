#include "SDL.h"
#include "ui_error.h"
#include "ui_frame.h"
#include "ui_draw.h"

/**
 * @brief  draw_point
 * @note   dessine un point sur l'ecran
 * @param  *rend: pointeur sur le rendu
 * @param  x: position x du point
 * @param  y: position y du point
 * @param  *frame: frame (cadre) d'ecriture, si NULL la fenetre est utilise comme cadre
 * @retval None
 */
void	ui_draw_point(SDL_Renderer *rend, int x, int y, t_frame *frame)
{
	if (!frame)
	{
		if (SDL_RenderDrawPoint(rend, x, y) < 0)
			ui_error(SDL_GetError());
	}
	else
	{
		if (x >= frame->r.x && x <= frame->r.x + (int)frame->r.w
			&& y >= frame->r.y && x <= frame->r.y + (int)frame->r.h)
		{
			if (SDL_RenderDrawPoint(rend, x + frame->r.x, y + frame->r.y) < 0)
				ui_error(SDL_GetError());
		}
	}
}