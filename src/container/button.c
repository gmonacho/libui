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
void ui_add_btn_pos(t_btn *btn, t_rect new_pos, SDL_Texture *texture, int type)
{
  t_all_pos **dst_pos;
  int i;

  i = 0;
  if (!(dst_pos = malloc(sizeof(t_all_pos *) * (btn->count_pos + 1))))
    return ;
  while (i < btn->count_pos)
  {
      dst_pos[i] = malloc(sizeof(t_all_pos));
      if (btn->pos[i]->texture != NULL)
        dst_pos[i]->texture = btn->pos[i]->texture;
      dst_pos[i]->pos = btn->pos[i]->pos;
      i++;
  }
  dst_pos[i] = malloc(sizeof(t_all_pos));
  dst_pos[i]->pos = new_pos;
  if (texture != NULL)
    dst_pos[i]->texture = texture;
  btn->pos = dst_pos;
  btn->count_pos++;
  if (type < MAX_BTN)
    btn->key[type] = btn->count_pos;
}

/*
** ui_load_slider_texture: charge la texture du bouton et sa valeur en fonction de la position de la souris.
** @param btn: la structure boutton.
** @param rend: le rendu.
** @param mouse_x: la positon de la souris en x.
** @param mouse_y: la positon de la souris en y.
*/
void ui_load_slider_texture(t_btn *btn, SDL_Renderer *rend, int mouse_x, int mouse_y)
{
  int    m_x;
  t_rect pos_slider;
  t_rect pos_line;
  SDL_Texture *btn_texture;

  m_x = mouse_x;
  btn_texture = NULL;
  if ((btn->count_pos == 2 || btn->count_pos == 3) && btn->type == SLIDER)
  {
    if ((btn->key[SLIDER]) != 0 && (btn->key[H_LINE] != 0 || btn->key[V_LINE] != 0))
    {
      pos_slider = btn->pos[btn->key[SLIDER] - 1]->pos;
      btn_texture = btn->pos[btn->key[SLIDER] - 1]->texture;
      pos_line = (btn->key[V_LINE] != 0) ? btn->pos[(btn->key[V_LINE] - 1)]->pos : btn->pos[(btn->key[H_LINE] - 1)]->pos;
      SDL_SetRenderDrawColor(rend, (btn->color >> 24) & 0xFF, (btn->color >> 16) & 0xFF, (btn->color >> 8) & 0xFF, btn->color & 0xFF);
      // Vertical btn.
      if (btn->key[V_LINE] != 0)
      {
        btn->value = ((int)pos_line.y + ((int)pos_line.w)) - mouse_y;
        SDL_RenderDrawLine(rend, pos_line.x, pos_line.y, pos_line.x, pos_line.y + pos_line.w);
        if ((mouse_y != 0 && (mouse_y <= ((int)pos_line.y + ((int)pos_line.w))) && mouse_y >= (int)pos_line.y))
        {
          ui_draw_texture(rend, btn_texture, (t_rect){pos_line.x - (pos_slider.w / 2),
            pos_slider.y - ((pos_slider.y + (pos_slider.h / 2)) - mouse_y), pos_slider.w, pos_slider.h});

          btn->pos[btn->key[SLIDER] - 1]->pos.x = pos_line.x - (pos_slider.w / 2);
          btn->pos[btn->key[SLIDER] - 1]->pos.y = pos_slider.y - ((pos_slider.y + (pos_slider.h / 2)) - mouse_y);
        }
        else
        {
          if (btn->key[SLIDER] != 0)
          {
            ui_draw_texture(rend, btn->pos[(btn->key[SLIDER] - 1)]->texture, (t_rect){pos_line.x - (pos_slider.w / 2),
              pos_slider.y, pos_slider.w, pos_slider.h});
          }
        }
      }
      // Horizontal btn.
      if (btn->key[H_LINE] != 0)
      {
        SDL_RenderDrawLine(rend, pos_line.x, pos_line.y, pos_line.x + pos_line.w, pos_line.y);
        if ((m_x != 0 && (m_x <= ((int)pos_line.x + ((int)pos_line.w))) && m_x >= (int)pos_line.x))
        {
          btn->value = ((int)pos_line.x + ((int)pos_line.w)) - mouse_x;
          ui_draw_texture(rend, btn_texture, (t_rect){pos_slider.x - ((pos_slider.x + (pos_slider.w / 2)) - m_x),
          pos_line.y - (pos_slider.h / 2), pos_slider.w, pos_slider.h});

          btn->pos[btn->key[SLIDER] - 1]->pos.x = pos_slider.x - ((pos_slider.x + (pos_slider.w / 2)) - m_x);
          btn->pos[btn->key[SLIDER] - 1]->pos.y = pos_line.y - (pos_slider.h / 2);
        }
        else
        {
          if (btn->key[SLIDER] != 0)
          {
            ui_draw_texture(rend, btn->pos[btn->key[SLIDER] - 1]->texture, (t_rect){pos_slider.x,
            pos_line.y - (pos_slider.h / 2), pos_slider.w, pos_slider.h});
          }
        }
      }
    }
  }
  if (btn->count_pos == 3 && btn->count_pos > 1 && btn->key[TEXT] != 0)
    ui_draw_texture(rend, ui_create_text(ft_itoa(btn->value), "./ressource/police/arial.ttf", rend),
    btn->pos[btn->key[TEXT] - 1]->pos);
}

