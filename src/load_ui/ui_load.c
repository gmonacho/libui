#include <fcntl.h>
#include "ui.h"
#include "ui_error.h"
#include "libft.h"

char	**skip_next_block(char **str)
{
	int 	j;
	int		loop;
	int		nb_bracket;

	j = 0;
	loop = 1;
	nb_bracket = 0;
	while (str[j] && !ft_strchr(str[j], '{'))
		j++;
	if (str[j])
		j++;
	while (str[j] && loop)
	{
		if (ft_strchr(str[j], '}') && nb_bracket == 0)
			loop = 0;
		if (ft_strchr(str[j], '{'))
			nb_bracket++;
		else if (ft_strchr(str[j], '}'))
			nb_bracket--;
		j++;
	}
	return (&str[j]);
}

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
	while (text[i] && !ft_strchr(text[i], '}'))
	{
		printf("text[i] = %s\n", text[i]);
		if (ft_strcmp(text[i], "frame") != 0)
			return (ui_load_error("ui_load", "frame expected", 0, i + 1));
		i += 2;
		parse_frame(win, &text[i], &i);
	}
	return (1);
}