
#include "ui_win.h"
#include "libft.h"

static void		ui_update_simple_button(ui_simple_button *simple_button,
										ui_button *current,
										ui_button *on_mouse_button,
										ui_button *clicked_button)
{
	if (simple_button)
	{
		if (current == clicked_button && simple_button->textures.clicked)
			simple_button->textures.current = simple_button->textures.clicked;
		else if (current == on_mouse_button && simple_button->textures.on_mouse)
				simple_button->textures.current = simple_button->textures.on_mouse;
		else
			simple_button->textures.current = simple_button->textures.normal;
	}
}

static void		ui_update_text_entry(ui_text_entry_button *text_entry_button, ui_button *current, ui_button *clicked_button)
{
	if (text_entry_button)
	{
		if (current == clicked_button)
			text_entry_button->textures.current_box_texture = text_entry_button->textures.writting_box_texture;
		else
			text_entry_button->textures.current_box_texture = text_entry_button->textures.normal_box_texture;
	}
}

void			ui_update_buttons_rect(ui_win *win, SDL_bool force_update)
{
	ui_button	*b;
	ui_dot		win_size;

	SDL_GetWindowSize(win->ptr, &win_size.x, &win_size.y);
	b = win->ui.buttons;
	while (b)
	{
		if (!(b->resize_type & UI_RESIZE_LOCK_RATIO) || force_update)
		{
			if (b->resize_type & UI_RESIZE_W || force_update)
				b->rect.w = b->ratio.w * win_size.x;
			if (b->resize_type & UI_RESIZE_H || force_update)
				b->rect.h = b->ratio.h * win_size.y;
			if (b->resize_type & UI_RESIZE_X || force_update)
				b->rect.x = b->ratio.x * win_size.x;
			if (b->resize_type & UI_RESIZE_Y || force_update)
				b->rect.y = b->ratio.y * win_size.y;
		}
		b = b->next;
	}	
}

static void			ui_update_buttons_textures(ui_button **buttons, ui_button *on_mouse_button, ui_button *clicked_button)
{
	ui_button	*b;

	b = *buttons;
	while (b)
	{
		if (b->type == UI_BUTTON_SIMPLE)
			ui_update_simple_button((ui_simple_button*)b->data, b, on_mouse_button, clicked_button);
		else if (b->type == UI_BUTTON_TEXT_ENTRY)
			ui_update_text_entry((ui_text_entry_button*)b->data, b, clicked_button);
		b = b->next;
	}
}

void			ui_update_buttons(ui_win *win)
{
	ui_update_buttons_rect(win, SDL_FALSE);
	ui_update_buttons_textures(&win->ui.buttons, win->ui.on_mouse_button, win->ui.clicked_button);
}

