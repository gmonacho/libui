#include "ui.h"
#include "ui_error.h"

static t_simple_button 	*ui_ret_null_error_s(t_simple_button **simple_button, const char *function, const char *error_msg, void *return_value)
{
	ui_free_simple_button(simple_button);
	return (ui_ret_null_error(function, error_msg, return_value));
}

t_simple_button	*parse_simple_button(SDL_Renderer *rend, t_texture **textures, char **text, int *i)
{
	//printf("\n''''' parse_simple_button '''''\n");
	t_simple_button *simple_button;
	int				index;

	index = 0;
	if (!(simple_button = (t_simple_button*)ft_memalloc(sizeof(t_simple_button))))
		return (ui_ret_null_error_s(&simple_button, "parse_simple_button", "simple_button allocation failed", NULL));
	if (!check_line_name(text[index], "text") || !(simple_button->text = parse_str(text[index])))
		return (ui_ret_null_error_s(&simple_button, "parse_simple_button", "\"text : <str>\" expected", NULL));
	//printf("simple_button->text = %s\n", simple_button->text);
	incre_double_int(&index, i, 1);
	if (!(simple_button->textures.normal = parse_texture(rend, textures, "texture_normal", text[index])))
		return (ui_ret_null_error_s(&simple_button, "parse_simple_button", "parse_texture failed (expected line_name : \"texture_normal\")", NULL));
	incre_double_int(&index, i, 1);
	if (!(simple_button->textures.clicked = parse_texture(rend, textures, "texture_clicked", text[index])))
		return (ui_ret_null_error_s(&simple_button, "parse_simple_button", "parse_texture failed (expected line_name : \"texture_clicked\")", NULL));
	incre_double_int(&index, i, 1);
	if (!(simple_button->textures.on_mouse = parse_texture(rend, textures, "texture_on_mouse", text[index])))
		return (ui_ret_null_error_s(&simple_button, "parse_simple_button", "parse_texture failed (expected line_name : \"texture_on_mouse\")", NULL));
	incre_double_int(&index, i, 1);
	if (!(check_line_name(text[index], "clicked_condition") || (simple_button->clicked_condition = get_clicked_condition(text[index]) <= 0)))
		return (ui_ret_null_error_s(&simple_button, "parse_simple_button", "\"clicked_condition : <t_mouse_button>\" expected", NULL));
	incre_double_int(&index, i, 1);
	return (simple_button);
}