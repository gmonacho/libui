#ifndef UI_BUTTON_H
# define UI_BUTTON_H

#include "ui_event.h"
#include "ui_shape.h"
#include "ui_texture.h"


typedef enum		s_simple_state
{
	UI_SIMPLE_NONE = 0,
	UI_SIMPLE_ON_MOUSE = 1,
	UI_SIMPLE_CLICKED = 2
}					ui_simple_state;

typedef struct		s_simple_button
{
	char			*text;
	ui_simple_set	textures;
	ui_mouse_button	clicked_condition;
	void			(*f)(void *argument);
	void			*argurment;
}					ui_simple_button;

typedef enum			s_button_type
{
	UI_BUTTON_NONE = 0,
	UI_BUTTON_SIMPLE = 1
}						ui_button_type;

typedef enum			s_resize_type
{
	UI_RESIZE_NONE = 0,
	UI_RESIZE_LOCK_X = 1,
	UI_RESIZE_LOCK_Y = 2,
	UI_RESIZE_LOCK_X_RATIO = 4,
	UI_RESIZE_LOCK_Y_RATIO = 8,
	UI_RESIZE_LOCK_W = 16,
	UI_RESIZE_LOCK_H = 32,
	UI_RESIZE_LOCK_W_RATIO = 64,
	UI_RESIZE_LOCK_H_RATIO = 128
}						ui_resize_type;

typedef struct			s_button
{
	void				*data;
	ui_button_type		type;
	ui_resize_type		resize_type;
	ui_rect				rect;
	ui_frect			ratio;
	struct s_button		*next;
}						ui_button;

ui_button			*ui_new_button(ui_button_type type, ui_resize_type resize_type, ui_frect ratio,void *data);
ui_simple_button	*ui_new_simple_button(ui_mouse_button clicked_condition, void (*f)(void *argument), void *argument, ui_simple_set textures);
void				ui_add_button(ui_button **buttons, ui_button *new_button);


#endif	//	UI_BUTTON_H