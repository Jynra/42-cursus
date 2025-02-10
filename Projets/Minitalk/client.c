/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jynra <jynra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:03:48 by ellucas           #+#    #+#             */
/*   Updated: 2025/02/10 23:31:47 by jynra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_received = 0;

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

void	ack_handler(int signum)
{
	(void)signum;
	g_received = 1;
}

void	wait_for_ack(void)
{
	int	timeout;

	timeout = 0;
	while (!g_received && timeout < 100)
	{
		usleep(1);
		timeout++;
	}
	g_received = 0;
}

void	send_char(pid_t server_pid, char c)
{
	int	bit;

	bit = 7;	/* start sur le bit le plus fort */
	
	while (bit >= 0)
	{	
		if (c & (1 << bit))
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		wait_for_ack(); /* Attend ackitment du server */
		bit--;
	}
}

int	main(int ac, char **av)
{
	pid_t				server_pid;
	char				*message;
	int					i;
	struct sigaction	sa;

	if (ac != 3)
	{
		ft_printf("Usage : ./client [server_pid] [message]\n");
		return (1);
	}

	/* Config gestionnaire d'ackitment */
	sa.sa_handler = ack_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_error("Error : sigaction failed\n");
	
	server_pid = ft_atoi(av[1]);
	if (server_pid <= 0 || kill(server_pid, 0) == -1)
	{
		ft_error("Error : Invalid PID\n\n");
		return (1);
	}
	i = 0;
	message = av[2];
	while (message[i])
	{
		send_char(server_pid, message[i]);
		i++;
	}
	send_char(server_pid, '\n');
	return (0);
}
