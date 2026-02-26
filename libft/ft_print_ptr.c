/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zalkhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:41:19 by zalkhali          #+#    #+#             */
/*   Updated: 2024/09/19 18:32:19 by zalkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long n, int base, int c)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		count += write(1, "(nil)", 5);
	}
	else
	{
		count += ft_print_str("0x");
		count += ft_print_udigit(n, base, c);
	}
	return (count);
}
