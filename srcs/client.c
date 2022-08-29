#include "../includes/minitalk.h"

void	display_error(int num)
{
	if (num == USAGE)
		ft_putendl_fd("\tusage: ./client [pid] [\"string\"]", 2);
	else if (num == PIDERR)
		ft_putendl_fd("Bad PID", 2);
	else if (num == KILERR)
		ft_putendl_fd("Error in \"kill\"", 2);
	exit(EXIT_FAILURE);
}

void	send_signal(int s_pid, char str)
{
	size_t	bit;
	int		ret_kill;

	bit = 0;
	while (bit < CHAR_BIT)
	{
		if (str >> bit & 1)
			ret_kill = kill(s_pid, SIGUSR1);
		else
			ret_kill = kill(s_pid, SIGUSR2);
		if (ret_kill == -1)
			display_error(KILERR);
		bit++;
		usleep(100);
	}
}

int	valid_pid(char *str)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (ft_isdigit(str[i]) == 0)
		{
			display_error(PIDERR);
		}
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	int		s_pid;
	size_t	i;

	if (argc != 3)
		display_error(USAGE);
	valid_pid(argv[1]);
	s_pid = ft_atoi(argv[1]);
	if (s_pid <= 0)
		display_error(PIDERR);
	i = 0;
	while (i < ft_strlen(argv[2]))
	{
		send_signal(s_pid, argv[2][i]);
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
