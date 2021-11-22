/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagutier <cagutier@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:10:59 by cagutier          #+#    #+#             */
/*   Updated: 2021/11/22 12:58:36 by cagutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

void	ft_send_bits(int pid_numb, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (0x01 << bit) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
	x++;
}

void	ft_send_str(int pid_numb, char str)
{
	int	x;

	x = 0;
	while (str[x] >= 32 && str[x] <= 126)
	{
		ft_send_bits(pid_numb, str[x]);
		x++;
	}
}

int	main(int argc, char **argv)
{
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
			ft_send_str(pid_numb, argv[2][x]);
			x++;
		}
	}
}
