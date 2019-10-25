#include "ui_win.h"

static void		ui_display_simple(ui_win *win, ui_simple_button *simple_button)
{
	if (simple_button->textures.current)
	{
		
	}
	else
	{
		printf("NO_TEXTURES\n");
	}
	
}

void			ui_display_buttons(ui_win *win)
{
	ui_button	*b;

	b = win->ui.buttons;
	while (b)
	{
		if (b->type == UI_BUTTON_SIMPLE)
			ui_display_simple(win, (ui_simple_button*)b->data);
		b = b->next;
	}
}