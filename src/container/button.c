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

/*
** ui_create_text: Ajoute une texture texte.
** @param  str: le texte.
** @param  police_path: la police.
** @param  rend: le rendu.
** @return SDL_Texture.
*/
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

/* ------ TODO: detecter si la souris est dans un trianngle. --------

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

/*
** ui_add_btn_pos: Enregistre la position et la texture du boutton.
** @param btn: la structure boutton.
** @param new_pos: la position du boutton sur la fenêtre.
** @param texture: la texture à applquée sur le rendu.
*/
void ui_add_btn_pos(t_btn *btn, t_rect new_pos, SDL_Texture *texture)
{
  t_all_pos **dst_pos;
  int i;

  i = 0;
  if (!(dst_pos = malloc(sizeof(t_all_pos *) * (btn->count_pos + 1))))
    return ;
  while (i < btn->count_pos)
  {
      dst_pos[i] = malloc(sizeof(t_all_pos));
      dst_pos[i]->texture = btn->pos[i]->texture;
      dst_pos[i]->pos = btn->pos[i]->pos;
      i++;
  }
  dst_pos[i] = malloc(sizeof(t_all_pos));
  dst_pos[i]->pos = new_pos;
  dst_pos[i]->texture = texture;
  btn->pos = dst_pos;
  btn->count_pos++;
}

void ui_load_arrow_texture(t_btn *btn, SDL_Renderer *rend)
{
    if (btn->count_pos == 3)
    {
      ui_draw_texture(rend, ui_create_text(ft_itoa(btn->value), "./ressource/police/arial.ttf", rend), btn->pos[0]->pos);
      ui_draw_texture(rend, btn->pos[1]->texture, btn->pos[1]->pos);
      ui_draw_texture(rend, btn->pos[2]->texture, btn->pos[2]->pos);
    }
}

/*
** ui_render_arrow_btn: Applique les textures du bouton arrow.
** @param  rend: le rendu.
** @param  btn: la structure boutton.
** @param  x: la positon en x de la souris.
** @param  y: la position en y de la souris.
** @return 1 si l'utilisateur à clique sur le bouton, 0 dans le cas contraire.
*/
int  ui_render_arrow_btn(SDL_Renderer *rend, t_btn *btn, int x, int y)
{
  int i;
  int is_set;

  i = 0;
  is_set = 0;
  while (i < btn->count_pos)
  {
    if ((x >= btn->pos[i]->pos.x) && (y >= btn->pos[i]->pos.y)
    && (x < btn->pos[i]->pos.x + (int)btn->pos[i]->pos.w)
    && (y < btn->pos[i]->pos.y + (int)btn->pos[i]->pos.h))
    {
      if (btn->type == ARROW && i == 1)
      {
        btn->value++;
        ui_set_draw_color(rend, 0x7f827a, 255);
        ui_load_arrow_texture(btn, rend);
        is_set = 1;
      }
      if (btn->type == ARROW && i == 2 && btn->value > 0)
      {
        btn->value--;
        ui_set_draw_color(rend, 0x7f827a, 255);
        ui_load_arrow_texture(btn, rend);
        is_set = 1;
      }
    }
    i++;
  }
  return (is_set);
}

/*
** ui_create_btn: Création d'un bouton.
** @param  type: le type de boutton.
** @param  action: l'action associe au bouton.
** @return  struct btn.
**/
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
