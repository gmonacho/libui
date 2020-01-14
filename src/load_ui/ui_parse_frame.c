#include "ui.h"
#include "ui_error.h"

static void	incre_double_int(int *a, int *b, int value)
{
	(*a) += value;
	(*b) += value;
}

static t_simple_frame	*ui_ret_null_error_sf(t_simple_frame **simple_frame, const char *function, const char *error_msg, void *return_value)
{
	ui_free_simple_frame(simple_frame);
	return (ui_ret_null_error(function, error_msg, return_value));
}

static t_simple_frame	*parse_simple_frame(SDL_Renderer *rend, t_texture **textures, char **str, int *i)
{
	t_simple_frame	*simple_frame;

	if (!(simple_frame = ft_memalloc(sizeof(t_simple_frame))))
		return (ui_ret_null_error_sf(&simple_frame, "parse_simple_frame", "simple_frame allocation failed", NULL));
	//printf("path = %s\n", path);
	simple_frame->text = NULL;
	simple_frame->text_background = NULL;
	simple_frame->text_ratio = (t_frect){0, 0, 0, 0};
	if (!(simple_frame->texture = parse_texture(rend, textures, "texture", str[0])))
		return (ui_ret_null_error_sf(&simple_frame, "parse_simple_frame", "parse_texture failed (expected line_name : \"texture\")", NULL));
	(*i)++;
	return (simple_frame);
}

static void	*parse_frame_data(t_win *win, char **str, t_frame_type frame_type, int *i)
{
	//printf("\n..... get_frame_data .....\n");
	void	*data;

	data = NULL;
	if (!ft_strstr(str[0], "data"))
		return (ui_ret_null_error("parse_frame_data", "\"data\" (frame) is missing", NULL));
	(*i) += 2;
	if (frame_type == UI_FRAME_SIMPLE)
		data = parse_simple_frame(win->rend, &win->ui.textures, &str[2], i);
	(*i)++;
	return (data);
}

static int		ui_ret_error_f(t_ui *ui, const char *function, const char *error_msg, int ret_value)
{
	t_frame *f;
	t_frame *next;

	f = ui->frames;
	if (f)
	{
		next = f->next;
		ui_free_frame(&f);
		ui->frames = next;
	}
	return (ui_ret_error(function, error_msg, ret_value));
}

int		parse_frame(t_win *win, char **text, int *i)
{
	printf("\n''''' parse_frame '''''\n");
	t_frame	*f;
	int		index;

	if (!(f = ui_new_frame(0, 0, (t_frect){0, 0, 0, 0}, NULL)))
		return (ui_ret_error("parse_frame", "f allocation failed", 0));
	ui_add_frame(&win->ui.frames, f);
	if (win && i)
	{
		index = 0;
		// printf("parse_frame : text[index] = %s\n", text[index]);
		if (!check_line_name((const char*)text[index], "type") || (f->type = get_frame_type(text[index])) <= 0)
			return (ui_ret_error_f(&win->ui, "parse_frame", "\"type : <t_type_frame>\" expected", 0));
		// printf("f->type = %d\n", f->type);
		incre_double_int(&index, i, 1);
		if (!check_line_name(text[index], "resize_type") || (f->resize_type = get_resize_type(text[index])) <= 0)
			return (ui_ret_error_f(&win->ui, "parse_frame", "\"resize_type : <t_resize_type>\" expected", 0));
		// printf("f->resize_type = %d\n", f->resize_type);
		incre_double_int(&index, i, 1);
		if (!check_line_name(text[index], "ratio") || !get_ratio((const char*)text[index], &f->ratio))
			return (ui_ret_error_f(&win->ui, "parse_frame", "\"ratio : <t_frect>\" expected", 0));
		incre_double_int(&index, i, 1);
		if (!(f->data = parse_frame_data(win, &text[index], f->type, i)))
			return (ui_ret_error_f(&win->ui, "parse_frame", "frame data block expected", 0));
		if (!(text = skip_next_block(&text[index])))
			return (ui_ret_error_f(&win->ui, "parse_frame", "invalid data block {} syntax", 0));
		index = 0;
		if (!parse_buttons(win, &text[index], i))
			return (ui_ret_error_f(&win->ui, "parse_frame", "parse_buttons", 0));
	}
	return (1);
}