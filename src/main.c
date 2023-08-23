#include "../inc/so_long.h"

int32_t	main(int argc, char** argv)
{
    if (check_args(argc, argv))
         game_init(*(argv + 1));
    else
        ft_printf("ERROR = Fail To init the game\n");

}
