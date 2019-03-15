#include "window.h"
#include "renderer.h"
//#include <stdio.h>

int		main()
{
	SDL_Window		*win;
	SDL_Renderer	*rend;

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
        return (1);
	if (!(win = open_window("test", 600, 600, 0)))
		return (1);
	if (!(rend = create_renderer(win, -1, 0)))
		return (1);
	set_win_pos(win, 50, 50);
	clear_rend(rend);
	SDL_Delay(5000);
	SDL_Quit();
	return (0);
}