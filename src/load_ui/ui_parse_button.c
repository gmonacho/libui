#include "ui.h"
#include "ui_error.h"

static void	incre_double_int(int *a, int *b, int value)
{
	if (a)
		(*a) += value;
	if (b)
		(*b) += value;
}

static t_simple_button	*parse_simple_button(SDL_Renderer *rend, char **text, int *i)
{
	printf("\n''''' parse_simple_button '''''\n");
	t_simple_button *simple_button;
	int				index;
	char			*path;

	index = 0;
	if (!(simple_button = (t_simple_button*)ft_memalloc(sizeof(t_simple_button))))
		return (ui_ret_null_error("parse_simple_button", "simple_button allocation failed", NULL));
	if (!check_line_name(text[index], "text") || !(simple_button->text = parse_str(text[index])))
		return (ui_ret_null_error("parse_simple_button", "\"text : <str>\" expected", NULL));
	printf("simple_button->text = %s\n", simple_button->text);
	incre_double_int(&index, i, 1);
	if (!check_line_name(text[index], "texture_normal") || !(path = parse_str(text[index])))
		return (ui_ret_null_error("parse_simple_button", "\"texture_normal : \"path\"\" expected", NULL));
	if (!(simple_button->textures.normal = ui_load_image(rend, path)))
		return (ui_ret_null_error("parse_simple_button", "ui_load_image failed", NULL));
	incre_double_int(&index, i, 1);
	if (!check_line_name(text[index], "texture_clicked") || !(path = parse_str(text[index])))
		return (ui_ret_null_error("parse_simple_button", "\"texture_clicked : \"path\"\" expected", NULL));
	if (!(simple_button->textures.clicked = ui_load_image(rend, path)))
		return (ui_ret_null_error("parse_simple_button", "ui_load_image failed", NULL));
	incre_double_int(&index, i, 1);
	if (!check_line_name(text[index], "texture_on_mouse") || !(path = parse_str(text[index])))
		return (ui_ret_null_error("parse_simple_button", "\"texture_on_mouse : \"path\"\" expected", NULL));
	if (!(simple_button->textures.clicked = ui_load_image(rend, path)))
		return (ui_ret_null_error("parse_simple_button", "ui_load_image failed", NULL));
	incre_double_int(&index, i, 1);
	if (!(check_line_name(text[index], "clicked_condition") || (simple_button->clicked_condition = get_clicked_condition(text[index]) <= 0)))
		return (ui_ret_null_error("parse_simple_button", "\"clicked_condition : <t_mouse_button>\" expected", NULL));
	incre_double_int(&index, i, 1);
	return (simple_button);
}

static void	*parse_button_data(SDL_Renderer *rend, char **text, t_button_type button_type, int *i)
{
	void	*data;

	data = NULL;
	printf ("text[0] = %s\n", text[0]);
	if (!ft_strstr(text[0], "data"))
		return (ui_ret_null_error("parse_button_data", "\"data\" (button) is missing", NULL));
	(*i) += 2;
	if (button_type == UI_FRAME_SIMPLE)
		data = parse_simple_button(rend, &text[2], i);
	(*i)++;
	return (data);
}


static t_button	*parse_button(SDL_Renderer *rend, char **text, int *i)
{
	printf("\n''''' parse_button '''''\n");
	t_button	*b;
	int			index;

	if (!(b = (t_button*)ft_memalloc(sizeof(t_button))))
		return (ui_ret_null_error("parse_button", "b allocation failed", NULL));
	index = 0;
	if (!check_line_name((const char *)text[index], "id") || !(b->id = parse_str(text[index])))
		return (ui_ret_null_error("parse_button", "\"id : <str>\" expected", NULL));
	printf("button->id = %s\n", b->id);
	incre_double_int(&index, i, 1);
	if (!check_line_name((const char *)text[index], "type") || (b->type = get_button_type((const char*)text[index])) <= 0)
		return (ui_ret_null_error("parse_button", "\"type : <t_button_type>\" expected", NULL));
	printf("button->type = %d\n", b->type);
	incre_double_int(&index, i, 1);
	if (!check_line_name((const char *)text[index], "resize_type") || (b->resize_type = get_resize_type((const char*)text[index])) <= 0)
		return (ui_ret_null_error("parse_button", "\"resize_type : <t_resize_type>\" expected", NULL));
	incre_double_int(&index, i, 1);
	if (!check_line_name((const char *)text[index], "ratio") || !get_ratio((const char*)text[index], &b->ratio))
		return (ui_ret_null_error("parse_button", "\"ratio : <t_frect>\" expected", NULL));
	incre_double_int(&index, i, 1);
	if ((!(b->data = parse_button_data(rend, &text[index], b->type, i))))
		return (ui_ret_null_error("parse_button", "invalid button data block", NULL));
	return (b);
}

int		parse_buttons(SDL_Renderer *rend, t_frame *frame, char **text, int *i)
{
	printf("\n''''' parse_buttons '''''\n");
	t_button	*b;
	int			index;

	index = 0;
	while (ft_strstr(text[index], "button"))
	{
		incre_double_int(&index, i, 1);
		if (!ft_strchr(text[index], '{'))
			return (ui_ret_error("parse_buttons", "'{' (to open button block) is missing", 0));
		incre_double_int(&index, i, 1);
		if ((b = parse_button(rend, &text[index], i)))
			ui_add_button(&frame->buttons, b);
		else
			return (ui_ret_error("parse_buttons", "parse_button failed", 0));
		if (!(text = skip_next_block(text)))
			return (ui_ret_error("parse_buttons", "invalid button block {} syntax", 0));
		index = 0;
		(*i)++;
	}
	return (1);
}