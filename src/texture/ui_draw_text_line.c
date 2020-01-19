#include "ui_texture.h"
#include "ui_error.h"
#include "libft.h"

// static char		*ui_remove_last_word(const char *text, char c)
// {
// 	char		*new_text;
// 	void		*tmp;
// 	int			i;

// 	if (!(new_text = ft_strrev(text)))
// 	{
// 		return (ui_ret_null_error("ui_remove_last_word",
// 			"ft_strrev [0] failed", NULL));
// 	}
// 	i = 0;
// 	while (new_text[i] && new_text[i] != c)
// 		i++;
// 	while (new_text[i] == c)
// 		i++;
// 	tmp = (void*)new_text;
// 	if (!(new_text = ft_strdup(&new_text[i])))
// 	{
// 		return (ui_ret_null_error("ui_remove_last_word",
// 									"ft_strdup failed", NULL));
// 	}
// 	ft_strdel((char**)&tmp);
// 	tmp = (void*)new_text;
// 	if (!(new_text = ft_strrev(new_text)))
// 	{
// 		return (ui_ret_null_error("ui_remove_last_word",
// 								"ft_strrev [1] failed", NULL));
// 	}
// 	ft_strdel((char**)&tmp);
// 	return (new_text);
// }

// static int		ui_count_words(char *str, char c)
// {
// 	int			i;
// 	int			i_words;

// 	i_words = 0;
// 	if (str)
// 	{
// 		i = 0;
// 		while (str[i])
// 		{
// 			if (str[i] != c)
// 			{
// 				i_words++;
// 				while (str[i] && str[i] != c)
// 					i++;
// 			}
// 			while (str[i] && str[i] == c)
// 				i++;
// 		}
// 	}
// 	return (i_words);
// }

// static char		*ui_jump_words(char *str, int nb_words)
// {
// 	int			i;
// 	int			i_words;

// 	i_words = 0;
// 	i = 0;
// 	if (str)
// 	{
// 		while (str[i] && i_words < nb_words)
// 		{
// 			if (str[i] != ' ')
// 			{
// 				i_words++;
// 				while (str[i] && str[i] != ' ')
// 					i++;
// 			}
// 			while (str[i] && str[i] == ' ')
// 				i++;
// 		}
// 		if (str[i])
// 			return (ft_strdup(&str[i]));
// 	}
// 	return (NULL);
// }

static t_rect	*get_src_rect(t_text_line_kit *text, t_dot texture_size, int width)
{
	t_rect	*src_rect;

	if (!(src_rect = (t_rect*)ft_memalloc(sizeof(t_rect))))
		return (ui_ret_null_error("get_src_rect", "src_rect allocation failed", NULL));
	if (width > text->max_width)
	{
		if (text->alignment & TEXT_ALIGN_LEFT)
		{
			*src_rect = (t_rect){0, 0,
					texture_size.x * text->max_width / width,
					texture_size.y};
		}
		else if (text->alignment & TEXT_ALIGN_RIGHT)
		{
			*src_rect = (t_rect){
				texture_size.x - texture_size.x * text->max_width / width,
				0, texture_size.x, texture_size.y};
		}
		else if (text->alignment & TEXT_ALIGN_CENTER)
		{
			*src_rect = (t_rect){
				texture_size.x / 2 - texture_size.x * text->max_width / width / 2,
				0, texture_size.x * text->max_width / width, texture_size.y};
		}
		else
			src_rect = NULL;
	}
	else
		src_rect = NULL;
	return (src_rect);
}

static t_rect	get_dst_rect(t_text_line_kit *text, int width)
{
	if (width > text->max_width)
	{
		if (text->alignment & TEXT_ALIGN_RIGHT)
			return ((t_rect){text->pos.x - text->max_width, text->pos.y, text->max_width, text->height});
		else if (text->alignment & TEXT_ALIGN_CENTER)
			return ((t_rect){text->pos.x - text->max_width / 2, text->pos.y, text->max_width, text->height});
		else
			return ((t_rect){text->pos.x, text->pos.y, text->max_width, text->height});
	}
	else
	{
		if (text->alignment & TEXT_ALIGN_RIGHT)
			return ((t_rect){text->pos.x - width, text->pos.y, width, text->height});
		else if (text->alignment & TEXT_ALIGN_CENTER)
			return((t_rect){text->pos.x - width / 2, text->pos.y, width, text->height});
		else
			return ((t_rect){text->pos.x, text->pos.y, width, text->height});
	}
}

