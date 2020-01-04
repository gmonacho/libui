#include "ui.h"
#include "ui_error.h"

char				*parse_str(char *str)
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