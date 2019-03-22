#include "ui.h"
#include <stdio.h>

int		main()
{
	t_win			*win;
  int      is_pushed;
  int      prev_x;
  int      prev_y;
	SDL_Event			event;
  SDL_Texture *texture;
	int				loop;
	t_btn 		*btn;
	t_rect			r;

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
        return (1);

	win = ui_open_window("test", (t_dot){200, 200}, (t_len){1000, 1000}, UI_WIN_RESIZABLE);
	loop = 1;
	//btn = ui_create_btn(ARROW, 0);
	ui_set_draw_color(win->rend, 0x7f827a);
	//ui_add_btn_pos(btn, (t_rect){100, 410, 30, 20}, ui_create_text(ft_itoa(btn->value), "./ressource/police/arial.ttf", win->rend));
	//ui_add_btn_pos(btn, (t_rect){150, 400, 30, 10}, ui_load_img("./ressource/image/top-arrow.png", UI_PNG, win->rend));
	//ui_add_btn_pos(btn, (t_rect){150, 420, 30, 10}, ui_load_img("./ressource/image/down-arrow.png", UI_PNG, win->rend));

  btn = ui_create_btn(SLIDER, 0);
  ui_add_btn_pos(btn, (t_rect){100, 410, 30, 20}, ui_create_text(ft_itoa(btn->value), "./ressource/police/arial.ttf", win->rend), SLIDER);
  ui_add_btn_pos(btn, (t_rect){150, 400, 40, 30}, ui_load_img("./ressource/image/slider.png", UI_JPG, win->rend), SLIDER);
  ui_add_btn_pos(btn, (t_rect){150, 400, 100, 30}, NULL, SLIDER);

  texture = ui_create_bloc_texture(win->rend, (t_len){30, 100}, 0xFF005544, 0xFF0000FF);
  ui_load_slider_texture(btn, win->rend, 0, 0);
  //ui_draw_texture(win->rend, texture, (t_rect){100, 100, 50, 50});
	//ui_load_arrow_texture(btn, win->rend);
	ui_draw_rend(win->rend);
  is_pushed = 0;
  prev_x = 0;
  prev_y = 0;
	while (loop)
	{
	ui_update_event(UI_KEY_UPDATE);
    ui_set_draw_color(win->rend, 0x666666FF);
    SDL_WaitEvent(&event);
    set_click_event(event, btn, win->rend);
    if (ui_is_key_pressed(SDL_SCANCODE_Q, 0))
			loop = 0;
		r = (t_rect){0, 0, 100, 50};
    ui_draw_texture(win->rend, texture, (t_rect){100, 100, 50, 50});
    //ui_load_arrow_texture(btn, win->rend);
    if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
      is_pushed = 1;
    if(event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT)
      is_pushed = 0;

    if ((event.button.x >= btn->pos[1]->pos.x) && (event.button.y >= btn->pos[1]->pos.y)
    && (event.button.x < btn->pos[1]->pos.x + (int)btn->pos[1]->pos.w)
    && (event.button.y < btn->pos[1]->pos.y + (int)btn->pos[1]->pos.h))
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
