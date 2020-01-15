#include "ui.h"
#include "ui_error.h"

static t_text_entry_button	*ui_ret_null_error_te(t_text_entry_button **text_entry_button, const char *function, const char *error_msg, void *return_value)
{
	ui_free_text_entry_button(text_entry_button);
	return (ui_ret_null_error(function, error_msg, return_value));
}

t_text_entry_button	*parse_text_entry_button(SDL_Renderer *rend, t_texture **textures, char **text, int *i)
{
	t_text_entry_button	*text_entry_button;
	int					index;
	char				*tmp;
	int					j;

	index = 0;
	if (!(text_entry_button = (t_text_entry_button*)ft_memalloc(sizeof(t_text_entry_button))))
		return (ui_ret_null_error("parse_text_entry_button", "text_entry_button allocation failed", NULL));
	if (!check_line_name(text[index], "name") || !(text_entry_button->name = parse_str(text[index])))
		return (ui_ret_null_error_te(&text_entry_button, "parse_text_entry_button", "\"name : <str>\" expected", NULL));
	incre_double_int(&index, i, 1);
	if (!check_line_name(text[index], "text"))
		return (ui_ret_null_error_te(&text_entry_button, "parse_text_entry_button", "\"text : <str>\" expected", NULL));
	tmp = parse_str(text[index]);
	incre_double_int(&index, i, 1);
	if (!check_line_name(text[index], "max_text_size") || !parse_int(text[index], &text_entry_button->max_text_size))
		return (ui_ret_null_error_te(&text_entry_button, "parse_text_entry_button", "\"max_text_size : <int>\" expected", NULL));
	if (!(text_entry_button->text = (char*)ft_memalloc(
								sizeof(char) * (text_entry_button->max_text_size + 1))))
		return (ui_ret_null_error_te(&text_entry_button, "parse_text_entry_button",
									"new_text_entry->text allocation failed",
									NULL));
	if (!(text_entry_button->new_text = (char*)ft_memalloc(
										sizeof(char) * (text_entry_button->max_text_size + 1))))
		return (ui_ret_null_error_te(&text_entry_button, "parse_text_entry_button",
									"new_text_entry->new_text\
									allocation failed",
									NULL));
	j = 0;
	while (tmp[j])
	{
		(text_entry_button->text)[j] = tmp[j];
		j++;
	}
	if (tmp)
		ft_strdel(&tmp);
	incre_double_int(&index, i, 1);
	if (!check_line_name(text[index], "min_int") || !parse_int(text[index], &text_entry_button->min_int))
		return (ui_ret_null_error_te(&text_entry_button, "parse_text_entry_button", "\"min_int : <int>\" expected", NULL));
	incre_double_int(&index, i, 1);
	if (!check_line_name(text[index], "max_int") || !parse_int(text[index], &text_entry_button->max_int))
		return (ui_ret_null_error_te(&text_entry_button, "parse_text_entry_button", "\"max_int : <int>\" expected", NULL));
	incre_double_int(&index, i, 1);
	if (!(text_entry_button->textures.name_side_texture = parse_texture(rend, textures, "name_side_texture", text[index])))
		return (ui_ret_null_error_te(&text_entry_button, "parse_text_entry_button", "parse_texture failed (expected line_name : \"name_side_texture\")", NULL));
	incre_double_int(&index, i, 1);
	if (!(text_entry_button->textures.normal_box_texture = parse_texture(rend, textures, "normal_box_texture", text[index])))
		return (ui_ret_null_error_te(&text_entry_button, "parse_text_entry_button", "parse_texture failed (expected line_name : \"normal_box_texture\")", NULL));
	incre_double_int(&index, i, 1);
	if (!(text_entry_button->textures.writting_box_texture = parse_texture(rend, textures, "writting_box_texture", text[index])))
		return (ui_ret_null_error_te(&text_entry_button, "parse_text_entry_button", "parse_texture failed (expected line_name : \"writting_box_texture\")", NULL));
	incre_double_int(&index, i, 1);
	if (!check_line_name(text[index], "text_side") || !(text_entry_button->text_side = get_text_side(text[index])))
		return (ui_ret_null_error_te(&text_entry_button, "parse_text_entry_button", "\"text_side : \" expected", NULL));
	incre_double_int(&index, i, 1);
	if (!check_line_name(text[index], "text_type") || (int)(text_entry_button->text_type = get_text_type(text[index])) == -1)
		return (ui_ret_null_error_te(&text_entry_button, "parse_text_entry_button", "\"text_type : \" expected", NULL));
	(*i)++;
	//printf("text_entry_button->text_type = %d\n", text_entry_button->text_type);
	return (text_entry_button);
}