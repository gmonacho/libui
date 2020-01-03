#include "ui.h"
#include "ui_error.h"

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
		index++;
		(*i)++;
		if (!check_line_name(text[index], "resize_type") || (f->resize_type = get_resize_type(text[index])) <= 0)
			return (ui_ret_error("parse_frame", "\"resize_type : <t_resize_type>\" expected", 0));
		index++;
		(*i)++;
		if (!check_line_name(text[index], "ratio") || !get_ratio((const char*)text[index], &f->ratio))
			return (ui_ret_error("parse_frame", "\"ratio : <t_frect>\" expected", 0));
		index++;
		(*i)++;
		while (text[index] && ft_strcmp(text[index], "    button") != 0)
			index++;
		index += 2;
		(*i) += 2;
		parse_button(&text[index], i);
	}
	return (1);
}