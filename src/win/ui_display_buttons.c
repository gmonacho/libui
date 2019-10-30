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
																		rect->h * win->ui.button_text_ratio});
			}
			else
				ui_ret_error("ui_display_simple", "ui_new_text failed", 0);
		}
		else
			ui_ret_error("ui_display_simple", "(ui_win)->(TTF_Font*)button_font is not set", 0);
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
		b = b->next;
	}
}