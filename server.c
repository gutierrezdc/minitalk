/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagutier <cagutier@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:11:09 by cagutier          #+#    #+#             */
/*   Updated: 2021/11/29 14:55:20 by cagutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

void	ft_signal_handler(int signal)
{
	static int	bit;
	static int	c;

	if (signal == SIGUSR1)
		c |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(c, 1);
		bit = 0;
		c = 0;
	}

}

/*ft_print_received(int signal)
{
	if (signum == SIGUSR1 || signum == SIGUSR2)
		ft_putstr_fd("\033[92mSignal received\033[0m\n");
}*/

int	main(int argc, char **argv)
{
	int	pid;
	
	(void)argv;
	pid = getpid();
	ft_putstr_fd("This is your \033[93;4mPID\033[0m \033[92m------->\033[0m ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n\033[90mWaiting for the message...\033[0m\n", 1);
	while (argc == 1)
	{
		signal(SIGUSR1, ft_signal_handler);
		signal(SIGUSR2, ft_signal_handler);
		pause ();
	}
	return(0);
}
