#ifndef UI_H
# define UI_H

# include <stdio.h>
# include "ui_win.h"
# include "ui_frame.h"
# include "ui_draw.h"
# include "libft.h"
# include "SDL.h"

int			ui_init(Uint32 sdl_flags);

char	    **skip_next_block(char **str);

char		*parse_str(char *str);

int			get_resize_type(const char *line);

int		    get_clicked_condition(const char *line);
char	    *get_next_flag(const char *flags);
char		**get_flags_tab(const char *flags);
int			get_ratio(const char *line, t_frect *ratio_ptr);
int			get_float(char *str, double *fnb_ptr);

int			get_frame_type(const char *line);
int			get_button_type(const char *line);

int			parse_frame(t_win *win, char **text, int *i);

int		    parse_buttons(SDL_Renderer *rend, t_frame *frame, char **text, int *i);

int			check_line_name(const char *line, const char *expected);
int			ui_load(const char *path, t_win *win);

#endif
