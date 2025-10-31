#include "../includes/cub3d.h"

// void far_from_exit(int *x, int *y)
// {
	
// }

// void glitch_consume(void)
// {
// 	int x;
// 	int y;

// 	x = 0;
// 	y = 0;
// 	far_from_exit(*x, *y);
// 	if
// 	{
		
// 	}
//     game()->map.map[]
// }

// void	flood_fill(char **temp_map, int y, int x, t_game *game)
// {
// 	if (x < 0 || x >= game->map.width || y < 0 || y >= game->map.height)
// 		return ;
// 	if (temp_map[y][x] == 'C' || temp_map[y][x] == 'E' || temp_map[y][x] == 'P'
// 		|| temp_map[y][x] == '0')
// 	{
// 		if (temp_map[y][x] == 'E')
// 			game->map.e--;
// 		if (temp_map[y][x] == 'C')
// 			game->map.c--;
// 		if (temp_map[y][x] == 'P')
// 			game->map.p--;
// 		temp_map[y][x] = '-';
// 		flood_fill(temp_map, y + 1, x, game);
// 		flood_fill(temp_map, y - 1, x, game);
// 		flood_fill(temp_map, y, x + 1, game);
// 		flood_fill(temp_map, y, x - 1, game);
// 	}
// }