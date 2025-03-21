/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellucas <ellucas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:03:51 by ellucas           #+#    #+#             */
/*   Updated: 2025/03/07 13:31:44 by ellucas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_data	g_data;

void	print_banner(void)
{
	int		fd;
	char	*line;

	fd = open("logo.txt", O_RDONLY);
	if (fd == -1)
	{
		ft_error("Error: Could not read banner\n");
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		ft_putstr_fd(line, 1);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	print_time(void)
{
	clock_t	end_time;
	double	time_taken;

	end_time = clock();
	time_taken = ((double)(end_time - g_data.start_time))
		/ CLOCKS_PER_SEC * 1000;
	ft_putstr_fd("Time taken : ", 1);
	ft_putnbr_fd((int)time_taken, 1);
	ft_putstr_fd(" ms\n\n", 1);
	g_data.is_first_char = 1;
}

void	handle_signal(int signum, siginfo_t *info, void *context)
{
	(void)context;
	g_data.client_pid = info->si_pid;
	if (g_data.bit_count < 8)
	{
		g_data.c = g_data.c << 1;
		if (signum == SIGUSR2)
			g_data.c |= 1;
		g_data.bit_count++;
	}
	if (g_data.bit_count == 8)
	{
		if (g_data.is_first_char)
		{
			g_data.start_time = clock();
			g_data.is_first_char = 0;
		}
		if (g_data.c == '\0')
			print_time();
		else
			write(1, &g_data.c, 1);
		g_data.c = 0;
		g_data.bit_count = 0;
	}
	kill(g_data.client_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	print_banner();
	g_data.c = 0;
	g_data.bit_count = 0;
	g_data.is_first_char = 1;
	g_data.client_pid = 0;
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset (&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr_fd("\nPID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n\n", 1);
	while (1)
		pause ();
	return (0);
}
