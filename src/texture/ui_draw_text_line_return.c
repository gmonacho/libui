#include "ui_texture.h"
#include "ui_error.h"
#include "libft.h"

static int		count_words(char *str)
{
	int			i;
	int			i_words;

	i_words = 0;
	if (str)
	{
		i = 0;
		while (str[i])
		{
			if (ft_isprint(str[i]))
			{
				i_words++;
				while (ft_isprint(str[i]))
					i++;
			}
			while (str[i] && !ft_isprint(str[i]))
				i++;
		}
	}
	return (i_words);
}

static char		*jump_n_words(const char *str, int n)
{
	int			i;
	int			i_words;

	i_words = 0;
	i = 0;
	if (str)
	{
		while (str[i] && i_words < n)
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

static char		*skip_first_word(char *str)
{
	while (*str && !ft_isprint(*str))
		str++;
	while (ft_isprint(*str))
		str++;
	while (*str && !ft_isprint(*str))
		str++;
	return (str);
}

static char		*remove_last_word(const char *str)
{
	char	*rev_str;
	char	*new_str;
	char	*tmp;
	char	*rev_start;

	if (!(rev_str = ft_strrev(str)))
	{
		return (ui_ret_null_error("remove_last_word",
			"ft_strrev(rev_str) allocation failed", NULL));
	}
	rev_start = rev_str;
	rev_str = skip_first_word(rev_str);
	if (!(new_str = ft_strdup(rev_str)))
		ui_ret_null_error("remove_last_word",
		"rev_str allocation failed", NULL);
	tmp = new_str;
	if (!(new_str = ft_strrev(new_str)))
		ui_ret_null_error("remove_last_word",
		"ft_strrev(new_str) allocation failed", NULL);
	ft_strdel(&tmp);
	ft_strdel(&rev_start);
	return (new_str);
}

static char		*remove_words_from_end(const char *str, int n)
{
	char	*tmp;
	char	*new_str;
	int		i;

	i = 0;
	new_str = ft_strdup(str);
	while (i < n)
	{
		tmp = new_str;
		if (!(new_str = remove_last_word(new_str)))
		{
			return (ui_ret_null_error("remove_word_from_end",
			"remove_last_word failed", NULL));
		}
		ft_strdel(&tmp);
		i++;
	}
	return (new_str);
}

static int		remove_word(t_text_line_kit *text, char **str, int n_rem_words)
{
	int		width;
	char	*tmp;

	tmp = *str;
	*str = remove_words_from_end(text->str, n_rem_words);
	ft_strdel(&tmp);
	width = ui_get_text_width(text->font, *str, text->height);
	tmp = *str;
	*str = ft_strdup(text->str);
	ft_strdel(&tmp);
	return (width);
}

static int		draw_one_line_return(SDL_Renderer *rend,
									t_text_line_kit *text,
									int n_to_rem,
									int n_words)
{
	int		width;
	char	*str;
	char	*tmp;
	int		n_rem_words;

	str = ft_strdup(text->str);
	width = ui_get_text_width(text->font, str, text->height);
	n_rem_words = 0;
	while (str && width > text->max_width
			&& n_to_rem + n_rem_words < n_words)
		width = remove_word(text, &str, ++n_rem_words);
	if (n_rem_words)
	{
		if (width == 0)
			return (-1);
		tmp = str;
		str = remove_words_from_end(text->str, n_rem_words);
		ft_strdel(&tmp);
	}
	if (n_to_rem + n_rem_words < n_words && ft_strlen(str))
		ui_draw_text_line(rend, &(t_text_line_kit){str,
			text->color, text->pos, text->max_width,
			text->height, text->font, text->alignment});
	return ((n_rem_words == 0) ? -1 : count_words(text->str) - n_rem_words);
}

int				ui_draw_text_line_return(SDL_Renderer *rend,
								t_text_line_kit *text)
{
	int				n_rem_words;
	int				n_words;
	int				jumped;
	t_text_line_kit	text_tmp;

	if (text)
	{
		n_rem_words = 0;
		n_words = count_words(text->str);
		text_tmp = *text;
		while (text_tmp.str && jumped != -1 && n_rem_words < n_words)
		{
			jumped = draw_one_line_return(rend, &text_tmp,
									n_rem_words, n_words);
			text_tmp.pos.y += text_tmp.height;
			text_tmp.str = jump_n_words(text_tmp.str, jumped);
			n_rem_words += jumped;
		}
	}
	return (1);
}
