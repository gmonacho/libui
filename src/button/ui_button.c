#include "ui_button.h"
#include "libft.h"
#include "ui_error.h"

t_button				*ui_new_button(t_button_type type,
										t_resize_type resize_type,
										t_frect ratio,
										void *data)
{
	t_button	*new_button;

	if (!(new_button = (t_button*)ft_memalloc(sizeof(t_button))))
		return (ui_ret_null_error("ui_new_button",
									"new_button allocation failed",
									NULL));
	new_button->data = data;
	new_button->type = type;
	new_button->resize_type = resize_type;
	new_button->ratio = ratio;
	new_button->next = NULL;
	return (new_button);
}

void					ui_add_button(t_button **buttons,
										t_button *new_button)
{
	if (new_button)
	{
		new_button->next = *buttons;
		*buttons = new_button;
	}
	else
		ui_ret_error("ui_add_button", "new_button is NULL", 0);
}

t_simple_button		*ui_new_simple_button(t_mouse_button clicked_condition,
												void (*f)(void *argument),
												void *argument,
												t_simple_set textures)
{
	t_simple_button	*new_simple;

	if (!(new_simple = (t_simple_button*)ft_memalloc(
						sizeof(t_simple_button))))
		return (ui_ret_null_error("ui_new_simple_button",
									"new_simple allocation_failed",
									NULL));
	new_simple->id = -1;
	new_simple->textures = textures;
	new_simple->clicked_condition = clicked_condition;
	new_simple->f = f;
	new_simple->argurment = argument;
	new_simple->text = NULL;
	return (new_simple);
}
