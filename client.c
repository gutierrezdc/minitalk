/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagutier <cagutier@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:10:59 by cagutier          #+#    #+#             */
/*   Updated: 2021/12/13 10:23:05 by cagutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

void	ft_send_bits(int pid_numb, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)) != 0)
			kill(pid_numb, SIGUSR1);
		else
			kill(pid_numb, SIGUSR2);
		usleep(20);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid_numb;
	int	x;

	x = 0;
	if (argc != 3)
	{
		ft_putstr_fd("\033[97m-----\033[41;1mERROR\033[0m\033[97m-----\033[0m\n", 1);
		ft_putstr_fd("\033[91mNumber of arguments is invalid\033[0m\n", 1);
		ft_putstr_fd("Try: ./client \033[93mPID\033[0m \033[93mMESSAGE\033[0m\n", 1);
		return (1);
	}
	pid_numb = ft_atoi(argv[1]);
	while (argv[2][x] != '\0')
	{
		ft_send_bits(pid_numb, argv[2][x]);
		x++;
	}
	ft_putstr_fd("\033[90mMessage sent\033[0m\n", 1);
	return (0);
}
