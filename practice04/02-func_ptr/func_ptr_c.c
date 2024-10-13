#include <stdio.h>

typedef void (*operation_t)(int*);

void inc(int* val) {
	(*val)++;
}

void dec(int* val) {
	(*val)--;
}
void show(int* val) {
	printf("%d ", *val);
}

void process_array(int *array, int n, operation_t op) {
	for(int i = 0; i < n; i++) {
		op(&array[i]);
	}
}

enum { INC, DEC, SHOW};

int main() {
	int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	operation_t operations[] = { inc, dec, show };

	process_array(array, 10, operations[SHOW]);
	printf("\n");

	process_array(array, 10, operations[DEC]);

	process_array(array, 10, operations[SHOW]);
	printf("\n");

	return  0;
}
