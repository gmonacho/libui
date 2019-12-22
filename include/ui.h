#ifndef UI_H
# define UI_H

# include <stdio.h>
# include "ui_win.h"
# include "ui_frame.h"
# include "ui_draw.h"
# include "libft.h"
# include "SDL.h"

int		ui_init(Uint32 sdl_flags);
int     ui_load(const char *path, t_win *win);

#endif
