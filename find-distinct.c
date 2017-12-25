#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct TreeNode {
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
} Node;


void inorder(Node *node)
{
	if (node == NULL) {
		return;
	}

	inorder(node->left);
	printf("<%d> ", node->data);
	inorder(node->right);
}


Node * minnode(Node *node)
{
	int minvalue = -1;
	Node *temp;

	if (node == NULL) return NULL;

	if (node->left == NULL)
		return node;

	temp = minnode(node->left);

	return temp;
}

Node * bst_insert(Node *node, int data)
{
	if (node == NULL) {
		node = (Node *)malloc(sizeof(Node));
		node->data = data;
		node->left = NULL;
		node->right = NULL;
		return node;
	}

	if (data <= node->data) {
		node->left = bst_insert(node->left, data);
	}
	else {
		node->right = bst_insert(node->right, data);
	}

	return node;
}

Node * bst_delete(Node *node, int data)
{
	Node *temp = NULL;
	int minval = 0;

	if (node == NULL) return NULL;

	if (data < node->data)
		node->left = bst_delete(node->left, data);
	else if (data > node->data)
		node->right = bst_delete(node->right, data);
	else {
		if (node->left == NULL) {
			temp = node->right;
			free(node);
			return temp;
		} else if (node->right == NULL) {
			temp = node->left;
			free(node);
			return temp;
		}

		temp = minnode(node->right);
		node->data = temp->data;
		node->right = bst_delete(node->right, temp->data);
	}

	return node;
}

int bst_search(Node *node, int data)
{
	int found = 0;

	if (node == NULL) return 0;

	if (node->data == data) return 1;

	if (data < node->data)
		found = bst_search(node->left, data);
	else if (data > node->data)
		found = bst_search(node->right, data);

	return found;
}

int main()
{
	int arr[] = {6, 10, 5, 4, 9, 120, 4, 6, 10};
	int i,N;
	Node *root = NULL;
	Node *temp = NULL;
	int val = 0, found = 0;

	N = sizeof(arr)/sizeof(arr[0]);
	printf("size of arr = %d\n", N);
	for (i = 0; i < N; i++) {
		found = bst_search(root, arr[i]);
		if (found == 0)
			root = bst_insert(root, arr[i]);
	}
	printf("The original arr is:\n");
	for (i = 0; i < N; i++)
		printf("%d  ", arr[i]);
	printf("\n");
	printf("The distinct arr is:\n");
	inorder(root);
	printf("\n");

	return 0;
}