/*
** ui_render_slider_btn: une fonction à enlever ?
** @param rend: le rendu.
** @param btn: la structure boutton.
** @param x: la positon de la souris en x.
** @param y: la positon de la souris en y.
*/
void ui_render_slider_btn(SDL_Renderer *rend, t_btn *btn, int x, int y)
{
    int i;

    i = 0;
    while (i < btn->count_pos)
    {
      if ((x >= btn->pos[i]->pos.x) && (y >= btn->pos[i]->pos.y)
      && (x < btn->pos[i]->pos.x + (int)btn->pos[i]->pos.w)
      && (y < btn->pos[i]->pos.y + (int)btn->pos[i]->pos.h))
      {
        if (btn->type == SLIDER && i == 1)
        {
          btn->value++;
          ui_set_draw_color(rend, 0x7f827a);
          ui_load_slider_texture(btn, rend, x, y);
        }
      }
      i++;
    }
}

/*
** ui_load_arrow_texture: charge la texture du boutton en fonction de sa valeur.
** @param btn: la structure boutton.
** @param rend: le rendu.
*/
void ui_load_arrow_texture(t_btn *btn, SDL_Renderer *rend)
{
    if ((btn->count_pos == 2 || btn->count_pos == 3) && btn->type == ARROW)
    {
      if (btn->key[ARROW_UP] != 0 && btn->key[ARROW_DOWN] != 0)
      {
        ui_draw_texture(rend, btn->pos[btn->key[ARROW_UP] - 1]->texture, btn->pos[btn->key[ARROW_UP] - 1]->pos);
        ui_draw_texture(rend, btn->pos[btn->key[ARROW_DOWN] - 1]->texture, btn->pos[btn->key[ARROW_DOWN] - 1]->pos);
      }
    }
    if (btn->count_pos == 3 && btn->count_pos > 1 && btn->key[TEXT] != 0)
      ui_draw_texture(rend, ui_create_text(ft_itoa(btn->value), "./ressource/police/arial.ttf", rend), btn->pos[btn->key[TEXT] - 1]->pos);
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
      if (btn->type == ARROW && btn->key[ARROW_UP] != 0 && i == btn->key[ARROW_UP] - 1)
      {
        btn->value++;
        ui_set_draw_color(rend, 0x7f827a);
        ui_load_arrow_texture(btn, rend);
        is_set = 1;
      }
      if (btn->type == ARROW && btn->key[ARROW_DOWN] != 0 && btn->value > 0 && i == btn->key[ARROW_DOWN] - 1)
      {
        btn->value--;
        ui_set_draw_color(rend, 0x7f827a);
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
t_btn *ui_create_btn(int type, int action, char *name, int color)
{
  t_btn *btn;
  int i;

  i = 0;
  btn = malloc(sizeof(t_btn));
  btn->type = type;
  btn->color = color;
  btn->name = ft_strdup(name);
  if (type == SLIDER)
    btn->value = 100;
  while (i < MAX_BTN)
  {
    btn->key[i] = 0;
    i++;
  }
  btn->action = action;
  btn->pos = NULL;
  btn->count_pos = 0;
  return (btn);
}
