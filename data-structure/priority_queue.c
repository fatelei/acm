/*
 * input
 * 10
 * 1
 * 2
 * 3
 * 4
 * 5
 * 6
 * 7
 * 8
 * 9
 * 10
 */
#include <stdio.h>
#include <string.h>
#define MIN_VALUE -999999
#define LEFT(x) x*2
#define RIGHT(x) x*2+1
#define PARENT(x) x/2

typedef struct {
	int ary[1000];
	int heapsize;
}HEAP;

HEAP heap;

void max_heapify(HEAP *heap, int root) {
	int left = LEFT(root);
	int right = RIGHT(root);
	int max = root;

	if (left <= heap->heapsize && heap->ary[left] > heap->ary[max]) {
		max = left;
	}

	if (right <= heap->heapsize && heap->ary[right] > heap->ary[max]) {
		max = right;
	}

	if (max != root) {
		int tmp = heap->ary[root];
		heap->ary[root] = heap->ary[max];
		heap->ary[max] = tmp;
		max_heapify(heap, max);
	}

}

int heap_maximun() {
	return heap.ary[1];
}

int heap_extract_max() {
	if (heap.heapsize < 1) {
		return -1;
	}

	int max = heap.ary[1];

	// exchange
	heap.ary[1] = heap.ary[heap.heapsize];
	heap.heapsize -= 1;
	max_heapify(&heap, 1);
	return max;
}

void heap_increase_key(int index, int value) {
	int tmp;
	if (value > heap.ary[index]) {
		heap.ary[index] = value;

		while (index > 1 && heap.ary[PARENT(index)] < heap.ary[index]) {
			tmp = heap.ary[index];
			heap.ary[index] = heap.ary[PARENT(index)];
			heap.ary[PARENT(index)] = tmp;
			index = PARENT(index);
		}
	}
}

void max_heap_insert(int value) {
	heap.heapsize += 1;
	heap.ary[heap.heapsize] = MIN_VALUE;
	heap_increase_key(heap.heapsize, value);
}

void init() {
	memset(heap.ary, 0, sizeof(heap.ary));
	heap.heapsize = 0;
}

int main() {
	int i, n;
	int value;
	init();
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &value);
		max_heap_insert(value);
	}

	while (1) {
		int max = heap_extract_max();
		if (max == -1) {
			break;
		}
		printf("current max: %d\n", max);
	}

	return 0;
}
