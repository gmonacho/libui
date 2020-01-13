#include "ui_error.h"
#include "libft.h"

int		ui_ret_error(const char *function, const char *error_msg, int ret_value)
{
	char	*str;

	str = ft_strjoin(function,
		  ft_strjoin(" : ",
		  ft_strjoin(error_msg,
		  ft_strjoin(" (code error : ",
		  ft_strjoin(ft_itoa(ret_value), ").")))));
	ft_putendl_fd(str, 2);
	ft_strdel(&str);
	return (ret_value);
}

void	*ui_ret_null_error(const char *function, const char *error_msg, void *return_value)
{
	char	*str;

	str = ft_strjoin(function,
		  ft_strjoin(" : ", error_msg));
	ft_putendl_fd(str, 2);
	ft_strdel(&str);
	return (return_value);
}