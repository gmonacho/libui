#include "ui.h"
#include <stdio.h>

int		main()
{
	SDL_Window		*win;
	SDL_Renderer	*rend;
	SDL_Texture		*texture;
	int				loop;
	t_rect			r;

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
        return (1);
	if (!(win = ui_open_window("test", 600, 600, UI_WIN_RESIZABLE)))
		return (1);
	if (!(rend = ui_create_renderer(win, -1, 0)))
		return (1);
	// char *str, char *police_path, SDL_Renderer *rend;
	//if (!(texture = ui_create_text("Test", "./ressources/police/arial.tff", rend)))
		//return (1);
	if (!(texture = ui_create_text("Test", "./ressource/police/Rastazm.ttf", rend)))
		SDL_GetError();
	//if (!())
	loop = 1;
	while (loop)
	{
		ui_update_event(UI_KEY_UPDATE);
		if (ui_is_key_pressed(SDL_SCANCODE_Q, 0))
			loop = 0;
		r = (t_rect){0, 0, 100, 50};
		ui_draw_texture(rend, texture, NULL, &r);
		ui_draw_rend(rend);
	}
	SDL_Quit();
	return (0);
}
