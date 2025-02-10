/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jynra <jynra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:03:51 by ellucas           #+#    #+#             */
/*   Updated: 2025/02/10 23:32:44 by jynra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_data;

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

void    print_banner(void)
{
    int     fd;
    char    *line;

    fd = open("logo.txt", O_RDONLY);
    if (fd == -1)
    {
        ft_error("Error: Could not read banner\n");
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        ft_putstr_fd(line, 1);
        free(line);
    }
    close(fd);
}

/* calcule le temps de traitement du message */
void	print_time(void)
{
	clock_t	end_time;
	double	time_taken;

	end_time = clock();
	time_taken = ((double)(end_time - g_data.start_time)) / CLOCKS_PER_SEC * 1000;
	
	ft_putstr_fd("Time taken : ", 1);
	ft_putnbr_fd((int)time_taken, 1);
	ft_putstr_fd(" ms\n", 1);
	ft_putstr_fd("\n[OUTPUT] : ", 1);
	g_data.is_first_char = 1;
}

void	handle_signal(int signum, siginfo_t *info, void *context)
{
	(void)context;

	g_data.client_pid = info->si_pid;
	
	/* Decalage de bit uniquement si pas caractere complet */
	if (g_data.bit_count < 8)
	{
		g_data.c = g_data.c << 1;
		if (signum == SIGUSR2)
			g_data.c |= 1;
		g_data.bit_count++;
	}

	/* Si recu un caractere complet */
	if (g_data.bit_count == 8)
	{
		write(1, &g_data.c, 1);
		if (g_data.c == '\n')
			print_time();
		g_data.c = 0;
		g_data.bit_count = 0;
	}
	/* Envoi ackitment au client */
	kill(g_data.client_pid, SIGUSR1);

	/* Si char complet recu (8 bits) */
	if (g_data.bit_count == 8)
	{
		if (g_data.is_first_char)
		{
			time(&g_data.start_time);
			g_data.is_first_char = 0;
		}
		if (g_data.c == '\n')
			print_time();
		g_data.c = 0;			/* reinit pour le char suivant */
		g_data.bit_count = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	print_banner();
	/* Init des datas */
	g_data.c = 0;
	g_data.bit_count = 0;
	g_data.is_first_char = 1;
	g_data.client_pid = 0;
	
	/* Config du gestionnaire de signaux */
	sa.sa_sigaction = handle_signal;	/* Fonction de traitement */
	sa.sa_flags = SA_SIGINFO;				/* Recevoir les infos du signal */
	sigemptyset (&sa.sa_mask);		/* pas de masque de signaux */

	/* Installation des gestionnaires pour SIGUSR1 et 2 */
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	
	/* Affichage du PID */
	ft_putstr_fd("\nPID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("\n[OUTPUT] : ", 1);

	/* Boucle d'attente des signaux */
	while (1)
		pause ();
	return (0);
}
