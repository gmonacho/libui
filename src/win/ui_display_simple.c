#include "ui_win.h"
#include "ui_draw.h"
#include "ui_error.h"

static void		ui_display_simple_draw_text(t_win *win,
											t_simple_button *simple_button,
											const t_rect *rect)
{
	ui_draw_text_in_rect(win->rend,
							&(t_text){simple_button->text,
							rect->h * win->ui.button_text_ratio,
							win->ui.button_font, win->ui.button_text_color,
							(t_dot){0, 0},
							TEXT_ALIGN_CENTER},
							(t_rect){rect->x,
							rect->y + (rect->h - rect->h
							* win->ui.button_text_ratio) / 2,
							rect->w,
							rect->h * win->ui.button_text_ratio},
							UI_DRAW_TEXT_NONE);
}

void			ui_display_simple(t_win *win,
									t_simple_button *simple_button,
									const t_rect *rect)
{
	SDL_Texture	*text_texture;

	if (simple_button->textures.current)
		SDL_RenderCopy(win->rend, simple_button->textures.current,
						NULL, (SDL_Rect*)rect);
	else
	{
		ui_set_draw_color(win->rend, &(SDL_Color){200, 200, 200, 255});
		ui_draw_rect(win->rend, rect);
	}
	if (simple_button->text)
	{
		if (win->ui.button_font)
		{
			if ((text_texture = ui_new_text(win->rend,
					win->ui.button_font, simple_button->text,
					&win->ui.button_text_color)))
				ui_display_simple_draw_text(win, simple_button, rect);
			else
				ui_ret_error("ui_display_simple", "ui_new_text failed", 0);
		}
		else
			ui_ret_error("ui_display_simple",
							"(ui_win)->(TTF_Font*)button_font is not set", 0);
	}
}
