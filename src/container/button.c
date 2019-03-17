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
#include "ui_shape.h"
#include "ui_error.h"
#include "ui_btn.h"
#include "SDL_ttf.h"

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

t_btn ui_create_btn(SDL_Texture *texture, int type, t_rect rect)
{
  t_btn btn;

  btn.rect = rect;
  btn.texture = texture;
  btn.type = type;
  return (btn);
}
