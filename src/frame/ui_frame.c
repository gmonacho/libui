#include "ui_frame.h"
#include "libft.h"
#include "ui_error.h"

t_frame     *ui_new_frame(t_frame_type type, t_resize_type resize_type, t_frect ratio, void *data)
{
    t_frame	*frame;

	if (!(frame = (t_frame*)ft_memalloc(sizeof(t_frame))))
		return (ui_ret_null_error("ui_new_frame", "frame allocation failed", NULL));
	frame->type = type;
	frame->resize_type = resize_type;
	frame->ratio = ratio;
	frame->data = data;
	frame->next = NULL;
	frame->buttons = NULL;
    return (frame);
}

void		ui_add_frame(t_frame **frames, t_frame *new_frame)
{
	if (new_frame)
	{
		new_frame->next = *frames;
		*frames = new_frame;
	}
}

t_simple_frame	*ui_new_simple_frame(char *text,
										t_frect text_ratio,
										SDL_Texture *texture,
										SDL_Texture *text_background)
{
	t_simple_frame	*simple_frame;

	if (!(simple_frame = (t_simple_frame*)ft_memalloc(sizeof(t_simple_frame))))
		return (ui_ret_null_error("ui_new_simple_frame", "simple_frame allocation frame failed", NULL));
	simple_frame->text = text;
	simple_frame->text_ratio = text_ratio;
	simple_frame->texture = texture;
	simple_frame->text_background = text_background;
	return (simple_frame);
}