#include "ui.h"

void	incre_value(void *value)
{
	int	*int_value;

	int_value = value;
	*int_value += 1;
}

int		main()
{
	ui_win		*win;
	int			loop;

	if (ui_init(SDL_INIT_VIDEO) < 0)
		return (1);
		
	/////////////////////////////////////////////////////////
	//////////////////////// WINDOW. ////////////////////////
	/////////////////////////////////////////////////////////

	if (!(win = ui_new_win("libui",
							(ui_rect){SDL_WINDOWPOS_CENTERED,
							SDL_WINDOWPOS_CENTERED,
							1000,
							1000},
							SDL_WINDOW_RESIZABLE,
							SDL_RENDERER_ACCELERATED)))
		return (1);

	SDL_Texture	*texture;
	
	if (!(win->ui.button_font = ui_load_font("font/Raleway-Regular.ttf", 100)))
		return (1);
	if (!(texture = ui_new_text(win->rend, win->ui.button_font, "button", &(SDL_Color){255, 255, 255, 255})))
		return (1);

	/////////////////////////////////////////////////////////
	///---------------------------------------------------///
	/////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////
	////////////////////// ADD_BUTTONS //////////////////////
	/////////////////////////////////////////////////////////

	int					value = 0;
	ui_simple_set		simple_set;
	ui_text_entry_set	text_entry_set;

	simple_set.normal = ui_load_image(win->rend, "textures/ui_normal_button.png");
	simple_set.clicked = ui_load_image(win->rend, "textures/ui_clicked_button.png");
	simple_set.on_mouse = ui_load_image(win->rend, "textures/ui_on_mouse_button.png");
	ui_add_button(&win->ui.buttons,
				  ui_new_button(UI_BUTTON_SIMPLE, UI_RESIZE_ALL_LINEAR,
				  (ui_frect){0.1, 0.1, 0.09, 0.03},
				  ui_new_simple_button(UI_MOUSE_LEFT,
				  					   &incre_value,
									   &value,
									   simple_set)));
	((ui_simple_button*)win->ui.buttons->data)->text = "button";

	ui_add_button(&win->ui.buttons,
				  ui_new_button(UI_BUTTON_SIMPLE, UI_RESIZE_ALL_LINEAR,
				  (ui_frect){0.1, 0.3, 0.09, 0.03},
				  ui_new_simple_button(UI_MOUSE_LEFT,
				  					   &incre_value,
									   &value,
									   simple_set)));
	((ui_simple_button*)win->ui.buttons->data)->text = "button";

	text_entry_set.name_side_texture = NULL;
	text_entry_set.normal_box_texture = ui_load_image(win->rend, "textures/ui_text_entry_button_normal.png");
	text_entry_set.writting_box_texture = ui_load_image(win->rend, "textures/ui_text_entry_button_writting.png");
	text_entry_set.name_side_texture = ui_load_image(win->rend, "textures/ui_text_entry_button_normal.png");
	ui_add_button(&win->ui.buttons,
				  ui_new_button(UI_BUTTON_TEXT_ENTRY,
				  UI_RESIZE_ALL_LINEAR,
				  (ui_frect){0.4, 0.1, 0.09, 0.03},
				  ui_new_text_entry_button("nom", NULL, UI_TEXT_SIDE_LEFT, 10)));
	((ui_text_entry_button*)win->ui.buttons->data)->textures = text_entry_set;
	ui_update_buttons_rect(win, SDL_TRUE);

	/////////////////////////////////////////////////////////
	///---------------------------------------------------///
	/////////////////////////////////////////////////////////
	
	/////////////////////////////////////////////////////////
	///////////////////////// LOOP. /////////////////////////
	/////////////////////////////////////////////////////////

	loop = 1;
	while (loop)
	{
		ui_set_draw_color(win->rend, &(SDL_Color){50, 50, 50, 255});
		ui_clear_win(win);
		ui_display_buttons(win, win->ui.buttons);
		// SDL_RenderCopy(win->rend, texture, NULL, NULL);
		// ui_draw_text(win->rend, font, &(ui_text){"voilatrucmuch on s'ammuse\ngrosse ambiance putain\nCordialement\n",
		// 										20,
		// 										&(SDL_Color){200, 200, 255, 255},
		// 										(ui_dot){200, 200}, TEXT_ALIGN_LEFT});
		ui_set_draw_color(win->rend, &(SDL_Color){255, 0, 0, 255});
		ui_draw_rect(win->rend, &(ui_rect){400, 200, 200, 200});
		ui_draw_text_in_rect(win->rend, &(ui_text){"11111111111111111 222222222222222222222222222 222222222222222222",
												20,
												win->ui.button_font,
												(SDL_Color){200, 200, 200, 255},
												(ui_dot){200, 200},
												TEXT_ALIGN_LEFT | TEXT_ALIGN_V_MIDDLE},
												(ui_rect){400, 200, 200, 200}, UI_DRAW_TEXT_HIDE_LEFT);
		ui_draw_rend(win);
		ui_wait_event(&win->event);
		ui_update_ui(win);
		if (win->event.type == SDL_QUIT)
			loop = 0;
	}

	/////////////////////////////////////////////////////////
	///---------------------------------------------------///
	/////////////////////////////////////////////////////////

	return (0);
}
