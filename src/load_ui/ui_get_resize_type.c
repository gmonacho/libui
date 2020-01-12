#include "ui.h"
#include "ui_error.h"

int		get_resize_type(const char *line)
{
	//printf("\n..... get_resize_type .....\n");
	char			*all_flags;
	char			**flags;
	int				i;
	t_resize_type	resize_type;

	//printf("line = %s\n", line);
	if (!(all_flags = ft_strstr(line, " : ")))
		return (ui_ret_error("get_resize_type", "\" : \" not found", -1));
	all_flags += 3;
	//printf("all_flags = %s\n", all_flags);
	flags = get_flags_tab(all_flags);
	// ft_2dputendl((const char**)flags);
	i = 0;
	resize_type = 0;
	while (flags[i])
	{
		if (ft_strcmp(flags[i], "UI_RESIZE_X"))
			resize_type |= UI_RESIZE_X;
		else if (ft_strcmp(flags[i], "UI_RESIZE_Y"))
			resize_type |= UI_RESIZE_Y;
		else if (ft_strcmp(flags[i], "UI_RESIZE_W"))
			resize_type |= UI_RESIZE_W;
		else if (ft_strcmp(flags[i], "UI_RESIZE_H"))
			resize_type |= UI_RESIZE_H;
		else if (ft_strcmp(flags[i], "UI_RESIZE_LOCK_RATIO"))
			resize_type |= UI_RESIZE_LOCK_RATIO;
		else if (ft_strcmp(flags[i], "UI_RESIZE_POS_LINEAR"))
			resize_type |= UI_RESIZE_POS_LINEAR;
		else if (ft_strcmp(flags[i], "UI_RESIZE_SIZE_LINEAR"))
			resize_type |= UI_RESIZE_SIZE_LINEAR;
		else if (ft_strcmp(flags[i], "UI_RESIZE_ALL_LINEAR"))
			resize_type |= UI_RESIZE_ALL_LINEAR;
		i++;
	}
	if (resize_type)
		return (resize_type);
	else
		return (ui_ret_error("get_resize_type", "invalid frame type", -1));
}