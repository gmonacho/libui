#include "ui.h"
#include "ui_error.h"

static int		parse_text_area_first_step(char **text,
											int *i,
											t_text_area *text_area)
{
	int		index;

	index = 0;
	if (!check_line_name(text[index], "text")
	|| !(text_area->text = parse_str(text[index])))
	{
		return (ui_ret_error("parse_text_area_first_step",
					"\"text : <str>\" expected", 0));
	}
	incre_double_int(&index, i, 1);
	if (!check_line_name(text[index], "resize_text")
	|| (text_area->resize_text = get_resize_text(text[index]) == -1))
	{
		return (ui_ret_error("parse_text_area_first_step",
				"\"resize_text : <t_resize_text>\" expected", 0));
	}
	(*i)++;
	return (1);
}

static int		parse_text_area_second_step(char **text,
											int *i,
											t_text_area *text_area)
{
	if (check_line_name(text[0], "text_height"))
	{
		if (text_area->resize_text == UI_RESIZE_TEXT_NONE)
		{
			if (!parse_int(text[0], (int*)&text_area->text_height))
			{
				return (ui_ret_error("parse_text_area_second_step",
				"text_height : <int> expected", 0));
			}
		}
		else if (text_area->resize_text == UI_RESIZE_TEXT_LINEAR)
		{
			if (!get_float(text[0], (double*)&text_area->text_height))
			{
				return (ui_ret_error("parse_text_area_second_step",
				"text_height : <float> expected", 0));
			}
		}
	}
	else
		return (ui_ret_error("p_t_a_s_s", "text_height : <float> expected", 0));
	(*i)++;
	return (1);
}

static int		parse_text_area_third_step(char **text,
											int *i,
											t_text_area *text_area)
{
	int		index;

	index = 0;
	if (!check_line_name(text[index], "text_align")
	|| (text_area->text_align = get_text_align(text[index]) == -1))
	{
		return (ui_ret_error("parse_text_area_third_step",
		"\"text_align : <t_text_align>\" expected", 0));
	}
	incre_double_int(&index, i, 1);
	if (!check_line_name(text[index], "text_color")
	|| !parse_sdl_color(text[index], &text_area->text_color))
	{
		return (ui_ret_error("parse_text_area_third_step",
		"\"text_color : <int> <int> <int> <int>\" expected", 0));
	}
	incre_double_int(&index, i, 1);
	return (1);
}

static void		*ui_ret_null_error_ta(t_text_area **text_area,
										const char *function,
										const char *error_msg,
										void *return_value)
{
	ui_free_text_area(text_area);
	return (ui_ret_null_error(function, error_msg, return_value));
}

t_text_area		*parse_text_area(char **text,
								int *i)
{
	t_text_area	*text_area;
	int			index;

	if (!(text_area = (t_text_area*)ft_memalloc(sizeof(t_text_area))))
	{
		return (ui_ret_null_error_ta(&text_area, "parse_text_area",
		"text_area allocation failed", NULL));
	}
	index = 0;
	if (!parse_text_area_first_step(&text[index], i, text_area))
	{
		return (ui_ret_null_error_ta(&text_area, "parse_text_area",
		"parse_text_area_first_step failed", NULL));
	}
	index += 2;
	if (!parse_text_area_second_step(&text[index], i, text_area))
	{
		return (ui_ret_null_error_ta(&text_area, "parse_text_area",
		"parse_text_area_second_step failed", NULL));
	}
	index++;
	if (!parse_text_area_third_step(&text[index], i, text_area))
	{
		return (ui_ret_null_error_ta(&text_area, "parse_text_area",
		"parse_text_area_third_step failed", NULL));
	}
	return (text_area);
}
