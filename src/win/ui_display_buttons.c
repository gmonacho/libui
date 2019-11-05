#include "ui_win.h"
#include "ui_draw.h"
#include "ui_error.h"

static void		ui_display_simple(ui_win *win, ui_simple_button *simple_button, const ui_rect *rect)
{
	SDL_Texture	*text_texture;

	if (simple_button->textures.current)
		SDL_RenderCopy(win->rend, simple_button->textures.current, NULL, (SDL_Rect*)rect);
	else
	{
		ui_set_draw_color(win->rend, &(SDL_Color){200, 200, 200, 255});
		ui_draw_rect(win->rend, rect);
	}
	if (simple_button->text)
	{
		if (win->ui.button_font)
		{
			if ((text_texture = ui_new_text(win->rend, win->ui.button_font, simple_button->text, &win->ui.button_text_color)))
			{
				ui_draw_text_in_rect(win->rend,
										&(ui_text){simple_button->text,
										rect->h * win->ui.button_text_ratio,
										win->ui.button_font, win->ui.button_text_color,
										(ui_dot){0, 0},
										TEXT_ALIGN_CENTER}, (ui_rect){rect->x,
																		rect->y + (rect->h - rect->h * win->ui.button_text_ratio) / 2,
																		rect->w,
																		rect->h * win->ui.button_text_ratio}, UI_DRAW_TEXT_NONE);
			}
			else
				ui_ret_error("ui_display_simple", "ui_new_text failed", 0);
		}
		else
			ui_ret_error("ui_display_simple", "(ui_win)->(TTF_Font*)button_font is not set", 0);
	}
}

static void		ui_display_text_entry(ui_win *win, ui_text_entry_button *text_entry_button, const ui_rect *rect)
{
	SDL_Texture	*text_texture;
	ui_rect		name_rect;
	ui_rect		texture_rect;
	int			text_width;
	int			text_height;
	char		*text_entry;

	if (text_entry_button->textures.current_box_texture)
		SDL_RenderCopy(win->rend, text_entry_button->textures.current_box_texture, NULL, (SDL_Rect*)rect);
	else
	{
		ui_set_draw_color(win->rend, &(SDL_Color){200, 200, 200, 255});
		ui_draw_rect(win->rend, rect);
	}
		if (win->ui.button_font)
		{
			if (text_entry_button->name)
			{
				if ((text_texture = ui_new_text(win->rend, win->ui.button_font, text_entry_button->name, &win->ui.button_text_color)))
				{
					text_height = rect->h * win->ui.button_text_ratio;
					text_width = ui_get_text_width(win->ui.button_font, text_entry_button->name, text_height);
					if (text_entry_button->text_side == UI_TEXT_SIDE_TOP)
					{
						name_rect = (ui_rect){rect->x, rect->y - rect->h + rect->h / 8, rect->w, rect->h};
						texture_rect = (ui_rect){rect->x, rect->y - rect->h, rect->w, rect->h};
					}
					else if (text_entry_button->text_side == UI_TEXT_SIDE_BOT)
					{
						name_rect = (ui_rect){rect->x, rect->y + rect->h + rect->h / 8, rect->w, rect->h};
						texture_rect = (ui_rect){rect->x, rect->y + rect->h, rect->w, rect->h};
					}
					else if (text_entry_button->text_side == UI_TEXT_SIDE_LEFT)
					{
						name_rect = (ui_rect){rect->x - text_width - rect->w / 10, rect->y + text_height / 5, text_width, text_height};
						texture_rect = (ui_rect){rect->x - text_width - rect->w / 5, rect->y, text_width + rect->w / 5, rect->h};
					}
					else if (text_entry_button->text_side == UI_TEXT_SIDE_RIGHT)
					{
						name_rect = (ui_rect){rect->x + rect->w + rect->w / 10, rect->y + text_height / 5, text_width, text_height};
						texture_rect = (ui_rect){rect->x + rect->w, rect->y, text_width + rect->w / 5, rect->h};
					}
					else 
					{
						name_rect = (ui_rect){0, 0, 0, 0};
						texture_rect = (ui_rect){0, 0, 0, 0};
					}
					if (text_entry_button->textures.name_side_texture)
						SDL_RenderCopy(win->rend, text_entry_button->textures.name_side_texture, NULL, (SDL_Rect*)&texture_rect);
					ui_draw_text_in_rect(win->rend,
										&(ui_text){text_entry_button->name,
										text_height,
										win->ui.button_font, win->ui.button_text_color,
										(ui_dot){0, 0},
										TEXT_ALIGN_CENTER}, name_rect, UI_DRAW_TEXT_NONE);
				}
			}
			if (win->ui.clicked_button && win->ui.clicked_button->type == UI_BUTTON_TEXT_ENTRY)
				text_entry = text_entry_button->new_text;
			else
				text_entry =  text_entry_button->text;
			if (text_entry[0] && (text_texture = ui_new_text(win->rend, win->ui.button_font, text_entry, &win->ui.button_text_color)))
			{
				ui_draw_text_in_rect(win->rend,
									&(ui_text){text_entry,
									rect->h * win->ui.button_text_ratio,
									win->ui.button_font, win->ui.button_text_color,
									(ui_dot){0, 0},
									TEXT_ALIGN_LEFT}, (ui_rect){rect->x + rect->w / 20,
																	rect->y + (rect->h - rect->h * win->ui.button_text_ratio) / 2,
																	rect->w - rect->w / 10,
																	rect->h * win->ui.button_text_ratio},
																	(win->ui.clicked_button && win->ui.clicked_button->data == text_entry_button) ? UI_DRAW_TEXT_HIDE_LEFT : UI_DRAW_TEXT_HIDE_RIGHT);
			}
		}
	
}

void			ui_display_buttons(ui_win *win, ui_button *buttons)
{
	ui_button	*b;

	b = buttons;
	while (b)
	{
		if (b->type == UI_BUTTON_SIMPLE)
			ui_display_simple(win, (ui_simple_button*)b->data, &b->rect);
		else if (b->type == UI_BUTTON_TEXT_ENTRY)
			ui_display_text_entry(win, (ui_text_entry_button*)b->data, &b->rect);
		b = b->next;
	}
}