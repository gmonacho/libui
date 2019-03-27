#ifndef UI_BUTTON

#define UI_BUTTON

#include "ui_shape.h"

# define MAX_BTN 30

enum s_btn_type
{
  LOGO = 1,
  TEXT = 2,
  CHECKBOX = 3,
  PANEL = 4,
  OPTIONS = 5,
  ARROW_UP = 6,
  ARROW_DOWN = 7,
  SLIDER = 15,
  V_LINE = 14,
  H_LINE = 17,
  ARROW = 12,
  SIMPLE = 18
};

enum s_state
{
  CHECKED = 1,
  UNCHECKED = 2,
  IS_PUSHED = 3,
  NOT_PUSHED = 4
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

typedef struct  s_btn
{
  t_rect      rect;
  SDL_Texture *texture;
  t_all_pos   **pos;
  int         value;
  int         key[MAX_BTN];
  int         type;
  int         state;
  int         action;
  int         count_pos;
  char        *name;
  int         color;
}               t_btn;

SDL_Texture    *ui_create_text(char *str, char *police_path, SDL_Renderer *rend);
char		       *ft_itoa(int value);
char           *ft_strdup(const char *s);
t_btn          *ui_create_btn(int type, int action, char *name, int color);
void           ui_add_btn_pos(t_btn *btn, t_rect new_pos, SDL_Texture *texture, int type);
void           ui_load_arrow_texture(t_btn *btn, SDL_Renderer *rend);
int            ui_render_arrow_btn(SDL_Renderer *rend, t_btn *btn, int x, int y);
void           ui_render_slider_btn(SDL_Renderer *rend, t_btn *btn, int x, int y);
void           ui_load_slider_texture(t_btn *btn, SDL_Renderer *rend, int mouse_x, int mouse_y);
void           ui_render_checkbox_btn(t_btn *btn, int x, int y);
void           ui_load_checkbox_btn(SDL_Renderer *rend, t_btn *btn);
void           ui_load_simple_btn(SDL_Renderer *rend, t_btn *btn);

#endif
