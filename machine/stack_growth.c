#include <stdio.h>

#define STACK_UP	1
#define STACK_DOWN	2

int check_stack_growth(int* param) {
	int local;
	if (&local > param) 
		return STACK_UP;
	else
		return STACK_DOWN;
}

int main(void) {
	int param = 0;
	printf("%s\n", check_stack_growth(&param) ==  STACK_UP ? "STACK_UP" : "STACK_DOWN");
	return 0;
}