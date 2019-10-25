
#include "ui_win.h"

static void		ui_update_simple_button(ui_simple_button *simple_button, ui_simple_state state)
{
	if (state == UI_SIMPLE_CLICKED)
		simple_button->textures.current = simple_button->textures.clicked;
	else if (state == UI_SIMPLE_ON_MOUSE)
		simple_button->textures.current = simple_button->textures.on_mouse;
	else
		simple_button->textures.current = simple_button->textures.normal;
	
}

void			ui_update_buttons_rect(ui_win *win)
{
	ui_button	*b;
	ui_dot		win_size;

	SDL_GetWindowSize(win->ptr, &win_size.x, &win_size.y);
	b = win->ui.buttons;
	while (b)
	{
		b->rect = (ui_rect){b->ratio.x * win_size.x,
							b->ratio.y * win_size.y,
							b->ratio.w * win_size.x,
							b->ratio.h * win_size.y};
		b = b->next;
	}	
}

static void			ui_update_buttons_textures(ui_button **buttons, ui_button *on_mouse_button, ui_button *clicked_button)
{
	ui_button	*b;

	b = *buttons;
	while (b)
	{
		if (b == clicked_button)
			ui_update_simple_button((ui_simple_button*)b->data, UI_SIMPLE_CLICKED);
		else if (b == on_mouse_button)
			ui_update_simple_button((ui_simple_button*)b->data, UI_SIMPLE_ON_MOUSE);
		else
			ui_update_simple_button((ui_simple_button*)b->data, UI_SIMPLE_NONE);
		b = b->next;
	}
}

void			ui_update_buttons(ui_win *win)
{
	ui_update_buttons_rect(win);
	ui_update_buttons_textures(&win->ui.buttons, win->on_mouse_button, win->clicked_button);
}

