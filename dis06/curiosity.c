#include <pthread.h>
#include <stdio.h>
#include <investigate.h>
#include <mystery.h>

pthread_mutex_t lock;
pthread_cond_t cv;
int data = 177013;

void *chitanda(void *args) {
	printf("I'm curious!\n");
	investigate(data, args);
}

int main()
{
	pthread_mutex_init(&lock);
	pthread_cond_init(&cv);
	pthread_t thread;
	char *mystery = create_mystery();
	while (mystery != NULL) {
		pthread_create(&thread, NULL, chitanda, mystery);
		mystery = create_mystery();
	}
}
