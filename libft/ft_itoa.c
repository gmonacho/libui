/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 16:49:31 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/20 18:18:02 by thbrouss    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

static char		*ft_p_itoa(int value, int neg, int length, int tmp)
{
	char	*result;
	int		index;

	index = 0;
	while (tmp > 0)
	{
		length++;
		tmp /= 10;
	}
	if (!(result = malloc(sizeof(char) * length + 1)))
		return (NULL);
	index = 0;
	while (value > 0)
	{
		result[index] = value % 10 + '0';
		index++;
		value = value / 10;
	}
	if (neg)
		result[index++] = '-';
	result[index] = '\0';
	return (result);
}

char			*ft_itoa(int value)
{
	int		length;
	int		tmp;
	int		neg;
	char	*dest;

	length = 0;
	neg = 0;
	tmp = value;
	if (value == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (value == 2147483647)
		return (ft_strdup("2147483647"));
	if (value <= 0)
		length++;
	if (value < 0)
	{
		value = -value;
		tmp = -tmp;
		neg = 1;
	}
	if (value == 0)
		return (ft_strdup("0"));
	if (!(dest = ft_p_itoa(value, neg, length, tmp)))
		return (NULL);
	return (ft_strrev(dest));
}
