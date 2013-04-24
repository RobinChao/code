#include <stdio.h>

int* top_k(int* list, int k) {
	int* top;
	int i;
	
	if (k == 0)		return NULL;
	
	top = (int*)malloc(k*sizeof(int));
	
	return top;
}

int main() {
	int n = 15;
	int arr[] = {5, 3, 4, 6, 9, 
				 0, 5, 6, 9, 8, 
				 5, 3, 1, 9, 7};
	int k = 5;
	int* top;
	int i;
	
	top = top_k(arr, k);
	for (i = 0; i < k; ++i)
		printf("%d ", top[i]);
	free(top);
	
	return 0;
}