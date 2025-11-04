
void draw_minimap(void)
{
    int y, x;
    float player_x = game()->player.player_x;
    float player_y = game()->player.player_y;
    float dir_x = game()->raycast.ray_x;
    float dir_y = game()->raycast.ray_y;
    float plane_x = game()->raycast.plane_x;
    float plane_y = game()->raycast.plane_y;
    y = 0;
    while (y < 192)
    {
        x = 0;
        while (x < 192)
        {
            float dx = (x - 96) / 64.0f;
            float dy = (y - 96) / 64.0f;
            float fx = player_x + dx * plane_x + dy * dir_x;
            float fy = player_y + dx * plane_y + dy * dir_y;
            int tex_x = ((int)(fx * 64)) % 64;
            int tex_y = ((int)(fy * 64)) % 64;
            if (tex_x < 0) tex_x += 64;
            if (tex_y < 0) tex_y += 64;
            char map_char = '\0';
            if(fx < 0 || fy < 0)
				map_char = '\0';
			else if (game()->map.map[(int)fy] && game()->map.map[(int)fy][(int)fx])
				map_char = game()->map.map[(int)fy][(int)fx];
            unsigned int color = 0x000000;
            if (map_char == '1')
                color = my_mlx_pixel_get(&game()->wall, tex_x, tex_y);
			else if (map_char == '0' && (int)fy != (int)game()->player.player_y && (int)fx != (int)game()->player.player_x)
				color = 0xFFFFFF;
            else if (map_char == '0' || map_char == 'N' || map_char == 'W' ||
                     map_char == 'S' || map_char == 'E' || map_char == 'O')
                color = 0x66FF00;
            else if (map_char == 'C')
                color = 0x00FF00;
			y = 192 - y;
            my_mlx_pixel_put(&game()->minimap, x, y, color);
            x++;
        }
        y++;
    }
}

float player_x = game()->player.player_x;
    float player_y = game()->player.player_y;
    float dir_x = game()->raycast.ray_x;
    float dir_y = game()->raycast.ray_y;
    float plane_x = game()->raycast.plane_x;
    float plane_y = game()->raycast.plane_y;


    float dx = (x - 96) / 64.0f;
            float dy = (y - 96) / 64.0f;
            float fx = player_x + dx * plane_x + dy * dir_x;
            float fy = player_y + dx * plane_y + dy * dir_y;
            int tex_x = ((int)(fx * 64)) % 64;
            int tex_y = ((int)(fy * 64)) % 64;
            if (tex_x < 0) tex_x += 64;
            if (tex_y < 0) tex_y += 64;
            if(fx < 0 || fy < 0)
				break ;
            if (game()->map.map[(int)fy] && game()->map.map[(int)fy][(int)fx] && game()->map.map[(int)fy][(int)fx] == '1')