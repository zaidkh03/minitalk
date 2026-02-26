/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_udigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zalkhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:29:14 by zalkhali          #+#    #+#             */
/*   Updated: 2024/09/19 18:30:58 by zalkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_udigit(unsigned long n, unsigned int base, int c)
{
	int		count;
	char	*symbols;

	if (c == 1)
		symbols = "0123456789ABCDEF";
	else
		symbols = "0123456789abcdef";
	if (n < base)
		return (ft_print_char(symbols[n]));
	else
	{
		count = ft_print_udigit(n / base, base, c);
		return (count + ft_print_udigit(n % base, base, c));
	}
}
