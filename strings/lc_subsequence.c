#include <string.h>
#include <stdlib.h>
#include <stdio.h>
 
#define MAX(A,B) (((A) > (B)) ? (A) : (B))

void debug(const char *a, const char *b, int **lengths) {
	int i, j;
	int len_a = strlen(a)+1;
	int len_b = strlen(b)+1;

	for( j = 0; j < len_b; ++j) {
		if (j == 0)
			printf("    ");
		else
			printf("%c ", b[j-1]);
	}
	printf("\n");

	for (i = 0; i < len_a; ++i) {
		if (i == 0)
			printf("  ");
		else
			printf("%c ", a[i-1]);

		for( j = 0; j < len_b; ++j) {
			printf("%d ", lengths[i][j]);
		}
		printf("\n");
	}
}

/*
                  /
                  |  0, 											if i = 0 or j= 0 
lcs(x[i], y[j]) = |  lcs(x[i-1], y[j-1]) + 1,	 					if x[i] = x[j]
                  |  longest(lcs(x[i], x[j-1]), lcs(x[i-1], y[j])),	otherwise
                  \ 
*/

// subsequence is different from a substring, 
// for the terms of the former need not be consecutive terms of the original sequence
char * lcs(const char *a, const char * b) {
	int len_a = strlen(a)+1;
	int len_b = strlen(b)+1;

	int buf_len = 40;
	char buf[40], *result;

	int i, j;
	const char *x, *y;
	
	int *la = malloc(len_a * len_b * sizeof(int));
	int **lengths = malloc( len_a * sizeof(int*));
	
	for (i = 0; i < len_a; ++i)
		lengths[i] = la + i*len_b;

	for (i = 0, x = a; *x; i++, x++) {
		for (j = 0, y = b; *y; j++, y++) {
			if (*x == *y) {
				lengths[i+1][j+1] = lengths[i][j] + 1;
			}
			else {
				int max_len = MAX(lengths[i+1][j], lengths[i][j+1]);
				lengths[i+1][j+1] = max_len;
			}
		}
	}

	// debug(a, b, lengths);

	result = buf + buf_len;
	*--result = '\0';
	i = len_a - 1;
	j = len_b - 1;
	
	while ( (i > 0) && (j > 0) ) {
		if (lengths[i][j] == lengths[i-1][j])
			i -= 1;
		else if (lengths[i][j] == lengths[i][j-1])
			j -= 1;
		else {
			*--result = a[i-1];
			// printf("a[%d] = %c\n", i-1, a[i-1]);
			i-=1; j-=1;
		}
	}
	
	free(la); 
	free(lengths);
	
	return strdup(result);
}



int main() {
	printf("%s\n", lcs("thisisatest", "testing123testing")); // tsitest
	return 0;
}
