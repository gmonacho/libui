#include "ui_win.h"
#include "ui_error.h"
#include "ui_draw.h"

static void		ui_display_simple_draw_text(t_winui *win,
											t_simple_button *simple_button,
											const t_rect *rect)
{
	int		w;
	int		h;

	SDL_DestroyTexture(simple_button->textures.render);
	SDL_QueryTexture(simple_button->textures.current, NULL, NULL, &w, &h);
	SDL_CreateTexture(win->rend, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_TARGET, w, h);
	SDL_SetRenderTarget(win->rend, simple_button->textures.render);
	SDL_RenderCopy(win->rend, simple_button->textures.current, NULL, NULL);
	ui_set_draw_color(win->rend, &(SDL_Color){0, 0, 0, 0});
	SDL_RenderClear(win->rend);
	ui_draw_text_line(win->rend,
					&(t_text_line_kit){simple_button->text,
					win->ui.button_text_color,
					(t_dot){rect->w / 2,
					rect->h / 2},
					rect->w,
					rect->h * win->ui.button_text_ratio,
					win->ui.button_font,
					TEXT_ALIGN_CENTER | TEXT_ALIGN_V_MIDDLE});
}

void	ui_update_simple_texture(t_win *win, t_button *button)
{
	t_simple_button	*simple_button;
	SDL_Texture		*text_texture;

	simple_button = (t_simple_button*)button->data;
	if (simple_button->text && ft_strlen(simple_button->text) > 0)
	{
		if (win->ui.button_font)
		{
			if ((text_texture = ui_new_text(win->rend,
					win->ui.button_font, simple_button->text,
					&win->ui.button_text_color)))
			{
				ui_display_simple_draw_text(win, simple_button, button->rect);
				SDL_DestroyTexture(text_texture);
			}
			else
				ui_ret_error("ui_update_simple_texture", "ui_new_text failed", 0);
		}
		else
			ui_ret_error("ui_update_simple_texture",
							"(ui_win)->(TTF_Font*)button_font is not set", 0);
	}
}