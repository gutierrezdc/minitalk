/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagutier <cagutier@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:10:59 by cagutier          #+#    #+#             */
/*   Updated: 2021/11/26 11:29:33 by cagutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <signal.h>
#include <unistd.h>
#include "libft/ft_printf/ft_printf.h"
#include "libft/libft.h"*/
#include "minitalk.h"

void	ft_send_bits(int pid_numb, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)) == 1)
			kill(pid_numb, SIGUSR1);
		else
			kill(pid_numb, SIGUSR2);
		usleep(100);
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
		ft_putstr_fd("                             \033[97m-----\033[41;1mERROR\033[0m\033[97m-----\033[0m\n", 1);
		ft_putstr_fd("Number of arguments is invalid\n", 1);
		ft_putstr_fd("Correct format: ./client [\033[97mSERVER_PID\033[0m] [\033[97mMESSAGE\033[0m]\n", 1);
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
