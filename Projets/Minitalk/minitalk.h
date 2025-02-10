/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jynra <jynra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:17:24 by ellucas           #+#    #+#             */
/*   Updated: 2025/02/10 23:11:20 by jynra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define _POSIX_C_SOURCE 199309L	// Definition POSIX
# define _DEFAULT_SOURCE			// usleep

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/time.h>
# include <time.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_data
{
	char			c;				// char en construction
	int				bit_count;		// Nb de bits recus (0-7)
	clock_t			start_time;
	int				is_first_char;
	pid_t			client_pid;
}	t_data;

void	ft_error(char *str);

#endif
