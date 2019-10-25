#ifndef UI_TEXTURE_H
# define UI_TEXTURE_H

#include "SDL.h"

typedef struct	s_button_texture_set
{
	SDL_Texture *normal;
	SDL_Texture	*on_click;
	SDL_Texture *on_mouse;
	SDL_Texture	*current;
}				ui_simple_set;

typedef enum	e_text_align
{
	TEXT_ALIGN_NONE = 0,
	TEXT_ALIGN_LEFT = 1,
	TEXT_ALIGN_RIGHT = 2,
	TEXT_ALIGN_CENTER = 3
}				ui_text_align;

SDL_Texture		*ui_load_image(SDL_Renderer *rend, const char *file);
void			ui_destroy_texture(SDL_Texture *texture);ui_simple_set	create_simple_set(SDL_Texture *normal, SDL_Texture *on_click, SDL_Texture *on_mouse);

#endif