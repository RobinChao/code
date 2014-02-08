#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* append(char* str, char c) {
	int len = strlen(str);
	char* new_str = (char*) malloc(sizeof(char) * (len+2));
	for (int i = 0; i < len; ++i) {
		new_str[i] = str[i];
	}
	new_str[len] = c;
	new_str[len+1] = '\0';
	return new_str;
}

void permute_inner(char* alphabet, char* prefix, int n, int k) {
	if (k == 0) {
		printf("%s\n", prefix);
		return;
	}

	for (int i = 0; i < n; ++i) {
		char* new_prefix = append(prefix, alphabet[i]);
		permute_inner(alphabet, new_prefix, n, k-1);
	}

}

// find all strings of length k
void permute(char* alphabet, int k) {
	int n = strlen(alphabet);
	char empty_prefix[] = "";
	permute_inner(alphabet, empty_prefix, n, k);
}


int main(void) {
	char a[] = "abcde";
	int k = 3;
	permute(a, k);

	return 0;
}