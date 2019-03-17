#ifndef UI_FRAME_H
# define UI_FRAME_H

# include "SDL.h"
# include "ui_shape.h"
# include "ui_btn.h"

/*
** Les frames sont des elements incontournables,
** la plupart des interfaces et fonction d'affichage en dependent
** Il est conseille de stocker les frames dans des listes chainees
** L'affichage se fera du premier au dernier
** r : zone permettant de delimiter l'affichage ect
** *name : nom du frame (id sous forme de chaine de caractere)
** *texture : pointeur sur la texture a afficher sur le frame
*/
typedef struct	s_frame
{
	t_rect			r;
	char			*name;
	SDL_Texture		*texture;
	t_btn 			*btn;
	int 			n_btn;
	struct s_frame	*next;
	/*
	**  Et pleins d'autres selon le besoin,
	**  mais reste coherent @!&*@$ de ta race !
	*/
}					t_frame;


t_frame		*ui_new_frame(t_rect rect,
						char *name,
						SDL_Texture *texture);
void		ui_add_frame_back(t_frame **frames, t_frame *new_frame);
void		ui_add_frame_n(t_frame **frames, t_frame *new_frame, int n);
t_frame		*ui_get_frame(t_frame **frames, char *name);
int			ui_add_button_to_frame(t_frame *frame, t_btn btn);

#endif
