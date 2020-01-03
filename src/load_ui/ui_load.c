#include <fcntl.h>
#include "ui.h"
#include "ui_error.h"
#include "libft.h"

static int		check_line_name(const char *line, const char *expected)
{
	printf("\n..... check_line_name .....\n");
	int		i;
	int		il;
	char	name[ft_strlen(expected) + 1];

	name[ft_strlen(expected)] = '\0';
	il = 0;
	while (line && !ft_isprint(line[il]) && line[il])
		il++;
	i = 0;
	while (line && ft_isprint(line[il]) && i < (int)ft_strlen(expected))
		name[i++] = line[il++];
	name[i] = '\0';
	printf("line name = %s\n", name);
	if (ft_strcmp(name, expected) != 0)
		return (ui_ret_error("check_line_name", "bad line name", 0));
	else 
		return (1);
}

static char				*parse_str(char *str)
{
	char	*new_str;
	int		len;
	int		i;
	int		start;

	len = -1;
	i = 0;
	while (str[i] != '\"' && str[i])
		i++;
	if (str[i] != '\"')
		return (ui_ret_null_error("parse_str", "no <\"str\"> found", NULL));
	start = i;
	i++;
	len = 0;
	while (str[i] != '\"' && str[i])
	{
		i++;
		len++;
	}
	if (str[i] != '\"')
		return (ui_ret_null_error("parse_str", "bad <\"str\"> format", NULL));
	if (!(new_str = (char*)ft_memalloc(sizeof(char) * (len + 1))))
		return (ui_ret_null_error("parse_str", "new_str allocation failed", NULL));
	i = start + 1;
	while (str[i] != '\"' && str[i])
	{
		new_str[i - start - 1] = str[i];
		i++;
	}
	new_str[i - start - 1] = '\0';
	return (new_str);
}

static t_simple_frame	*parse_simple_frame(SDL_Renderer *rend, char **str, int *i)
{
	t_simple_frame	*simple_frame;
	char			*path;

	if (!(simple_frame = ft_memalloc(sizeof(t_simple_frame))))
		return (ui_ret_null_error("parse_simple_frame", "simple_frame allocation failed", NULL));
	if (!(check_line_name(str[0], "texture")) || !(path = parse_str(str[0])))
		return (ui_ret_null_error("parse_simple_frame", "\"texture : \"path\"\" expected", NULL));
	*i++;
	printf("path = %s\n", path);
	simple_frame->text = NULL;
	simple_frame->text_background = NULL;
	simple_frame->text_ratio = (t_frect){0, 0, 0, 0};
	if (!(simple_frame->texture = ui_load_image(rend, path)))
		return (ui_ret_null_error("parse_simple_frame", "ui_load_image failed", NULL));
	*i++;
	return (simple_frame); 
}

static void	*parse_frame_data(SDL_Renderer *rend, char **str, t_frame_type frame_type, int *i)
{
	printf("\n..... get_frame_data .....\n");
	void	*data;

	if (frame_type == UI_FRAME_SIMPLE)
		data = parse_simple_frame(rend, str, i);
	return (data);
}

static int	get_float(char *str, double *fnb_ptr)
{	
	double	fnb;
	int		i;

	i = 0;
	while (!(ft_isprint(str[i]) && str[i]))
		i++;
	fnb = ft_atof(str);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '.' || str[i] == ',')
	{
		i++;
		while (ft_isdigit(str[i]))
			i++;
	}
	*fnb_ptr = fnb;
	return (i);
}

static int	get_ratio(const char *line, t_frect *ratio_ptr)
{
	printf("\n..... get_ratio .....\n");
	char	*ratio_str;
	void	*ptr;

	ptr = ratio_ptr;

	if (!(ratio_str = ft_strstr(line, " : ")))
		return (ui_ret_error("get_ratio", "\" : \" not found", 0));
	ratio_str += 3;
	ratio_str += get_float(ratio_str, &ratio_ptr->x);
	ratio_str += get_float(ratio_str, &ratio_ptr->y);
	ratio_str += get_float(ratio_str, &ratio_ptr->w);
	ratio_str += get_float(ratio_str, &ratio_ptr->h);
	printf("ratio .x = %f, .y = %f, w = %f, h = %f\n", (*ratio_ptr).x, (*ratio_ptr).y, (*ratio_ptr).w, (*ratio_ptr).h);
	return (1);
}

