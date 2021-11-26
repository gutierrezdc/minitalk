/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagutier <cagutier@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:11:09 by cagutier          #+#    #+#             */
/*   Updated: 2021/11/26 09:56:32 by cagutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

int	ft_signal_handler()
{


}

void	ft_print_received(int signum, siginfo_t *siginfo, void *context)
{
	if (signum == SIGUSR1 && signum == SIGUSR2)
		ft_printf("\033[92mSignal received\033[0m\n");
}

int	main(int argc, char **argv)
{
	struct sigaction sig;

	sig.sa_sigaction = ft_print_received;
}
