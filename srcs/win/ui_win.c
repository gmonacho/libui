/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_win.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:18:51 by gal               #+#    #+#             */
/*   Updated: 2020/05/29 23:42:08 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ui_win.h"
#include "ui_frame.h"
#include "ui_error.h"
#include "libft.h"
#include "ui_shape.h"

static void	fill_win(t_winui *win)
{
	win->ui.frames = NULL;
	win->ui.on_mouse_button = NULL;
	win->ui.clicked_button = NULL;
	win->ui.button_font = NULL;
	win->ui.button_text_color = (SDL_Color){255, 255, 255, 255};
	win->ui.button_text_ratio = 0.7;
	win->ui.cursor_position = 0;
	win->ui.cursor_color = (SDL_Color){255, 255, 255, 255};
	win->ui.textures = NULL;
	win->ui.delay_text_entry = 80;
	win->ui.delay_text_del = 30;
	win->ui.last_char = '\0';
}

t_winui		*ui_new_win(const char *title,
						t_rect rect,
						Uint32 sdl_win_flags,
						Uint32 sdl_rend_flags)
{
	t_winui	*win;

	if (!(win = (t_winui*)ft_memalloc(sizeof(t_winui))))
	{
		return (ui_ret_null_error("ui_create_win",
				"ui_win allocation failed", NULL));
	}
	if (!(win->ptr = SDL_CreateWindow(title, rect.x, rect.y,
									rect.w, rect.h, sdl_win_flags)))
		return (ui_ret_null_error("ui_create_win", SDL_GetError(), NULL));
	if (sdl_rend_flags == 5)
		win->rend = 0;
	else if (!(win->rend = SDL_CreateRenderer(win->ptr, -1, sdl_rend_flags)))
		return (ui_ret_null_error("ui_create_win", SDL_GetError(), NULL));
	SDL_PollEvent(&win->event);
	ui_event_update_mouse(&win->mouse);
	fill_win(win);
	return (win);
}

void		ui_clear_win(t_winui *win)
{
	SDL_RenderClear(win->rend);
}

void		ui_draw_rend(t_winui *win)
{
	SDL_RenderPresent(win->rend);
}

void		ui_free_win(t_winui **win)
{
	t_winui	*w;

	w = *win;
	if (w)
	{
		if (w->rend)
			SDL_DestroyRenderer(w->rend);
		if (w->ptr)
			SDL_DestroyWindow(w->ptr);
		ui_free_ui(&w->ui);
		free(w);
		*win = NULL;
	}
}
