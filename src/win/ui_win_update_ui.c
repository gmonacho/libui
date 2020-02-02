/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ui_win_update_ui.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 17:37:31 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 15:51:46 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ui_win.h"
#include "libft.h"

static void		ui_event(t_winui *win)
{
	ui_event_update_mouse(&win->mouse);
	if (win->event.type == SDL_KEYDOWN)
	{
		if (win->ui.clicked_button
		&& win->ui.clicked_button->type == UI_BUTTON_TEXT_ENTRY)
		{
			if (win->event.key.keysym.scancode == SDL_SCANCODE_LEFT)
			{
				if (win->ui.cursor_position > 0)
					win->ui.cursor_position--;
			}
			if (win->event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
			{
				if (win->ui.cursor_position < (int)ft_strlen(
				((t_text_entry_button*)win->ui.clicked_button->data)->new_text))
					win->ui.cursor_position++;
			}
		}
	}
}

void			ui_update_ui(t_winui *win)
{
	ui_event(win);
	ui_resolve_buttons_event(win);
	ui_update_frames(win);
}
