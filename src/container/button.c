/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   button.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/17 20:27:46 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/17 20:29:14 by thbrouss    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "SDL.h"
#include "ui_error.h"
#include "SDL_ttf.h"
#include "ui_draw.h"
#include "ui_image.h"
#include "ui_btn.h"

SDL_Texture   *ui_create_text(char *str, char *police_path, SDL_Renderer *rend)
{
 SDL_Surface  *txt;
 SDL_Texture  *texture;
 TTF_Font     *police;

 if (TTF_Init() == -1)
    return (ui_null_error(TTF_GetError()));
 if (!(police = TTF_OpenFont(police_path, 65)))
    return (ui_null_error(TTF_GetError()));
 if (!(txt = TTF_RenderText_Blended(police, str, (SDL_Color){255, 255, 255, 255})))
    return (ui_null_error(TTF_GetError()));
 if ((texture = SDL_CreateTextureFromSurface(rend, txt)) < 0)
    return (ui_null_error(SDL_GetError()));
 SDL_FreeSurface(txt);
 return (texture);
}

/*

----- Savoir si la souris est dans un triangle.

function ptInTriangle(p, p0, p1, p2) {
    var dX = p.x-p2.x;
    var dY = p.y-p2.y;
    var dX21 = p2.x-p1.x;
    var dY12 = p1.y-p2.y;
    var D = dY12*(p0.x-p2.x) + dX21*(p0.y-p2.y);
    var s = dY12*dX + dX21*dY;
    var t = (p2.y-p0.y)*dX + (p0.x-p2.x)*dY;
    if (D<0) return s<=0 && t<=0 && s+t>=D;
    return s>=0 && t>=0 && s+t<=D;
}
 */

void ui_add_btn_pos(t_btn *btn, t_rect new_pos)
{
  t_all_pos **dst_pos;
  int i;

  i = 0;
  if (!(dst_pos = malloc(sizeof(t_all_pos *) * (btn->count_pos + 1))))
    return ;
  while (i < btn->count_pos)
  {
      dst_pos[i] = malloc(sizeof(t_all_pos));
      dst_pos[i]->pos = btn->pos[i]->pos;
      i++;
  }
  dst_pos[i] = malloc(sizeof(t_all_pos));
  dst_pos[i]->pos = new_pos;
  btn->pos = dst_pos;
  btn->count_pos++;
}

void ui_load_arrow_texture(t_btn *btn, SDL_Renderer *rend)
{
    t_frame_dep dep;

    if (btn->count_pos == 3)
    {
      dep.r = btn->pos[0]->pos;
      dep.f_r = (t_rect){0, 0, 600, 600};
      ui_draw_texture(rend, ui_create_text(ft_itoa(btn->value), "./ressource/police/arial.ttf", rend), UI_ABSOLUTE, dep);
      dep.r = btn->pos[1]->pos;
      ui_draw_texture(rend, ui_load_img("./ressource/image/top-arrow.png", UI_PNG, rend), UI_ABSOLUTE, dep);
      dep.r = btn->pos[2]->pos;
      ui_draw_texture(rend, ui_load_img("./ressource/image/down-arrow.png", UI_PNG, rend), UI_ABSOLUTE, dep);
    }
}

t_btn *ui_create_btn(int type, int action)
{
  t_btn *btn;

  btn = malloc(sizeof(t_btn));
  btn->type = type;
  btn->value = 0;
  btn->action = action;
  btn->pos = NULL;
  btn->count_pos = 0;
  return (btn);
}
