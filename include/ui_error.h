#ifndef UI_ERROR_H
# define UI_ERROR_H

int		ui_ret_error(const char *function, const char *error_msg, int ret_value);
void	*ui_ret_null_error(const char *function, const char *error_msg, void *return_value);

#endif