#include "ui_button.h"
#include "libft.h"
#include "ui_error.h"

ui_button		*ui_new_button(ui_button_type type, ui_resize_type resize_type, ui_frect ratio, void *data)
{
	ui_button	*new_button;

	if (!(new_button = (ui_button*)ft_memalloc(sizeof(ui_button))))
		return (ui_ret_null_error("ui_new_button", "new_button allocation failed", NULL));
	new_button->data = data;
	new_button->type = type;
	new_button->resize_type = resize_type;
	new_button->ratio = ratio;
	new_button->next = NULL;
	return (new_button);
}

void		ui_add_button(ui_button **buttons, ui_button *new_button)
{
	if (new_button)
	{
		new_button->next = *buttons;
		*buttons = new_button;
	}
	else
		ui_ret_error("ui_add_button", "new_button is NULL", 0);
}

ui_simple_button	*ui_new_simple_button(ui_mouse_button clicked_condition, void (*f)(void *argument), void *argument, ui_simple_set textures)
{
	ui_simple_button	*new_simple;

	if (!(new_simple = (ui_simple_button*)ft_memalloc(sizeof(ui_simple_button))))
		return (ui_ret_null_error("ui_new_simple_button", "new_simple_allocation_failed", NULL));
	new_simple->textures = textures;
	new_simple->clicked_condition = clicked_condition;
	new_simple->f = f;
	new_simple->argurment = argument;
	return (new_simple);
}