#include "SDL.h"
#include "ui_error.h"
#include "libft.h"
#include "ui_renderer.h"
#include "ui_frame.h"
#include "ui_window.h"

t_win			*ui_open_window(const char *title, t_dot pos, t_len size, Uint32 flags)
{
	t_win		*win;

	if (!(win = (t_win*)ft_memalloc(sizeof(t_win))))
		return (ui_null_perror("t_win allocation failed in ui_open_window\n"));
	if (!(win->ptr = SDL_CreateWindow(title, pos.x, pos.y, size.x, size.y, flags)))
	{
		ft_putstr_fd(SDL_GetError(), 2);
			return (ui_null_error(SDL_GetError()));
	}
	if (!(win->rend = SDL_CreateRenderer(win->ptr, -1, SDL_RENDERER_ACCELERATED)))
	{
		ft_putstr_fd(SDL_GetError(), 2);
			return (ui_null_error(SDL_GetError()));
	}
	SDL_SetRenderDrawBlendMode(win->rend, SDL_BLENDMODE_BLEND);
	win->pos = pos;
	win->size = size;
	win->frames = NULL;
	return (win);
}

void			ui_update_window(t_win *win)
{
	SDL_GetWindowPosition(win->ptr, &(win->pos.x), &(win->pos.y));
	SDL_GetWindowSize(win->ptr, (int*)&(win->size.x), (int*)&(win->size.y));
}

int			ui_add_frame_to_win(t_win *win, t_frame *frame)
{
	t_frame	**new_tab;
	t_frame **tmp;
	int		i;

	if (!(new_tab = (t_frame**)ft_memalloc(sizeof(t_frame*) * (win->n_frames + 1))))
		return (ui_perror("new frame allocation failed in ui_update_window\n"));
	i = 0;
	while (i < win->n_frames)
	{
		new_tab[i] = win->frames[i];
		i++;
	}
	new_tab[i] = frame;
	tmp = win->frames;
	win->frames = new_tab;
	win->n_frames++;
	free(tmp);
	return (1);
}

void	ui_draw_window(t_win *win)
{
	int		i;

	i = 0;
	while (i < win->n_frames)
	{
		ui_draw_frame(win->rend, win->frames[i]);
		i++;
	}
}

/*int				ui_add_frame_to_win_n(t_win *win, t_frame *frame, int n)
{
	t_frame	**new_tab;
	t_frame **tmp;
	int		i;

	if (!(new_tab = (t_frame**)ft_memalloc(sizeof(t_frame*) * win->n_frames)))
		return (ui_perror("new frame allocation failed in ui_update_window\n"));
	i = 0;
	while (i < win->n_frames)
	{
		new_tab[i] = win->frames[i];
		i++;
	}
	new_tab[i] = frame;
	tmp = win->frames;
	win->frames = new_tab;
	free(tmp);
	return (1);
}*/
