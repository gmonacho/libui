#include <stdio.h>
#include "error.h"

/**
 * @brief  error
 * @note   Affiche un message d'erreur personnalise avec perror
 * @param  *error_msg : Message d'erreur personnalise
 * @retval  0 : A fin de quitter le programme
 */
int		error(const char *error_msg)
{
	perror(error_msg);
	return (0);
}

/**
 * @brief  null_error
 * @note   Affiche un message d'erreur personnalise avec perror
 * @param  *error_msg : Message d'erreur personnalise
 * @retval NULL : A fin de quitter le programme
 */
void	*null_error(const char *error_msg)
{
	perror(error_msg);
	return (NULL);
}