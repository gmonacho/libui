#include "window.h"
//#include <stdio.h>

int		main()
{
	SDL_Window	*win;

	if (!(win = open_window("test", 600, 600, 0)))
		return (1);
	set_win_pos(win, UI_WINPOS_CENTERED, UI_WINPOS_CENTERED);
	SDL_Delay(5000);
	SDL_Quit();
	return (0);
}