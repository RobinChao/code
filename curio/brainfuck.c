#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DEFAULT_ARR_SIZE	1024
#define DEFAULT_STK_SIZE	128

int arr_size;
char* arr;
long long arr_ptr;
char* filename;
FILE* file;

long long *stack;
long long top;

long long pop() {
	if (top == -1)	return -1;
	long long result = stack[top];
	--top;
	return result;
}

long long peek() {
	if (top == -1)	return -1;
	long long result = stack[top];
	return result;
}

int push(long long byte_num) {
	if (top+1 < DEFAULT_STK_SIZE) {
		++top;
		stack[top] = byte_num;
		return 0;
	}
	return -1;
}

// >	++ptr;
// <	--ptr;
// +	++*ptr;
// -	--*ptr;
// .	putchar(*ptr);
// ,	*ptr=getchar();
// [	while (*ptr) {
// ]	}

int compile() {
	char c;
	long long byte_num = -1;
	while((c = (char)fgetc(file)) != EOF) {
		++byte_num;

		if (isspace(c)) {
			continue;
		}
		else { 
			// printf("%lld. c = '%c', arr_ptr = %lld, top = %lld\n", byte_num, c, arr_ptr, top);

			if (c == '>') {
				++arr_ptr;
			}
			else if (c == '<') {
				--arr_ptr;

				if (arr_ptr < -1)
					arr_ptr = -1;
			}
			else if (c == '+') {
				++*(arr + arr_ptr);
			}
			else if (c == '-') {
				--*(arr + arr_ptr);
			}
			else if (c == '.') {
				putchar(*(arr + arr_ptr));
			}
			else if (c == ',') {
				*(arr + arr_ptr) = getchar();
			}
			else if (c == '[') {
				push(byte_num);
			}
			else if (c == ']') {
				long long num = peek();
				// printf("%lld. num = %lld\n", byte_num, num);
				if (num != -1) {
					if (*(arr + arr_ptr) == 0) {
						pop();
						continue;
					}
					else {
						byte_num = num - 2;
						fseek(file, byte_num, SEEK_SET);
					}
				}
			}
			else {
				printf("%lld : source code has invalid character !\n", byte_num);
				return -1;
			}
		}
	}

	return 0;
}

int init() {
	arr_size = (arr_size < DEFAULT_ARR_SIZE) ? DEFAULT_ARR_SIZE : arr_size;
	arr = (char*) malloc(sizeof(char) * arr_size);
	if (arr == NULL)	return -1;
	memset(arr, 0, arr_size);

	arr_ptr = 0;

	file = fopen(filename, "r");
	if (file == NULL)	return -1;

	stack = (long long *) malloc(sizeof(long long) * DEFAULT_STK_SIZE);
	if (stack == NULL) 	return -1;

	top = -1;

	// printf("[%d] arr = %lld, arr_ptr =%lld\n", __LINE__, (long long)arr, arr_ptr);

	return 0;
}

void usage(char* cmd) {
	printf("%s <src_code.bf> [-size n]\n", cmd);
}

int parse_args(int argc, char** argv) {
	if (argc < 2) {
		usage(argv[0]);
		return -1;
	}
	else {
		int i;
		for (i = 1; i < argc; ++i) {
			if (strcasecmp("-size", argv[i]) == 0) {
				if (i+1 < argc) {
					++i;
					arr_size = atoi(argv[i]);
				}
				else {
					printf("2\n");
					usage(argv[0]);
					return -1;
				}
			}
			else 
				filename = argv[i];
		}
		return 0;
	}
}

int main(int argc, char** argv) {
	if (parse_args(argc, argv) == 0) {
		if (init() == 0) {
			compile();
			fclose(file);
		}
	}

	return 0;
}