int		ui_draw_text_line(SDL_Renderer *rend,
							t_text_line_kit *text)
{
	int			width;
	SDL_Texture	*texture;
	t_rect		*src_rect;
	t_rect		dst_rect;
	t_dot		texture_size;

	width = ui_get_text_width(text->font, text->str, text->height);
	if (text->str)
	{
		if ((texture = ui_new_text(rend, text->font,
		text->str, &text->color)))
		{
			SDL_QueryTexture(texture, NULL, NULL,
					&texture_size.x, &texture_size.y);
			src_rect = get_src_rect(text, texture_size, width);
			dst_rect = get_dst_rect(text, width);
			SDL_RenderCopy(rend, texture,
			(SDL_Rect*)src_rect, (SDL_Rect*)&dst_rect);
			SDL_DestroyTexture(texture);
		}
	}
	return (text->height);
}

// int		ui_draw_line_in_rect(SDL_Renderer *rend,
// 							t_text *ui_text,
// 							t_rect rect)
// {
// 	int			width;
// 	char		*text;
// 	SDL_Texture	*texture;
// 	void		*tmp;
// 	int			nb_words;
// 	SDL_Rect	src_rect;
// 	SDL_Rect	dst_rect;
// 	t_dot		texture_size;

// 	text = ft_strdup(ui_text->text);
// 	nb_words = 0;
// 	while (text && nb_words < ui_count_words(ui_text->text, ' '))
// 	{
// 		while (text && (width = ui_get_text_width(ui_text->font,
// 			text, ui_text->height)) > rect.w
// 			&& ui_count_words(text, ' ') > 1)
// 		{
// 			tmp = text;
// 			text = ui_remove_last_word(text, ' ');
// 			ft_strdel((char**)&tmp);
// 		}
// 		if (text)
// 		{
// 			if ((texture = ui_new_text(rend, ui_text->font,
// 			text, &ui_text->color))
// 			&& rect.y + ui_text->height <= rect.y + rect.h)
// 			{
// 				SDL_QueryTexture(texture, NULL, NULL,
// 						&texture_size.x, &texture_size.y);
// 				if (width > rect.w)
// 				{
// 					if (ui_text->alignment & TEXT_ALIGN_LEFT)
// 					{
// 						src_rect = (SDL_Rect){0, 0,
// 								texture_size.x * rect.w / width,
// 								texture_size.y};
// 						dst_rect = (SDL_Rect){ui_get_x_alignment(rect,
// 								ui_text->alignment, width),
// 								rect.y, rect.w - 1, ui_text->height};
// 					}
// 					else if (ui_text->alignment & TEXT_ALIGN_RIGHT)
// 					{
// 						src_rect = (SDL_Rect){
// 							texture_size.x - texture_size.x * rect.w / width,
// 							0, texture_size.x, texture_size.y};
// 						dst_rect = (SDL_Rect){ui_get_x_alignment(rect,
// 							ui_text->alignment,
// 							width) + 1, rect.y,
// 							rect.w - 1, ui_text->height};
// 					}
// 					else
// 					{
// 						src_rect = (SDL_Rect){-1, -1, -1, -1};
// 						dst_rect = (SDL_Rect){ui_get_x_alignment(rect,
// 								ui_text->alignment, width),
// 								rect.y, width,
// 								ui_text->height};
// 					}
// 				}
// 				else
// 				{
// 					src_rect = (SDL_Rect){-1, -1, -1, -1};
// 					dst_rect = (SDL_Rect){ui_get_x_alignment(rect,
// 							ui_text->alignment, width),
// 							rect.y, width, ui_text->height};
// 				}
// 				SDL_RenderCopy(rend, texture,
// 				(src_rect.x != -1) ? &src_rect : NULL, &dst_rect);
// 				SDL_DestroyTexture(texture);
// 			}
// 			nb_words += ui_count_words(text, ' ');
// 			ft_strdel(&text);
// 			text = ui_jump_words(ui_text->text, nb_words);
// 			rect.y += ui_text->height;
// 			rect.h -= ui_text->height;
// 		}
// 	}
// 	return (rect.y);
// }
