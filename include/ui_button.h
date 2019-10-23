#ifndef UI_BUTTON_H
# define UI_BUTTON_H

#include "SDL.h"
#include "ui_shape.h"
#include "ui_event.h"

typedef struct	s_button_texture_set
{
	SDL_Texture *normal;
	SDL_Texture	*on_click;
	SDL_Texture *on_mouse;
	SDL_Texture	*current;
}				ui_simple_set;

typedef enum		s_simple_state
{
	UI_SIMPLE_NONE = 0,
	UI_SIMPLE_ON_MOUSE = 1,
	UI_SIMPLE_CLICKED = 2
}					ui_simple_state;

typedef struct		s_simple_button
{
	ui_simple_set	textures;
	ui_simple_state	state;
	ui_mouse_button	clicked_condition;
	void			(*f)(void *argument);
	void			*argurment;
	ui_rect			rect;
	ui_frect		ratio;
}					ui_simple_button;

typedef enum			s_button_type
{
	UI_BUTTON_NONE = 0,
	UI_BUTTON_SIMPLE = 1
}						ui_button_type;

typedef struct			s_button
{
	void				*data;
	ui_button_type		type;
	struct s_button		*next;
}						ui_button;

ui_button	*ui_new_simple_button(ui_simple_set textures, void (*f)(void *argument), void *argument);
void		ui_add_button(ui_button **buttons, ui_button *new_button);


#endif	//	UI_BUTTON_H