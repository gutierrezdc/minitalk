/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagutier <cagutier@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:39:06 by cagutier          #+#    #+#             */
/*   Updated: 2021/12/01 13:10:49 by cagutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

void	ft_signal_handler(int signal, siginfo_t *info, void *ucontest_t)
{
	static int	bit;
	static int	c;

	(void)ucontest_t;
	(void)info;
	if (signal == SIGUSR1)
		c |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(c, 1);
		kill(info->si_pid, SIGUSR1);
		bit = 0;
		c = 0;
		usleep(30);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sig;
	int					pid;

	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd("\033[91mNumber of arguments is invalid\033[0m\n", 1);
		ft_putstr_fd("Correct format:\033[93m ./server\033[0m\n", 1);
		return (1);
	}
	pid = getpid();
	ft_putstr_fd("This is your \033[93;4mPID\033[0m \033[92m------->\033[0m ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n\033[90mWaiting for the message...\033[0m\n", 1);
	sig.sa_handler = (void (*)(int))ft_signal_handler;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = 0;
	while (argc == 1)
	{
		sigaction(SIGUSR1, &sig, NULL);
		sigaction(SIGUSR2, &sig, NULL);
		pause ();
	}
	return (0);
}
