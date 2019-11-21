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

	TTF_SizeText(font, text, &w, &h);
	width = 0;
	if (h > 0)
		width = (w * height) / h;
	return (width);
}

void			ui_draw_text(SDL_Renderer *rend, const t_text *text)
{
	char		**text_tab;
	SDL_Texture	*texture;
	int			i;
	t_dot		pos;

	pos = text->pos;
	text_tab = ft_strsplit(text->text, '\n');
	if (text_tab)
	{
		i = 0;
		while (text_tab[i])
		{
			if ((texture = ui_new_text(rend, text->font, text_tab[i], &text->color)))
			{
				SDL_RenderCopy(rend, texture, NULL, &(SDL_Rect){pos.x, pos.y, ui_get_text_width(text->font, text_tab[i], text->height), text->height});
				SDL_DestroyTexture(texture);
			}
			pos.y += text->height;
			i++;
		}
	}
}

static int		ui_get_x_alignment(t_rect rect, t_text_align aligment, int text_width)
{	
	if (aligment & TEXT_ALIGN_CENTER)
		return (rect.x + rect.w / 2 - text_width / 2);
	else if (aligment & TEXT_ALIGN_RIGHT)
		return (rect.x + rect.w - text_width);
	else
		return (rect.x);
}

static char		*ui_remove_last_word(const char *text, char c)
{
	char		*new_text;
	void		*tmp;
	int			i;

	if (!(new_text = ft_strrev(text)))
		return (ui_ret_null_error("ui_remove_last_word", "ft_strrev [0] failed", NULL));
	i = 0;
	while (new_text[i] && new_text[i] != c)
		i++;
	while (new_text[i] == c)
		i++;
	tmp = (void*)new_text;
	if (!(new_text = ft_strdup(&new_text[i])))
		return (ui_ret_null_error("ui_remove_last_word", "ft_strdup failed", NULL));
	ft_strdel((char**)&tmp);
	tmp = (void*)new_text;
	if (!(new_text = ft_strrev(new_text)))
		return (ui_ret_null_error("ui_remove_last_word", "ft_strrev [1] failed", NULL));
	ft_strdel((char**)&tmp);
	return (new_text);
}

// static char		*ui_remove_last_letter(const char *text)
// {
// 	char	*new_text;
// 	void	*tmp;

// 	if (!(new_text = ft_strrev(text)))
// 		return (ui_ret_null_error("ui_remove_last_letter", "ft_strrev [0] failed", NULL));
// 	tmp = (void*)new_text;
// 	if (!(new_text = ft_strdup(&new_text[1])))
// 		return(ui_ret_null_error("ui_remoce_last_letter", "ft_strdup", NULL));
// 	ft_strdel((char**)&tmp);
// 	if (!(new_text = ft_strrev(new_text)))
// 		return (ui_ret_null_error("ui_remove_last_letter", "ft_strrev [2] failed", NULL));
// 	ft_strdel((char**)&tmp);
// 	return (new_text);
// }

static char		*ui_jump_words(char *str, int nb_words)
{
	int             i;
	int             i_words;

	i_words = 0;
	i = 0;
	if (str)
	{
		while (str[i] && i_words < nb_words)
		{
			if (str[i] != ' ')
			{
				i_words++;
				while (str[i] && str[i] != ' ')
					i++;
			}
			while (str[i] && str[i] == ' ')
				i++;
		}
		if (str[i])
			return (ft_strdup(&str[i]));
	}
	return (NULL);
}

static int		ui_count_words(char *str, char c)
{
	int             i;
	int             i_words;

	i_words = 0;
	if (str)
	{
		i = 0;
		while (str[i])
		{
			if (str[i] != c)
			{
				i_words++;
				while (str[i] && str[i] != c)
					i++;
			}
			while (str[i] && str[i] == c)
				i++;
		}
	}
	return (i_words);
}

static int		ui_draw_line_in_rect(SDL_Renderer *rend, t_text *ui_text, t_rect rect, t_draw_text_flag flags)
{
	int			width;
	char		*text;
	SDL_Texture	*texture;
	void		*tmp;
	int			nb_words;
	SDL_Rect	src_rect;
	SDL_Rect	dst_rect;
	t_dot		texture_size;

	text = ft_strdup(ui_text->text);
	nb_words = 0;
	while (text && nb_words < ui_count_words(ui_text->text, ' '))
	{
		while (text && (width = ui_get_text_width(ui_text->font, text, ui_text->height)) > rect.w && ui_count_words(text, ' ') > 1)
		{
			tmp = text;
			text = ui_remove_last_word(text, ' ');
			ft_strdel((char**)&tmp);
		}
		if (text)
		{
			if ((texture = ui_new_text(rend, ui_text->font, text, &ui_text->color)) && rect.y + ui_text->height <= rect.y + rect.h)
			{
				SDL_QueryTexture(texture, NULL, NULL, &texture_size.x, &texture_size.y);
				if (width > rect.w)
				{
					if (flags & UI_DRAW_TEXT_HIDE_RIGHT)
					{
						src_rect = (SDL_Rect){0, 0, texture_size.x * rect.w / width, texture_size.y};
						dst_rect = (SDL_Rect){ui_get_x_alignment(rect, ui_text->alignment, width), rect.y, rect.w - 1, ui_text->height};
					}
					else if (flags & UI_DRAW_TEXT_HIDE_LEFT)
					{
						src_rect = (SDL_Rect){texture_size.x - texture_size.x * rect.w / width, 0, texture_size.x, texture_size.y};
						dst_rect = (SDL_Rect){ui_get_x_alignment(rect, ui_text->alignment, width) + 1, rect.y, rect.w - 1, ui_text->height};
					}
					else
					{
						src_rect = (SDL_Rect){-1, -1, -1, -1};
						dst_rect = (SDL_Rect){ui_get_x_alignment(rect, ui_text->alignment, width), rect.y, width, ui_text->height};
					}
				}
				else
				{
					src_rect = (SDL_Rect){-1, -1, -1, -1};
					dst_rect = (SDL_Rect){ui_get_x_alignment(rect, ui_text->alignment, width), rect.y, width, ui_text->height};
				}
				SDL_RenderCopy(rend, texture, (src_rect.x != -1) ? &src_rect : NULL, &dst_rect);
				SDL_DestroyTexture(texture);
			}
			nb_words += ui_count_words(text, ' ');
			ft_strdel(&text);
			text = ui_jump_words(ui_text->text, nb_words);
			rect.y += ui_text->height;
			rect.h -= ui_text->height;
		}
	}
	return (rect.y);
}

void			ui_draw_text_in_rect(SDL_Renderer *rend, const t_text *text, t_rect rect, t_draw_text_flag flags)
{
	char		**text_tab;
	int			i;
	int			y;

	text_tab = ft_strsplit(text->text, '\n');
	if (text_tab)
	{
		i = 0;
		while (text_tab[i])
		{
			y = ui_draw_line_in_rect(rend, &(t_text){text_tab[i], text->height, text->font, text->color, text->pos, text->alignment}, rect, flags);
			rect.h -= y - rect.y;
			rect.y = y;
			i++;
		}
	}
}