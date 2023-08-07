//
// Created by angomes- on 8/7/23.
//

#include "../inc/so_long.h"

int check_param(int argc, char**argv)
{
    if (argc == 2)
    {
        printf("%s", *(argv + 1));
    }
    else
    {
       printf("We need one map");
    }
    return (1);
}