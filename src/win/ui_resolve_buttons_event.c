#include "ui_win.h"
#include "libft.h"

static void	ui_resolve_simple_button(t_win *win, t_simple_button *simple_button)
{
	if (simple_button->clicked_condition & win->mouse.releasing)
		simple_button->f(simple_button->argurment);
}

static void	ui_resolve_text_entry_button(t_win *win,
							t_text_entry_button *text_entry_button)
{
	int		nb;
	char	tmp[text_entry_button->max_text_size + 1];
	int		i;
	int		i_tmp;

	if (win->event.type == SDL_KEYDOWN)
	{
		if (win->event.key.keysym.scancode == SDL_SCANCODE_BACKSPACE
			&& win->ui.cursor_position > 0)
		{
			if (ft_strlen(text_entry_button->new_text) > 0)
			{
				if (text_entry_button->text_type == UI_TEXT_TYPE_DIGITAL)
					text_entry_button->new_text[
					ft_strlen(text_entry_button->new_text) - 1] = '\0';
				else
				{
					ft_bzero(tmp, text_entry_button->max_text_size + 1);
					ft_strncpy(tmp,
						&(text_entry_button->new_text[win->ui.cursor_position]),
						ft_strlen(&(text_entry_button->new_text[
							win->ui.cursor_position])));
					i = win->ui.cursor_position - 1;
					i_tmp = 0;
					while (tmp[i_tmp])
						text_entry_button->new_text[i++] = tmp[i_tmp++];
					text_entry_button->new_text[i] = '\0';
				}
			}
			win->ui.cursor_position--;
			if (win->ui.cursor_position < 0)
				win->ui.cursor_position = 0;
		}
	}
	if (win->event.type == SDL_TEXTINPUT)
	{
		if (text_entry_button->text_type & UI_TEXT_TYPE_DIGITAL)
		{
			if (ft_isdigit(win->event.text.text[0]) ||
			(win->event.text.text[0] == '-' && text_entry_button->min_int < 0))
			{
				if ((int)ft_strlen(text_entry_button->new_text) <=
					text_entry_button->max_text_size - 1)
				{
					ft_strcat(text_entry_button->new_text,
							win->event.text.text);
					nb = ft_atoi(text_entry_button->new_text);
					if (nb > text_entry_button->max_int ||
						nb < text_entry_button->min_int)
						text_entry_button->new_text[
							ft_strlen(text_entry_button->new_text) - 1] = '\0';
					win->ui.cursor_position++;
				}
			}
		}
		else
		{
			if ((int)ft_strlen(text_entry_button->new_text) <=
				text_entry_button->max_text_size - 1)
			{
				ft_bzero(tmp, text_entry_button->max_text_size + 1);
				ft_strncpy(tmp,
						&(text_entry_button->new_text[win->ui.cursor_position]),
						ft_strlen(&(text_entry_button->new_text[
									win->ui.cursor_position])));
				text_entry_button->new_text[win->ui.cursor_position] =
						win->event.text.text[0];
				i = win->ui.cursor_position + 1;
				i_tmp = 0;
				while (tmp[i_tmp])
					text_entry_button->new_text[i++] = tmp[i_tmp++];
				win->ui.cursor_position++;
			}
		}
	}
}

static void	ui_call_text_entry_function(t_text_entry_button *text_entry_button)
{
	if (text_entry_button->f)
		text_entry_button->f(text_entry_button->argument, text_entry_button->text);
}

static void	ui_mouse_releasing(t_win *win)
{
	if (win->mouse.releasing)
	{
		if (win->ui.clicked_button)
		{
			if (win->ui.clicked_button->type == UI_BUTTON_SIMPLE &&
				win->ui.clicked_button == win->ui.on_mouse_button)
				ui_resolve_simple_button(win, win->ui.clicked_button->data);
			if (win->ui.clicked_button->type != UI_BUTTON_TEXT_ENTRY)
				win->ui.clicked_button = NULL;
		}
	}
}

static void	ui_check_text_entry_button(t_win *win)
{
	if (win->ui.clicked_button && win->ui.clicked_button->type == UI_BUTTON_TEXT_ENTRY)
	{
		if ((win->mouse.clicking
			&& win->ui.on_mouse_button != win->ui.clicked_button)
			|| win->event.key.keysym.scancode == SDL_SCANCODE_RETURN)
		{
			SDL_StopTextInput();
			ft_strcpy(((t_text_entry_button*)
					win->ui.clicked_button->data)->text,
					((t_text_entry_button*)
					win->ui.clicked_button->data)->new_text);
			ft_bzero(((t_text_entry_button*)
					win->ui.clicked_button->data)->new_text,
					((t_text_entry_button*)
					win->ui.clicked_button->data)->max_text_size);
			ui_call_text_entry_function(win->ui.clicked_button->data);
			win->ui.clicked_button = NULL;
			win->ui.cursor_position = 0;
		}
		else
			ui_resolve_text_entry_button(win, win->ui.clicked_button->data);
	}
}

static void	ui_start_text_input(t_win *win)
{
	SDL_StartTextInput();
	printf("new_text = %s text = %s\n", ((t_text_entry_button*)win->ui.clicked_button->data)->new_text,
										((t_text_entry_button*)win->ui.clicked_button->data)->text);
	ft_strcpy(((t_text_entry_button*)
				win->ui.clicked_button->data)->new_text,
				((t_text_entry_button*)
				win->ui.clicked_button->data)->text);
	win->ui.cursor_position = ft_strlen(((t_text_entry_button*)
					win->ui.clicked_button->data)->new_text);
}

void		ui_resolve_buttons_event(t_win *win)
{
	t_frame				*f;
	t_button			*b;

	ui_mouse_releasing(win);
	ui_check_text_entry_button(win);
	f = win->ui.frames;
	while (f)
	{
		b = f->buttons;
		win->ui.on_mouse_button = NULL;
		while (b)
		{
			if (ui_is_dot_in_rect(win->mouse.pos, b->rect))
			{
				if (win->mouse.clicking &&
					!(win->ui.clicked_button &&
					win->ui.clicked_button->type == UI_BUTTON_TEXT_ENTRY &&
					win->ui.clicked_button == b))
				{
					win->ui.clicked_button = b;
					if (win->ui.clicked_button->type == UI_BUTTON_TEXT_ENTRY)
						ui_start_text_input(win);
				}
				win->ui.on_mouse_button = b;
			}
			b = b->next;
		}
		f = f->next;
	}
}
