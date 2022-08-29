#include "../includes/minitalk.h"

volatile sig_atomic_t	g_receive_sig;
int bit = 0;
int ret = 0;

void	output_char()
{
	if (g_receive_sig == SIGUSR1)
	{
		ret += (0b00000001 << bit);
	}
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
	printf("pid : %d\n", s_pid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
	{
		pause();
		output_char();
	}
}
