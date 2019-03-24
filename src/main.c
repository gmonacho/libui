#include "ui.h"
#include <stdio.h>

int		main()
{
	t_win			*win;
	int      		is_pushed;
	int      		prev_x;
	int      		prev_y;
	SDL_Event		event;
	SDL_Texture		*texture;
	SDL_Texture		*src;
	SDL_Texture		*dst;
	int				loop;
	t_btn 			*btn;
	t_rect			r;
	t_len			resolution;

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
        return (1);
	win = ui_open_window("test", (t_dot){200, 200}, (t_len){1000, 1000}, UI_WIN_RESIZABLE);
	loop = 1;
	//btn = ui_create_btn(ARROW, 0);
	ui_set_draw_color(win->rend, 0x666666FF);
	//ui_add_btn_pos(btn, (t_rect){100, 410, 30, 20}, ui_create_text(ft_itoa(btn->value), "./ressource/police/arial.ttf", win->rend));
	//ui_add_btn_pos(btn, (t_rect){150, 400, 30, 10}, ui_load_img("./ressource/image/top-arrow.png", UI_PNG, win->rend));
	//ui_add_btn_pos(btn, (t_rect){150, 420, 30, 10}, ui_load_img("./ressource/image/down-arrow.png", UI_PNG, win->rend));
	src = ui_load_img("./ressource/image/teleteub.png", UI_PNG, win->rend);
	dst = ui_load_img("./ressource/image/top-arrow.png", UI_PNG, win->rend);
	printf("la2\n");
	ui_blit_texture(win->rend, src, dst, (t_frect){0.5, 0.4, 0.3, 0.5});
	btn = ui_create_btn(SLIDER, 0, "Test button", 0xffffffff);


	ui_add_btn_pos(btn, (t_rect){150, 400, 100, 30}, NULL, H_LINE);
	ui_add_btn_pos(btn, (t_rect){150, 400, 40, 30}, ui_load_img("./ressource/image/slider.png", UI_JPG, win->rend), SLIDER);
	//ui_add_btn_pos(btn, (t_rect){150, 400, 100, 30}, NULL, H_LINE);
	ui_add_btn_pos(btn, (t_rect){110, 410, 30, 20}, ui_create_text(ft_itoa(btn->value), "./ressource/police/arial.ttf", win->rend), TEXT);
	//ui_add_btn_pos(btn, (t_rect){150, 400, 40, 30}, ui_load_img("./ressource/image/slider.png", UI_JPG, win->rend), SLIDER);
	//ui_add_btn_pos(btn, (t_rect){100, 410, 30, 20}, ui_create_text(ft_itoa(btn->value), "./ressource/police/arial.ttf", win->rend), TEXT);
	//ui_add_btn_pos(btn, (t_rect){100, 410, 30, 20}, ui_create_text(ft_itoa(btn->value), "./ressource/police/arial.ttf", win->rend), TEXT);

	texture = ui_create_empty_texture(win->rend, (t_len){400, 100});
	resolution = ui_get_texture_resolution(texture);
	printf("x = %d, y = %d\n", resolution.x, resolution.y);
	ui_set_render_target(win->rend, texture);
	ui_fill_curved_rect(win->rend, (t_rect){0, 0, resolution.x - 1, resolution.y - 1}, 50, 0x5555FFAA);
	ui_draw_curved_rect(win->rend, (t_rect){0, 0, resolution.x - 1, resolution.y - 1}, 50, 0xAAAABBFF);
	ui_set_render_target(win->rend, NULL);
	ui_load_slider_texture(btn, win->rend, 0, 0);
	//ui_draw_texture(win->rend, texture, (t_rect){100, 100, 50, 50});
	//ui_load_arrow_texture(btn, win->rend);
	// evt.key.keysym.sym == SDLK_ESCAPE
	is_pushed = 0;
	prev_x = 0;
	prev_y = 0;
	// checkbox, simple btn : create_bloc_rect..., create_bloc_curl...
	while (loop)
	{
		ui_update_event(UI_KEY_UPDATE);
		ui_set_draw_color(win->rend, 0x666666FF);
		ui_clear_rend(win->rend);
		SDL_WaitEvent(&event);
		set_click_event(event, btn, win->rend);
		if (ui_is_key_pressed(SDL_SCANCODE_Q, 0))
				loop = 0;
		r = (t_rect){0, 0, 100, 50};
		//ui_draw_texture(win->rend, src, (t_rect){200, 500, 600, 300});
		//ui_fill_curved_rect(win->rend, (t_rect){300, 400, 200, 50}, 40, 0x5555FFAA);
		ui_draw_texture(win->rend, texture, (t_rect){100, 100, 400, 100});
		//ui_draw_texture(win->rend, texture, (t_rect){500, 500, 600, 600});
		ui_load_arrow_texture(btn, win->rend);
		if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
			is_pushed = 1;
		if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT)
			is_pushed = 0;
		if ((event.button.x >= btn->pos[btn->key[SLIDER] - 1]->pos.x) && (event.button.y >= btn->pos[btn->key[SLIDER] - 1]->pos.y)
			&& (event.button.x < btn->pos[btn->key[SLIDER] - 1]->pos.x + (int)btn->pos[btn->key[SLIDER] - 1]->pos.w)
			&& (event.button.y < btn->pos[btn->key[SLIDER] - 1]->pos.y + (int)btn->pos[btn->key[SLIDER] - 1]->pos.h))
		{
			if (event.type == SDL_MOUSEMOTION && is_pushed)
				ui_load_slider_texture(btn, win->rend, event.motion.x, event.motion.y);
			else
				ui_load_slider_texture(btn, win->rend, 0, 0);
		}
		else
			ui_load_slider_texture(btn, win->rend, 0, 0);
		ui_draw_rend(win->rend);
	}
	SDL_DestroyWindow(win->ptr);
	SDL_Quit();
	return (0);
}
