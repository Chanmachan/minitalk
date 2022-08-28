#include <signal.h>
#include <stdio.h>
#include <unistd.h>

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
	printf("%c\n", 0x1100001);
}