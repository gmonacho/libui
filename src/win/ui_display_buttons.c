#include "ui_win.h"
#include "ui_draw.h"
#include "ui_error.h"

void			ui_display_buttons(t_win *win, t_button *buttons)
{
	t_button	*b;

	b = buttons;
	while (b)
	{
		if (b->type == UI_BUTTON_SIMPLE)
			ui_display_simple(win, (t_simple_button*)b->data, &b->rect);
		else if (b->type == UI_BUTTON_TEXT_ENTRY)
			ui_display_text_entry(win, (t_text_entry_button*)b->data, &b->rect);
		b = b->next;
	}
}
