#include "SDL.h"
#include "ui_error.h"
#include "ui_renderer.h"

/*
** @brief  create_renderer
** @note   cree un moteur de rendu
** @param  *win: pointeur sur la fenetre
** @param  index: 0 pour choisir le mode de rendu ou -1 pour privilegier l'acceleration materielle
** @param  flags: mode de rendu voir readme
** @retval le rendu cree
*/
SDL_Renderer	*ui_create_renderer(SDL_Window *win, int index, Uint32 flags)
{
	SDL_Renderer	*rend;

	rend = NULL;
	if (!(rend = SDL_CreateRenderer(win, index, flags)))
		return (ui_null_error(SDL_GetError()));
	SDL_SetRenderDrawBlendMode(rend, SDL_BLENDMODE_BLEND);
	return (rend);
}

/*
** @brief  draw_rend
** @note   affiche le rendu
** @param  *rend: pointeur sur le rendu
** @retval None
*/
void			ui_draw_rend(SDL_Renderer *rend)
{
	SDL_RenderPresent(rend);
}

/*
** @brief  clear_rend
** @note   remplie le rendu de la couleur du pinceau
** @param  *rend: pointeur sur le rendu
** @retval None
*/
void			ui_clear_rend(SDL_Renderer *rend)
{
	SDL_RenderClear(rend);
}

/*
** @brief  destroy_rend
** @note   detruit le rendu
** @param  *rend: pointeur sur le rendu
** @retval None
*/
void			ui_destroy_rend(SDL_Renderer *rend)
{
	SDL_DestroyRenderer(rend);
}

/*
** @brief  set_draw_color
** @note   change de couleur d'ecriture du rendu donne
** @param  *rend: pointeur sur le rendu
** @param  color: couleur
** @retval None
*/
void			ui_set_draw_color(SDL_Renderer *rend, int color)
{
	SDL_SetRenderDrawColor(rend, (color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF, (color >> 24) & 0xFF);
	ui_clear_rend(rend);
}
