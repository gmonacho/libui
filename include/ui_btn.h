#ifndef UI_BUTTON

#define UI_BUTTON

#include "ui_shape.h"

enum s_btn_type
{
  LOGO = 1,
  TEXT = 2,
  CHECKBOX = 3,
  PANEL = 4,
  OPTIONS = 5,
  ARROW = 6,
  SLIDER = 7,
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
  DRAW = 4,
  DRAG = 5
};


typedef struct s_texture
{
    t_rect pos;
    SDL_Texture *texture;
}             t_texture;

typedef struct  s_all_pos
{
  t_rect pos;
  SDL_Texture *texture;
}               t_all_pos;

typedef struct  s_arrow
{
  t_texture **texture;
  int       value;
  /*SDL_Texture *up_arrow_texture;
  SDL_Texture *down_arrow_texture;
  SDL_Texture *btn_value;
  t_rect      up_arrow;
  t_rect      down_arrow;
  t_rect      linked_btn;*/
}              t_arrow;

typedef struct  s_option
{
  t_rect pos;
  SDL_Texture *txt;
}              t_option;

typedef struct  s_checkbox
{
  t_rect pos;

}              t_checkbox;

typedef struct  s_modify_txt
{
  t_rect pos;

}              t_modify_txt;

typedef struct  s_btn
{
  t_rect      rect;
  SDL_Texture *texture;
  t_all_pos   **pos;
  t_arrow     arrow;
  int         value;
  t_option    option;
  t_checkbox  checkbox;
  t_modify_txt modify_txt;
  //t_slide      slide;
  int         type;
  int         state;
  int         action;
  int         count_pos;
}               t_btn;

SDL_Texture    *ui_create_text(char *str, char *police_path, SDL_Renderer *rend);
char		       *ft_itoa(int value);
t_btn          *ui_create_btn(int type, int action);
void           ui_add_btn_pos(t_btn *btn, t_rect new_pos, SDL_Texture *texture, int type);
void           ui_load_arrow_texture(t_btn *btn, SDL_Renderer *rend);
int            ui_render_arrow_btn(SDL_Renderer *rend, t_btn *btn, int x, int y);
void           ui_render_slider_btn(SDL_Renderer *rend, t_btn *btn, int x, int y);
void           ui_load_slider_texture(t_btn *btn, SDL_Renderer *rend, int mouse_x, int mouse_y);

#endif
