#include "ui_win.h"
#include "ui_draw.h"
#include "ui_error.h"
#include "libft.h"

static void		ui_draw_cursor(t_win *win, char *text, const t_rect *rect)
{
	int		x_pos;
	int		x_size;
	int		x_pre_size;
	char	pre_cursor_text[ft_strlen(text) + 1];

	ft_bzero(pre_cursor_text, ft_strlen(text) + 1);
	ft_strncpy(pre_cursor_text, text, win->ui.cursor_position);
	x_pre_size = ui_get_text_width(win->ui.button_font, pre_cursor_text,
									rect->h * win->ui.button_text_ratio);
	x_size = ui_get_text_width(win->ui.button_font, text,
					rect->h * win->ui.button_text_ratio);
	ui_set_draw_color(win->rend, &win->ui.cursor_color);
	x_pos = rect->x + rect->w / 2 - x_size / 2 + x_pre_size;
	ui_draw_line(win->rend,
		&((t_line){(t_dot){x_pos, rect->y},
		(t_dot){x_pos, rect->y + rect->h}}));
}

static t_rect	get_name_side_rect(t_win *win,
										t_text_entry_button *text_entry_button,
										const t_rect *rect)
{
	int			text_width;
	int			text_height;
	t_rect		texture_rect;

	text_height = rect->h * win->ui.button_text_ratio;
	text_width = ui_get_text_width(win->ui.button_font,
					text_entry_button->name, text_height);
	if (text_entry_button->text_side == UI_TEXT_SIDE_TOP)
		texture_rect = (t_rect){rect->x, rect->y, rect->w / 3, rect->h};
	else if (text_entry_button->text_side == UI_TEXT_SIDE_BOT)
		texture_rect = (t_rect){rect->x, rect->y + rect->h,
								rect->w / 3, rect->h};
	else if (text_entry_button->text_side == UI_TEXT_SIDE_LEFT)
		texture_rect = (t_rect){rect->x, rect->y, rect->w / 3, rect->h};
	else if (text_entry_button->text_side == UI_TEXT_SIDE_RIGHT)
		texture_rect = (t_rect){rect->x + rect->w - rect->w / 3, rect->y,
								rect->w / 3, rect->h};
	else
		texture_rect = (t_rect){0, 0, 0, 0};
	return (texture_rect);
}

static t_rect	get_text_side_rect(t_win *win,
										t_text_entry_button *text_entry_button,
										const t_rect *rect)
{
	int			text_width;
	int			text_height;
	t_rect		texture_rect;

	text_height = rect->h * win->ui.button_text_ratio;
	text_width = ui_get_text_width(win->ui.button_font,
					text_entry_button->name, text_height);
	if (text_entry_button->text_side == UI_TEXT_SIDE_TOP)
		texture_rect = (t_rect){rect->x, rect->y + rect->h,
								rect->w - rect->w / 3, rect->h};
	else if (text_entry_button->text_side == UI_TEXT_SIDE_BOT)
		texture_rect = (t_rect){rect->x, rect->y,
								rect->w - rect->w / 3, rect->h};
	else if (text_entry_button->text_side == UI_TEXT_SIDE_LEFT)
		texture_rect = (t_rect){rect->x + rect->w / 3,
							rect->y, rect->w - rect->w / 3, rect->h};
	else if (text_entry_button->text_side == UI_TEXT_SIDE_RIGHT)
		texture_rect = (t_rect){rect->x, rect->y,
								rect->w - rect->w / 3, rect->h};
	else
		texture_rect = (t_rect){0, 0, 0, 0};
	return (texture_rect);
}

static void		ui_draw_text_side(t_win *win,
									const t_rect *rect,
									t_text_entry_button *text_entry,
									char *text)
{
	t_rect				r;
	char				pre_cursor_text[ft_strlen(text) + 1];
	int					cursor_x;
	t_dot				text_size;

	ft_bzero(pre_cursor_text, ft_strlen(text) + 1);
	ft_strncpy(pre_cursor_text, text, win->ui.cursor_position);
	TTF_SizeText(win->ui.button_font, pre_cursor_text,
					&text_size.x, &text_size.y);
	r = get_text_side_rect(win, text_entry, rect);
	cursor_x = (r.h * text_size.x) / text_size.y;
	ui_draw_text_line(win->rend,
						&(t_text_line_kit){text,
						win->ui.button_text_color,
						(t_dot){r.x + r.w / 2, r.y + r.h / 2},
						r.w,
						r.h * win->ui.button_text_ratio,
						win->ui.button_font,
						TEXT_ALIGN_CENTER | TEXT_ALIGN_V_MIDDLE});
	if (win->ui.clicked_button
			&& (t_text_entry_button*)(
			win->ui.clicked_button->data) == text_entry)
		ui_draw_cursor(win, text,
						&r);
}

static void		ui_draw_name_side(t_win *win,
									t_text_entry_button *text_entry_button,
									const t_rect *rect)
{
	SDL_Texture	*text_texture;
	t_rect		r;

	if (text_entry_button->name)
	{
		if ((text_texture = ui_new_text(win->rend, win->ui.button_font,
			text_entry_button->name, &win->ui.button_text_color)))
		{
			r = get_name_side_rect(win, text_entry_button, rect);
			if (text_entry_button->textures.name_side_texture)
				SDL_RenderCopy(win->rend,
				text_entry_button->textures.name_side_texture,
				NULL, (SDL_Rect*)&r);
			ui_draw_text_line(win->rend,
								&(t_text_line_kit){text_entry_button->name,
								win->ui.button_text_color,
								(t_dot){r.x + r.w / 2, r.y + r.h / 2},
								r.w,
								r.h * win->ui.button_text_ratio,
								win->ui.button_font,
								TEXT_ALIGN_CENTER | TEXT_ALIGN_V_MIDDLE});
		}
	}
}

static void		ui_draw_text_entry_normally(t_win *win,
									t_text_entry_button *text_entry_button,
									const t_rect *rect)
{
	SDL_Texture	*text_texture;
	char		*text;

	ui_draw_name_side(win, text_entry_button, rect);
	if (win->ui.clicked_button
		&& win->ui.clicked_button->type == UI_BUTTON_TEXT_ENTRY)
		text = text_entry_button->new_text;
	else
		text = text_entry_button->text;
	if (text[0]
		&& (text_texture = ui_new_text(win->rend,
										win->ui.button_font,
										text,
										&win->ui.button_text_color)))
		ui_draw_text_side(win, rect, text_entry_button, text);
}

void			ui_display_text_entry(t_win *win,
										t_text_entry_button *text_entry_button,
										const t_rect *rect)
{
	t_rect text_side_rect;

	if (text_entry_button->textures.current_box_texture)
	{
		text_side_rect = get_text_side_rect(win, text_entry_button, rect);
		SDL_RenderCopy(win->rend,
						text_entry_button->textures.current_box_texture,
						NULL, (SDL_Rect*)&text_side_rect);
	}
	else
	{
		ui_set_draw_color(win->rend, &(SDL_Color){200, 200, 200, 255});
		ui_draw_rect(win->rend, rect);
	}
	if (win->ui.button_font)
		ui_draw_text_entry_normally(win, text_entry_button, rect);
}
