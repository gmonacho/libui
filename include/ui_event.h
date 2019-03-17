#ifndef EVENT_H
# define EVENT_H

# include "ui_event_flag.h"

void	ui_update_event(Uint32 event_flags);
int		ui_is_key_pressed(Uint32 key_flags, int update);
int		ui_is_mouse_pressed(Uint32 mouse_flags, int *x, int *y);

#endif