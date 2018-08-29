#include <stdio.h>
#include "violet.h"

int main()
{
	char str[20];
	int i;
	for (i = 0; i < 19; i++) {
		str[i] = 'a';
	}
	str[19] = 0;
	printf("before: %s\n", str);
	violet(str);
	printf("after:  %s\n", str);
	return 0;
}
