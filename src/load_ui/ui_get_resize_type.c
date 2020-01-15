#include "ui.h"
#include "ui_error.h"

static t_resize_type	convert_str_flag(const char *flag)
{
	if (ft_strcmp(flag, "UI_RESIZE_X") == 0)
		return (UI_RESIZE_X);
	else if (ft_strcmp(flag, "UI_RESIZE_Y") == 0)
		return (UI_RESIZE_Y);
	else if (ft_strcmp(flag, "UI_RESIZE_W") == 0)
		return (UI_RESIZE_W);
	else if (ft_strcmp(flag, "UI_RESIZE_H") == 0)
		return (UI_RESIZE_H);
	else if (ft_strcmp(flag, "UI_RESIZE_LOCK_RATIO") == 0)
		return (UI_RESIZE_LOCK_RATIO);
	else if (ft_strcmp(flag, "UI_RESIZE_POS_LINEAR") == 0)
		return (UI_RESIZE_POS_LINEAR);
	else if (ft_strcmp(flag, "UI_RESIZE_SIZE_LINEAR") == 0)
		return (UI_RESIZE_SIZE_LINEAR);
	else if (ft_strcmp(flag, "UI_RESIZE_ALL_LINEAR") == 0)
		return (UI_RESIZE_ALL_LINEAR);
	else
		return (0);
}

int						get_resize_type(const char *line)
{
	char			*all_flags;
	char			**flags;
	int				i;
	t_resize_type	resize_type;

	if (!(all_flags = ft_strstr(line, " : ")))
		return (ui_ret_error("get_resize_type", "\" : \" not found", -1));
	all_flags += 3;
	flags = get_flags_tab(all_flags);
	i = 0;
	resize_type = 0;
	while (flags[i])
		resize_type |= convert_str_flag(flags[i++]);
	ft_2dstrdel(&flags);
	if (resize_type)
		return (resize_type);
	else
		return (ui_ret_error("get_resize_type", "invalid frame type", -1));
}
