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

typedef enum		e_text_side
{
	UI_TEXT_SIDE_NONE = 0,
	UI_TEXT_SIDE_RIGHT = 1,
	UI_TEXT_SIDE_TOP = 2,
	UI_TEXT_SIDE_LEFT = 3,
	UI_TEXT_SIDE_BOT = 4
}					ui_text_side;

typedef struct		s_text_entry_button
{
	char				*name;
	char				*text;
	char				*new_text;
	ui_text_side		text_side;
	ui_text_entry_set	textures;
	void				(*f)(char *argument);
	
}					ui_text_entry_button;

ui_text_entry_button	*ui_new_text_entry_button(char *name,
													void (*f)(char *argument),
													ui_text_side text_side,
													ui_text_entry_set textures);


typedef enum			s_button_type
{
	UI_BUTTON_NONE = 0,
	UI_BUTTON_SIMPLE = 1,
	UI_BUTTON_TEXT_ENTRY = 2
}						ui_button_type;

# define UI_RESIZE_POS_LINEAR 3
# define UI_RESIZE_SIZE_LINEAR 12
# define UI_RESIZE_ALL_LINEAR 15

typedef enum			s_resize_type
{
	UI_RESIZE_NONE = 0,
	UI_RESIZE_X = 1,
	UI_RESIZE_Y = 2,
	UI_RESIZE_W = 4,
	UI_RESIZE_H = 8,
	UI_RESIZE_LOCK_RATIO = 16
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