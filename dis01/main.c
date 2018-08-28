#include <stdio.h>
#include "violet.h"

int main()
{
	char str[100];
	int i;
	for (i = 0; i < 100; i++) {
		str[i] = 'a';
	}
	printf("before: %s\n", str);
	violet(str);
	printf("after: %s\n", str);
	return 0;
}
