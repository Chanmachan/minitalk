#include "../includes/minitalk.h"

int main(int argc, char **argv)
{
	int		s_pid;
	size_t	i;
	size_t	bit;

	if (argc != 3)
		return (0);
	s_pid = ft_atoi(argv[1]);
	i = 0;
	while (i < ft_strlen(argv[2]))
	{
		bit = 0;
		while (bit < CHAR_BIT)
		{
			if (argv[2][i] >> bit & 1)
				kill(s_pid, SIGUSR1);
			else
				kill(s_pid, SIGUSR2);
			bit++;
			usleep(500);
		}
		i++;
	}
	return (0);
}

/*int main(int argc, char **argv)
{
	(void)argc;
	pid_t s_pid = ft_atoi(argv[1]);
	kill(s_pid, ft_atoi(argv[2]));
}*/
