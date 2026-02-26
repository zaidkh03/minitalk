/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zalkhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 22:35:41 by zalkhali          #+#    #+#             */
/*   Updated: 2025/01/14 20:59:23 by zalkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handel_bit_length(int signum, unsigned int *length, char **message)
{
	static int	bit_index = 0;
	int			flag;

	flag = (signum == SIGUSR2);
	*length |= flag << bit_index;
	bit_index++;
	if (bit_index == 32)
	{
		if (*length > 0)
		{
			*message = malloc(*length + 1);
			if (!*message)
				exit(1);
			(*message)[*length] = '\0';
		}
		else
		{
			ft_printf("Invalid length: %u\n", *length);
			exit(1);
		}
		bit_index = 0;
	}
}

void	handel_bit_message(int signum, unsigned int *length, char **message)
{
	static unsigned int		char_index = 0;
	static char				current_char = 0;
	static int				bit_index = 0;
	int						flag;

	flag = (signum == SIGUSR2);
	current_char |= flag << bit_index;
	bit_index++;
	if (bit_index == 8)
	{
		(*message)[char_index++] = current_char;
		bit_index = 0;
		current_char = 0;
		if (char_index == *length)
		{
			ft_printf("received message: %s\n", *message);
			free(*message);
			*message = NULL;
			*length = 0;
			char_index = 0;
		}
	}
}

void	sig_handler(int signum)
{
	static unsigned int	length = 0;
	static char			*message = NULL;

	if (message == NULL)
		handel_bit_length(signum, &length, &message);
	else
		handel_bit_message(signum, &length, &message);
}

int	main(void)
{
	ft_printf("pid: %d\n", getpid());
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
		pause();
	return (0);
}
