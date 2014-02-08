#include <string.h>
#include <stdlib.h>
#include <stdio.h>
 
char* lcs(char* a, char* b) {
	int i,j;
	int len_a = strlen(a);
	int len_b = strlen(b);

	if (len_a == 0 || len_b == 0)
		return NULL;

	int *la = malloc(len_a * len_b * sizeof(int));
	int **lengths = malloc( len_a * sizeof(int*));
	for (i = 0; i < len_a; ++i)
		lengths[i] = la + i*len_b;

	char* ret = NULL;
	int max_len = 0;
	int start = -1;

	for (int i = 0; i < len_a; ++i) {
		for (int j = 0; j < len_b; ++j) {
			if (a[i] == b[j]) {
				if (i == 0 || j == 0) {
					lengths[i][j] = 1;
				}
				else {
					lengths[i][j] = lengths[i-1][j-1] + 1;
				}

				if (lengths[i][j] > max_len) {
					max_len = lengths[i][j];
					start = i-max_len+1;
				}
				else if (lengths[i][j] == max_len){
					// other substrings of same size;
				}
			}
			else {
				lengths[i][j] = 0;
			}
		}
	}

	if (max_len > 0) {
		ret = (char*)malloc(sizeof(char) * (max_len+1));
		memcpy(ret, a + start, max_len);
		ret[max_len] = '\0';
	}

	return ret;
}



int main() {
	printf("%s\n", lcs("thisisatest", "testing123testing")); // test

	printf("%s\n", lcs("abcdef", "pqdef123"));

	printf("%s\n", lcs("abcdef", "pq123"));

	printf("%s\n", lcs("abcdef", ""));
	return 0;
}
