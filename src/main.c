#include "../inc/so_long.h"

int	main(int argc, char** argv)
{
    if (check_args(argc, argv))
         game_init(*(argv + 1));
    else
        ft_error("Error\n Fail To init the game\n");
    return (0);
}
