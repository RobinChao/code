#include <stdio.h>

#define BIG_ENDIAN		1
#define LITTLE_ENDIAN	2

int check_endianess() {
	unsigned int a = 1;
	unsigned char* c = (unsigned char*)&a;

	if (*c == 1)
		return LITTLE_ENDIAN;
	else
		return BIG_ENDIAN;
}

int main(void) {
	printf("%s\n", check_endianess() == LITTLE_ENDIAN ? "LITTLE_ENDIAN" : "BIG_ENDIAN");
	return 0;
}