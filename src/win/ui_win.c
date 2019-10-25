#include "ui_win.h"
#include "ui_error.h"
#include "libft.h"
#include "ui_shape.h"

ui_win		*ui_new_win(const char *title, ui_rect rect, Uint32 sdl_win_flags, Uint32 sdl_rend_flags)
{
	ui_win	*win;

	if (!(win = (ui_win*)ft_memalloc(sizeof(ui_win))))
		return (ui_ret_null_error("ui_create_win", "ui_win allocation failed", NULL));
	if (!(win->ptr = SDL_CreateWindow(title, rect.x, rect.y, rect.w, rect.h, sdl_win_flags)))
		return (ui_ret_null_error("ui_create_win", SDL_GetError(), NULL));
	if (!(win->rend = SDL_CreateRenderer(win->ptr, -1, sdl_rend_flags)))
		return (ui_ret_null_error("ui_create_win", SDL_GetError(), NULL));
	return (win);
}

void		ui_set_win_size(ui_win *win, int w, int h)
{
	SDL_SetWindowSize(win->ptr, w, h);
}

ui_dot		ui_get_win_size(ui_win *win)
{
	ui_dot	size;

	SDL_GetWindowSize(win->ptr, &size.x, &size.y);
	return (size);
}

void		ui_lock_win_size(ui_win *win)
{
	SDL_SetWindowResizable(win->ptr, SDL_FALSE);
}

void		ui_unlock_win_size(ui_win *win)
{
	SDL_SetWindowResizable(win->ptr, SDL_TRUE);
}

void		ui_clear_win(ui_win *win)
{
	SDL_RenderClear(win->rend);
}

void		ui_draw_rend(ui_win *win)
{
	SDL_RenderPresent(win->rend);
}

static void	ui_event_update_mouse(ui_mouse *mouse)
{
	Uint32			mouse_state;
	ui_mouse_button	last_clicked;

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

static void		ui_event(ui_win *win)
{
	ui_event_update_mouse(&win->mouse);
}

void		ui_update_ui(ui_win *win)
{
	ui_event(win);
	ui_resolve_buttons_event(win);
	ui_update_buttons(win);
	printf("win->clicked_button = %p\n", win->clicked_button);
	printf("win->on_mouse_button = %p\n", win->on_mouse_button);
}
