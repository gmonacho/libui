#include "ui_button.h"
#include "libft.h"
#include "ui_error.h"

ui_button	*ui_new_simple_button(ui_simple_set textures, void (*f)(void *argument), void *argument)
{
	ui_button			*button;
	ui_simple_button	*data;

	if (!(button = (ui_button*)ft_memalloc(sizeof(ui_button))))
		return (ui_ret_null_error("new_simple_button", "button allocation failed", NULL));
	data->textures = textures;
	data->state = UI_SIMPLE_NONE;
	data->f = f;
	data->argurment = argument;
	button->data = data;
	button->next = NULL;
	return (button);
}

void		ui_add_button(ui_button **buttons, ui_button *new_button)
{
	new_button->next = *buttons;
	*buttons = new_button;
}