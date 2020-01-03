#include <fcntl.h>
#include "ui.h"
#include "ui_error.h"
#include "libft.h"

int		check_line_name(const char *line, const char *expected)
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