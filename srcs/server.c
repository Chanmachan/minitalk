#include "../includes/minitalk.h"

volatile sig_atomic_t	g_receive_sig;

void	output_char()
{
	static int	bit;
	static int	ret;

	if (g_receive_sig == SIGUSR1)
		ret += (0b00000001 << bit);
	if (bit == 7)
	{
		ft_putchar_fd(ret, 1);
		bit = 0;
		ret = 0;
		return;
	}
	bit++;
}

void	signal_handler(int signum)
{
	g_receive_sig = signum;
}

int main()
{
	int			s_pid;

	s_pid = getpid();
	ft_printf("pid : %d\n", s_pid);
	if (signal(SIGUSR1, signal_handler) == SIG_ERR)
		exit(EXIT_FAILURE);
	if (signal(SIGUSR2, signal_handler) == SIG_ERR)
		exit(EXIT_FAILURE);
	while (1)
	{
		pause();
		output_char();
	}
}
