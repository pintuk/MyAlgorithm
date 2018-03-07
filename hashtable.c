#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#define HASHSIZE	51

struct list {
	struct list *next;
	int key;
	int value;
} *hashtab[HASHSIZE];

unsigned hash(int key)
{
	unsigned index;

	index = key % HASHSIZE;
}

struct list *lookup(int key, int value)
{
	struct list *np;
	int index;

	index = hash(key);
	for (np = hashtab[index]; np != NULL; np = np->next) {
		if (np->value == value)
			return np;
	}

	return NULL;
}

struct list *insert(int key, int value)
{
	struct list *np, *ptr;
	unsigned index = 0;

	//printf("top insert:: index:%d, key:%d, value:%d\n", index, key, value);
	np = (struct list *)malloc(sizeof(*np));
	if (np == NULL)
		return NULL;
	np->key = key;
	np->value = value;
	np->next = NULL;
	index = hash(key);

	//printf("top insert:: index:%d, key:%d, value:%d\n", index, key, value);

	if (hashtab[index] == NULL) {
		hashtab[index] = np;
	} else {
		printf("insert:: index:%d, key:%d, value:%d\n", index, key, value);
		ptr = hashtab[index];
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = np;
	}

	return np;
}

void display(int N)
{
	int i;
	struct list *np;

	for (i = 0; i < N; i++) {
		for (np = hashtab[i]; np != NULL; np = np->next) {
			printf("[%d,%d]->", np->key, np->value);
		}
		printf("\n");
	}
}

void clear(void)
{
	int i;

	for (i = 0; i < HASHSIZE; i++)
		hashtab[i] = NULL;
}

int main()
{
	int i, N;
	int A[HASHSIZE];
	struct list *np;

	printf("Enter N: ");
	scanf("%d", &N);
	clear();
	printf("Enter the elements:\n");
	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
		insert(A[i], i);
	}
	display(HASHSIZE);

	np = lookup(4, 29);
	if (np != NULL) {
		printf("Found: key: %d, value: %d\n", np->key, np->value);
	} else {
		printf("Not Found...!\n");
	}

	return 0;
}





