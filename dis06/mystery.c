int num = 10;

char *create_mystery(void) {
	if (num > 0) {
		char *ret = malloc(10);
		strcpy(ret, "mystery");
		return ret;
	}
	return NULL;
}
