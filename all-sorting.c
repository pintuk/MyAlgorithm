#include <stdio.h>

#define SWAP(a,b)	do { \
				int t; \
				t = a; \
				a = b; \
				b = t; \
			} while (0)

void bubblesort(int A[], int N)
{
	int i,j;

	for (i = 0; i < N-1; i++) {
		for (j = i+1; j < N; j++) {
			if (A[i] > A[j]) {
				SWAP(A[i], A[j]);
			}
		}
	}
}

void merge(int A[], int start, int mid, int end)
{
	int i, j, k;
	int C[1024];

	k = 0; i = start; j = mid+1;
	while (i <= mid && j <= end) {
		if (A[i] < A[j])
			C[k++] = A[i++];
		else
			C[k++] = A[j++];
	}
	while (i <= mid) {
		C[k++] = A[i++];
	}
	while (j <= end) {
		C[k++] = A[j++];
	}
	k = 0;
	for (i = start; i <= end; i++)
		A[i] = C[k++];
}

void mergesort(int A[], int start, int end)
{
	if (start < end) {
		int mid = (start + end) / 2;
		mergesort(A, start, mid);
		mergesort(A, mid+1, end);
		merge(A, start, mid, end);
	}
}

int partition(int A[], int start, int end)
{
	int i,j, key;

	key = A[start]; i = start; j = end;
	printf("Partition: key: %d, i: %d, j: %d\n",key,i,j);
	while (i <= j) {
		while (key >= A[i]) i++;
		while (key < A[j]) j--;

		if (i < j)
			SWAP(A[i], A[j]);
		else
			SWAP(A[start], A[j]);
	}
	return j;
}

void quicksort(int A[], int start, int end)
{
	if (start < end) {
		int pivot;
		pivot = partition(A, start, end);
		quicksort(A, start, pivot-1);
		quicksort(A, pivot+1, end);	
	}
}

void heapify(int A[], int N, int root)
{
	int left, right, max;

	max = root;
	left = 2*root + 1;
	right = 2*root + 2;

	if (left < N && A[left] > A[max])
		max = left;

	if (right < N && A[right] > A[max])
		max = right;

	if (max != root) {
		SWAP(A[root], A[max]);
		heapify(A, N, max);
	}
}

void heapsort(int A[], int N)
{
	int i, end;

	for (int i = N / 2 - 1; i >= 0; i--)
		heapify(A, N, i);

	for (end = N-1; end >= 0; end--) {
		SWAP(A[0], A[end]);
		heapify(A, end, 0);
	}	
}

int main()
{
	int i, N;
	int A[1024];

	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);

	//bubblesort(A, N);
	//mergesort(A, 0, N-1);
	//quicksort(A, 0, N-1);
	heapsort(A, N);
	printf("Sorted:\n");
	for (i = 0; i < N; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");

	return 0;
}
