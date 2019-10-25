
#include "ui_win.h"

static void	ui_update_simple_button(ui_simple_button *simple_button, const ui_mouse *mouse)
{
	if (ui_is_dot_in_rect(mouse->pos, simple_button->rect))
	{
		if (mouse->clicked == simple_button->clicked_condition)
			simple_button->textures.current = simple_button->textures.on_click;
		else
			simple_button->textures.current = simple_button->textures.on_mouse;
		
	}
	else
		simple_button->textures.current = simple_button->textures.normal;
	
}

void		ui_update_buttons(ui_button **buttons, const ui_mouse *mouse)
{
	ui_button	*b;

	b = *buttons;
	while (b)
	{
		if (b->type & UI_BUTTON_SIMPLE)
			ui_update_simple_button((ui_simple_button*)b->data, mouse);
		b = b->next;
	}
}
