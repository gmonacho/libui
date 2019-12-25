
#include "../includes/libft.h"

float	ft_atof(const char *str)
{
	float	is_neg;
	float	nb;
	float	fnb;
	int		zero_count;

	is_neg = 1;
	nb = 0;
	zero_count = 0;
	if (str)
	{
		while (!ft_isprint(*str) && *str)
			str++;
		nb = ft_atoi(str);
		while (ft_isdigit(*str))
			str++;
		if (*str == '.' || *str == ',')
		{
			str++;
			while (*str == '0')
			{
				str++;
				zero_count++;
			}
			fnb = ft_atoi(str);
			while (fnb >= 1)
				fnb /= 10;
			while (zero_count--)
				fnb /= 10;
		}
	}
	return ((nb + fnb) * is_neg);
}
