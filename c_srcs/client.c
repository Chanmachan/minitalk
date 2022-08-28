#include "../includes/minitalk.h"

int main(int argc, char **argv)
{
	int		s_pid;
	size_t	i;
	size_t	j;

	j = 0;
	if (argc <= 2)
	{
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
	return (0);
}
