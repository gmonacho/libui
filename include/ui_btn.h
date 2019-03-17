#ifndef UI_BUTTON

#define UI_BUTTON

# include "ui_shape.h"

enum s_btn_type
{
  LOGO = 1,
  TEXT = 2
};

typedef struct  s_btn
{
  t_rect      rect;
  SDL_Texture *texture;
  int         type;
}               t_btn;

SDL_Texture   *ui_create_text(char *str, char *police_path, SDL_Renderer *rend);
t_btn          ui_create_btn(SDL_Texture *texture, int type, t_rect rect);

#endif
