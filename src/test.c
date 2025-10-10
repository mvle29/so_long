#include "../include/so_long.h"

void    display_map(t_map *map)
{
    int x;
    int y;

    y = 0;
    printf("\n");
    while (y <= map->y_max)
    {
        x = 0;
        while (x <= map->x_max)
        {
            printf(" %c ", map->grid[y][x]);
            x++;
        }
        printf("\n");
        y++;
    }
}

int    display_error(void)
{
    printf("\n UNE ERREUR A ETE RENCONTREE \n");
    return (1);
}

int main(int agc, char **agv)
{
    t_map       *mapp;
    //t_game      *game;
    
    if (agc != 2)
        return (display_error());
    mapp = map(agv[1]); // Fait
    if (!mapp)
        return (display_error());
    display_map(mapp);
    free_map(mapp);
}
