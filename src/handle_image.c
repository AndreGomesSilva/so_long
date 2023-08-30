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
    mlx_resize_image(game->player_img, 80, 80);
    return (TRUE);
}

int32_t create_texture_from_png(t_game *game)
{
    game->background_texture = mlx_load_png("./textures/floor2.png");
    game->wall_texture = mlx_load_png("./textures/rock6.png");
    game->player_texture = mlx_load_png("./textures/idle_player_W.png");
    game->exit_texture = mlx_load_png("./textures/exit.png");
    game->collectable_texture = mlx_load_png("./textures/book1.png");
    if (!game->background_texture || !game->wall_texture || !game->player_texture
    || !game->collectable_texture || !game->exit_texture)
        return (FALSE);
    return (TRUE);
}

void create_img_from_texture(t_game *game)
{
    int32_t width;
    int32_t height;

    width = 80;
    height = 80;
    game->player_img = mlx_texture_to_image(game->mlx, game->player_texture);
    game->exit_img = mlx_texture_to_image(game->mlx, game->exit_texture);
    game->background_img = mlx_texture_to_image(game->mlx, game->background_texture);
    game->wall_img = mlx_texture_to_image(game->mlx, game->wall_texture);
    game->collectable_img= mlx_texture_to_image(game->mlx, game->collectable_texture);
    mlx_resize_image(game->player_img, width, height);
    mlx_resize_image(game->wall_img, width, height);
    mlx_resize_image(game->background_img, width, height/ 2);
    mlx_resize_image(game->collectable_img, width/2, height/2);
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