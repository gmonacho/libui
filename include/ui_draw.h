#ifndef DRAW_H
# define DRAW_H

# include "SDL.h"
# include "ui_frame.h"
# include "ui_renderer.h"

enum	s_type_texture_draw
{
	UI_ABSOLUTE = 1,
	UI_RESPONSIVE = 2,
	UI_PROPORTIONAL = 6
};

enum	s_circle_corner
{
	UI_ALL_CORNER = 00001111,
	UI_UPRIGHT_CORNER = 00000001,
	UI_DOWNRIGHT_CORNER = 00000010,
	UI_DOWNLEFT_CORNER = 00000100,
	UI_UPLEFT_CORNER = 00001000
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
void	ui_draw_circle(SDL_Renderer *rend, t_dot p, int radius, int color, int corner_flag);
void	ui_fill_circle(SDL_Renderer *rend, t_dot p, int radius, int color, int corner_flag);
void	ui_draw_rect(SDL_Renderer *rend, t_rect rect, int color);
void	ui_fill_rect(SDL_Renderer *rend, t_rect rect, int color);
void	ui_draw_curved_rect(SDL_Renderer *rend, t_rect rect, int radius, int color);
void	ui_fill_curved_rect(SDL_Renderer *rend, t_rect rect, int radius, int color);

#endif
