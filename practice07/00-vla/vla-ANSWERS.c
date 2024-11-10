#include <stdio.h>
#include <string.h>

int get_frequent(int* array, int size, int max) {
	int counts[max + 1];
	memset(counts, 0, sizeof(int) * (max + 1));
	for (int i = 0; i < size; i++)
		counts[array[i]]++;

	int max_idx = 0;
	for (int i = 1; i < max; i++)
		if (counts[i] > counts[max_idx])
			max_idx = i;

	return max_idx;
}

int array[10] = { 1, 1, 2, 2, 3, 3, 3, 4, 5, 6 };

int main() {
	int m = get_frequent(array, 10, 6);
	printf("%d\n", m);
	return 0;
}