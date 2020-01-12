#include "ui.h"
#include "ui_error.h"

int		get_frame_type(const char *line)
{
	char	*type;

	//printf("\n..... get_frame_type .....\n");
	if (!(type = ft_strstr(line, " : ")))
		return (ui_ret_error("get_frame_type", "\" : \" not found", -1));
	type += 3;
	//printf("type = %s\n", type);
	if (ft_strcmp(type, "UI_FRAME_SIMPLE") == 0)
		return (UI_FRAME_SIMPLE);
	else
		return (ui_ret_error("get_frame_type", "invalid frame type", -1));
}

int		get_button_type(const char *line)
{
	char	*type;

	//printf("\n..... get_button_type .....\n");
	if (!(type = ft_strstr(line, " : ")))
		return (ui_ret_error("get_button_type", "\" : \" not found", -1));
	type += 3;
	//printf("type = %s\n", type);
	if (ft_strcmp(type, "UI_BUTTON_SIMPLE") == 0)
		return (UI_BUTTON_SIMPLE);
	else if (ft_strcmp(type, "UI_BUTTON_TEXT_ENTRY") == 0)
		return (UI_BUTTON_TEXT_ENTRY);
	else
		return (ui_ret_error("get_button_type", "invalid button type", -1));
}

int		get_clicked_condition(const char *line)
{
	char	*type;

	//printf("\n..... get_clicked_condition .....\n");
	if (!(type = ft_strstr(line, " : ")))
		return (ui_ret_error("get_clicked_condition", "\" : \" not found", -1));
	type += 3;
	//printf("type = %s\n", type);
	if (ft_strcmp(type, "UI_MOUSE_LEFT") == 0)
		return (UI_MOUSE_LEFT);
	else if (ft_strcmp(type, "UI_MOUSE_RIGHT") == 0)
		return (UI_MOUSE_RIGHT);
	else if (ft_strcmp(type, "UI_MOUSE_MIDDLE") == 0)
		return (UI_MOUSE_MIDDLE);
	else
		return (ui_ret_error("get_clicked_condition", "invalid flag <t_mouse_button>", -1));
}
