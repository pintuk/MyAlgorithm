#include <stdio.h>
#include <limits.h>

#define SWAP(a,b)	do { \
				int t; \
				t = a; \
				a = b; \
				b = t; \
			} while (0)


void print_heap(int A[], int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%d  ", A[i]);
	printf("\n");
}

void min_heapify(int A[], int n, int root)
{
	int min, left, right;

	min = root;
	left = 2*root + 1;
	right = 2*root + 2;

	if (left < n && A[left] < A[min])
		min = left;
	if (right < n && A[right] < A[min])
		min = right;

	if (min != root) {
		SWAP(A[min], A[root]);
		min_heapify(A, n, min);
	}
}

void max_heapify(int A[], int n, int root)
{
	int max, left, right;

	max = root;
	left = 2*root + 1;
	right = 2*root + 2;

	if (left < n && A[left] > A[max])
		max = left;
	if (right < n && A[right] > A[max])
		max = right;

	if (max != root) {
		SWAP(A[max], A[root]);
		max_heapify(A, n, max);
	}
}

void max_heap_increase_key(int A[], int n, int index, int key)
{
	int parent;

	A[index] = key;
	if (index == 0)
		return;

	parent = (index - 1)/2;
	while (index != 0 && A[parent] < A[index]) {
		SWAP(A[parent], A[index]);
		index = (index - 1)/2;
		parent = (index - 1)/2;
	}
}

void max_heap_insert_key(int A[], int *n, int key)
{
	int i;

	*n = *n + 1;
	i = *n - 1;
	A[i] = INT_MIN;
	max_heap_increase_key(A, *n, i, key);
}

void max_heap_decrease_key(int A[], int n, int index, int key)
{
	int parent;

	A[index] = key;
	max_heapify(A, n, index);
}

int heap_extract_max(int A[], int *n)
{
	int root;

	if (*n < 0) return 0;
	if (*n == 1) return A[0];

	root = A[0];
	A[0] = A[*n-1];
	*n = *n - 1;
	max_heapify(A, *n, 0);

	return root;
}

void build_heap(int A[], int n)
{
	int i, end;

	for (i = n/2 - 1; i >= 0; i--)
		max_heapify(A, n, i);
}


int main()
{
	int i, N;
	int A[1024];
	int value = 0;

	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);

	build_heap(A, N);
	printf("Heap result:\n");
	print_heap(A, N);
	max_heap_increase_key(A, N, 3, 12);
	printf("Heap result increase_key (3, 12):\n");
	print_heap(A, N);
	max_heap_decrease_key(A, N, 5, 0);
	printf("Heap result decrease_key (5, 0):\n");
	print_heap(A, N);
	max_heap_insert_key(A, &N, 11);
	printf("Heap after insert_key (11):\n");
	print_heap(A, N);
	value = heap_extract_max(A, &N);
	printf("Heap max value is: %d\n", value);
	print_heap(A, N);
	return 0;
}
