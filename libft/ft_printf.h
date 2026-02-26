/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zalkhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:06:23 by zalkhali          #+#    #+#             */
/*   Updated: 2024/09/19 18:28:33 by zalkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_print_format(char specifier, va_list ap);
int	ft_print_digit(long n, int base, int c);
int	ft_print_udigit(unsigned long n, unsigned int base, int c);
int	ft_print_ptr(unsigned long n, int base, int c);
int	ft_print_str(char *s);
int	ft_print_char(char c);

#endif
