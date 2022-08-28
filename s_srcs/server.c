#include "../includes/minitalk.h"

void	signal_handler(int signum)
{
	(void)signum;
}

int main()
{
	int	s_pid;

	s_pid = getpid();
	printf("%d\n", s_pid);

	int a = 10;
	int i = 1;
	int digit = 0;
	while (i < a)
	{
		printf("%d [%d]\n", a>>digit & 1, digit);
		digit++;
		i = i * 2;
	}
	signal(SIGUSR1, signal_handler);
}