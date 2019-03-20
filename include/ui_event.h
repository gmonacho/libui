#ifndef EVENT_H
# define EVENT_H

# include "ui_event_flag.h"
# include "ui_btn.h"

void	ui_update_event(Uint32 event_flags);
void  ui_set_event(SDL_Event event);
int		ui_is_key_pressed(Uint32 key_flags, int update);
int		ui_is_mouse_pressed(Uint32 mouse_flags, int *x, int *y);
void  set_click_event(SDL_Event event, t_btn *btn, SDL_Renderer	*rend);

#endif
