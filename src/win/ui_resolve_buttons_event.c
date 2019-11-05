#include "ui_win.h"
#include "libft.h"

static void	ui_resolve_simple_button(ui_win *win, ui_simple_button *simple_button)
{
	if (simple_button->clicked_condition & win->mouse.releasing)
		simple_button->f(simple_button->argurment);
}

static void	ui_resolve_text_entry_button(ui_win *win, ui_text_entry_button *text_entry_button)
{		
	if (win->event.type == SDL_KEYDOWN)
	{
		if (win->event.key.keysym.scancode == SDL_SCANCODE_BACKSPACE)
		{
			if (ft_strlen(text_entry_button->new_text) > 0)
				text_entry_button->new_text[ft_strlen(text_entry_button->new_text) - 1] = '\0';
		}
	}
	if (win->event.type == SDL_TEXTINPUT)
	{

		if ((int)ft_strlen(text_entry_button->new_text) <= text_entry_button->max_text_size - 1)
        	ft_strcat(text_entry_button->new_text, win->event.text.text);
	}
}

void		ui_resolve_buttons_event(ui_win *win)
{
	ui_button			*b;

	if (win->mouse.releasing)
	{
		if (win->ui.clicked_button)
		{
			if (win->ui.clicked_button->type == UI_BUTTON_SIMPLE && win->ui.clicked_button == win->ui.on_mouse_button)
				ui_resolve_simple_button(win, win->ui.clicked_button->data);
			if (win->ui.clicked_button->type != UI_BUTTON_TEXT_ENTRY)
				win->ui.clicked_button = NULL;
		}
	}
	if (win->ui.clicked_button && win->ui.clicked_button->type == UI_BUTTON_TEXT_ENTRY)
	{
		if ((win->mouse.clicking && win->ui.on_mouse_button != win->ui.clicked_button) || win->event.key.keysym.scancode == SDL_SCANCODE_RETURN)
		{
			SDL_StopTextInput();
			ft_strcpy(((ui_text_entry_button*)win->ui.clicked_button->data)->text, ((ui_text_entry_button*)win->ui.clicked_button->data)->new_text);
			ft_bzero(((ui_text_entry_button*)win->ui.clicked_button->data)->new_text, ((ui_text_entry_button*)win->ui.clicked_button->data)->max_text_size);
			ui_resolve_simple_button(win, win->ui.clicked_button->data);
			win->ui.clicked_button = NULL;
		}
		else
			ui_resolve_text_entry_button(win, win->ui.clicked_button->data);		
	}
	b = win->ui.buttons;
	win->ui.on_mouse_button = NULL;
	while (b)
	{
		if (ui_is_dot_in_rect(win->mouse.pos, b->rect))
		{
			if (win->mouse.clicking && !(win->ui.clicked_button && win->ui.clicked_button->type == UI_BUTTON_TEXT_ENTRY && win->ui.clicked_button == b))
			{
				win->ui.clicked_button = b;
				if (win->ui.clicked_button->type == UI_BUTTON_TEXT_ENTRY)
				{
					SDL_StartTextInput();
					ft_strcpy(((ui_text_entry_button*)win->ui.clicked_button->data)->new_text, ((ui_text_entry_button*)win->ui.clicked_button->data)->text);
				}
			}
			win->ui.on_mouse_button = b;
		}
		b = b->next;
	}
}