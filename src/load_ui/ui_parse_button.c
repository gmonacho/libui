#include "ui.h"
#include "ui_error.h"

static void	incre_double_int(int *a, int *b, int value)
{
	(*a) += value;
	(*b) += value;
}

t_button	*parse_button(char **text, int *i)
{
	printf("\n''''' parse_button '''''\n");
	t_button	*b;
	int			index;

	if (!(b = (t_button*)ft_memalloc(sizeof(t_button))))
		return (ui_ret_null_error("parse_button", "b allocation failed", NULL));
	index = 0;
	if (!check_line_name((const char *)text[index], "id")) // string a parser
		return (ui_ret_null_error("parse_button", "\"id : <str>\" expected", NULL));
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
	return (b);
}

int		parse_buttons(t_frame *frame, char **text, int *i)
{
	t_button	*b;
	int			index;

	index = 0;
	while (ft_strcmp(text[index], "button") == 0)
	{
		incre_double_int(&index, i, 1);
		if (!ft_strchr(text[index], '{'))
			return (ui_ret_error("parse_buttons", "'{' (to open button block) is missing", 0));
		incre_double_int(&index, i, 1);
		if ((b = parse_button(&text[index], i)))
			ui_add_button(&frame->buttons, b);
		else
			return (ui_ret_error("parse_buttons", "parse_button failed", 0));
		while (text[index] && !ft_strchr(text[index], '}'))
			incre_double_int(&index, i, 1);
		incre_double_int(&index, i, 1);
		while (text[index] && !ft_strchr(text[index], '}'))
			incre_double_int(&index, i, 1);
		incre_double_int(&index, i, 1);
	}
	return (1);
}