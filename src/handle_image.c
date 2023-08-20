//
// Created by Andre on 12/08/23.
//

#include "../inc/so_long.h"

int32_t create_texture_from_png(t_game *game)
{
    game->background_texture = mlx_load_png("./textures/tile_040.png");
    game->wall_texture = mlx_load_png("./textures/tile_065.png");
    game->player_texture = mlx_load_png("./textures/player_idle/tile007.png");
    game->exit_texture = mlx_load_png("./textures/tile_036.png");
    game->collectable_texture = mlx_load_png("./textures/boar_NE_idle_2.png");
    if (!game->background_texture || !game->wall_texture || !game->player_texture
    || !game->collectable_texture || !game->exit_texture)
        return (FALSE);
    return (TRUE);
}

void create_img_from_texture(t_game *game)
{
    game->player_img = mlx_texture_to_image(game->mlx, game->player_texture);
    game->exit_img = mlx_texture_to_image(game->mlx, game->exit_texture);
    game->background_img = mlx_texture_to_image(game->mlx, game->background_texture);
    game->wall_img = mlx_texture_to_image(game->mlx, game->wall_texture);
    game->collectable_img= mlx_texture_to_image(game->mlx, game->collectable_texture);
    mlx_resize_image(game->player_img, 64, 64);
    mlx_resize_image(game->wall_img, 64, 64);
    mlx_resize_image(game->background_img, 64, 64);
    mlx_resize_image(game->collectable_img, 64, 64);
    mlx_resize_image(game->exit_img, 64, 64);
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