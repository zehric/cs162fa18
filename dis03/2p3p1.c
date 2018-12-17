#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int pid, status;
	int newfd;
	if ((newfd = open("output_file.txt", O_CREAT|O_TRUNC|O_WRONLY, 0644)) < 0) {
		exit(1);
	}
	printf("Luke, I am your...\n");
	dup2(newfd, 1);
	printf("father\n");
	exit(0);
}
