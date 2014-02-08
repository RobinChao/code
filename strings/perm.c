#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char* a, char* b) {
	char tmp = *a;
	*a = *b;
	*b = tmp;
}


// with no duplicates
void permute(char* str, int n) { 	
	int i;
	int len = strlen(str);
	if (n == len) 
		printf("%s, ", str);
	else {
		for(i = n; i < len; i++) {
			swap(str+n, str+i);
			permute(str, n+1);
			swap(str+i, str+n);
		}
	}
}

// with duplicates
void permute2(char* str, int n) {	
	int i;
	char visited_char[256];
	memset(visited_char, 0, 256);

	int len = strlen(str);

	if (n == len) 
		printf("%s, ", str);
	else {
		for(i = n; i < len; i++) {
			if(visited_char[str[i]])	
				continue;
			else 
				visited_char[str[i]] = 1;
			
			swap(str+n, str+i);
			permute2(str, n+1);
			swap(str+i, str+n);
		}
	}
}

int compare(const void* x, const void* y) { 
	return ( *(char*)x - *(char*)y); 
}

int main(){
	char s1[] = "abcde"; // do not use string literals like char* s = "123"
	printf("\n\npermute('%s', 0) = \n", s1);
	permute(s1, 0);

	char s2[] = "abc";
	printf("\n\npermute('%s', 0) = \n", s2);
	permute(s2, 0);

	char s3[] = "abac";
	printf("\n\npermute('%s', 0) =  <incorrect>\n", s3);
	permute(s3, 0);
	
	// qsort(s3, strlen(s3), sizeof(char), compare);
	// printf("\nafter qsort s3 = %s\n", s3);
	printf("\n\npermute2('%s', 0) = \n", s3);
	permute2(s3, 0);
	
	return 0;
}