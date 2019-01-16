#include <stdio.h>
#include <stdlib.h>


#define MAX(a, b)	((a) > (b) ? (a) : (b))

typedef struct tree {
	int item;
	struct tree *left;
	struct tree *right;
} Node;


int height(Node *root)
{
	int left, right;

	if (root == NULL)
		return 0;

	left = height(root->left);
	right = height(root->right);

	return MAX(left, right) + 1;
}

Node *insert(Node *root, int item)
{
	if (root == NULL) {
		root = (Node *)malloc(sizeof(Node));
		root->item = item;
		root->left = NULL;
		root->right = NULL;
		return root;
	}

	if (item <= root->item) 
		root->left = insert(root->left, item);
	else
		root->right = insert(root->right, item);

	return root;
}

int main()
{
	int i, N;
	int A[100005];
	Node *root = NULL;
	int value = 0;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
		root = insert(root, A[i]);
	}
	value = height(root);
	printf("%d\n", value);

	return 0;
}
