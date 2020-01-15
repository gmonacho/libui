#include "ui.h"
#include "ui_error.h"

int				check_line_name(const char *line, const char *expected)
{
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
	if (ft_strcmp(name, expected) != 0)
		return (ui_ret_error("check_line_name", "bad line name", 0));
	else
		return (1);
}
