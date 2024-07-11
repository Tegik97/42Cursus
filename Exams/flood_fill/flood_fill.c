#include <stdio.h>
#include <stdlib.h>

typedef struct  s_point
{
int           x;
int           y;
}               t_point;

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char	replace;
	int		n;

	replace = tab[begin.y][begin.x];
	tab[begin.y][begin.x] = 'F';
	if (begin.x < (size.x - 1) && tab[begin.y][begin.x + 1] == replace)
	{
		n = begin.x;
		begin.x++;
		flood_fill(tab, size, begin);
		begin.x = n;
	}
	if (begin.x != 0 && tab[begin.y][begin.x - 1] == replace)
	{
		n = begin.x;
		begin.x--;
		flood_fill(tab, size, begin);
		begin.x = n;
	}
	if (begin.y < (size.y - 1) && tab[begin.y + 1][begin.x] == replace)
	{
		n = begin.y;
		begin.y++;
		flood_fill(tab, size, begin);
		begin.y = n;
	}
	if (begin.y != 0 && tab[begin.y - 1][begin.x] == replace)
	{
		n = begin.y;
		begin.y--;
		flood_fill(tab, size, begin);
		begin.y = n;
	}
}
