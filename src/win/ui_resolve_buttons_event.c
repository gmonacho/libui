#include "ui_win.h"

static void	ui_resolve_simple_button(ui_win *win, ui_simple_button *simple_button)
{
	if (simple_button->clicked_condition & win->mouse.releasing)
		simple_button->f(simple_button->argurment);
}

void		ui_resolve_buttons_event(ui_win *win)
{
	ui_button			*b;

	if (win->mouse.releasing)
	{
		if (win->ui.clicked_button)
		{
			if (win->ui.clicked_button->type == UI_BUTTON_SIMPLE && win->ui.clicked_button == win->ui.on_mouse_button)
				ui_resolve_simple_button(win, win->ui.clicked_button->data);
			if (win->ui.clicked_button->type != UI_BUTTON_TEXT_ENTRY)
				win->ui.clicked_button = NULL;
		}
	}
	if (win->ui.clicked_button && win->ui.clicked_button->type == UI_BUTTON_TEXT_ENTRY && win->mouse.clicking && win->ui.on_mouse_button != win->ui.clicked_button)
		win->ui.clicked_button = NULL;
	b = win->ui.buttons;
	win->ui.on_mouse_button = NULL;
	while (b)
	{
		if (ui_is_dot_in_rect(win->mouse.pos, b->rect))
		{
			if (win->mouse.clicking)
				win->ui.clicked_button = b;
			win->ui.on_mouse_button = b;
		}
		b = b->next;
	}
	
}