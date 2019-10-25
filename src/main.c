#include "ui.h"

int		main()
{
	ui_win	*win;
	int		loop;

	if (ui_init(SDL_INIT_VIDEO) < 0)
		return (1);
	if (!(win = ui_create_win("libui",
							(ui_rect){SDL_WINDOWPOS_CENTERED,
							SDL_WINDOWPOS_CENTERED,
							1200,
							800},
							0,
							SDL_RENDERER_ACCELERATED)))
		return (1);
	loop = 1;
	while (loop)
	{
		ui_set_draw_color(win, (SDL_Color){100, 100, 100, 255});
		ui_clear_win(win);
		ui_draw_rend(win);
		ui_wait_event(&win->event);
		if (win->event.type == SDL_QUIT)
			loop = 0;
	}
	return (0);
}
