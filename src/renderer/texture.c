#include "SDL.h"
#include "ui_shape.h"
#include "ui_error.h"
#include "ui_texture.h"

/*
** @brief  ui_load_texture
** @note   charge la texture donnee format bmp
** @param  *bmp_file: chemin bmp
** @param  *rend: pointeur sur le rendu
** @retval 
*/
SDL_Texture		*ui_load_texture(const char *bmp_file, SDL_Renderer *rend)
{
	SDL_Surface *tmp;
	SDL_Texture *texture;

	if (!(tmp = SDL_LoadBMP(bmp_file)))
		return (ui_null_error(SDL_GetError()));
	if (!(texture = SDL_CreateTextureFromSurface(rend, tmp)))
		return (ui_null_error(SDL_GetError()));
	SDL_FreeSurface(tmp);
	return (texture);
}

/*
** @brief  ui_draw_texture
** @note   affiche une texture
** @param  *rend: pointeur sur le rendu
** @param  *texture: pointeur sur la texture
** @param  *text_rect: pointeur sur le rectangle source
** @param  *dst_rect: pointeur sur le rectangle cible
** @retval None
*/
void			ui_draw_texture(SDL_Renderer *rend,
									SDL_Texture *texture,
									t_rect *text_rect,
									t_rect *dst_rect)
{
	if (SDL_RenderCopy(rend, texture, (SDL_Rect*)text_rect, (SDL_Rect*)dst_rect) < 0)
		perror(SDL_GetError());
}
