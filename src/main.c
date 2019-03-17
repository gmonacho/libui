#include "ui.h"
#include <stdio.h>

int		main()
{
	SDL_Window		*win;
	SDL_Renderer	*rend;
	int				loop;
	int				x;
	int				y;

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
        return (1);
	if (!(win = ui_open_window("test", 600, 600, UI_WIN_RESIZABLE)))
		return (1);
	if (!(rend = ui_create_renderer(win, -1, 0)))
		return (1);
	loop = 1;
	while (loop)
	{
		ui_update_event(UI_KEY_UPDATE);
		if (ui_is_key_pressed(UI_AT_LEAST_ONE, 0))
			printf("key pressed\n");
		if (ui_is_key_pressed(SDL_SCANCODE_ESCAPE, 0))
			loop = 0;
		if (ui_is_mouse_pressed(UI_AT_LEAST_ONE, &x, &y))
			printf("mouse pressed = %d, %d\n", x, y);
	}
	SDL_Quit();
	return (0);
}