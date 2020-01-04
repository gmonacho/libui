#include "ui.h"
#include "ui_error.h"

static void	incre_double_int(int *a, int *b, int value)
{
	(*a) += value;
	(*b) += value;
}

static t_simple_frame	*parse_simple_frame(SDL_Renderer *rend, char **str, int *i)
{
	t_simple_frame	*simple_frame;
	char			*path;

	if (!(simple_frame = ft_memalloc(sizeof(t_simple_frame))))
		return (ui_ret_null_error("parse_simple_frame", "simple_frame allocation failed", NULL));
	if (!(check_line_name(str[0], "texture")) || !(path = parse_str(str[0])))
		return (ui_ret_null_error("parse_simple_frame", "\"texture : \"path\"\" expected", NULL));
	(*i)++;
	printf("path = %s\n", path);
	simple_frame->text = NULL;
	simple_frame->text_background = NULL;
	simple_frame->text_ratio = (t_frect){0, 0, 0, 0};
	if (!(simple_frame->texture = ui_load_image(rend, path)))
		return (ui_ret_null_error("parse_simple_frame", "ui_load_image failed", NULL));
	return (simple_frame); 
}

static void	*parse_frame_data(SDL_Renderer *rend, char **str, t_frame_type frame_type, int *i)
{
	printf("\n..... get_frame_data .....\n");
	void	*data;

	data = NULL;
	if (!ft_strstr(str[0], "data"))
		return (ui_ret_null_error("parse_frame_data", "\"data\" (frame) is missing", NULL));
	(*i) += 2;
	if (frame_type == UI_FRAME_SIMPLE)
		data = parse_simple_frame(rend, &str[2], i);
	(*i)++;
	return (data);
}

int		parse_frame(t_win *win, char **text, int *i)
{
	printf("\n''''' parse_frame '''''\n");
	t_frame	*f;
	int		index;

	if (!(f = ui_new_frame(0, 0, (t_frect){0, 0, 0, 0}, NULL)))
		return (ui_ret_error("parse_frame", "f allocation failed", 0));
	if (win && i)
	{
		index = 0;
		printf("parse_frame : text[index] = %s\n", text[index]);
		if (!check_line_name((const char*)text[index], "type") || (f->type = get_frame_type(text[index])) <= 0)
			return (ui_ret_error("parse_frame", "\"type : <t_type_frame>\" expected", 0));
		printf("f->type = %d\n", f->type);
		incre_double_int(&index, i, 1);
		if (!check_line_name(text[index], "resize_type") || (f->resize_type = get_resize_type(text[index])) <= 0)
			return (ui_ret_error("parse_frame", "\"resize_type : <t_resize_type>\" expected", 0));
		incre_double_int(&index, i, 1);
		if (!check_line_name(text[index], "ratio") || !get_ratio((const char*)text[index], &f->ratio))
			return (ui_ret_error("parse_frame", "\"ratio : <t_frect>\" expected", 0));
		incre_double_int(&index, i, 1);
		if (!(f->data = parse_frame_data(win->rend, &text[index], f->type, i)))
			return (ui_ret_error("parse_frame", "frame data block expected", 0));
		if (!(text = skip_next_block(&text[index])))
			return (ui_ret_error("parse_frame", "invalid data block {} syntax", 0));
		index = 0;
		parse_buttons(win->rend, f, &text[index], i);
	}
	f->next = NULL;
	ui_add_frame(&win->ui.frames, f);
	return (1);
}