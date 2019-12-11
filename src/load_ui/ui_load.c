#include "ui.h"
#include "ui_error.h"
#include "libft.h"

static char		**get_flags_tab(const char *flags)
{
	char	**tab;
	char	flag[50];
	int		index;
	void	*tmp;
	int		flags_count;

	tab = NULL;
	flags_count = 0;
	while (flags && *flags)
	{
		if (*flags != ' ')
		{
			index = 0;
			while (*flags && *flags != ' ')
				flag[index++] = *flags++;
			flag[index] = '\0';
			tmp = tab;
			tab = ft_2dstrpushback(tab, flags_count++, flag);
			ft_2dstrdel((char***)&tmp);
		}
		else
		{
			if (flags = ft_strstr(flags, " : ")
				flags += 3;
		}
	}
	return (tab);
}

static int		get_frame_type(const char *line)
{
	char	*type;

	if (!(type = ft_strstr(line, " : ")))
		return (ui_ret_error("get_frame_type", "\" : \" not found", -1));
	type += 3;
	if (ft_strcmp(type, UI_RESIZE_POS_LINEAR) == 0)
		return (UI_RESIZE_POS_LINEAR);
	else if (ft_strcmp(type, UI_RESIZE_SIZE_LINEAR) == 0)
		return (UI_RESIZE_SIZE_LINEAR);
	else
		return (ui_ret_error("get_frame_type", "invalid frame type", -1));
}

static int		get_resize_type(const char *line)
{
	char			*type;
	char			**flags;
	int				i;
	t_resize_type	resize_type;

	if (!(type = ft_strstr(line, " : ")))
		return (ui_ret_error("get_resize_type", "\" : \" not found", -1));
	type += 3;
	flags = get_flags_tab(type);
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
		return (resize_type)
	else
		return (ui_ret_error("get_resize_type", "invalid frame type", -1));
}

static int		check_line_name(const char *line, const char *expected)
{
	int		i;
	char	name[ft_strlen(expected) + 1];

	i = 0;
	while (line && line[i] != ' ' && name[i])
	{
		name[i] = line[i];
		i++;
	}
	if (ft_strlen(expected) == i && line[i] != ' ')
		return (ui_ret_error("check_line_name", line, 0));
	return (1);
}

static int		parse_frame(t_win *win, char **text, int *i)
{
	t_frame	*f;
	int		index;

	index = 0;
	if (!check_line_name(text[index], "type") || (f->type = get_frame_type(text[index]) == -1))
		return (ui_ret_error("parse_frame", "type : <t_type_frame> expected", 0));
	index++;
	*i++;
	if (!check_line_name(text[index], "resize_type") || (f->resize_type = get_frame_resize_type(text[index] == -1)))
		return (ui_ret_error("parse_frame", "resize_type : <t_resize_type> expected", 0));
	
	
}

static char		**read_ui(const char *path)
{
	char	*line;
	char	**text;
	void	*tmp;
	int		i;
	int		fd;

	i = 0;
	text = NULL;
	if ((fd = open(path, O_RDONLY)) <= 0)
		return (ui_ret_error("read_ui", "ui file oppening failed", NULL));
	while (get_next_line(fd, &line) > 0)
	{
		tmp = text;
		text = ft_2dstrpushback(text, i, line)
		ft_2dstrdel((char***(&tmp));
		i++;
	}
	return (text);
}

static int		ui_load_error(const char *function, const char *error_msg, int ret_value, int line)
{
	char	*str;
	char	*number;

	number = ft_itoa(line);
	str = ft_strjoin("read error line : ", number);
	ft_putendl_fd(str, 2);
	return (ui_ret_error(function, error_msg, ret_value));
}

int				ui_load(const char *path, t_win *win)
{
	int		i;
	int		fd;
	char	*line;
	char	**text;

	i = 0;
	if ((text = read_ui(path)) == NULL)
		return (ui_ret_error("ui_load", "read_ui failed", NULL));
	while (text[i])
	{
		if (ft_strcmp(text[i], "frame") != 0)
			return (ui_load_error("ui_load", text[i], 0, i));
		i += 2;
		parse_frame(&text[i], &i);
	}
}