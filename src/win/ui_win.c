#include "ui_win.h"
#include "ui_frame.h"
#include "ui_error.h"
#include "libft.h"
#include "ui_shape.h"

t_win		*ui_new_win(const char *title, t_rect rect, Uint32 sdl_win_flags, Uint32 sdl_rend_flags)
{
	t_win	*win;

	if (!(win = (t_win*)ft_memalloc(sizeof(t_win))))
		return (ui_ret_null_error("ui_create_win", "ui_win allocation failed", NULL));
	if (!(win->ptr = SDL_CreateWindow(title, rect.x, rect.y, rect.w, rect.h, sdl_win_flags)))
		return (ui_ret_null_error("ui_create_win", SDL_GetError(), NULL));
	if (!(win->rend = SDL_CreateRenderer(win->ptr, -1, sdl_rend_flags)))
		return (ui_ret_null_error("ui_create_win", SDL_GetError(), NULL));
	SDL_PollEvent(&win->event);
	ui_event_update_mouse(&win->mouse);
	win->ui.frames = NULL;
	win->ui.on_mouse_button = NULL;
	win->ui.clicked_button = NULL;
	win->ui.button_font = NULL;
	win->ui.button_text_color = (SDL_Color){255, 255, 255, 255};
	win->ui.button_text_ratio = 0.7;
	win->ui.cursor_position = 0;
	win->ui.cursor_color = (SDL_Color){255, 255, 255, 255};
	return (win);
}

void		ui_set_win_size(t_win *win, int w, int h)
{
	SDL_SetWindowSize(win->ptr, w, h);
}

t_dot		ui_get_win_size(t_win *win)
{
	t_dot	size;

	SDL_GetWindowSize(win->ptr, &size.x, &size.y);
	return (size);
}

void		ui_lock_win_size(t_win *win)
{
	SDL_SetWindowResizable(win->ptr, SDL_FALSE);
}

void		ui_unlock_win_size(t_win *win)
{
	SDL_SetWindowResizable(win->ptr, SDL_TRUE);
}

void		ui_clear_win(t_win *win)
{
	SDL_RenderClear(win->rend);
}

void		ui_draw_rend(t_win *win)
{
	SDL_RenderPresent(win->rend);
}

void		ui_event_update_mouse(t_mouse *mouse)
{
	Uint32			mouse_state;
	t_mouse_button	last_clicked;

	last_clicked = mouse->clicked;
	mouse->clicked = UI_MOUSE_NONE;
	mouse->clicking = UI_MOUSE_NONE;
	mouse->releasing = UI_MOUSE_NONE;
	mouse_state = SDL_GetMouseState(&mouse->pos.x, &mouse->pos.y);
	if (mouse_state & SDL_BUTTON(SDL_BUTTON_LEFT))
		mouse->clicked |= UI_MOUSE_LEFT;
	if (mouse_state & SDL_BUTTON(SDL_BUTTON_RIGHT))
		mouse->clicked |= UI_MOUSE_RIGHT;
	if (mouse_state & SDL_BUTTON(SDL_BUTTON_MIDDLE))
		mouse->clicked |= UI_MOUSE_MIDDLE;
	if (!(last_clicked & UI_MOUSE_LEFT) && (mouse->clicked & UI_MOUSE_LEFT))
		mouse->clicking |= UI_MOUSE_LEFT;
	if (!(last_clicked & UI_MOUSE_RIGHT) && (mouse->clicked & UI_MOUSE_RIGHT))
		mouse->clicking |= UI_MOUSE_RIGHT;
	if (!(last_clicked & UI_MOUSE_MIDDLE) && (mouse->clicked & UI_MOUSE_MIDDLE))
		mouse->clicking |= UI_MOUSE_MIDDLE;
	if ((last_clicked & UI_MOUSE_LEFT) && !(mouse->clicked & UI_MOUSE_LEFT))
		mouse->releasing |= UI_MOUSE_LEFT;
	if ((last_clicked & UI_MOUSE_RIGHT) && !(mouse->clicked & UI_MOUSE_RIGHT))
		mouse->releasing |= UI_MOUSE_RIGHT;
	if ((last_clicked & UI_MOUSE_MIDDLE) && !(mouse->clicked & UI_MOUSE_MIDDLE))
		mouse->releasing |= UI_MOUSE_MIDDLE;
}

// static void		ui_window_resize()

static void		ui_event(t_win *win)
{
	ui_event_update_mouse(&win->mouse);
	if (win->event.type == SDL_KEYDOWN)
	{
		if (win->ui.clicked_button && win->ui.clicked_button->type == UI_BUTTON_TEXT_ENTRY)
		{
			if (win->event.key.keysym.scancode == SDL_SCANCODE_LEFT)
			{
				if (win->ui.cursor_position > 0)
					win->ui.cursor_position--;
			}
			if (win->event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
			{
				if (win->ui.cursor_position < (int)ft_strlen(((t_text_entry_button*)win->ui.clicked_button->data)->new_text))
					win->ui.cursor_position++;
			}
		}
	}
	// if (win->event.type == SDL_WINDOWEVENT)
	// {
	// 	if (win->event.window.event == SDL_WINDOWEVENT_RESIZED)
	// 	{
			
	// 	}
	// }
}

void		ui_update_ui(t_win *win)
{
	ui_event(win);
	ui_resolve_buttons_event(win);
	ui_update_frames(win);
}
