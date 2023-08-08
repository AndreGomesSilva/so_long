#include "../inc/so_long.h"

int	main(int argc, char** argv)
{
    if (check_param(argc, argv))
    {
        game_init(*(argv + 1));

    }
}
