#include "../includes/libft.h"

int     ft_get_pgcd(int a, int b)
{
    int reste;

    if (b > a)
        ft_swap(&a, &b);
    while ((reste = a % b) != 0)
    {
        a = b;
        b = reste;
    }
    return (b);
}