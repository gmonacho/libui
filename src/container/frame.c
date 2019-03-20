#include "SDL.h"
#include "libft.h"
#include "ui_btn.h"
#include "ui_error.h"
#include "ui_shape.h"
#include "ui_struct_2d.h"
#include "ui_draw.h"
#include "ui_frame.h"

t_frame				*ui_new_frame(t_rect rect, char *name, SDL_Texture *texture)
{
	t_frame			*new_frame;

	if (!(new_frame = (t_frame*)ft_memalloc(sizeof(t_frame))))
		return (ui_null_perror("new_frame allocation failed in ui_new_frame\n"));
	if (name)
	{
		new_frame->rect = rect;
		new_frame->texture = texture;
		new_frame->btn = NULL;
		new_frame->n_btn = 0;
		return (new_frame);
	}
	else
		return (NULL);
}

int					ui_add_button_to_frame(t_frame *frame, t_btn btn)
{
	int				i;
	t_btn			*new_btn;
	t_btn			*tmp;

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

void				ui_set_frame_rect(t_frame *frame, int x, int y, t_len size)
{
	frame->rect.x = x;
	frame->rect.y = y;
	frame->rect.w = size.x;
	frame->rect.h = size.y;
}

void				ui_move_frame(t_frame *frame, int dx, int dy)
{
	frame->rect.x += dx;
	frame->rect.y += dy;
}

void				ui_resize_frame(t_frame *frame, int dw, int dh)
{
	frame->rect.w += dw;
	frame->rect.h += dh;
}

void				ui_draw_frame(SDL_Renderer *rend, t_frame *frame)
{
	ui_draw_texture(rend, frame->texture, frame->rect);
}