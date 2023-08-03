/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:55:40 by angomes-          #+#    #+#             */
/*   Updated: 2023/07/06 19:13:41 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	print_char(char c);
int	print_string(char *str);
int	print_number(long int number);
int	print_unsigned_number(long int number);
int	print_number(long int number);
int	print_pointer(int pointer);
int	hexadecimal_convert(unsigned long number, int result, int flag_type);

#endif
