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
	Node *root = NULL;
	Node *temp = NULL;
	int val = 0, found = 0;
/*
	root = bst_insert(root, 25);
	root = bst_insert(root, 5);
	root = bst_insert(root, 10);
	root = bst_insert(root, 15);
	root = bst_insert(root, 20);
	root = bst_insert(root, 30);
	root = bst_insert(root, 40);
*/
	printf("Enter element to insert (-9999 to quit): ");
	while (1) {
		scanf("%d", &val);
		if (val == -9999) break;
		root = bst_insert(root, val);
	}

	inorder(root);
	printf("\n");

	temp = minnode(root);
	if (temp == NULL)
		printf("min node = NULL\n");
	else
		printf("Min node value = %d\n", temp->data);

	printf("Enter a value to delete: ");
	scanf("%d", &val);
	root = bst_delete(root, val);
	printf("After delete element <%d>: \n", val);
	inorder(root);
	printf("\n");

	printf("Enter element to search: ");
	scanf("%d", &val);
	found = bst_search(root, val);
	if (found == 0)
		printf("Element <%d> not found\n", val);
	else if (found == 1)
		printf("Element <%d> - FOUND\n", val);

	return 0;
}
