#ifndef DRAW_H
# define DRAW_H

# include "SDL.h"
# include "ui_frame.h"
# include "ui_renderer.h"

enum	e_arc
{
	ARC45 = 2,
	ARC90 = 4,
	ARC135 = 8, 
	ARC180 = 16, 
	ARC225 = 32, 
	ARC270 = 64, 
	ARC315 = 128, 
	ARC360 = 256, 
	ARCFULL = 510
};

typedef struct		s_frame_dep
{
	t_rect			f_r;
	t_rect			r;
}					t_frame_dep;

typedef struct      s_draw
{
    SDL_Renderer    *rend;
	t_frame			*frame;
    Uint32			draw_texture_flag;
	SDL_Texture		**texture;
}                   t_draw;

void    ui_draw_point(SDL_Renderer *rend, int x, int y, t_frame *frame);
void	ui_draw_texture(SDL_Renderer *rend, SDL_Texture *texture, t_rect dst);
void	ui_draw_texture(SDL_Renderer *rend, SDL_Texture *texture, t_rect dst);
void	ui_draw_arc(SDL_Renderer *rend, t_circle circle, int flags_arc, int color);
void	ui_fill_arc(SDL_Renderer *rend, t_circle circle, int arc, int color);
void	ui_draw_rect(SDL_Renderer *rend, t_rect rect, int border_width, int color);
void	ui_fill_rect(SDL_Renderer *rend, t_rect rect, int color);
void	ui_draw_curved_rect(SDL_Renderer *rend, t_curved_rect rect, int border_width, int color);
void	ui_fill_curved_rect(SDL_Renderer *rend, t_curved_rect rect, int color);

#endif
