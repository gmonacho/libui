#include "ui_draw.h"
#include "ui_button.h"

static void		ui_display_simple(SDL_Renderer *rend, ui_simple_button *simple_button, const ui_rect *rect)
{
	if (simple_button->textures.current)
		SDL_RenderCopy(rend, simple_button->textures.current, NULL, (SDL_Rect*)rect);
	else
	{
		ui_set_draw_color(rend, &(SDL_Color){200, 200, 200, 255});
		ui_draw_rect(rend, rect);
	}
}

void			ui_display_buttons(SDL_Renderer *rend, ui_button *buttons)
{
	ui_button	*b;

	b = buttons;
	while (b)
	{
		if (b->type == UI_BUTTON_SIMPLE)
			ui_display_simple(rend, (ui_simple_button*)b->data, &b->rect);
		b = b->next;
	}
}