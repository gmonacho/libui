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

SDL_Texture		*ui_new_text(SDL_Renderer *rend,
								TTF_Font *font,
								const char *text,
								const SDL_Color *color)
{
	SDL_Surface	*surface;
	SDL_Texture	*texture;

	if (!(surface = TTF_RenderText_Blended(font, text, *color)))
		return (ui_ret_null_error("ui_new_text [1]", TTF_GetError(), NULL));
	if (!(texture = SDL_CreateTextureFromSurface(rend, surface)))
		return (ui_ret_null_error("ui_new_text [2]", SDL_GetError(), NULL));
	SDL_FreeSurface(surface);
	return (texture);
}

int				ui_get_text_width(TTF_Font *font, const char *text, int height)
{
	int		w;
	int		h;
	int		width;

	width = 0;
	if (text)
	{
		TTF_SizeText(font, text, &w, &h);
		if (h > 0)
			width = (w * height) / h;
	}
	return (width);
}

// void			ui_draw_text(SDL_Renderer *rend, const t_text *text)
// {
// 	char		**text_tab;
// 	SDL_Texture	*texture;
// 	int			i;
// 	t_dot		pos;

// 	pos = text->pos;
// 	text_tab = ft_strsplit(text->text, '\n');
// 	if (text_tab)
// 	{
// 		i = 0;
// 		while (text_tab[i])
// 		{
// 			if ((texture = ui_new_text(rend, text->font, text_tab[i],
// 														&text->color)))
// 			{
// 				SDL_RenderCopy(rend, texture, NULL, &(SDL_Rect){pos.x, pos.y,
// 					ui_get_text_width(text->font, text_tab[i],
// 									text->height), text->height});
// 				SDL_DestroyTexture(texture);
// 			}
// 			pos.y += text->height;
// 			i++;
// 		}
// 	}
// }

int		ui_get_x_alignment(t_rect rect, t_text_align aligment, int text_width)
{
	if (aligment & TEXT_ALIGN_CENTER)
		return (rect.x + rect.w / 2 - text_width / 2);
	else if (aligment & TEXT_ALIGN_RIGHT)
		return (rect.x + rect.w - text_width);
	else
		return (rect.x);
}

// void			ui_draw_text_in_rect(SDL_Renderer *rend,
// 						const t_text *text,
// 						t_rect rect)
// {
// 	char		**text_tab;
// 	int			i;
// 	int			y;

// 	text_tab = ft_strsplit(text->text, '\n');
// 	if (text_tab)
// 	{
// 		i = 0;
// 		while (text_tab[i])
// 		{
// 			y = ui_draw_text_line(rend, &(t_text_line_kit){text, });
// 			rect.h -= y - rect.y;
// 			rect.y = y;
// 			i++;
// 		}
// 		ft_2dstrdel(&text_tab);
// 	}
// }
