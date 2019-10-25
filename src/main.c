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
	if (!(win = ui_new_win("libui",
							(ui_rect){SDL_WINDOWPOS_CENTERED,
							SDL_WINDOWPOS_CENTERED,
							1200,
							800},
							0,
							SDL_RENDERER_ACCELERATED)))
		return (1);

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");

	TTF_Font	*font;
	SDL_Texture	*texture;
	
	if (!(font = ui_load_font("font/Raleway-Regular.ttf", 100)))
		return (1);
	if (!(texture = ui_new_text(win->rend, font, "button", &(SDL_Color){255, 255, 255, 255})))
		return (1);

	/////////////////////////////////////////////////////////
	////////////////////// ADD_BUTTONS //////////////////////
	/////////////////////////////////////////////////////////

	int				value = 0;
	ui_simple_set	simple_set;


	simple_set.normal = ui_load_image(win->rend, "texture/normal_button.png");
	simple_set.clicked = ui_load_image(win->rend, "texture/clicked_button.png");
	simple_set.on_mouse = ui_load_image(win->rend, "texture/on_mouse_button.png");
	ui_add_button(&win->ui.buttons,
				  ui_new_button(UI_BUTTON_SIMPLE, UI_RESIZE_NONE,
				  (ui_frect){0.1, 0.1, 0.1, 0.1},
				  ui_new_simple_button(UI_MOUSE_LEFT,
				  					   &incre_value,
									   &value,
									   simple_set)));

	/////////////////////////////////////////////////////////
	///---------------------------------------------------///
	/////////////////////////////////////////////////////////
	
	/////////////////////////////////////////////////////////
	///////////////////////// LOOP. /////////////////////////
	/////////////////////////////////////////////////////////

	loop = 1;
	while (loop)
	{
		printf("value = %d\n", value);
		ui_set_draw_color(win->rend, &(SDL_Color){100, 100, 100, 255});
		ui_clear_win(win);
		ui_display_buttons(win->rend, win->ui.buttons);
		// SDL_RenderCopy(win->rend, texture, NULL, NULL);
		ui_draw_text(win->rend, font, &(ui_text){"voilatrucmuch on s'ammuse\ngrosse ambiance putain\nCordialement\n",
												20,
												&(SDL_Color){255, 255, 255, 255},
												(ui_dot){200, 200}, TEXT_ALIGN_LEFT});
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
