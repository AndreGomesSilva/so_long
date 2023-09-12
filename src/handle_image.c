//
// Created by Andre on 12/08/23.
//

#include "../inc/so_long.h"

int create_new_player_image(t_window *window, char *path)
{
    mlx_delete_texture(window->player_texture);
    mlx_delete_image(window->mlx, window->player_img);
    window->player_texture = mlx_load_png(path);
    window->player_img = mlx_texture_to_image(window->mlx, window->player_texture);
    mlx_resize_image(window->player_img, IMAGE_WIDTH, IMAGE_HEIGHT);
    return (TRUE);
}

int32_t create_texture_from_png(t_window *window)
{
    window->background_texture = mlx_load_png("./textures/floor/Grass.png");
    window->wall_texture = mlx_load_png("./textures/wall/Tree.png");
    window->player_texture = mlx_load_png("./textures/player_idle/right/tile000.png");
    window->exit_texture = mlx_load_png("./textures/exit/tile000.png");
    window->collectable_texture = mlx_load_png("./textures/collectable/potion1.png");
    if (!window->background_texture || !window->wall_texture || !window->player_texture
    || !window->collectable_texture || !window->exit_texture)
        return (FALSE);
    return (TRUE);
}

void create_img_from_texture(t_window *window)
{
    int  width;
    int height;

    width = IMAGE_WIDTH;
    height = IMAGE_HEIGHT;
    window->player_img = mlx_texture_to_image(window->mlx, window->player_texture);
    window->exit_img = mlx_texture_to_image(window->mlx, window->exit_texture);
    window->background_img = mlx_texture_to_image(window->mlx, window->background_texture);
    window->wall_img = mlx_texture_to_image(window->mlx, window->wall_texture);
    window->collectable_img= mlx_texture_to_image(window->mlx, window->collectable_texture);
    mlx_resize_image(window->player_img, width, height);
    mlx_resize_image(window->wall_img, width, height);
    mlx_resize_image(window->background_img, width, height);
    mlx_resize_image(window->collectable_img, width, height);
    mlx_resize_image(window->exit_img, width, height);
}

void    free_images(t_window *window)
{
    mlx_delete_image(window->mlx, window->background_img);
    mlx_delete_image(window->mlx, window->wall_img);
    mlx_delete_image(window->mlx, window->player_img);
    mlx_delete_image(window->mlx, window->exit_img);
    mlx_delete_image(window->mlx, window->collectable_img);
}

void    free_textures(t_window *window)
{
    mlx_delete_texture(window->collectable_texture);
    mlx_delete_texture(window->background_texture);
    mlx_delete_texture(window->wall_texture);
    mlx_delete_texture(window->player_texture);
    mlx_delete_texture(window->exit_texture);
}