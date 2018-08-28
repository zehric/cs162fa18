#include <stdio.h>

int violet(char *str)
{
	/* "major!" is 6 characters */
	char *major = "major!";
	int i;
	for (i = 0; i < 6; i++) {
		str[i] = major[i];
	}
	return 0;
}
