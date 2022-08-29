#include "../includes/minitalk.h"

void	display_error(int num)
{
	if (num == USAGE)
		ft_putendl_fd("\tusage: ./client [pid] [\"string\"]", 2);
	else if (num == ERROR)
		ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
	int		s_pid;
	size_t	i;
	size_t	bit;
	int		ret_kill;

	if (argc != 3)
		display_error(USAGE);
	s_pid = ft_atoi(argv[1]);
	i = 0;
	while (i < ft_strlen(argv[2]))
	{
		bit = 0;
		while (bit < CHAR_BIT)
		{
			if (argv[2][i] >> bit & 1)
				ret_kill = kill(s_pid, SIGUSR1);
			else
				ret_kill = kill(s_pid, SIGUSR2);
			if (ret_kill == -1)
				display_error(ERROR);
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
