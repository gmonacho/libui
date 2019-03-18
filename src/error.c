#include <stdio.h>
#include "libft.h"
#include "ui_error.h"


int		ui_error(const char *error_msg)
{
	ft_putstr(error_msg);
	return (0);
}


void	*ui_null_error(const char *error_msg)
{
	ft_putstr(error_msg);
	return (NULL);
}

/*
** @brief  error
** @note   Affiche un message d'erreur personnalise avec perror
** @param  *error_msg : Message d'erreur personnalise
** @retval  0 : A fin de quitter le programme
*/
int		ui_perror(const char *error_msg)
{
	perror(error_msg);
	return (0);
}


/*
** @brief  null_error
** @note   Affiche un message d'erreur personnalise avec perror
** @param  *error_msg : Message d'erreur personnalise
** @retval NULL : A fin de quitter le programme
*/
void	*ui_null_perror(const char *error_msg)
{
	perror(error_msg);
	return (NULL);
}