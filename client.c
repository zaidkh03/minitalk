/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zalkhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 22:35:28 by zalkhali          #+#    #+#             */
/*   Updated: 2025/01/14 20:59:59 by zalkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_length(int pid, unsigned int len)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if ((len >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(1000);
		i++;
	}
}

void	send_string(int pid, char *str)
{
	int	i;
	int	bit;

	i = 0;
	while (str[i])
	{
		bit = 0;
		while (bit < 8)
		{
			if ((str[i] >> bit) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(1000);
			bit++;
		}
		i++;
	}
}

void	send_bit(int pid, char *str, unsigned int len)
{
	send_length(pid, len);
	send_string(pid, str);
}

int	main(int ac, char **av)
{
	int		pid;
	char	*str;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		str = av[2];
		send_bit(pid, str, ft_strlen(str));
	}
	else
	{
		ft_printf("Usage: %s <PID> <Message>\n", av[0]);
	}
	return (0);
}