static char		*get_next_flag(const char *flags)
{
	char	*flag;
	int		i;
	int		start;
	int		len;

	i = 0;
	while (flags[i] && !ft_isprint(flags[i]))
		i++;
	start = i;
	len = 0;
	while (ft_isprint(flags[i]) && flags[i] != '|')
	{
		i++;
		len++;
	}
	if (!(flag = ft_strsub(flags, start, len)))
		return (ui_ret_null_error("get_next_flag", "flag <- ft_strsub failed", NULL));
	printf("get_next_flag = %s\n", flag);
	return (flag);
}

static char		**get_flags_tab(const char *flags)
{
	void	*tmp;
	char	**tab;
	char	*next_flag;
	int		i;

	tab = NULL;
	i = 0;
	while (*flags)
	{
		if (!(next_flag = get_next_flag(flags)))
			return (ui_ret_null_error("get_flags_tab", "get_next_falg failed", NULL));
		tmp = tab;
		tab = ft_2dstrpushback(tab, i++, next_flag);
		ft_strdel(&next_flag);
		ft_2dstrdel((char***)&tmp);
		while (!ft_isprint(*flags) && *flags)
			flags++;
		while (ft_isprint(*flags))
			flags++;
		while (!ft_isprint(*flags) && *flags)
			flags++;
		if (*flags == '|')
			flags++;
	}
	return (tab);
}

static int		get_resize_type(const char *line)
{
	printf("\n..... get_resize_type .....\n");
	char			*all_flags;
	char			**flags;
	int				i;
	t_resize_type	resize_type;

	printf("line = %s\n", line);
	if (!(all_flags = ft_strstr(line, " : ")))
		return (ui_ret_error("get_resize_type", "\" : \" not found", -1));
	all_flags += 3;
	printf("all_flags = %s\n", all_flags);
	flags = get_flags_tab(all_flags);
	ft_2dputendl((const char**)flags);
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

static int		get_frame_type(const char *line)
{
	char	*type;

	printf("\n..... get_frame_type .....\n");
	if (!(type = ft_strstr(line, " : ")))
		return (ui_ret_error("get_frame_type", "\" : \" not found", -1));
	type += 3;
	printf("type = %s\n", type);
	if (ft_strcmp(type, "UI_FRAME_SIMPLE") == 0)
		return (UI_FRAME_SIMPLE);
	else
		return (ui_ret_error("get_frame_type", "invalid frame type", -1));
}

static int		parse_frame(t_win *win, char **text, int *i)
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
		if (!ft_strstr(text[index], "data"))
			return (ui_ret_error("parse_frame", "\"data\" frame block expected", 0));
		index += 2;
		i += 2;
		f->data = parse_frame_data(win->rend, &text[index], f->type, i);
	}
	return (1);
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
		return (ui_ret_null_error("read_ui", "ui file oppening failed", NULL));
	while (get_next_line(fd, &line) > 0)
	{
		tmp = text;
		text = ft_2dstrpushback(text, i, line);
		ft_2dstrdel((char***)(&tmp));
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
	ft_strdel(&str);
	return (ui_ret_error(function, error_msg, ret_value));
}

int				ui_load(const char *path, t_win *win)
{
	int		i;
	char	**text;

	i = 0;
	if ((text = read_ui(path)) == NULL)
		return (ui_ret_error("ui_load", "read_ui failed", 0));
	ft_2dputendl((const char**)text);
	printf("--------- Debut Parsing ---------\n");
	while (text[i])
	{
		if (ft_strcmp(text[i], "frame") != 0)
			return (ui_load_error("ui_load :", "frame expected", 0, i + 1));
		i += 2;
		parse_frame(win, &text[i], &i);
	}
	return (1);
}