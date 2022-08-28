#include <signal.h>
#include <unistd.h>
#include "../libft/srcs/libft.h"

//void signal_handler()
//{
//
//}

int main(int argc, char **argv)
{
	int		s_pid;
	int		message;
	size_t	i;

	s_pid = ft_atoi(argv[1]);
	i = 0;
	while (i < ft_strlen(argv[2]))
	{
		while (j < 8)
		{
			kill(s_pid, argv[2][j]);
			j++;
		}
		i++;
	}
}
