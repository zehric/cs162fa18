#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *helper(void *arg) {
	printf("HELPER\n");
	return NULL;
}
int main() {
	pthread_t thread;
	pthread_create(&thread, NULL, &helper, NULL);
	pthread_yield();
	printf("MAIN\n");
	return 0;
}
