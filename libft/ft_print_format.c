/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zalkhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:39:52 by zalkhali          #+#    #+#             */
/*   Updated: 2024/09/19 18:35:07 by zalkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += ft_print_str(va_arg(ap, char *));
	else if (specifier == 'p')
		count += ft_print_ptr((unsigned long)va_arg(ap, void *), 16, 0);
	else if (specifier == 'd' || specifier == 'i')
		count += ft_print_digit(va_arg(ap, int), 10, 0);
	else if (specifier == 'u')
		count += ft_print_udigit(va_arg(ap, unsigned int), 10, 0);
	else if (specifier == 'x')
		count += ft_print_udigit(va_arg(ap, unsigned int), 16, 0);
	else if (specifier == 'X')
		count += ft_print_udigit(va_arg(ap, unsigned int), 16, 1);
	else if (specifier == '%')
		count += ft_print_char('%');
	return (count);
}
