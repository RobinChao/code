#include <stdio.h>

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int* arr, int lo, int hi, int k) {
	int i;

	int pivot_index = (lo + hi) / 2;
	int pivot_value = arr[pivot_index];

	swap(arr + pivot_index, arr + hi);
	int store_index = lo;
	for (i = lo; i <= hi-1; ++i) {
		if (arr[i] <= pivot_value) {
			swap (arr + store_index, arr + i);
			++store_index;
		}
	}

	swap(arr + hi, arr + store_index);

	return store_index;
}

int quickselect_inner(int* arr, int lo, int hi, int k) {
	if (lo == hi)
		return arr[lo];

	int pivot_index = partition(arr, lo, hi, k);
	if (pivot_index == k)
		return arr[pivot_index];
	else if (pivot_index < k)
		return quickselect_inner(arr, pivot_index + 1, hi, k);
	else
		return quickselect_inner(arr, lo, pivot_index - 1, k);
}

int quickselect(int* arr, int n, int k) {
	return quickselect_inner(arr, 0, n-1, k-1); // since indexing starts at 0
}

int main(void) {
	int arr[] = { 3, 4, 9, 7, 5, 2, 6, 1, 0, 8 };
	printf("%d\n", quickselect(arr, 10, 1));
	printf("%d\n", quickselect(arr, 10, 2));
	printf("%d\n", quickselect(arr, 10, 3));
	printf("%d\n", quickselect(arr, 10, 10));
	return 0;
}