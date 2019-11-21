#include "ui_win.h"
#include "ui_draw.h"
#include "ui_error.h"

static void		ui_draw_cursor(t_win *win, char *text, const t_rect *rect)
{
	int		i;
	int		x_pos;
	t_dot	size;
	t_dot	min;
	t_dot	max;

	i = 0;
	x_pos = 0;
	size.y = TTF_FontHeight(win->ui.button_font);
	while (i < win->ui.cursor_position)
	{
		TTF_GlyphMetrics(win->ui.button_font, text[i],
							&min.x, &max.x,
							&min.y, &max.y,
							&size.x);
		ui_draw_rect(win->rend, rect);
		x_pos += rect->h * size.x / size.y;
		i++;
	}
	ui_set_draw_color(win->rend, &win->ui.cursor_color);
	ui_draw_line(win->rend,
					&((t_line){(t_dot){rect->x + x_pos, rect->y},
					(t_dot){rect->x + x_pos, rect->y + rect->h}}));
}

static t_rect	ui_get_name_rect(t_win *win,
									t_text_entry_button *text_entry_button,
									const t_rect *rect)
{
	int			text_width;
	int			text_height;
	t_rect		name_rect;

	text_height = rect->h * win->ui.button_text_ratio;
	text_width = ui_get_text_width(win->ui.button_font,
									text_entry_button->name, text_height);
	if (text_entry_button->text_side == UI_TEXT_SIDE_TOP)
		name_rect = (t_rect){rect->x, rect->y - rect->h + rect->h / 8,
								rect->w, rect->h};
	else if (text_entry_button->text_side == UI_TEXT_SIDE_BOT)
		name_rect = (t_rect){rect->x, rect->y + rect->h + rect->h / 8,
								rect->w, rect->h};
	else if (text_entry_button->text_side == UI_TEXT_SIDE_LEFT)
		name_rect = (t_rect){rect->x - text_width - rect->w / 10,
								rect->y + text_height / 5,
								text_width, text_height};
	else if (text_entry_button->text_side == UI_TEXT_SIDE_RIGHT)
		name_rect = (t_rect){rect->x + rect->w + rect->w / 10,
								rect->y + text_height / 5,
								text_width, text_height};
	else
		name_rect = (t_rect){0, 0, 0, 0};
	return (name_rect);
}

static t_rect	ui_get_texture_rect(t_win *win,
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
		texture_rect = (t_rect){rect->x, rect->y - rect->h, rect->w, rect->h};
	else if (text_entry_button->text_side == UI_TEXT_SIDE_BOT)
		texture_rect = (t_rect){rect->x, rect->y + rect->h, rect->w, rect->h};
	else if (text_entry_button->text_side == UI_TEXT_SIDE_LEFT)
		texture_rect = (t_rect){rect->x - text_width - rect->w / 5, rect->y,
									text_width + rect->w / 5, rect->h};
	else if (text_entry_button->text_side == UI_TEXT_SIDE_RIGHT)
		texture_rect = (t_rect){rect->x + rect->w, rect->y,
								text_width + rect->w / 5, rect->h};
	else
		texture_rect = (t_rect){0, 0, 0, 0};
	return (texture_rect);
}

static void		ui_draw_text_side(t_win *win,
									const t_rect *rect,
									char *text_entry,
									t_text_entry_button *text_entry_button)
{
	t_rect display_rect;

	display_rect = (t_rect){rect->x + rect->w / 20,
				rect->y + (rect->h - rect->h * win->ui.button_text_ratio) / 2,
				rect->w - rect->w / 10,
				rect->h * win->ui.button_text_ratio};
	ui_draw_text_in_rect(win->rend,
				&(t_text){text_entry,
				rect->h * win->ui.button_text_ratio,
				win->ui.button_font, win->ui.button_text_color,
				(t_dot){0, 0},
				TEXT_ALIGN_LEFT},
				display_rect,
				(win->ui.clicked_button
				&& win->ui.clicked_button->data == text_entry_button) ?
				UI_DRAW_TEXT_HIDE_LEFT : UI_DRAW_TEXT_HIDE_RIGHT);
	ui_draw_cursor(win, text_entry, &display_rect);
}

static void		ui_draw_name_side(t_win *win,
									t_text_entry_button *text_entry_button,
									const t_rect *rect)
{
	SDL_Texture	*text_texture;
	t_rect		name_rect;
	t_rect		texture_rect;

	if (text_entry_button->name)
	{
		if ((text_texture = ui_new_text(win->rend, win->ui.button_font,
			text_entry_button->name, &win->ui.button_text_color)))
		{
			name_rect = ui_get_name_rect(win, text_entry_button, rect);
			texture_rect = ui_get_texture_rect(win, text_entry_button, rect);
			if (text_entry_button->textures.name_side_texture)
				SDL_RenderCopy(win->rend,
				text_entry_button->textures.name_side_texture,
				NULL, (SDL_Rect*)&texture_rect);
			ui_draw_text_in_rect(win->rend,
								&(t_text){text_entry_button->name,
								rect->h * win->ui.button_text_ratio,
								win->ui.button_font, win->ui.button_text_color,
								(t_dot){0, 0},
								TEXT_ALIGN_CENTER},
								name_rect, UI_DRAW_TEXT_NONE);
		}
	}
}

static void		ui_draw_text_entry_normally(t_win *win,
									t_text_entry_button *text_entry_button,
									const t_rect *rect)
{
	SDL_Texture	*text_texture;
	char		*text_entry;

	ui_draw_name_side(win, text_entry_button, rect);
	if (win->ui.clicked_button
		&& win->ui.clicked_button->type == UI_BUTTON_TEXT_ENTRY)
		text_entry = text_entry_button->new_text;
	else
		text_entry = text_entry_button->text;
	if (text_entry[0]
		&& (text_texture = ui_new_text(win->rend,
										win->ui.button_font,
										text_entry,
										&win->ui.button_text_color)))
		ui_draw_text_side(win, rect, text_entry, text_entry_button);
}

void			ui_display_text_entry(t_win *win,
										t_text_entry_button *text_entry_button,
										const t_rect *rect)
{

	if (text_entry_button->textures.current_box_texture)
		SDL_RenderCopy(win->rend,
						text_entry_button->textures.current_box_texture,
						NULL, (SDL_Rect*)rect);
	else
	{
		ui_set_draw_color(win->rend, &(SDL_Color){200, 200, 200, 255});
		ui_draw_rect(win->rend, rect);
	}
	if (win->ui.button_font)
		ui_draw_text_entry_normally(win, text_entry_button, rect);
}
