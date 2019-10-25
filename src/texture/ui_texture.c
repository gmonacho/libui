#include "ui_texture.h"
#include "SDL.h"
#include "SDL_image.h"
#include "ui_error.h"

SDL_Texture		*ui_load_image(SDL_Renderer *rend, const char *file)
{
	SDL_Surface	*surface;
	SDL_Texture	*texture;

	if (!(surface = IMG_Load(file)))
		return (ui_ret_null_error("ui_load_image", IMG_GetError(), NULL));
	if (!(texture = SDL_CreateTextureFromSurface(rend, surface)))
		return (ui_ret_null_error("ui_load_image", SDL_GetError(), NULL));
	return (texture);
}

ui_simple_set	ui_create_simple_set(SDL_Texture *normal, SDL_Texture *on_click, SDL_Texture *on_mouse)
{
	ui_simple_set	simple_set;

	simple_set.normal = normal;
	simple_set.clicked = on_click;
	simple_set.on_mouse = on_mouse;
	return (simple_set);
}

void			ui_set_rend_target(SDL_Renderer *rend, SDL_Texture *texture)
{
	SDL_SetRenderTarget(rend, texture);
}

void			ui_draw_texture(SDL_Renderer *rend, SDL_Texture	*texture, const ui_rect *src_rect, const ui_rect *dst_rect)
{
	SDL_RenderCopy(rend, texture, (SDL_Rect*)src_rect, (SDL_Rect*)dst_rect);
}

// SDL_Texture		*create_button_texture(SDL_Texture *bg, const char *text, TTF_Font *font, ui_text_align text_alignment)
// {

// }

void			ui_destroy_texture(SDL_Texture *texture)
{
	SDL_DestroyTexture(texture);
}