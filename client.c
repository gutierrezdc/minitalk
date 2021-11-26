/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagutier <cagutier@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:10:59 by cagutier          #+#    #+#             */
/*   Updated: 2021/11/25 15:27:37 by cagutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_send_bits(int pid_numb, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (0x01 << bit) == 1)
			kill(pid_numb, SIGUSR1);
		else
			kill(pid_numb, SIGUSR2);
		usleep(100);
	}
	bit++;
}

/*void	ft_send_str(int pid_numb, char *str)
{
	int	x;

	x = 0;
	while (str[x] >= 32 && str[x] <= 126)
	{
		ft_send_bits(pid_numb, str[x]);
		x++;
	}
}*/

void	ft_print_received(int signum, siginfo_t *siginfo, void *context)
{
	if (signum == SIGUSR1 && signum == SIGUSR2)
		write(1, "Signal received\n", 16);
}	

int	main(int argc, char **argv)
{
	struct sigaction sig;
	int	pid_numb;
	int	x;

	x = 0;
	if (argc != 3)
	{
		ft_printf("Error: invalid number of arguments\n");
		ft_printf("Correct format: ./client [PID] [string]\n");
	}
	if (argc == 3)
	{
		pid_numb = ft_atoi(argv[1]);
		if (pid_numb <= 0)
		{
			ft_printf("Unknown PID\n");
			exit (-1);
		}
		while (argv[2][x] != '\0')
		{
//			ft_send_str(pid_numb, argv[2][x]);
			ft_send_bits(pid_numb, argv[2][x]);
			x++;
		}
		sig.sa_sigaction = ft_print_received;
	}
}
