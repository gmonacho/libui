#include "ui_win.h"
#include "ui_frame.h"

void		ui_update_frames_rect(t_win *win, SDL_bool force_update)
{
	t_frame		*f;
	t_dot		win_size;

	SDL_GetWindowSize(win->ptr, &win_size.x, &win_size.y);
	f = win->ui.frames;
	while (f)
	{
		if (!(f->resize_type & UI_RESIZE_LOCK_RATIO) || force_update)
		{
			if (f->resize_type & UI_RESIZE_W || force_update)
				f->rect.w = f->ratio.w * win_size.x;
			if (f->resize_type & UI_RESIZE_H || force_update)
				f->rect.h = f->ratio.h * win_size.y;
			if (f->resize_type & UI_RESIZE_X || force_update)
				f->rect.x = f->ratio.x * win_size.x;
			if (f->resize_type & UI_RESIZE_Y || force_update)
				f->rect.y = f->ratio.y * win_size.y;
		}
		f = f->next;
	}
}

void		ui_update_frames(t_win *win)
{
	ui_update_frames_rect(win, SDL_FALSE);
	ui_update_buttons_rect(win, SDL_FALSE);
	ui_update_buttons_textures(win, win->ui.on_mouse_button, win->ui.clicked_button);
}
