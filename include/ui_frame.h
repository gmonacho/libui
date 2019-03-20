#ifndef UI_FRAME_H
# define UI_FRAME_H

# include "SDL.h"
# include "ui_shape.h"
# include "ui_struct_2d.h"
# include "ui_btn.h"


typedef struct	s_frame
{
	t_rect			rect;
	SDL_Texture		*texture;
	t_btn 			*btn;
	int				n_btn;
	/*
	**  Et pleins d'autres selon le besoin,
	**  mais reste coherent @!&*@$ de ta race !
	*/
}					t_frame;

t_frame				*ui_new_frame(t_rect rect, char *name, SDL_Texture *texture);

/*
**	=========================== Manage Frame ==========================
*/

void		ui_set_frame_rect(t_frame *frame, int x, int y, t_len size);
void		ui_move_frame(t_frame *frame, int dx, int dy);
void		ui_resize_frame(t_frame *frame, int dw, int dh);

/*
**	======================= Manage Frame's Butttons =====================
*/

int			ui_add_button_to_frame(t_frame *frame, t_btn btn);

#endif
