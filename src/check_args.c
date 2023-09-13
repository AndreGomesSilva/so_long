//
// Created by angomes- on 8/7/23.
//

#include "../inc/so_long.h"

static int arg_is_ext_ber(char *str)
{
    int len;
    char    *extension;


    len = (int)ft_strlen(str);
    extension = ".ber";
    if(ft_strncmp(&str[len - 4], extension, 4) == 0)
        return (TRUE);
    else
        return (FALSE);
}

int check_args(int argc, char**argv)
{
    if (argc == 2)
    {
      if (arg_is_ext_ber(*(argv + 1)))
          return (TRUE);
      else
          ft_error("ERROR\n - need a file with extension .ber\n");
    }
    else
        ft_error("ERROR\n - wrong number of args\n");
    return (0);
}