//
// Created by Andre on 12/08/23.
//

#include "../inc/so_long.h"

int create_new_player_image(t_game *game, char *path)
{
    mlx_delete_texture(game->player_texture);
    mlx_delete_image(game->mlx, game->player_img);
    game->player_texture = mlx_load_png(path);
    game->player_img = mlx_texture_to_image(game->mlx, game->player_texture);
    mlx_resize_image(game->player_img, game->image_new_width, game->image_new_height);
    return (TRUE);
}

int32_t create_texture_from_png(t_game *game)
{
    game->background_texture = mlx_load_png("./textures/floor/Grass.png");
    game->wall_texture = mlx_load_png("./textures/wall/Rock.png");
    game->player_texture = mlx_load_png("./textures/player_idle/right/tile000.png");
    game->exit_texture = mlx_load_png("./textures/exit/Sign.png");
    game->collectable_texture = mlx_load_png("./textures/collectable/potion.png");
    if (!game->background_texture || !game->wall_texture || !game->player_texture
    || !game->collectable_texture || !game->exit_texture)
        return (FALSE);
    return (TRUE);
}

void create_img_from_texture(t_game *game)
{
    int  width;
    int height;

    width = game->image_new_width;
    height = game->image_new_height;
    game->player_img = mlx_texture_to_image(game->mlx, game->player_texture);
    game->exit_img = mlx_texture_to_image(game->mlx, game->exit_texture);
    game->background_img = mlx_texture_to_image(game->mlx, game->background_texture);
    game->wall_img = mlx_texture_to_image(game->mlx, game->wall_texture);
    game->collectable_img= mlx_texture_to_image(game->mlx, game->collectable_texture);
    mlx_resize_image(game->player_img, width, height);
    mlx_resize_image(game->wall_img, width, height);
    mlx_resize_image(game->background_img, width, height);
    mlx_resize_image(game->collectable_img, width, height);
    mlx_resize_image(game->exit_img, width, height);
}

void    free_images(t_game *game)
{
    mlx_delete_image(game->mlx, game->background_img);
    mlx_delete_image(game->mlx, game->wall_img);
    mlx_delete_image(game->mlx, game->player_img);
    mlx_delete_image(game->mlx, game->exit_img);
    mlx_delete_image(game->mlx, game->collectable_img);
}

void    free_textures(t_game *game)
{
    mlx_delete_texture(game->collectable_texture);
    mlx_delete_texture(game->background_texture);
    mlx_delete_texture(game->wall_texture);
    mlx_delete_texture(game->player_texture);
    mlx_delete_texture(game->exit_texture);
}