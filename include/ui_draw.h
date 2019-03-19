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

typedef struct      s_draw
{
    SDL_Renderer    *rend;
	t_frame			*frame;
    Uint32			draw_texture_flag;
	SDL_Texture		**texture;
}                   t_draw;



void    ui_draw_point(SDL_Renderer *rend, int x, int y, t_frame *frame);
void	ui_draw_texture(SDL_Renderer *rend, SDL_Texture *texture, Uint32 type_draw, t_rect f_r, t_frect r);
void	ui_draw_texture_abs(SDL_Renderer *rend, SDL_Texture *texture, t_rect f_r, t_frect r);
/*void			ui_draw_full_texture_resp(SDL_Renderer *rend,
										SDL_Texture *texture,
										t_rect frame_r,
										t_frect resp_r);*/

#endif