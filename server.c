/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagutier <cagutier@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:11:09 by cagutier          #+#    #+#             */
/*   Updated: 2021/11/26 15:35:19 by cagutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

void	ft_signal_handler(int signal)
{
	static int	bit;
	static int	c;

	while (bit < 8)
	{
		if (signal == SIGUSR1 || signal == SIGUSR2)
			c += 0x01 << bit;
		bit++;
	}
	if (bit == 8)
		write(1, &c, 1);
}

/*void	ft_print_received(int signum, siginfo_t *siginfo, void *context)
{
	if (signum == SIGUSR1 && signum == SIGUSR2)
		ft_printf("\033[92mSignal received\033[0m\n");
}*/

int	main(int argc, char **argv)
{
	struct sigaction sig;
	int	pid;
	
	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd("Correct format: ./server", 1);
		return (0);
	}
	pid = getpid();
	ft_putstr_fd("This is your \033[93;4mPID\033[0m \033[92m------->\033[0m ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n\033[90mWaiting for the message...\033[0m\n", 1);
	sigemptyset(&sig.sa_mask);
	sig.sa_handler = ft_signal_handler;
return(0);
}
