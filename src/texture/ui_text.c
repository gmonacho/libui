#include "ui_texture.h"
#include "ui_error.h"
#include "libft.h"

TTF_Font		*ui_load_font(const char *file, int pixel_height)
{
	TTF_Font	*new_font;

	if (!(new_font = TTF_OpenFont(file, pixel_height)))
		return (ui_ret_null_error("ui_load_font", TTF_GetError(), NULL));
	return (new_font);
}

SDL_Texture		*ui_new_text(SDL_Renderer *rend, TTF_Font *font, const char *text, const SDL_Color *color)
{
	SDL_Surface	*surface;
	SDL_Texture	*texture;

	if (!(surface = TTF_RenderText_Blended(font, text, *color)))
		return (ui_ret_null_error("ui_new_text_texture", TTF_GetError(), NULL));
	if (!(texture = SDL_CreateTextureFromSurface(rend, surface)))
		return (ui_ret_null_error("ui_new_text_texture", SDL_GetError(), NULL));
	SDL_FreeSurface(surface);
	return (texture);
}

static int	ui_get_text_width(TTF_Font *font, const char *text, int height)
{
	int		w;
	int		h;
	int		width;

	TTF_SizeText(font, text, &w, &h);
	width = 0;
	if (h > 0)
		width = (w * height) / h;
	return (width);
}

void			ui_draw_text(SDL_Renderer *rend, TTF_Font *font, const ui_text *text)
{
	char		**text_tab;
	SDL_Texture	*texture;
	int			i;
	ui_dot		pos;

	pos = text->pos;
	text_tab = ft_strsplit(text->text, '\n');
	i = 0;
	if (text_tab)
	{
		while (text_tab[i])
		{
			if ((texture = ui_new_text(rend, font, text_tab[i], text->color)))
			{
				SDL_RenderCopy(rend, texture, NULL, &(SDL_Rect){pos.x, pos.y, ui_get_text_width(font, text_tab[i], text->height), text->height});
				SDL_DestroyTexture(texture);
			}
			pos.y += text->height;
			i++;
		}
	}
}