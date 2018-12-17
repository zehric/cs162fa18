#include <unistd.h>

void investigate(int *data, void* args) {
	*data = *data + 1;
	sleep(3);
}
