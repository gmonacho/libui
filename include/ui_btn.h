#ifndef UI_BUTTON

#define UI_BUTTON

# include "ui_shape.h"

enum s_btn_type
{
  LOGO = 1,
  TEXT = 2,
  CHECKBOX = 3,
  PANEL = 4,
  OPTIONS = 5,
  ARROW = 6,
  SLIDE = 7,
  SCROLL = 8
};

enum s_btn_display
{
  SHOW_CONTENT = 1,
  SHOW_OPTIONS = 2,
  SELECT_BTN = 3,
  DEC_VALUE = 4,
  INC_VALUE = 5,
  MODIFY_TXT = 6,
  MODIFY_SLIDE = 7,
  NAVIGUATE = 8
};

enum s_btn_action
{
  OPEN_WINDOW = 1,
  ADD_CONTENT = 2,
  PREV_CONTENT = 3,
  DRAW = 4
};

typedef struct  s_btn
{
  t_rect      rect;
  SDL_Texture *texture;
  int         type;
  int         event;
}               t_btn;

SDL_Texture   *ui_create_text(char *str, char *police_path, SDL_Renderer *rend);
t_btn          ui_create_btn(SDL_Texture *texture, int type, t_rect rect);

#endif
