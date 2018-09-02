#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid = fork();
	int exit;
	if (pid != 0) {
		wait(&exit);
	}
	printf("Hello World\n: %d\n", pid);
}
