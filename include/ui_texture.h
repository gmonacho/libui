#ifndef UI_TEXTURE_H
# define UI_TEXTURE_H

# include "SDL.h"
# include "SDL_ttf.h"
# include "ui_shape.h"


void			ui_set_rend_target(SDL_Renderer *rend, SDL_Texture *texture);
void			ui_draw_texture(SDL_Renderer *rend, SDL_Texture	*texture, const ui_rect *src_rect, const ui_rect *dst_rect);

typedef struct	s_button_texture_set
{
	SDL_Texture *normal;
	SDL_Texture	*clicked;
	SDL_Texture *on_mouse;
	SDL_Texture	*current;
}				ui_simple_set;


SDL_Texture		*ui_load_image(SDL_Renderer *rend, const char *file);
void			ui_destroy_texture(SDL_Texture *texture);
ui_simple_set	ui_create_simple_set(SDL_Texture *normal, SDL_Texture *clicked, SDL_Texture *on_mouse);

typedef enum	e_text_align
{
	TEXT_ALIGN_NONE = 0,
	TEXT_ALIGN_LEFT = 1,
	TEXT_ALIGN_RIGHT = 2,
	TEXT_ALIGN_CENTER = 3
}				ui_text_align;

typedef struct	s_text_entry_texture_set
{
	SDL_Texture *name_side_texture;
	SDL_Texture	*normal_box_texture;
	SDL_Texture	*writting_box_texture;
	SDL_Texture *current_box_texture;
}				ui_text_entry_set;

ui_text_entry_set	ui_create_text_entry_set(SDL_Texture *name_side_texture, SDL_Texture *normal_box_texture, SDL_Texture *writting_box_texture);

typedef struct		s_text
{
	char			*text;
	int				height;
	TTF_Font		*font;
	SDL_Color		color;
	ui_dot			pos;
	ui_text_align	alignment;
}					ui_text;


TTF_Font		*ui_load_font(const char *file, int pixel_height);
SDL_Texture		*ui_new_text(SDL_Renderer *rend, TTF_Font *font, const char *text, const SDL_Color *color);
int				ui_get_text_width(TTF_Font *font, const char *text, int height);
void			ui_draw_text(SDL_Renderer *rend, const ui_text *text);
void			ui_draw_text_in_rect(SDL_Renderer *rend, const ui_text *text, ui_rect rect);

#endif