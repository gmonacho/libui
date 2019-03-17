#include "SDL.h"
#include "libft.h"
#include "ui_btn.h"
#include "ui_error.h"
#include "ui_shape.h"
#include "ui_frame.h"

/*
** @brief  ui_new_frame (nouveau cadre)
** @note   alloue un nouveau maillon frame
** @param  rect: position et dimension du frame
** @param  color: couleur par default du frame
** @param  *name: nom identificateur du frame
** @retval le noubeau maillon frame ou NULL si erreur
*/
t_frame			*ui_new_frame(t_rect rect, char *name, SDL_Texture *texture)
{
	t_frame		*new_frame;

	if (name)
	{
		if (!(new_frame = (t_frame*)ft_memalloc(sizeof(t_frame*))))
			return (ui_null_error("ui_new_frame : error memory allocation"));
		new_frame->r = rect;
		new_frame->name = name;
		new_frame->texture = texture;
		new_frame->btn = NULL;
		new_frame->n_btn = 0;
		new_frame->next = NULL;
		return (new_frame);
	}
	else
		return (ui_null_error("ui_new_frame : invalid frame name (NULL?)"));
}

/*
** @brief  ui_add_frame_back
** @note   ajoute un element frame a la liste passe en parametre
** @param  **frames: pointeur sur la liste de frame
** @param  *new_frame: l'element frame a ajouter en fin de liste
** @retval None
*/
void			ui_add_frame_back(t_frame **frames, t_frame *new_frame)
{
	t_frame		*tmp;

	tmp = *frames;
	if (!tmp)
		tmp = new_frame;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_frame;
	}
}

/*
** @brief  ui_add_frame_n
** @note   ajoute un element frame a la liste a la position n
** @param  **frames: pointeur sur la liste de frame
** @param  *new_frame: l'element frame a ajouter en position n
** @param  n: position ou ajouter le frame
** @retval None
*/
void			ui_add_frame_n(t_frame **frames, t_frame *new_frame, int n)
{
	t_frame		*tmp;
	int			i;

	tmp = *frames;
	if (!tmp)
		tmp = new_frame;
	else
	{
		i = 0;
		while (i < n)
			tmp = tmp->next;
		tmp->next = new_frame;
	}
}

/*
** @brief  ui_get_frame
** @note   retourne l'element frame demande si existant
** @param  **frames: pointeur sur la liste de frame
** @param  *name: nom du frame voulu
** @retval frame dont le nom correspond a celui donne en parametre
*/
t_frame			*ui_get_frame(t_frame **frames, char *name)
{
	t_frame		*tmp;

	tmp = *frames;
	while (tmp)
	{
		if (tmp->name == name)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int				ui_add_button_to_frame(t_frame *frame, t_btn btn)
{
	int		i;
	t_btn	*new_btn;
	t_btn	*tmp;

	if (!(new_btn = (t_btn*)ft_memalloc(sizeof(t_btn) * frame->n_btn + 1)))
		return (ui_error("Allocation Buttons Failed"));
	i = 0;
	while (i < frame->n_btn)
	{
		new_btn[i] = frame->btn[i];
		i++;
	}
	new_btn[i] = btn;
	tmp = frame->btn;
	frame->btn = new_btn;
	frame->n_btn++;
	free(tmp);
	return (1);
}