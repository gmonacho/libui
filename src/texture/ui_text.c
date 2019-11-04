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

void			ui_draw_text(SDL_Renderer *rend, const ui_text *text)
{
	char		**text_tab;
	SDL_Texture	*texture;
	int			i;
	ui_dot		pos;

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

static int		ui_get_x_alignment(ui_rect rect, ui_text_align aligment, int text_width)
{	
	if (aligment == TEXT_ALIGN_CENTER)
		return (rect.x + rect.w / 2 - text_width / 2);
	else if (aligment == TEXT_ALIGN_RIGHT)
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

static int		ui_draw_line_in_rect(SDL_Renderer *rend, ui_text *ui_text, ui_rect rect)
{
	int			width;
	char		*text;
	SDL_Texture	*texture;
	void		*tmp;
	int			nb_words;

	text = ft_strdup(ui_text->text);
	nb_words = 0;
	while (text && nb_words < ui_count_words(text, ' '))
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
				// if (width > )
				SDL_RenderCopy(rend, texture, NULL, &(SDL_Rect){ui_get_x_alignment(rect, ui_text->alignment, width), rect.y, width, ui_text->height});
				SDL_DestroyTexture(texture);
			}
			nb_words = ui_count_words(text, ' ');
			ft_strdel(&text);
			text = ui_jump_words(ui_text->text, nb_words);
			rect.y += ui_text->height;
			rect.h -= rect.y;
		}
	}
	return (rect.y);
}

void			ui_draw_text_in_rect(SDL_Renderer *rend, const ui_text *text, ui_rect rect)
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
			y = ui_draw_line_in_rect(rend, &(ui_text){text_tab[i], text->height, text->font, text->color, text->pos, text->alignment}, rect);
			rect.h -= y - rect.y;
			rect.y = y;
			i++;
		}
	}
}