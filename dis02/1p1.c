#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t pid = fork();
	printf("Hello world: %d\n", pid);
}
