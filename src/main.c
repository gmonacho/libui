#include "ui.h"
#include <stdio.h>


void fillTexture(SDL_Renderer *renderer, SDL_Texture *texture, int r, int g, int b, int a)
{
    SDL_SetRenderTarget(renderer, texture);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderFillRect(renderer, NULL);
}

void prepareForRendering(SDL_Renderer *renderer)
{
    SDL_SetRenderTarget(renderer, NULL);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer, 255, 128, 128, 20);
}

int		main()
{
	t_win			*win;
	SDL_Event			event;
	int				loop;
	t_btn 		*btn;
	t_rect			r;

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
        return (1);

	printf("la\n");	
	win = ui_open_window("test", (t_dot){200, 200}, (t_len){1000, 1000}, UI_WIN_RESIZABLE);
	printf("la1\n");
	loop = 1;
	btn = ui_create_btn(ARROW, 0);
	ui_set_draw_color(win->rend, 0x7f827a, 255);
	ui_add_btn_pos(btn, (t_rect){30, 410, 100, 20});
	ui_add_btn_pos(btn, (t_rect){150, 400, 30, 10});
	ui_add_btn_pos(btn, (t_rect){150, 420, 30, 10});
	ui_load_arrow_texture(btn, win->rend);
	ui_draw_rend(win->rend);
	while (loop)
	{
		ui_update_event(UI_KEY_UPDATE);
		SDL_WaitEvent(&event);
		is_btn_clicked(event, btn, win->rend);
		if (ui_is_key_pressed(SDL_SCANCODE_Q, 0))
			loop = 0;
		r = (t_rect){0, 0, 100, 50};
		//ui_load_arrow_texture(btn, rend);
		//ui_draw_texture(rend, texture, NULL, &r);
		//ui_draw_rend(rend);
	}
	SDL_DestroyWindow(win->ptr);
	SDL_Quit();
	return (0);
}
